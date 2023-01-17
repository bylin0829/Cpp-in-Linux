#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mx;

void func(int a)
{
    mx.lock();
    cout << "This is thread " << a << endl;
    mx.unlock();
}

int main()
{
    thread t1(func, 1);
    thread t2(func, 2);

    t1.join();
    t2.join();

    return 0;
}