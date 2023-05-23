#include <bits/stdc++.h>
using namespace std;
#include <mutex>
#include <thread>
#include <unistd.h>
class Singleton {
public:
    static Singleton* getInstance() {
        if (instance_ == nullptr) {
            unique_lock<mutex> lk(mtx_);
            if (instance_ == nullptr) {
                instance_ = new Singleton;
            }
        } 
        return instance_;
    }
    void show() {
        cout << this_thread::get_id() << endl;
    }
private:
    Singleton(){};
    static mutex mtx_;
    static Singleton* instance_;
};

mutex Singleton::mtx_;
Singleton* Singleton::instance_ = nullptr;

void func() {
    auto instance = Singleton::getInstance();
    instance->show();
}

int main() {
    for (int i = 0; i < 10; ++i) {
        thread(func).detach();
    }
    sleep(2);
    return 0;
}




