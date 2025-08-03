#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <vector>

class IntegerType;
class FloatType;
class FunctionType;
class ArrayType;
class PointerType;
class IRContext;

/**
 * @class Type
 * @brief 表示类型的类，用于中间端的类型系统。
 *
 * 该类提供了对类型参数和返回类型的访问接口。
 * - `paramBegin()` 和 `paramEnd()` 方法用于获取类型参数的迭代器范围。
 * - `getParamType(size_t i)` 方法用于获取指定索引的类型参数。
 * - `getReturnType()` 方法用于获取返回类型。
 *
 * 成员变量：
 * - `result_`：表示返回类型。
 * - `args_`：存储类型参数的容器。
 */
class Type {
public:
    enum TypeID {
        VoidTyID,     // Void
        LabelTyID,    // Labels
        IntegerTyID,  // Integers, I32 && I1
        FloatTyID,    // Float
        FunctionTyID, // Functions
        ArrayTyID,    // Arrays
        PointerTyID,  // Pointer
    };

    explicit Type(TypeID tid) : tid_(tid) {};
    ~Type() = default;

    TypeID getTypeId() const {
        return tid_;
    }

    bool isVoidType() const {
        return getTypeId() == VoidTyID;
    }

    bool isLabelType() const {
        return getTypeId() == LabelTyID;
    }

    bool isIntegerType() const {
        return getTypeId() == IntegerTyID;
    }

    bool isFloatType() const {
        return getTypeId() == FloatTyID;
    }

    bool isFunction_type() const {
        return getTypeId() == FunctionTyID;
    }

    bool isArrayType() const {
        return getTypeId() == ArrayTyID;
    }

    bool isPointerType() const {
        return getTypeId() == PointerTyID;
    }

    static bool isEqType(Type *ty1, Type *ty2) {
        return ty1 == ty2;
    };

    static Type *getVoidType();
    static Type *getLabelType();
    static IntegerType *getInt1Type();
    static IntegerType *getInt32Type();
    static PointerType *getInt32PtrType();
    static FloatType *getFloatType();
    static PointerType *getFloatPtrType();
    static PointerType *getPointerType(Type *contained);
    static ArrayType *getArrayType(Type *contained, size_t num_elements);
    Type *getPointerElementType();
    Type *getArrayElementType();

    // static void resetContext();

    static IRContext *context;

    int getSize();
    std::string print();

private:
    TypeID tid_;
};

/**
 * @class IntegerType
 * @brief 表示整数类型的类。
 *
 * 该类用于表示中间端的整数类型。
 * - 提供对整数类型的位宽和符号信息的访问。
 *
 * 成员变量：
 * - `bitWidth_`：表示整数类型的位宽。
 * - `isSigned_`：表示整数类型是否为有符号类型。
 */
class IntegerType : public Type {
public:
    explicit IntegerType(size_t num_bits)
        : Type(Type::IntegerTyID),
          num_bits_(num_bits) {}

    static IntegerType *get(size_t num_bits);

    size_t getNumBits();

private:
    size_t num_bits_;
};

/**
 * @class FloatType
 * @brief 表示浮点类型的类。
 *
 * 该类用于表示中间端的浮点类型。
 * - 提供对浮点类型的精度信息的访问。
 *
 * 成员变量：
 * - `precision_`：表示浮点类型的精度（例如单精度或双精度）。
 */
class FloatType : public Type {
public:
    FloatType() : Type(Type::FloatTyID) {}

    static FloatType *get();

private:
};

/**
 * @class PointerType
 * @brief 表示指针类型的类。
 *
 * 该类用于表示中间端的指针类型。
 * - 提供对指针指向的类型的访问。
 *
 * 成员变量：
 * - `pointee_`：表示指针指向的类型。
 */
class PointerType : public Type {
public:
    PointerType(Type *contained)
        : Type(Type::PointerTyID),
          contained_(contained) {}

    static PointerType *get(Type *contained);

    Type *getElementType() const {
        return contained_;
    }

private:
    Type *contained_; //& The element type of the pointer
};

/**
 * @class ArrayType
 * @brief 表示数组类型的类。
 *
 * 该类用于表示中间端的数组类型。
 * - 提供对数组元素类型和数组大小的访问。
 *
 * 成员变量：
 * - `contained_`：表示数组的元素类型。
 * - `num_elements_`：表示数组的元素数量。
 */
class ArrayType : public Type {
public:
    ArrayType(Type *contained, size_t num_elements);

    static ArrayType *get(Type *contained, size_t num_elements);

    static bool isValidElementType(Type *ty);

    Type *getElementType() const {
        return contained_;
    }

    size_t getNumOfElements() const {
        return num_elements_;
    }

private:
    Type *contained_;     //& The element type of the array.
    size_t num_elements_; //& Number of elements in the array.
};

/**
 * @class FunctionType
 * @brief 表示函数类型的类。
 *
 * 该类用于表示中间端的函数类型。
 * - 提供对函数返回类型和参数类型的访问。
 *
 * 成员变量：
 * - `result_`：表示函数的返回类型。
 * - `args_`：存储函数参数类型的容器。
 */
class FunctionType : public Type {
public:
    FunctionType(Type *result, std::vector<Type *> params);

    static FunctionType *get(Type *result, std::vector<Type *> params);

    static bool isValidReturnType(Type *ty);
    static bool isValidArgumentType(Type *params);

    size_t getNumOfArgs() const {
        return args_.size();
    };

    std::vector<Type *>::iterator paramBegin() {
        return args_.begin();
    }

    std::vector<Type *>::iterator paramEnd() {
        return args_.end();
    }

    Type *getParamType(size_t i) const {
        return args_[i];
    };

    Type *getReturnType() const {
        return result_;
    };

private:
    Type *result_;
    std::vector<Type *> args_;
};
#endif // TYPE_HPP
