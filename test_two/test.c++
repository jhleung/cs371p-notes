#include <array>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
struct A {
    int i;
    string f () {
        return "A::f";}};
struct B : A {
    int j;
    string f() {
        return "B::f";}};
int main() {
//    B* const a = new A[10];
    A* const a = new B[10];
    std::cout << "a[0]: " << a[0].f() << endl;
    std::cout << "a[1]: " << a[1].f() << endl; // undefined
}
//
