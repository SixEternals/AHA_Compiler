#ifndef IRCONTEXT_HPP
#define IRCONTEXT_HPP
#include "midend/Type.hpp"
#include <map>

class IRContext {
private:
    Type *label_ty_;
    Type *void_ty_;
    IntegerType *int1_ty_;
    IntegerType *int32_ty_;
    FloatType *float32_ty_;

private:
    std::map<Type *, PointerType *> pointer_map_;
    std::map<std::pair<Type *, int>, ArrayType *> array_map_;
    std::map<std::pair<Type *, std::vector<Type *>>, FunctionType *>
        function_map_;

public:
    static IRContext &getInstance();
    explicit IRContext();
    ~IRContext();

    Type *getVoidType();
    Type *getLabelType();
    IntegerType *getInt1Type();
    IntegerType *getInt32Type();
    FloatType *getFloatType();
    PointerType *getInt32PtrType();
    PointerType *getFloatPtrType();
    PointerType *getPointerType(Type *contained);
    ArrayType *getArrayType(Type *contained, unsigned num_elements);
    FunctionType *getFunctionType(Type *retty, std::vector<Type *> &args);
};

#endif // IRCONTEXT_HPP
