#include "midend/Module.hpp"
#include "midend/BasicBlock.hpp"
#include "midend/Constant.hpp"
#include "midend/Function.hpp"
#include "midend/GlobalVariable.hpp"
#include "midend/Instruction.hpp"
#include "midend/Type.hpp"
#include "midend/Value.hpp"
#include <ostream>
#include <set>

Module::Module(std::string name)
    : module_name_(name),
      instr_id2string_{
          {Instruction::OpID::ret, "ret"},
          {Instruction::OpID::br, "br"},
          {Instruction::OpID::add, "add"},
          {Instruction::OpID::sub, "sub"},
          {Instruction::OpID::mul, "mul"},
          {Instruction::OpID::mul64, "mul64"},
          {Instruction::OpID::sdiv, "sdiv"},
          {Instruction::OpID::srem, "srem"},
          {Instruction::OpID::fadd, "fadd"},
          {Instruction::OpID::fsub, "fsub"},
          {Instruction::OpID::fmul, "fmul"},
          {Instruction::OpID::fdiv, "fdiv"},
          {Instruction::OpID::alloca, "alloca"},
          {Instruction::OpID::load, "load"},
          {Instruction::OpID::store, "store"},
          {Instruction::OpID::memset, "memset"},
          {Instruction::OpID::cmp, "icmp"},
          {Instruction::OpID::fcmp, "fcmp"},
          {Instruction::OpID::phi, "phi"},
          {Instruction::OpID::call, "call"},
          {Instruction::OpID::getelementptr, "getelementptr"},
          {Instruction::OpID::land, "and"},
          {Instruction::OpID::lor, "or"},
          {Instruction::OpID::lxor, "xor"},
          {Instruction::OpID::asr, "ashr"},
          {Instruction::OpID::shl, "shl"},
          {Instruction::OpID::lsr, "lshr"},
          {Instruction::OpID::asr64, "asr64"},
          {Instruction::OpID::shl64, "shl64"},
          {Instruction::OpID::lsr64, "lsr64"},
          {Instruction::OpID::zext, "zext"},
          {Instruction::OpID::sitofp, "sitofp"},
          {Instruction::OpID::fptosi, "fptosi"},
          {Instruction::OpID::cmpbr, "cmpbr"},
          {Instruction::OpID::fcmpbr, "fcmpbr"},
          {Instruction::OpID::loadoffset, "loadoffset"},
          {Instruction::OpID::storeoffset, "storeoffset"},
          {Instruction::OpID::select, "select"},
      } {}

Function *Module::getMainFunction() {
    return *(functions_list_.rbegin());
}

void Module::deleteFunction(Function *f) {
    for (auto b: f->getBasicBlocks()) {
        for (auto i: b->getInstructions()) {
            i->removeUseOfOps();
        }
    }
    for (auto b: f->getBasicBlocks()) {
        for (auto i: b->getInstructions()) {
            delete i;
        }
        delete b;
    }

    functions_list_.remove(f);
}

Module::~Module() {
    // breakCheck();
    // 清理指令的操作数引用
    for (auto f: functions_list_) {
        for (auto b: f->getBasicBlocks()) {
            for (auto i: b->getInstructions()) {
                i->removeUseOfOps();
            }
        }
    }

    // 释放指令、基本块和函数
    for (auto f: functions_list_) {
        for (auto b: f->getBasicBlocks()) {
            for (auto i: b->getInstructions()) {
                delete i;
            }
            delete b;
        }
        delete f;
    }

    // 释放全局变量
    for (auto g: globals_list_) {
        delete g;
    }
    Constant::manager_->cached_bool.clear();
    Constant::manager_->cached_int.clear();
    Constant::manager_->cached_float.clear();
    Constant::manager_->cached_zero.clear();
}

void Module::addFunction(Function *f) {
    functions_list_.push_back(f);
}

void Module::addGlobalVariable(GlobalVariable *g) {
    globals_list_.push_back(g);
}

void Module::setPrintName() {
    for (auto &func: this->getFunctions()) {
        func->setInstrName();
    }
}

std::string Module::print() {
    std::ostringstream module_ir;
    module_ir <<
        R"(define i32 @loadoffset_i(i32* %base_addr,i32 %offset){
  %load = getelementptr i32 , i32* %base_addr , i32 %offset 
  %ret = load i32, i32* %load
  ret i32 %ret
}
define float @loadoffset_f(float* %base_addr,i32 %offset){
  %load = getelementptr float , float* %base_addr , i32 %offset 
  %ret = load float, float* %load
  ret float %ret
}
define void @storeoffset_i(i32 %val ,i32* %base_addr, i32 %offset){
    %store = getelementptr i32 , i32* %base_addr , i32 %offset
    store i32 %val, i32* %store
    ret void
}
define void @storeoffset_f(float %val , float* %base_addr, i32 %offset){
    %store = getelementptr float , float* %base_addr , i32 %offset
    store float %val, float* %store
    ret void
}
%struct.LUTEntry = type { i64, i32, i32 }

define dso_local i32* @xcCacheLookup(i32*, i32, i32) local_unnamed_addr #0 {
  %4 = bitcast i32* %0 to %struct.LUTEntry*
  %5 = zext i32 %1 to i64
  %6 = shl nuw i64 %5, 32
  %7 = sext i32 %2 to i64
  %8 = or i64 %6, %7
  %9 = urem i64 %8, 1021
  %10 = getelementptr inbounds %struct.LUTEntry, %struct.LUTEntry* %4, i64 %9
  %11 = getelementptr inbounds %struct.LUTEntry, %struct.LUTEntry* %4, i64 %9, i32 2
  %12 = load i32, i32* %11, align 4
  %13 = icmp eq i32 %12, 0
  %14 = getelementptr inbounds %struct.LUTEntry, %struct.LUTEntry* %10, i64 0, i32 0
  br i1 %13, label %22, label %15

15:
  %16 = load i64, i64* %14, align 8
  %17 = icmp eq i64 %16, %8
  br i1 %17, label %25, label %18

18:
  %19 = getelementptr inbounds %struct.LUTEntry, %struct.LUTEntry* %4, i64 %9
  %20 = getelementptr inbounds %struct.LUTEntry, %struct.LUTEntry* %4, i64 %9, i32 2
  store i32 0, i32* %20, align 4
  %21 = getelementptr inbounds %struct.LUTEntry, %struct.LUTEntry* %19, i64 0, i32 0
  br label %22

22:
  %23 = phi i64* [ %21, %18 ], [ %14, %3 ]
  %24 = phi %struct.LUTEntry* [ %19, %18 ], [ %10, %3 ]
  store i64 %8, i64* %23, align 8
  br label %25

25:
  %26 = phi %struct.LUTEntry* [ %10, %15 ], [ %24, %22 ]
  %27 = bitcast %struct.LUTEntry* %26 to i32*
  ret i32* %27
}

attributes #0 = { nofree norecurse nounwind uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
)";
    for (auto &global_val: this->globals_list_) {
        module_ir << global_val->print();
        module_ir << "\n";
    }
    module_ir << "\n";
    for (auto &func: this->functions_list_) {
        if (func->getName() == "xcCacheLookup") {
            continue;
        }
        module_ir << func->print();
        module_ir << "\n";
    }
    return module_ir.str();
}

/*
1. 检查所有的function，但是跳过声明
2. BFS检查BB可达性
3. 清除不可达BB内部的use关系
*/

// 在 IR 构造或变换之后对 整张函数图 做完整性和引用检查，确保 IR
// 没有悬空引用、不一致的数据流、或语义错误。
/*
控制流图检查：检查所有基本块是否是可达的。
数据流引用校验：检查每个指令的操作数是否合法，且没有 dangling use。
Use-Def 清理后检查：确保 use 列表全部为空（即无指令仍引用它们）。
*/
void Module::breakCheck() {
    /* Part 1
    检查所有的function，跳过[`声明`]
    */
    for (auto f: functions_list_) {
        if (f->isDeclaration()) {
            continue;
        }
        // 入口function不应该有preBB
        auto entry = f->getEntryBlock();
        assert(entry->getPreBasicBlocks().empty());

        // BFS 可达性检查：
        /*
        遍历控制流图（CFG）
        收集：
            所有可达的基本块 reachable
            所有指令 ins_list（用于后续引用清理）
        */
        std::list<BasicBlock *> work_list{entry};
        std::set<BasicBlock *> reachable;
        std::vector<Instruction *> ins_list;
        do {
            auto curbb = work_list.front();
            work_list.pop_front();
            reachable.insert(curbb);
            for (auto s: curbb->getSuccBasicBlocks()) {
                if (reachable.count(s)) {
                    continue;
                }
                work_list.push_back(s);
            }
            ins_list.insert(ins_list.end(), curbb->getInstructions().begin(),
                            curbb->getInstructions().end());
        } while (!work_list.empty());
        // 不可达BB检查
        for (auto b: f->getBasicBlocks()) {
            assert(reachable.count(b));
        }

        for (auto i: ins_list) {
            for (auto o: i->getOperands()) {
                if (o == 0) {
                    continue;
                }
                if (auto op_i = dynamic_cast<Instruction *>(o)) {
                    // assert(0);
                } else if (auto f = dynamic_cast<Function *>(o)) {
                    f->removeUse(i);
                } else if (auto g = dynamic_cast<GlobalVariable *>(o)) {
                    g->removeUse(i);
                } else if (auto constant = dynamic_cast<Constant *>(o)) {
                    constant->removeUse(i);
                } else if (auto bb = dynamic_cast<BasicBlock *>(o)) {
                    bb->removeUse(i);
                } else if (auto arg = dynamic_cast<Argument *>(o)) {
                    arg->removeUse(i);
                } else {
                    assert(0);
                }
            }
        }
        // 检查是否清理干净
        for (auto i: ins_list) {
            assert(i->useEmpty());
        }
    }
    for (auto g: globals_list_) {
        assert(g->useEmpty());
    }
    for (auto f: functions_list_) {
        assert(f->useEmpty());
        for (auto arg: f->getArgs()) {
            assert(arg->useEmpty());
        }
        for (auto b: f->getBasicBlocks()) {
            assert(b->useEmpty());
        }
    }
}

std::string Module::printGra() {
    std::string ret = "digraph {\n";
    for (auto f: getFunctions()) {
        if (f->isDeclaration()) {
            continue;
        }
        ret += f->printGra();
    }
    ret += "}\n";
    return ret;
}
