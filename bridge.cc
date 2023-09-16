#include <bits/stdc++.h>
using namespace std;

class Brand {
public:
    virtual void info() = 0;
};

class Lenovo: public Brand {
public:
    void info() override {
        cout << "联想" << endl;
    }
};

class Apple: public Brand {
public:
    void info() override {
        cout << "苹果" << endl;
    }
};

// 桥接模式中的桥
class Computer {
protected:
    Brand* brand;
    Computer(Brand* brand) { // 保护构造函数，保证只有继承这个类的子类能构造
        this->brand = brand;
    }
public:
    virtual void info() {
        brand->info();
    }
};

class Desktop: public Computer {
public:
    Desktop(Brand* brand) : Computer(brand){
    }
    void info() {
        Computer::info();
        cout << "台式机" << endl;
    }
};

class Laptop: public Computer {
public:
    Laptop(Brand* brand) : Computer(brand){
    }
    void info() {
        Computer::info();
        cout << "笔记本" << endl;
    }
};

int main() {
    // 苹果笔记本 建立了苹果和笔记本之间的联系，这个过程是通过桥来做的
    Computer* pc1 = new Laptop(new Apple());
    pc1->info();
    // 联想台式机
    Computer* pc2 = new Desktop(new Lenovo());
    pc2->info();
    return 0;
}