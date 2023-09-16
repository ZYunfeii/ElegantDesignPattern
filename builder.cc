#include <bits/stdc++.h>
using namespace std;

// // version1 : 有指挥者
// class Product;
// class Builder {
// public:
//     virtual void buildA() = 0;
//     virtual void buildB() = 0;
//     virtual void buildC() = 0;
//     virtual void buildD() = 0;
//     virtual Product* getProduct() = 0;
// };

// class Product {
// public:
//     string buildA;
//     string buildB;
//     string buildC;
//     string buildD; 
//     string getString() {
//         return "buildA:" + buildA + "\n"
//         + "buildB:" + buildB + "\n"
//         + "buildC:" + buildC + "\n"
//         + "buildD:" + buildD ;
//     }
// };

// class Worker: public Builder {
// private:
//     Product* product;
// public:
//     Worker() {
//         product = new Product();
//     }
//     void buildA() override {
//         product->buildA = "地基";
//         cout << "地基" << endl;
//     }
//     void buildB() override {
//         product->buildB = "钢筋工程";
//         cout << "钢筋工程" << endl;
//     }
//     void buildC() override {
//         product->buildC = "铺电线";
//         cout << "铺电线" << endl;
//     }
//     void buildD() override {
//         product->buildD = "粉刷";
//         cout << "粉刷" << endl;
//     }
//     Product* getProduct() override {
//         return product;
//     }
// };

// class Director {
// public:
//     Product* build(Builder* builder) {
//         builder->buildA();
//         builder->buildB();
//         builder->buildC();
//         builder->buildD();
//         return builder->getProduct();
//     }
// };


// int main() {
//     Director* director = new Director();
//     Product* product = director->build(new Worker());
//     cout << product->getString();
//     return 0;
// }

// version2 : 无指挥者
class Product;
class Builder {
public:
    virtual Builder* buildA(string s) = 0;
    virtual Builder* buildB(string s) = 0;
    virtual Builder* buildC(string s) = 0;
    virtual Builder* buildD(string s) = 0;
    virtual Product* getProduct() = 0;
};

class Product {
public:
    string buildA;
    string buildB;
    string buildC;
    string buildD; 
    Product() {
        buildA = "地基";
        buildB = "钢筋工程";
        buildC = "铺电线";
        buildD = "粉刷";
    }
    string getString() {
        return "buildA:" + buildA + "\n"
        + "buildB:" + buildB + "\n"
        + "buildC:" + buildC + "\n"
        + "buildD:" + buildD ;
    }
};

class Worker: public Builder {
private:
    Product* product;
public:
    Worker() {
        product = new Product();
    }
    Builder* buildA(string s) override {
        product->buildA = s;
        return this;
    }
    Builder* buildB(string s) override {
        product->buildB = s;
        return this;
    }
    Builder* buildC(string s) override {
        product->buildC = s;
        return this;
    }
    Builder* buildD(string s) override {
        product->buildD = s;
        return this;
    }
    Product* getProduct() override {
        return product;
    }
};


int main() {
    auto worker = new Worker();
    cout << worker->buildA("铺管道")->buildC("搞卫生")->getProduct()->getString();
    return 0;
}