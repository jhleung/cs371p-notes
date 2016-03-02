// -------------
// Variables.c++
// -------------

// http://www.cplusplus.com/doc/tutorial/pointers/

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl

int main () {
    using namespace std;
    cout << "Variables.c++" << endl;
    
    int  j = 2;
    int* p = &j; // a pointer to the address of j
    ++*p; // dereferencing the pointer gets the value of j. modification of this modifies j
    assert(j  == 3);
    assert(*p == 3);
    assert(p  == &j); // pointer to address of j is the same as the addr of j

    int  k = 2;
    int& r = k; // references are just another NAME for an existing object
    ++r;        // since r and k are virtually the same, modifying r modifies k
    assert(k  == 3);
    assert(r  == 3);
    assert(&r == &k); // therefore the address of r == address of k

    int   i = 2;
    int*  p = &i; // you can have a pointer to an address
    int*& r = p;  // r is just another name for p. you can point to that too 
    ++*r; // dereference r and modify value -> modifies i as well as *p
    assert(i  == 3);
    assert(*p == 3);
    assert(*r == 3);
    assert(&r == &p); // ok

    int a[] = {2, 3, 4};
    assert(*a == a[0]); 
    assert(a  == &a[0]); //a is the addr of the start of the array
    assert(sizeof(a)     != sizeof(&a[0]));
    assert(sizeof(a)     == 12);
    assert(sizeof(&a[0]) == 8);
//  ++a;                                    // error: lvalue required as left operand of assignment
    ++a[1];
    ++*(a + 1); // incrementing a by 1 increments the pointer to the next element
                // dereferencing it gets the value of which you can modify
    assert(a[1]     == 5);
    assert(*(a + 1) == 5);
//  assert(a[3]     == 0);                  // undefined

    int a[] = {2, 3, 4};
//  int b[] = a;                    // error: initializer fails to determine size of 'b'
    int* b  = a;    // pointer to a, which again is the addr of the start of the array
    assert(a         == b);
    assert(sizeof(a) != sizeof(b));
    assert(sizeof(a) == 12);
    assert(sizeof(b) ==  8);
    ++b[1]; // since b is a pointer to a, changing it will change a
            // b can also be accessed like an array using [] syntax
    ++*(b+1);   // or it can be accessed like this
    assert(a[1] == 5);
    assert(b[1] == 5);

    int a[] = {2, 3, 4};
    int b[] = {2, 3, 4};
    assert(a != b); // the addr of start of a != addr of start of b
    assert(equal(a, a + 3, b));
    ++b[1]; // no shit
    assert(a[1] == 3);
    assert(b[1] == 4);

    cout << "Done." << endl;
    return 0;}
