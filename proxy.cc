#include <bits/stdc++.h>
using namespace std;
// 代理模式，AOP底层，代理类和被代理类会实现同一个接口，然后代理类调用被代理类的同一个方法，并在其前后进行一些其他操作

class Rent {
public:
    virtual void rent() = 0;
};

class Host: public Rent {
public:
    void rent() override {
        cout << "出租房子" << endl;
    }
};

class Proxy: public Rent {
private:
    Host* host;
    void seeHouse() {
        cout << "看房子" << endl;
    }
    void hetong() {
        cout << "签合同" << endl;
    }
    void fare() {
        cout << "收房租" << endl;
    }
public:
    Proxy(Host* host) {
        this->host = host;
    }
    void rent() override {
        seeHouse();
        host->rent();
        hetong();
        fare();
    }
};

int main() {
    Host* host = new Host;
    Proxy* proxy = new Proxy(host);
    proxy->rent();
    return 0;
}