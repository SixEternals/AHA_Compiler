#include "midend/IRContext.hpp"
#include "midend/Type.hpp"
#include <cassert>
#include <iostream>
#include <vector>

void runIRContextTests() {
    std::cout << "--- Running IRContext Tests ---" << std::endl;

    // 1. 测试单例模式
    std::cout << "\n--- Testing Singleton ---" << std::endl;
    IRContext &context1 = IRContext::getInstance();
    IRContext &context2 = IRContext::getInstance();
    assert(&context1 == &context2 && "IRContext::getInstance() should return the same instance.");
    std::cout << "Singleton test passed." << std::endl;
    std::cout << "Context address: " << &context1 << std::endl;

    // 2. 测试基本类型
    std::cout << "\n--- Testing Basic Types ---" << std::endl;
    Type *void_ty = context1.getVoidType();
    Type *label_ty = context1.getLabelType();
    IntegerType *int1_ty = context1.getInt1Type();
    IntegerType *int32_ty = context1.getInt32Type();
    FloatType *float_ty = context1.getFloatType();

    assert(void_ty == context1.getVoidType() && "getVoidType should be cached.");
    assert(label_ty == context1.getLabelType() && "getLabelType should be cached.");
    assert(int1_ty == context1.getInt1Type() && "getInt1Type should be cached.");
    assert(int32_ty == context1.getInt32Type() && "getInt32Type should be cached.");
    assert(float_ty == context1.getFloatType() && "getFloatType should be cached.");

    std::cout << "Void Type: " << void_ty->print() << std::endl;
    std::cout << "Label Type: " << label_ty->print() << std::endl;
    std::cout << "Int1 Type: " << int1_ty->print() << std::endl;
    std::cout << "Int32 Type: " << int32_ty->print() << std::endl;
    std::cout << "Float Type: " << float_ty->print() << std::endl;
    std::cout << "Basic types test passed." << std::endl;

    // 3. 测试指针类型
    std::cout << "\n--- Testing Pointer Types ---" << std::endl;
    PointerType *int32_ptr_ty = context1.getInt32PtrType();
    PointerType *float_ptr_ty = context1.getFloatPtrType();
    PointerType *int1_ptr_ty = context1.getPointerType(int1_ty);
    PointerType *int32_ptr_ptr_ty = context1.getPointerType(int32_ptr_ty);

    assert(int32_ptr_ty == context1.getInt32PtrType() && "getInt32PtrType should be cached.");
    assert(float_ptr_ty == context1.getFloatPtrType() && "getFloatPtrType should be cached.");
    assert(int1_ptr_ty == context1.getPointerType(int1_ty) && "getPointerType should be cached.");
    assert(int32_ptr_ty != int1_ptr_ty && "Pointers to different types should be different.");

    std::cout << "Int32 Ptr Type: " << int32_ptr_ty->print() << std::endl;
    std::cout << "Float Ptr Type: " << float_ptr_ty->print() << std::endl;
    std::cout << "Int1 Ptr Type: " << int1_ptr_ty->print() << std::endl;
    std::cout << "Int32 Ptr Ptr Type: " << int32_ptr_ptr_ty->print() << std::endl;
    std::cout << "Pointer types test passed." << std::endl;

    // 4. 测试数组类型
    std::cout << "\n--- Testing Array Types ---" << std::endl;
    ArrayType *array_ty1 = context1.getArrayType(int32_ty, 10);
    ArrayType *array_ty2 = context1.getArrayType(int32_ty, 10);
    ArrayType *array_ty3 = context1.getArrayType(int32_ty, 20);
    ArrayType *array_ty4 = context1.getArrayType(float_ty, 10);

    assert(array_ty1 == array_ty2 && "getArrayType should be cached for same element type and size.");
    assert(array_ty1 != array_ty3 && "Arrays of different sizes should be different types.");
    assert(array_ty1 != array_ty4 && "Arrays of different element types should be different types.");

    std::cout << "Array Type 1: " << array_ty1->print() << std::endl;
    std::cout << "Array Type 2: " << array_ty2->print() << std::endl;
    std::cout << "Array Type 3: " << array_ty3->print() << std::endl;
    std::cout << "Array Type 4: " << array_ty4->print() << std::endl;
    std::cout << "Array types test passed." << std::endl;

    // 5. 测试函数类型
    std::cout << "\n--- Testing Function Types ---" << std::endl;
    std::vector<Type *> params1 = {int32_ty, float_ptr_ty};
    FunctionType *func_ty1 = context1.getFunctionType(int32_ty, params1);
    FunctionType *func_ty2 = context1.getFunctionType(int32_ty, params1);

    std::vector<Type *> params2 = {};
    FunctionType *func_ty3 = context1.getFunctionType(void_ty, params2);

    std::vector<Type *> params3 = {int32_ty, float_ptr_ty};
    FunctionType *func_ty4 = context1.getFunctionType(void_ty, params3);

    assert(func_ty1 == func_ty2 && "getFunctionType should be cached for same signature.");
    assert(func_ty1 != func_ty3 && "Functions with different signatures should be different types.");
    assert(func_ty1 != func_ty4 && "Functions with different return types should be different types.");

    std::cout << "Function Type 1: " << func_ty1->print() << std::endl;
    std::cout << "Function Type 2: " << func_ty2->print() << std::endl;
    std::cout << "Function Type 3: " << func_ty3->print() << std::endl;
    std::cout << "Function Type 4: " << func_ty4->print() << std::endl;
    std::cout << "Function types test passed." << std::endl;

    std::cout << "\n--- IRContext Tests Finished ---" << std::endl;
}
