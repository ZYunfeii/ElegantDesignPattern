#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

// abstract observer
class Observer {
public:
    virtual void update() = 0;
};

// abstract notifier
class Subject {
protected:
    list<Observer*> obsList_;
public:
    void add(Observer* obs) {
        obsList_.push_back(obs);
    }
    void remove(Observer* obs) {
        obsList_.remove(obs);
    }
    void notify() {
        for_each(obsList_.begin(), obsList_.end(), [](Observer* obs){
            obs->update();
        });
    }
};

class ConcreteSubject : public Subject {
private:
    string subjectState_;
public:
    string getState() {return subjectState_;}
    string setState(string state) {subjectState_ = state;} 
};

class ConcreteObserver : public Observer {
private:
    string name_;
    string observerState_;
    ConcreteSubject* subject_;
public:
    ConcreteObserver(ConcreteSubject* subject, string name) : subject_(subject), name_(name) {}
    void update() override {
        observerState_ = subject_->getState();
        cout << "observer:" << name_ << " " << "state:" << observerState_ << endl;
    }
};

int main() {
    ConcreteSubject* s = new ConcreteSubject();
    s->add(new ConcreteObserver(s, "Bob"));
    s->add(new ConcreteObserver(s, "John"));
    s->add(new ConcreteObserver(s, "Ketty"));

    s->setState("ABC");
    s->notify();
 
    s->setState("Boom!");
    s->notify();
    return 0;
}