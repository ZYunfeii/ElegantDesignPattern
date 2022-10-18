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

class Factory {
public:
    Oper* createOper(string name) {
        if (name == "Add") return new Add();
        else if (name == "Sub") return new Sub();
        else return nullptr;
    }
};

int main() {
    Factory fac;
    auto add = fac.createOper("Add");
    add->num1_ = 2;
    add->num2_ = 3;
    cout << add->getRes() << endl;
    return 0;
}