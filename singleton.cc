#include <iostream>
#include <string>
#include <mutex>

using namespace std;

// thread-safe Lazy Man Mode
class SingletonLazy {
private:
    static SingletonLazy* instance_;
    static mutex mtx_;
    SingletonLazy(){};
public:
    static SingletonLazy* getInstance() {
        if (instance_ == nullptr) {
            {
                lock_guard<mutex> lk(mtx_);
                if (instance_ == nullptr) { // double-check
                    instance_ = new SingletonLazy;
                }
            }
        }
        return instance_;
    }
};
SingletonLazy* SingletonLazy::instance_ = nullptr;
mutex SingletonLazy::mtx_;

// Hungry Mode
class SingletonHungry {
private:
    static SingletonHungry* instance_;
    SingletonHungry() {}
public:
    static SingletonHungry* getInstance() {
        return instance_;
    }
};

SingletonHungry* SingletonHungry::instance_ = new SingletonHungry;

int main() {
    auto ins1 = SingletonLazy::getInstance();
    auto ins2 = SingletonLazy::getInstance();
    return 0;
}