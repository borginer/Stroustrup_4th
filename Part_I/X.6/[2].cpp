#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

mutex print_mutex;

void printHello(){
    while(true){
        this_thread::sleep_for(chrono::seconds{1});
        print_mutex.lock();
        cout << "Hello ";
        print_mutex.unlock();
    }
}

void printWorld(){
    while(true){
        this_thread::sleep_for(chrono::seconds{1});
        print_mutex.lock();
        cout << "World!" << endl;
        print_mutex.unlock();
    }
}

int main(){
    thread t1 {printHello};
    thread t2 {printWorld};

    t1.join();
    t2.join();
}