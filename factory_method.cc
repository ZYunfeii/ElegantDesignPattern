#include <iostream>
#include <string>

using namespace std;

// 先定义资源：num1, num2
// 再定义各种操作资源的方式：add, sub
// 再定义一个抽象工厂类，接口为创建操作方式
// 再定义各种操作的具体工厂

class Oper {
public:
    int num1_;
    int num2_;
public:
    virtual int getRes() = 0;
};

class Add : public Oper {
public:
    int getRes() override {
        return num1_ + num2_;
    }
};

class Sub : public Oper {
public:
    int getRes() override {
        return num1_ - num2_;
    }
};

class IFactory {
public:
    virtual Oper* createOperation() = 0;
};

class AddFactory : public IFactory {
public:
    Oper* createOperation() {
        return new Add();
    }
};

class SubFactory : public IFactory {
public:
    Oper* createOperation() {
        return new Sub();
    }
};

int main() {
    IFactory* fac = new AddFactory();
    auto add = fac->createOperation();
    add->num1_ = 2;
    add->num2_ = 3;
    cout << add->getRes() << endl;
    return 0;
}