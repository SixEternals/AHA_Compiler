#include "midend/BasicBlock.hpp"
#include "midend/Constant.hpp"
#include "midend/Function.hpp"
#include "midend/GlobalVariable.hpp"
#include "midend/Instruction.hpp"
#include "midend/IRContext.hpp"
#include "midend/Module.hpp"
#include "midend/Type.hpp"
#include <iostream>
#include <memory>
#include <vector>

// 前向声明测试函数
void testTypesAndConstants();
void testInstructions(Function *func, BasicBlock *bb);
void testBasicBlock(Function *func);
void testFunction();
void testModule();
void cleanupMidendTests();

// 主函数，测试入口
void runMidendTests() {
    std::cout << "--- Running Midend IR Tests ---" << std::endl;
    // ▲初始化 Constant 管理器
    Constant::manager_ = new ConstManager();
    testTypesAndConstants(); // Constant有问题
    // 下面两个都有问题
    testFunction();
    testModule();
    std::cout << "\n--- Midend IR Tests Finished ---" << std::endl;
    cleanupMidendTests();
}

void cleanupMidendTests() {
    if (Constant::manager_) {
        Constant::manager_->clear();
        delete Constant::manager_;
        Constant::manager_ = nullptr;
    }
    // IRContext::reset();
    std::cout << "--- Midend Tests Cleaned Up ---" << std::endl;
}

void testTypesAndConstants() {
    std::cout << "\n--- Testing Types and Constants ---" << std::endl;

    // Types
    auto void_ty = Type::getVoidType();
    auto label_ty = Type::getLabelType();
    auto int1_ty = Type::getInt1Type();
    auto int32_ty = Type::getInt32Type();
    auto float_ty = Type::getFloatType();
    auto int32_ptr_ty = Type::getInt32PtrType();
    auto array_ty = Type::getArrayType(int32_ty, 10);
    auto ptr_to_array_ty = Type::getPointerType(array_ty);

    std::cout << "Void Type: " << void_ty->print() << std::endl;
    std::cout << "Label Type: " << label_ty->print() << std::endl;
    std::cout << "Int1 Type: " << int1_ty->print() << std::endl;
    std::cout << "Int32 Type: " << int32_ty->print() << std::endl;
    std::cout << "Float Type: " << float_ty->print() << std::endl;
    std::cout << "Int32 Ptr Type: " << int32_ptr_ty->print() << std::endl;
    std::cout << "Array Type: " << array_ty->print() << std::endl;
    std::cout << "Pointer to Array Type: " << ptr_to_array_ty->print()
              << std::endl;

    // Constants
    auto const_int_1 = ConstantInt::get(42);
    auto const_int_2 = ConstantInt::get(10);
    auto const_bool = ConstantInt::get(true);
    auto const_fp = ConstantFP::get(3.14f);
    auto const_zero = ConstantZero::get(int32_ty);
    
    std::map<int, Value *> array_init_map;

    array_init_map[0] = ConstantInt::get(1);
    array_init_map[1] = ConstantInt::get(2);
    auto const_array = ConstantArray::get(array_ty, array_init_map, 10);

    std::cout << "ConstantInt: " << const_int_1->print() << std::endl;
    std::cout << "ConstantBool: " << const_bool->print() << std::endl;
    std::cout << "ConstantFP: " << const_fp->print() << std::endl;
    std::cout << "ConstantZero: " << const_zero->print() << std::endl;
    std::cout << "ConstantArray: " << const_array->print() << std::endl;

    auto const_add =
        Constant::get(const_int_1, Instruction::OpID::add, const_int_2);
    std::cout << "Constant Expression (add): " << const_add->print()
              << std::endl;
}

void testInstructions(Function *func, BasicBlock *bb) {
    std::cout << "\n--- Testing Instructions ---" << std::endl;
    auto int32_ty = Type::getInt32Type();
    auto float_ty = Type::getFloatType();
    auto int1_ty = Type::getInt1Type();

    auto val1 = ConstantInt::get(10);
    auto val2 = ConstantInt::get(20);
    auto fval1 = ConstantFP::get(1.0);
    auto fval2 = ConstantFP::get(2.0);

    // BinaryInst
    auto add = BinaryInst::createAdd(val1, val2, bb);
    add->setName("add_res");
    std::cout << add->print() << std::endl;

    // AllocaInst
    auto alloca_inst = AllocaInst::createAlloca(int32_ty, bb);
    alloca_inst->setName("my_var");
    std::cout << alloca_inst->print() << std::endl;

    // StoreInst & LoadInst
    auto store_inst = StoreInst::createStore(val1, alloca_inst, bb);
    std::cout << store_inst->print() << std::endl;
    auto load_inst = LoadInst::createLoad(int32_ty, alloca_inst, bb);
    load_inst->setName("loaded_val");
    std::cout << load_inst->print() << std::endl;

    // CmpInst
    auto cmp_inst = CmpInst::createCmp(CmpOp::EQ, load_inst, val2, bb);
    cmp_inst->setName("cmp_res");
    std::cout << cmp_inst->print() << std::endl;

    // ZextInst
    auto zext_inst = ZextInst::createZext(cmp_inst, int32_ty, bb);
    zext_inst->setName("zext_res");
    std::cout << zext_inst->print() << std::endl;

    // SiToFpInst & FpToSiInst
    auto sitofp_inst = SiToFpInst::createSiToFp(val1, float_ty, bb);
    sitofp_inst->setName("sitofp_res");
    std::cout << sitofp_inst->print() << std::endl;
    auto fptosi_inst = FpToSiInst::createFpToSi(fval1, int32_ty, bb);
    fptosi_inst->setName("fptosi_res");
    std::cout << fptosi_inst->print() << std::endl;

    // SelectInst
    auto select_inst =
        SelectInst::createSelect(int32_ty, cmp_inst, val1, val2, bb);
    select_inst->setName("select_res");
    std::cout << select_inst->print() << std::endl;

    // ReturnInst
    auto ret_inst = ReturnInst::createRet(select_inst, bb);
    std::cout << ret_inst->print() << std::endl;

    // Test instruction deletion
    // bb->deleteInstr(ret_inst);
    // std::cout << "After deleting ret_inst, BB has " << bb->getNumOfInstrs()
    //           << " instructions." << std::endl;
    // ReturnInst::createVoidRet(bb); // Add a terminator back
}

void testBasicBlock(Function *func) {
    std::cout << "\n--- Testing BasicBlock ---" << std::endl;
    auto entry_bb = BasicBlock::create("entry", func);
    auto then_bb = BasicBlock::create("if.then", func);
    auto else_bb = BasicBlock::create("if.else", func);
    auto end_bb = BasicBlock::create("if.end", func);

    // Test CFG
    auto cond = ConstantInt::get(true);
    BranchInst::createCondBr(cond, then_bb, else_bb, entry_bb);
    BranchInst::createBr(end_bb, then_bb);
    BranchInst::createBr(end_bb, else_bb);

    // Test PHI
    auto phi_val = PhiInst::createPhi(Type::getInt32Type(), end_bb);
    phi_val->setName("phi_res");
    phi_val->addPhiPairOperand(ConstantInt::get(1), then_bb);
    phi_val->addPhiPairOperand(ConstantInt::get(0), else_bb);
    ReturnInst::createRet(phi_val, end_bb);

    std::cout << "Original Function with BBs:\n" << func->print() << std::endl;

    // Test BB copy
    auto copied_bb = entry_bb->copyBB();
    copied_bb->setName("entry_copied");
    func->addBasicBlock(copied_bb); // Manually add to function for printing
    std::cout << "Copied BB:\n" << copied_bb->print() << std::endl;

    // Test BB removal
    func->removeBasicBlock(copied_bb);
    delete copied_bb; // Manually delete since it's not managed after removal
    std::cout << "After removing copied BB, function has "
              << func->getNumBasicBlocks() << " basic blocks." << std::endl;
}

void testFunction() {
    std::cout << "\n--- Testing Function ---" << std::endl;
    auto module = std::make_unique<Module>("test_module");

    // Declare a function
    auto puts_type =
        FunctionType::get(Type::getInt32Type(), {Type::getInt32PtrType()});
    auto puts_func = Function::create(puts_type, "puts", module.get());

    // Define a function: int main(int argc, char** argv)
    std::vector<Type *> main_params = {
        Type::getInt32Type(), Type::getPointerType(Type::getInt32PtrType())};
    auto main_func_type = FunctionType::get(Type::getInt32Type(), main_params);
    auto main_func = Function::create(main_func_type, "main", module.get());

    // Test function arguments
    auto args = main_func->getArgs();
    int i = 0;
    for (auto &arg: args) {
        arg->setName("arg" + std::to_string(i++));
    }

    // Test with a simple BB and some instructions
    auto entry_bb = BasicBlock::create("entry", main_func);
    testInstructions(main_func, entry_bb);

    // Test with more complex BB structure
    // testBasicBlock(main_func); // 🔺 This call complicates the function state and likely causes the issue.

    std::cout << "\n--- Generated Function IR ---" << std::endl;
    std::cout << main_func->print() << std::endl; // 🔺 

    std::cout << "\n--- Generated Function CFG (DOT format) ---" << std::endl;
    std::cout << main_func->printGra() << std::endl;
}

void testModule() {
    std::cout << "\n--- Testing Module ---" << std::endl;
    auto module = std::make_unique<Module>("my_awesome_module");
    module->setFileName("test.c");

    // Add a global variable
    auto g_var = GlobalVariable::create("my_global_var", module.get(),
                                        Type::getInt32Type(), false,
                                        ConstantInt::get(123));

    // Add a function declaration
    auto printf_type =
        FunctionType::get(Type::getInt32Type(), {Type::getInt32PtrType()});
    Function::create(printf_type, "printf", module.get());

    // Add a function definition
    auto main_func_type = FunctionType::get(Type::getInt32Type(), {});
    auto main_func = Function::create(main_func_type, "main", module.get());
    auto entry_bb = BasicBlock::create("entry", main_func);
    auto val = ConstantInt::get(0);
    ReturnInst::createRet(val, entry_bb);

    std::cout << "\n--- Generated Module IR ---" << std::endl;
    std::cout << module->print() << std::endl;

    // Test function deletion from module
    module->deleteFunction(main_func);
    std::cout << "\n--- Module IR after deleting main ---" << std::endl;
    std::cout << module->print() << std::endl;
}
