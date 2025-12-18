#include <iostream>
using namespace std;

struct A {
    A() { cout << "A()\n"; }
    A(const A&) { cout << "A(copy)\n"; }
    ~A() { cout << "~A()\n"; }
};

A func(A x) {
    cout << "func body\n";
    return x;   // 반환 임시 객체
}

//int main() {
//    cout << "start\n";
//    A a;
//    cout << "call func\n";
//    func(a);      // 반환값을 받지 않음
//    cout << "after func\n";
//}
