#include <bits/stdc++.h>
using namespace std;
// 模拟场景，电脑想上网，但是没有网口，所以需要一个转换器，转换器连接网线，转换器再连接电脑，之后上网

// 要被适配的类(网线)
class Adaptee {
public:
    void request() {
        cout << "连接网线上网" << endl;
    }
};

class NetToUsb {
public:
    virtual void handleRequest() = 0;
};

// 客户端类：向上网，插不上网线
class Computer {
public:
    void net(NetToUsb* adapter) {
        adapter->handleRequest();
    }
};

// 真正的适配器，需要连接usb，连接网线
class Adapter : public NetToUsb {
private:
    Adaptee* adaptee;
public:
    Adapter(Adaptee* adaptee) {
        this->adaptee = adaptee;
    }
    void handleRequest() override {
       adaptee->request();
    }
};


int main() {
    Adaptee* adaptee = new Adaptee(); // 网线
    Adapter* adapter = new Adapter(adaptee); // 转接器
    Computer pc; // 电脑
    pc.net(adapter);
    return 0;
}