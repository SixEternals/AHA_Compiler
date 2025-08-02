- [IRGen部分](#irgen部分)
  - [IRGen继承自IRVisitor](#irgen继承自irvisitor)
- [Instruction部分](#instruction部分)
  - [br](#br)
    - [select代替 `br` + `cmp`](#select代替-br--cmp)
  - [addInstrAfterPhiInst](#addinstrafterphiinst)
  - [Compiler解耦Instruction部分](#compiler解耦instruction部分)
  - [哪些Instruction需要返回Type?](#哪些instruction需要返回type)
  - [vector和list的使用场合](#vector和list的使用场合)
  - [User和Value的关系](#user和value的关系)
    - [继承User](#继承user)
    - [Value存在的意义](#value存在的意义)
    - [只需要继承Value的类：](#只需要继承value的类)
- [BasicBlock部分](#basicblock部分)
  - [BasicBlock需要管理loop\_depth](#basicblock需要管理loop_depth)
  - [terminator](#terminator)
  - [addInstrBeforeTerminator](#addinstrbeforeterminator)
  - [erase和insert Instruction](#erase和insert-instruction)
    - [erase和insert使用例子](#erase和insert使用例子)
  - [CopyBB](#copybb)
    - [对PHI的特殊处理](#对phi的特殊处理)
- [三地址码](#三地址码)
- [Pass](#pass)
  - [Instruction Combining Pass](#instruction-combining-pass)
- [问题](#问题)
  - [incomplete type error](#incomplete-type-error)
  - [.sy获取途径](#sy获取途径)
  - [防止conda环境影响xmake](#防止conda环境影响xmake)


# IRGen部分

| 函数名                            | 作用                           | 关键点                                               |
| --------------------------------- | ------------------------------ | ---------------------------------------------------- |
| visit(ast::CompunitNode\&node)    | 处理复合单元节点，遍历全局定义 | 遍历全局定义，调用每个声明的 accept 方法             |
| visit(ast::FuncDef\&node)         | 处理函数定义，生成函数的 IR    | 创建函数类型、函数对象，处理参数和返回值，生成函数体 |
| visit(ast::FuncFParam\&node)      | 处理函数参数，确定参数类型     | 确定参数类型，处理数组参数                           |
| visit(ast::BlockStmt\&node)       | 处理代码块，管理作用域         | 进入和退出作用域，处理块内的语句                     |
| visit(ast::ValDeclStmt\&node)     | 处理变量声明                   | 确定变量类型，处理变量定义                           |
| visit(ast::ValDefStmt\&node)      | 处理变量定义，包括初始化       | 分配变量内存，处理初始化表达式                       |
| visit(ast::ConstDeclStmt\&node)   | 处理常量声明                   | 确定常量类型，处理常量定义                           |
| visit(ast::ConstDefStmt\&node)    | 处理常量定义，确保初始化       | 存储常量值，处理常量初始化                           |
| visit(ast::ArrDefStmt\&node)      | 处理数组定义，包括初始化       | 分配数组内存，处理数组初始化                         |
| visit(ast::ConstArrDefStmt\&node) | 处理常量数组定义               | 分配常量数组内存，处理初始化                         |
| visit(ast::IntConst\&node)        | 处理整型常量                   | 存储整型常量值                                       |
| visit(ast::FloatConst\&node)      | 处理浮点型常量                 | 存储浮点型常量值                                     |
| visit(ast::InitializerExpr\&node) | 处理初始化表达式               | 处理数组或结构体的初始化                             |
| visit(ast::ExprStmt\&node)        | 处理表达式语句                 | 处理表达式并生成 IR                                  |
| visit(ast::AssignStmt\&node)      | 处理赋值语句                   | 生成赋值操作的 IR                                    |
| visit(ast::UnaryExpr\&node)       | 处理一元表达式                 | 生成一元操作的 IR                                    |
| visit(ast::AssignExpr\&node)      | 处理赋值表达式                 | 生成赋值表达式的 IR                                  |
| visit(ast::RelopExpr\&node)       | 处理关系运算表达式             | 生成关系运算的 IR                                    |
| visit(ast::EqExpr\&node)          | 处理等式表达式                 | 生成等式比较的 IR                                    |
| visit(ast::AndExp\&node)          | 处理逻辑与表达式               | 生成逻辑与操作的 IR                                  |
| visit(ast::ORExp\&node)           | 处理逻辑或表达式               | 生成逻辑或操作的 IR                                  |
| visit(ast::BinopExpr\&node)       | 处理二元运算表达式             | 生成二元运算的 IR                                    |
| visit(ast::LvalExpr\&node)        | 处理左值表达式                 | 处理变量访问和数组访问                               |
| visit(ast::IfStmt\&node)          | 处理 if 语句                   | 生成条件跳转的 IR                                    |
| visit(ast::WhileStmt\&node)       | 处理 while 语句                | 生成循环结构的 IR                                    |
| visit(ast::CallExpr\&node)        | 处理函数调用                   | 生成函数调用的 IR                                    |
| visit(ast::RetStmt\&node)         | 处理返回语句                   | 生成返回指令的 IR                                    |
| visit(ast::ContinueStmt\&node)    | 处理 continue 语句             | 生成循环继续的 IR                                    |
| visit(ast::BreakStmt\&node)       | 处理 break 语句                | 生成循环跳出的 IR                                    |
| visit(ast::EmptyStmt\&node)       | 处理空语句                     | 生成空操作的 IR                                      |
| IRGen::IRGen()                    | 构造函数，初始化模块和内置函数 | 初始化 IR生成器，创建内置函数                        |

## IRGen继承自IRVisitor

# Instruction部分

## br

通过Operands的数量来判别是条件跳转or无条件跳转

### select代替 `br` + `cmp`

(select, 看最后一段)[https://mapping-high-level-constructs-to-llvm-ir.readthedocs.io/en/latest/control-structures/if-then-else.html]
在某些简单的条件跳转（cmp + br）结构中，如果两个分支只是在值选择（而非控制流程转移），那么可以使用 select 指令来替代 cmp + br + phi，从而避免基本块分裂与条件跳转，提升 IR 简洁度和优化空间。
原：

```LLVM
%cond = icmp eq i32 %a, %b
br i1 %cond, label %if_true, label %if_false

if_true:
  %v1 = add i32 %x, 1
  br label %merge

if_false:
  %v2 = add i32 %x, 2
  br label %merge

merge:
  %result = phi i32 [%v1, %if_true], [%v2, %if_false]
```

后：

```LLVMIR
%cond = icmp eq i32 %a, %b
%v1 = add i32 %x, 1
%v2 = add i32 %x, 2
%result = select i1 %cond, i32 %v1, i32 %v2
```
## addInstrAfterPhiInst
插入指令时若放在 Phi 前会导致语义错误，或打乱 SSA
构造逻辑。因此这个函数专门用来：
    保证你插入的指令 不会打断 Phi 链
    同时又尽量靠前插入，利于指令局部性、优化等

**例子：**
插入前：
```LLVMIR
BasicBlock bb:
    %a = phi i32 [ %x, %pred1 ], [ %y, %pred2 ]
    %b = phi i32 [ %m, %pred1 ], [ %n, %pred2 ]
    %c = add %a, %b
    br label %next
```
调用 addInstrAfterPhiInst(%t = mul %a, %b) 后，它会插在 %b 和 %c 之间：
```LLVMIR
BasicBlock bb:
    %a = phi ...
    %b = phi ...
    %t = mul %a, %b    <-- 新指令
    %c = add %a, %b
    br label %next
```

而且为了遵守LLVM规范
  1. PHI必须为BB第一批指令
  2. PHI必须连续出现，不能和非PHI指令交错
所以以下不正确:
```LLVMIR
BasicBlock bb:
    %tmp = mul 1, 2
    %a = phi ...
    %b = phi ...
// 或者
BasicBlock bb:
    %a = phi ...
    %tmp = mul 1, 2
    %b = phi ...
```
最终版
```cpp
void BasicBlock::addInstrAfterPhiInst(Instruction* instr){
  instr->setParent(this);
  auto pos = std::find_if_not(instr_list_.begin(), instr_list_.end(), [](Instruction* instr){
    return instr->isPhi();
  });
  instr_list_.insert(pos, instr);
}
``` 

## Compiler解耦Instruction部分

## 哪些Instruction需要返回Type?

需要:
  LoadInst, AllocaInst, ZextInst

不需要:
  MemsetInst

## vector和list的使用场合

```cpp
class Function {
    std::vector<std::unique_ptr<BasicBlock>> basicBlocks;
    // 顺序固定，按顺序执行，偶尔重排 → 用 vector 很合适
};

class BasicBlock {
    std::list<std::unique_ptr<Instruction>> instructions;
    // 要支持频繁地中间插入、删除指令（如 DCE、GCM、CSE）→ 用 list 是最佳选择
};
```

## User和Value的关系

取自源码

```cpp
// Value
class Value {
public:
    // 冷知识，explicit需要初始化形参，所以才有name=""
    explicit Value(Type *ty, const std::string &name=""): type_(ty), name_(name) {}
    virtual ~Value() = default;

    Type *getType() const { return type_; } 

    std::list<Use> &getUseList() { return use_list_; }
    int getUseNum() { return use_list_.size(); }
    void addUse(Value* val, size_t arg_no = 0);

    bool setName(std::string name) {
      if(name_ == "") {
        name_ = name;
        return  true;
      } 
      return false;
    }

    void takeName(Value* v){
        name_ = v->getName();
        v->name_= "";
    }
  
    std::string getName() const { return name_; }

    void replaceAllUseWith(Value *new_val);
    void replaceUseWithWhen(Value *new_val, std::function<bool(User *)> pred); //& replace `value` with `new_val` when the user of value satisfies predicate `pred`
    void removeUse(Value *val);

    __attribute__((always_inline))  bool useOne(){return use_list_.size()==1;}
    __attribute__((always_inline))  bool useEmpty(){return use_list_.empty();}  
    virtual std::string print() = 0;

private:
    Type *type_;
    std::list<Use> use_list_;   //& store the users who use this value
    std::string name_;        
};

// User
class User : public Value {
public:
    User(Type *ty, const std::string &name="", size_t num_ops = 0);
    ~User() = default;

    void replaceOperand(size_t i,Value*v);
    Value *getOperand(size_t i) const;   //& start from 0
    void setOperand(size_t i, Value *v);   //& start from 0
    void addOperand(Value *v);

    std::vector<Value *> &getOperands();
   size_t getNumOperands() const noexcept;

    void removeAllOperand();
    void removeOperands(int index1, int index2);
    void removeUseOfOps();
  
private:
    std::vector<Value *> operands_;   //& operands of this value
    // size_t num_ops_;  

};
```

User负责维护use-def -> std::list`<Use>` use_list_;
Value负责维护def-use -> std::vector<Value *> operands_;

### 继承User

Constant
  个别并非全部
  不是所有 Constant 都继承 User，但像 ConstantExpr 这种表达式型常量会继承 User，因为它们“使用了其他值”。
  `@arr = global [4 x i32] [i32 1, i32 2 + 3, i32 4, i32 5]`

GlobalVariable
  虽然 GlobalVariable 本身不像指令那样有复杂操作数，但它在 LLVM IR 中可能初始化为另一个常量（即它使用了一个常量表达式），所以也要记录它“用了谁”。
  `@x = global i32* @y`

Instruction（毋庸置疑）
  如 `%1 = add i32 %a, %b`

```cpp
         Value
           |
         User
        /  |   \
 Instr. Const Global
```

### Value存在的意义

Value 表示 IR 中可以被引用的抽象实体，具有名字、类型、use-def 信息。
诸如Function需要查询“谁”使用了它。
✅ 我们希望能够追踪这个函数被哪些地方引用或调用了。

不用继承User的原因：
  因为 Function 不会持有 operand，它不会 “使用” 别的值，而是“被使用”。

### 只需要继承Value的类：

ConstantInt: 是值但不引用其他值, 是[`立即数`]

# BasicBlock部分

## BasicBlock需要管理loop_depth

1. 用于分析
   比如在 `CLND`的analyseOnFunc()里

```cpp
// CLND.cpp
void CLND::analyseOnFunc(Function*func){
    auto initialfunc = initialFunction(func);
    if(initialfunc!=nullptr){
        marker.clear();
        dfn_.clear();
        low_.clear();
        dfn = 0;
        auto bb_entry = initialfunc->getEntryBlock();
        calLoopNestingDepth(bb_entry);
        while(!Loops.empty() ){
            auto loop = Loops.back();
            Loops.pop_back();
            auto bb_loop_entry = *(*loop).rbegin();
            marker[bb_loop_entry] = visited;
            if(!bb_[bb_loop_entry])
               outer_[loop] = bb_[bb_loop_entry]; 
            for(auto bb : *loop){
                // bb->loopDepthAdd(1); 代表增加循环嵌套深度
                bb->loopDepthAdd(1);        //0代表没循环，1代表一层循环
                bb_[bb] = loop;
            }
          
       
            //再来，现在已经分析完了一个函数的一层循环，接下来进入嵌套的一层
            dfn_.clear();
            low_.clear();
            dfn = 0;
      
            for(auto bb_succ : bb_loop_entry->getSuccBasicBlocks()){
                //如果bb_succ没被访问过，并且bb_succ属于循环一部分（如果bb_succ不是循环的一部分，就别谈它里面还有循环嵌套了）
                if(marker[bb_succ]!=visited && bb_[bb_succ]==loop)
                    calLoopNestingDepth(bb_succ);
            }
        }
    }  
}

// BasicBlock.hpp

void loopDepthAdd(int num) {
    loop_depth += num;
}
```

## terminator

标识BasicBlock的结束
如ret, br, cmpbr条件跳转, fcmpbr浮点条件跳转, 出自

```cpp
Instruction const *BasicBlock::getTerminator() const {
    if (instr_list_.empty()) {
        return nullptr;
    }
    // 
    switch (instr_list_.back()->getInstrType()) {
    case Instruction::OpID::ret:    return instr_list_.back();
    case Instruction::OpID::br:     return instr_list_.back();
    case Instruction::OpID::cmpbr:  return instr_list_.back();
    case Instruction::OpID::fcmpbr: return instr_list_.back();
    default:                        return nullptr;
    }
}
```

作用：
用于获取当前基本块（BasicBlock）的“终结指令”（terminator instruction），例如 ret、br、cmpbr、fcmpbr 等控制流指令。它返回的是指向 Instruction 的指针。
我比较喜欢把他的名字改为 `getVaildTerminator()`

┌───────────────────────────────────────────┐
│ 1. 设置 instr 的 parent = this BasicBlock │
└───────────────────────────────────────────┘
                 │
                 ▼
┌────────────────────────────────────────────┐
│ 2. 拿到当前终结指令 term = instr_list_.back() │
└────────────────────────────────────────────┘
                 │
                 ▼
┌──────────────────────────────────┐
│ 3. 把 terminator 从 list 中移除   │
│    instr_list_.pop_back()       │
└──────────────────────────────────┘
                 │
                 ▼
┌────────────────────────────────────┐
│ 4. 区分 term 的类型                │
│                                    │
│ ┌──────────────────────────────┐   │
│ │ case: ret / cmpbr / fcmpbr   │◄──┘
│ └──────────────────────────────┘
│         │
│         ▼
│ 插入顺序：instr → term
│
│    instr_list_.push_back(instr)
│    instr_list_.push_back(term)
│
│ ✔️ 这类 terminator 已经包含条件或返回值
│    instr 插入即可，不影响控制流结构
│
├────────────────────────────────────┤
│ ┌────────────────────────────────┐ │
│ │ case: br                       │ │
│ └────────────────────────────────┘ │
│         │                          │
│         ▼                          │
│ if br 是无条件跳转：              │
│    插入顺序：instr → term         │
│ else：                            │
│    查看 term 前一条是否是 cmp     │
│      │                            │
│      ├─✔️ 是 cmp：                 │
│      │     插入顺序：instr → cmp → term
│      └─❌ 否：                     │
│            插入顺序：instr → term │
│
└────────────────────────────────────┘

| Terminator 类型 | 是否需要额外处理 | 插入顺序                                |
| --------------- | ---------------- | --------------------------------------- |
| `ret`           | 否               | `instr` → `ret`                         |
| `cmpbr`         | 否               | `instr` → `cmpbr`                       |
| `fcmpbr`        | 否               | `instr` → `fcmpbr`                      |
| `br`（无条件）  | 否               | `instr` → `br`                          |
| `br`（条件）    | 是               | `cmp` → `br`，插入点要避开 `cmp` → `br` |

## addInstrBeforeTerminator
一个 BasicBlock 中的 terminator instruction 必须是最后一条指令，不能有任何指令出现在它之后。
Terminator instruction 通常是：ret、br、switch、invoke、unreachable 等。


```cpp
void BasicBlock::addInstrBeforeTerminator(Instruction *instr) {
    instr->setParent(this); // 新指令

                            // terminator最后会放回去的
    Instruction *term = instr_list_.back();
    instr_list_.pop_back();

    switch (term->getInstrType()) {
        // 这三个无需额外逻辑
    case Instruction::OpID::ret:
    case Instruction::OpID::cmpbr:
    case Instruction::OpID::fcmpbr:
        instr_list_.push_back(instr);
        instr_list_.push_back(term);
        break;

    /*疑问
    1. 如果按照llvm ir来写，term->getOperands().size() == 0应该是==0而不是==1
    2. 同理，第一层if-else的else，我觉得应该是==3
    也就是说应该是
    case br:
    if(term->getOperands().size() == 1){
      ...
    }else if(term->getOperands().size() == 3){
      ...
    }
    */
    case Instruction::OpID::br:
        if (term->getOperands().size() == 0) {
            // 无条件跳转
            instr_list_.push_back(instr);
            instr_list_.push_back(term);
        } else {
          /*
            // 条件跳转，判断前一条指令是否为cmp
            // cmp
            // br
            // ↓
            // new_instr
            // cmp
            // br
          */
            Instruction *cmp = instr_list_.back();
            if (dynamic_cast<CmpInst *>(cmp) || dynamic_cast<FCmpInst *>(cmp)) {
                instr_list_.pop_back();
                instr_list_.push_back(instr);
                instr_list_.push_back(cmp);
                instr_list_.push_back(term);
            } else {
              // 只要进入case br里，就说明上面的`Instruction *cmp = instr_list_.back();`的cmp肯定属于br

                instr_list_.push_back(instr);
                instr_list_.push_back(term);
            }
        }
        break;
    default: assert(0 && "Unknown Terminator!");
    }
}
```
我想把它改成：
我的理解是 case版本很直观
下面的if-else的优势是复用公用部分比case好点
```cpp
void BasicBlock::addInstrBeforeTeminator(Instruction *instr){
  instr->setParent(this);
  auto terminator = instr_list_.back();
  instr_list_.pop_back();

  if(auto *br = dynamic_cast<BranchInst*>(terminator)){
    if(br->isCondBr()){
      auto cmp = instr_list_.back();
      if (dynamic_cast<CmpInst *>(cmp) || dynamic_cast<FCmpInst *>(cmp)){
        instr_list_.pop_back();
        instr_list_.push_back(instr);
        instr_list_.push_back(cmp);
        instr_list_.push_back(terminator);
        return;
      }
    }
    instr_list_.push_back(instr);
    instr_list_.push_back(terminator);
    return;
  }
  // 其他类型的terminator，如RetInst, CmpBrInst, SwitchInst...
  instr_list_.push_back(instr);
  instr_list_.push_back(terminator);
}
```

## erase和insert Instruction
```cpp
// BasicBlock.hpp
using InstrListIter = ::std::list<Instruction *>::iterator ;
InstrListIter eraseInstr(InstrListIter instr_iter);
InstrListIter InsertInstr(InstrListIter instr_iter, Instruction *instr);

// BasicBlock.cpp
using InstrListIter = ::std::list<Instruction *>::iterator;
InstrListIter BasicBlock::eraseInstr(InstrListIter instr_iter){
  /*
  [a,b,c,d,e] -> 需要删除c -> 
  外部调用
    auto it = std::find(instr_list_.begin(), instr_list_.end(), c); // 找到 c
    auto next_it = bb.eraseInstr(it);  // 调用你写的函数
  内部
    auto instr = *instr_iter;         // instr 是指向 c 的指针
    auto ret = instr_list_.erase(instr_iter); // ret 是新的迭代器，指向 d
    instr->removeUseOfOps();         // 清除对 c 的引用
    delete instr;                    // delete c
    return ret;                      // 返回指向 d 的迭代器

  [a, b, c, d, e] ->  [a, b, d, e]
    instr 是原来指向 c 的指针（你需要删除它）。
    ret 是新的迭代器，指向 d。
  */
  auto instr = *instr_iter;
  auto ret = instr_list_.erase(instr_iter);
  instr->removeUseOfOps();
  delete instr;
  return ret;
  /*
  返回ret的作用：
    如果知识把它当作erase的话，不需要关心它的返回值，用法如下
    `used_bb->eraseInstr(cur_iter);`
  需要返回值的场合：一边迭代一边删除时
    auto& instructions = bb->getInstructions();
    // 注意：循环头没有 it++
    for (auto it = instructions.begin(); it != instructions.end(); ){
        if (isInstructionDead(*it)) {
            // eraseInstr 返回被删除元素的下一个有效迭代器
            // 我们用这个返回值来更新 it，从而安全地继续下一次循环
            it = bb->eraseInstr(it);
        } else {
            // 如果不删除，才手动将迭代器向前移动
            ++it;
        }
    }
  */ 
}

// [a,b,c,d] -> 插入c -> [a,b,c,d,e] -> 返回指向c的迭代器
InstrListIter BasicBlock::InsertInstr(InstrListIter instr_iter, Instruction *instr){
  return instr_list_.insert(instr_iter, instr);
}
```
### erase和insert使用例子
对一条乘法指令做 strength reduction 优化
`%1 = mul i32 %x, 8` -> 识别出乘以8可以改成左移 -> `%1 = shl i32 %x, 3`
```cpp
void optimizeStrengthReduction(BasicBlock *bb) {
    auto &instructions = bb->getInstructions();
    for (auto iter = instructions.begin(); iter != instructions.end(); /* no ++ here */) {
        Instruction *instr = *iter;

        if (auto mul = dynamic_cast<MulInstruction *>(instr)) {
            Value *rhs = mul->getOperand(1);
            if (auto const_rhs = dynamic_cast<ConstantInt *>(rhs)) {
                int val = const_rhs->getValue();
                if (isPowerOfTwo(val)) {
                    int shift_amt = log2(val);
                    Value *lhs = mul->getOperand(0);

                    // 构造新指令
                    auto *shl = new ShlInstruction(lhs, ConstantInt::get(shift_amt));
                    // 插入新指令到旧位置前
                    iter = bb->insertInstr(iter, shl); // 返回新插入指令的位置
                    ++iter; // 跳过新插入的指令，继续处理旧的 mul
                    shl->setParent(bb); // 若 insertInstr 未设置，可保留

                    // 替换旧指令的使用
                    mul->replaceAllUsesWith(shl);

                    // 删除旧指令（当前 iter 指向 mul）
                    iter = bb->eraseInstr(iter); // 指向下一条
                    continue;
                }
            }
        }

        ++iter;
    }
}
```

## CopyBB
```cpp
BasicBlock *BasicBlock::copyBB() {
    // 创建一个新的基本块，属于当前基本块的父函数
    BasicBlock *newBB = BasicBlock::create("", this->getParent());

    // 用于记录旧指令到新指令的映射关系
    std::map<Instruction *, Instruction *> instMap;

    // 1. 复制当前基本块中的所有指令到新基本块
    for (Instruction *inst : instr_list_) {
        Instruction *newInst = inst->copyInst(newBB); // 调用指令的复制方法
        if (inst->isPhi()) {
            // 如果是 PHI 指令，插入到 PHI 指令之后
            newBB->addInstrAfterPhiInst(newInst);
        } else {
            // 其他指令直接插入
            newBB->addInstr(newInst);
        }
        // 记录旧指令和新指令的映射关系
        instMap[inst] = newInst;
    }

    // 2. 替换新指令中的操作数
    for (Instruction *newInst : newBB->getInstructions()) {
        auto &ops = newInst->getOperands(); // 获取操作数列表
        for (int i = 0; i < ops.size(); ++i) {
            if (auto *oldInst = dynamic_cast<Instruction *>(ops[i])) {
                // 如果操作数是旧基本块中的指令，替换为新指令
                if (instMap.count(oldInst)) {
                    newInst->replaceOperand(i, instMap[oldInst]);
                }
            }
            // 其他类型的操作数（如全局变量、常量等）保持不变
        }
    }

    // 3. 更新前驱和后继基本块
    // 我把以下逻辑挪到了Function.hpp中
    for (BasicBlock *bb : getPreBasicBlocks()) {
        newBB->addPreBasicBlock(bb); // 添加前驱基本块
        bb->replaceSuccBasicBlock(this, newBB); // 更新前驱的后继为新基本块
    }
    for (BasicBlock *bb : getSuccBasicBlocks()) {
        newBB->addSuccBasicBlock(bb); // 添加后继基本块
        bb->replacePreBasicBlock(this, newBB); // 更新后继的前驱为新基本块
    }

    // 4. 特殊处理跳转指令和 PHI 指令
    for (Instruction *newInst : newBB->getInstructions()) {
        if (newInst->isBranch() || newInst->isCmpBranch()) {
            // 如果是跳转指令，更新目标基本块
            auto &ops = newInst->getOperands();
            for (int i = 0; i < ops.size(); ++i) {
                if (auto *targetBB = dynamic_cast<BasicBlock *>(ops[i])) {
                    if (targetBB == this) {
                        newInst->replaceOperand(i, newBB); // 替换目标为新基本块
                    }
                }
            }
        } else if (newInst->isPhi()) {
            // 如果是 PHI 指令，更新来自前驱基本块的值
            auto &ops = newInst->getOperands();
            for (int i = 0; i < ops.size(); i += 2) {
                if (auto *bb = dynamic_cast<BasicBlock *>(ops[i + 1])) {
                    if (bb == this) {
                        newInst->replaceOperand(i + 1, newBB); // 替换来源基本块为新基本块
                    }
                }
            }
        }
    }

    return newBB; // 返回新创建的基本块
}
```

用处：
1. 循环优化：循环展开、循环分割、循环矢量化
2. CFG重构：克隆BB用于服用、异常处理

┌─────────────────────────────────────────────────────┐
│ 1. 创建新的 BasicBlock，并设置其 Function 父节点       │
└─────────────────────────────────────────────────────┘
                   ↓
┌─────────────────────────────────────────────────────┐
│ 2. 遍历旧 BB 中的指令列表：                          │
│    - 调用 inst->copyInst(newBB) 创建新指令           │
│    - 如果是 phi，插入到 phi 区域后                   │
│    - 其他插入到普通区域                             │
│    - 用 instMap[old] = new 建立映射                  │
└─────────────────────────────────────────────────────┘
                   ↓
┌─────────────────────────────────────────────────────┐
│ 3. 遍历新 BB 中的指令，替换 operand：                │
│    - 如果 op 是 Instruction，并存在于旧 instMap 中    │
│      替换为对应新指令                                │
└─────────────────────────────────────────────────────┘
                   ↓
┌─────────────────────────────────────────────────────┐
│ 4. 更新前驱和后继基本块：                            │
│    - newBB->addPreBasicBlock(old_pre)               │
│    - old_pre->replaceSucc(this, newBB)              │
│    - newBB->addSuccBasicBlock(old_succ)             │
│    - old_succ->replacePre(this, newBB)              │
└─────────────────────────────────────────────────────┘
                   ↓
┌─────────────────────────────────────────────────────┐
│ 5. 遍历新指令，特殊处理：                           │
│    - 对于跳转指令，如果跳转目标是旧 BB，则改成 newBB │
│    - 对于 phi 指令，如果来源 block 是旧 BB，也替换   │
└─────────────────────────────────────────────────────┘
                   ↓
┌─────────────────────────────────────────────────────┐
│ 6. 返回 newBB                                        │
└─────────────────────────────────────────────────────┘

总而言之就是需要对[`PHI`]和[`Br`]和[`operands`]进行特殊处理

### 对PHI的特殊处理
如果直接复制 PHI 指令而不更新其前驱基本块和操作数，复制后的基本块将无法正确反映控制流关系，导致程序行为错误。
```cpp
// 例如：
// 原始基本块：
bb1:
  %1 = phi i32 [ %a, %bb0 ], [ %b, %bb2 ]
```

```cpp
// 如果直接复制为：
new_bb1:
  %2 = phi i32 [ %a, %bb0 ], [ %b, %bb2 ]
// 这里的 %bb0 和 %bb2 仍然指向原始基本块的前驱，而不是新基本块的前驱。
```
Br同理

### 对operands的特殊处理
原始基本块 bb1 的内容如下：
```cpp
bb1:
  %1 = add i32 %a, %b
  %2 = mul i32 %1, %c
  br label %bb2
// %1 是第一条指令的结果。
// %2 是第二条指令的结果，依赖于 %1。
// 跳转指令 br 跳转到基本块 bb2。
// 复制后的基本块（未替换操作数）
// 如果直接复制指令而不替换操作数，得到的新基本块 new_bb1 可能如下：

new_bb1:
  %3 = add i32 %a, %b
  %4 = mul i32 %1, %c  ; 错误：仍然引用旧基本块中的 %1
  br label %bb2
// %4 的操作数 %1 仍然引用原始基本块 bb1 中的指令，而不是新基本块 new_bb1 中的 %3。
// 这种情况下，新基本块 new_bb1 无法独立存在，依赖于原始基本块 bb1。
```

# 三地址码

```IR
%arrayty = [2 x [3 x [4 x uint]]]
; 2x3x4 array of size_t integer values
%aptr = [4 x int]*
; Pointer to array of four int values
%funcptr = float (int, int *) *
; Pointer to a function that takes an int
; and a pointer to int, returning float
%strty = { float, %funcptr }
; A structure, where the first element is a
; float and the second element is the
; %funcptr pointer to function type defined
; previously
```

# Pass

## Instruction Combining Pass

常见的代数恒等式或简化规则：

| 原始表达式        | 优化后    | 含义                           |
| ----------------- | --------- | ------------------------------ |
| `add X, 0`        | `X`       | 加零无效                       |
| `sub X, X`        | `0`       | 自减为零                       |
| `and X, -1`       | `X`       | 与全 1 运算无影响（补码）      |
| `mod X, 1`        | `0`       | 模 1 永远为 0                  |
| `xor X, X`        | `0`       | 同一数异或结果为 0             |
| `add (add X,1),1` | `add X,2` | 常量合并                       |
| `shl X, 64`       | `0`       | 移位超界变成 0（具体架构相关） |
| `phi X, X`        | `X`       | 同一个值的 φ 节点无意义        |

# 问题

## incomplete type error

1. virtual函数还没全部实现
2. 没有导入头文件（！真的犯过）

## .sy获取途径

(sy文件)[https://gitlab.eduxiji.net/csc1/nscscc/compiler2023]


## 防止conda环境影响xmake

```shell
unset LD_LIBRARY_PATH
export PATH=$(echo $PATH | tr ':' '\n' | grep -v 'anaconda' | paste -sd:)
./xmake_run.sh || 或其他xmake自定义命令
```

