#include <iostream>
#include <string>

using namespace std;

class Component {
public:
    virtual void operation() = 0;
};

class ConcreteComponent : public Component {
public:
    void operation() override {
        cout << "the concrete operation" << endl;
    }
};

class Decorator : public Component {
protected:
    Component* component_;
public:
    void setComponent(Component* component) {
        component_ = component;
    }
    void operation() override {
        if (component_ == nullptr) return;
        component_->operation();
    }
};

class ConcreteDecoratorA : public Decorator {
private:
    string addedState_;
public:
    void operation() override {
        Decorator::operation();
        addedState_ = "New state";
        cout << "Concrete decorator for A" << endl;
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    void operation() override {
        Decorator::operation();
        addBehavior();
        cout << "Concrete decorator for B" << endl;
    }
public:
    void addBehavior() {}
};

int main() {
    ConcreteComponent* c = new ConcreteComponent();
    ConcreteDecoratorA* d1 = new ConcreteDecoratorA();
    ConcreteDecoratorB* d2 = new ConcreteDecoratorB();
    d1->setComponent(c); 
    d2->setComponent(d1);
    d2->operation();
    return 0;
}