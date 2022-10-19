#include <iostream>
#include <string>

using namespace std;

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