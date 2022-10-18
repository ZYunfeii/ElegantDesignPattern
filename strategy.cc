#include <iostream>
#include <string>

using namespace std;

class Strategy {
public:
    virtual void algorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    void algorithmInterface() override {
        cout << "strategy A" << endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void algorithmInterface() override {
        cout << "strategy B" << endl;
    }
};

class Context {
private:
    Strategy* s_;
public:
    Context(Strategy* s) : s_(s) {}
    void contextInterface() {
        s_->algorithmInterface();
    }
};

int main() {
    Context* ctx;
    ctx = new Context(new ConcreteStrategyA());
    ctx->contextInterface();
    ctx = new Context(new ConcreteStrategyB());
    ctx->contextInterface();
    return 0;
}