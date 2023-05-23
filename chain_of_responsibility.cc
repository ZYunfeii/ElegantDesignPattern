#include <bits/stdc++.h>

using namespace std;

class Handler {
protected:
    Handler* successor;
public:
    void SetSuccessor(Handler* successor) {
        this->successor = successor;
    }
    virtual void HandleRequest(int request) {};
};

class ConcreteHandler1 : public Handler {
    void HandleRequest(int request) override {
        if (request >= 0 && request < 10) {
            cout << "ConcreteHandler1处理请求" << endl;
        } else {
            successor->HandleRequest(request);
        }
    }
};

class ConcreteHandler2 : public Handler {
    void HandleRequest(int request) override {
        if (request >= 10 && request < 20) {
            cout << "ConcreteHandler2处理请求" << endl;
        } else {
            successor->HandleRequest(request);
        }
    }
};

class ConcreteHandler3 : public Handler {
    void HandleRequest(int request) override {
        if (request >= 20 && request < 30) {
            cout << "ConcreteHandler3处理请求" << endl;
        } else {
            successor->HandleRequest(request);
        }
    }
};

int main() {
    Handler* h1 = new ConcreteHandler1();
    Handler* h2 = new ConcreteHandler2();
    Handler* h3 = new ConcreteHandler3();

    h1->SetSuccessor(h2);
    h2->SetSuccessor(h3);
    vector<int> req = {2, 5, 14, 22, 18, 3, 27, 20};
    for (auto r : req) {
        h1->HandleRequest(r);
    }
    return 0;
}