// -----------
// Lambdas.c++
// -----------

// http://en.cppreference.com/w/cpp/language/lambda
// http://en.cppreference.com/w/cpp/utility/functional/function
// http://www.cplusplus.com/reference/algorithm/transform/
// http://www.cplusplus.com/reference/numeric/accumulate/

#include <algorithm>  // equal, transform
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <numeric>    // accumulate
#include <vector>     // vector

using namespace std;

// typedef int (*UF) (int);
using UF1 = int (*) (int);
// typedef function<int (int)> UF;
using UF2 = function<int (int)>;

// typedef int (*BF) (int, int);
using BF1 = int (*) (int, int);
// typedef function<int (int, int)> BF;
using BF2 = function<int (int, int)>;

int add_function (int i, int j) {
    return i + j;}

BF1 add_lambda_1 () {
    return [] (int i, int j) -> int {return i + j;};}

BF2 add_lambda_2 () {
    return [] (int i, int j) -> int {return i + j;};}

// UF1 add_closure_1 (int i) {                     // error: no viable conversion from '(lambda at Lambdas.c++:40:12)' to 'UF1' (aka 'int (*)(int)')
//     return [i] (int j) -> int {return i + j;};}

UF2 add_closure_2 (int i) {
    return [i] (int j) -> int {return i + j;};}

// UF1 add_closure_3 (int& i) {                     // error: no viable conversion from '(lambda at Lambdas.c++:40:12)' to 'UF1' (aka 'int (*)(int)')
//     return [&i] (int j) -> int {return i + j;};}

UF2 add_closure_4 (int& i) {
    return [&i] (int j) -> int {return i + j;};}

// UF1 add_closure_5 (int& i) {                     // error: no viable conversion from '(lambda at Lambdas.c++:46:13)' to 'UF1' (aka 'int (*)(int)')
//     return [&i] (int j) -> int {return i + j;};}

UF2 add_closure_6 (int& i) {
    return [&i] (int j) -> int {return i++ + j;};}

int main () {
    cout << "Lambdas.c++" << endl;

    {
    const list<int> x = {2, 3, 4};

    BF1  f = add_function;
    BF2  g = add_function;
    auto h = add_function;

    assert(add_function(2, 3) == 5);
    assert(           f(2, 3) == 5);
    assert(           g(2, 3) == 5);
    assert(           h(2, 3) == 5);

    /*
     template<class InputIt, class T, class BinaryOperation>
     T accumulate(InputIt first, InputIt last, T init, 
                 BinaryOperation op)
     {
        for (; first != last; ++first) {
            init = op(init, *first);
        }
        return init;
     }
    */
    assert(accumulate(x.begin(), x.end(), 0, add_function) == 9);
    assert(accumulate(x.begin(), x.end(), 0, f)            == 9);
    assert(accumulate(x.begin(), x.end(), 0, g)            == 9);
    assert(accumulate(x.begin(), x.end(), 0, h)            == 9);
    }



    {
    const list<int> x = {2, 3, 4};

    /*
        using BF1 = int (*) (int, int);
        using BF2 = function<int (int, int)>;
    */
    // Write a lambda function that will sum up two integers. Store that function in a typedef-ed pointer
    // Then use it to sum up an array of integers
    BF1  f = [] (int i, int j) -> int {return i + j;};
    BF2  g = [] (int i, int j) -> int {return i + j;};
    auto h = [] (int i, int j) -> int {return i + j;};

    assert([] (int i, int j) -> int {return i + j;}(2, 3) == 5);
    assert(                                       f(2, 3) == 5);
    assert(                                       g(2, 3) == 5);
    assert(                                       h(2, 3) == 5);

    assert(accumulate(x.begin(), x.end(), 0, [] (int i, int j) -> int {return i + j;}) == 9);
    assert(accumulate(x.begin(), x.end(), 0, f)                                        == 9);
    assert(accumulate(x.begin(), x.end(), 0, g)                                        == 9);
    assert(accumulate(x.begin(), x.end(), 0, h)                                        == 9);
    }



    {
    const list<int> x = {2, 3, 4};
    /*
     * BF1 add_lambda_1 () {
     *    return [] (int i, int j) -> int {return i + j;};}
     */

    // Write a function that returns a lambda function. Initialize a pointer to that function.
    // Then use it to sum up a list of integers
    BF1  f = add_lambda_1();
    BF2  g = add_lambda_1();
    auto h = add_lambda_1();

    assert(add_lambda_1()(2, 3) == 5);
    assert(             f(2, 3) == 5);
    assert(             g(2, 3) == 5);
    assert(             h(2, 3) == 5);

    assert(accumulate(x.begin(), x.end(), 0, add_lambda_1()) == 9);
    assert(accumulate(x.begin(), x.end(), 0, f)              == 9);
    assert(accumulate(x.begin(), x.end(), 0, g)              == 9);
    assert(accumulate(x.begin(), x.end(), 0, h)              == 9);
    }



    {
    const list<int> x = {2, 3, 4};
    /*
     * BF2 add_lambda_2 () {
     *    return [] (int i, int j) -> int {return i + j;};}
     */

    // 
//  BF1  f = add_lambda_2(); // error: no viable conversion from 'BF2' (aka 'function<int (int, int)>') to 'BF1' (aka 'int (*)(int, int)')
    BF2  g = add_lambda_2();
    auto h = add_lambda_2();

    assert(add_lambda_2()(2, 3) == 5);
    assert(             g(2, 3) == 5);
    assert(             h(2, 3) == 5);

    assert(accumulate(x.begin(), x.end(), 0, add_lambda_2()) == 9);
    assert(accumulate(x.begin(), x.end(), 0, g)              == 9);
    assert(accumulate(x.begin(), x.end(), 0, h)              == 9);
    }



    {
    const int i = 2;
    // int (*) int is too weak for a closure
//  UF1  f = [i] (int j) -> int {return i + j;}; // error: no viable conversion from '(lambda at Lambdas.c++:109:14)' to 'UF1' (aka 'int (*)(int)')
    UF2  g = [i] (int j) -> int {return i + j;};
    auto h = [i] (int j) -> int {return i + j;};
    
    // Write a closure function that takes an integer and use that to double each element of a list of integers

    assert([i] (int j) -> int {return i + j;}(3) == 5);
    assert(i == 5); //fails. i doesnt change
    assert(                                 g(3) == 5);
    assert(                                 h(3) == 5);

    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {4, 5, 6};
    transform(x.begin(), x.end(), y.begin(), [i] (int j) -> int {return i + j;});
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {4, 5, 6};
    transform(x.begin(), x.end(), y.begin(), g);
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {4, 5, 6};
    transform(x.begin(), x.end(), y.begin(), h);
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    }



    {
    const int i = 2;

//  UF1  f = add_closure_2(i); //  error: no viable conversion from 'UF2' (aka 'function<int (int)>') to 'UF1' (aka 'int (*)(int)')
    UF2  g = add_closure_2(i);
    auto h = add_closure_2(i);

    assert(add_closure_2(i)(3) == 5);
    assert(               g(3) == 5);
    assert(               h(3) == 5);

    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {4, 5, 6};
    transform(x.begin(), x.end(), y.begin(), add_closure_2(i));
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {4, 5, 6};
    transform(x.begin(), x.end(), y.begin(), g);
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {4, 5, 6};
    transform(x.begin(), x.end(), y.begin(), h);
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    }



    {
    int i = 1;

//  UF1  f = [&i] (int j) -> int {return i + j;}; // error: no viable conversion from '(lambda at Lambdas.c++:109:14)' to 'UF1' (aka 'int (*)(int)')
    UF2  g = [&i] (int j) -> int {return i + j;};
    auto h = [&i] (int j) -> int {return i + j;};

    i = 2;

    assert([&i] (int j) -> int {return i + j;}(3) == 5);
    assert(                                  g(3) == 5);
    assert(                                  h(3) == 5);

    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {4, 5, 6};
    transform(x.begin(), x.end(), y.begin(), [i] (int j) -> int {return i + j;});
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {4, 5, 6};
    transform(x.begin(), x.end(), y.begin(), g);
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {4, 5, 6};
    transform(x.begin(), x.end(), y.begin(), h);
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    }



    {
    
    int i = 1;

//  UF1  f = add_closure_4(i); //  error: no viable conversion from 'UF2' (aka 'function<int (int)>') to 'UF1' (aka 'int (*)(int)')
    UF2  g = add_closure_4(i);
    auto h = add_closure_4(i);

    i = 2;

    assert(add_closure_4(i)(3) == 5);
    assert(               g(3) == 5);
    assert(               h(3) == 5)
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {4, 5, 6};
    transform(x.begin(), x.end(), y.begin(), add_closure_4(i));
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {4, 5, 6};
    transform(x.begin(), x.end(), y.begin(), g);
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {4, 5, 6};
    transform(x.begin(), x.end(), y.begin(), h);
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    }



    {
    // Write a closure function that captures an integer and uses it to modify the elements of an array by 2n
    // on each iteration

    int i = 2;

//  UF1  f = [&i] (int j) -> int {return i++ + j;}; // error: no viable conversion from '(lambda at Lambdas.c++:109:14)' to 'UF1' (aka 'int (*)(int)')
    UF2  g = [&i] (int j) -> int {return i++ + j;};
    auto h = [&i] (int j) -> int {return i++ + j;};

    assert([&i] (int j) -> int {return i++ + j;}(3) == 5);
    assert(                                    g(3) == 6);
    assert(                                    h(3) == 7);

    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {7, 9, 11};
    transform(x.begin(), x.end(), y.begin(), [&i] (int j) -> int {return i++ + j;});
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {10, 12, 14};
    transform(x.begin(), x.end(), y.begin(), g);
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {13, 15, 17};
    transform(x.begin(), x.end(), y.begin(), h);
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    }



    {
    int i = 2;

//  UF1  f = add_closure_6(i); //  error: no viable conversion from 'UF2' (aka 'function<int (int)>') to 'UF1' (aka 'int (*)(int)')
    UF2  g = add_closure_6(i);
    auto h = add_closure_6(i);

    assert(add_closure_6(i)(3) == 5);
    assert(               g(3) == 6);
    assert(               h(3) == 7);

    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {7, 9, 11};
    transform(x.begin(), x.end(), y.begin(), add_closure_6(i));
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {10, 12, 14};
    transform(x.begin(), x.end(), y.begin(), g);
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    {
    list<int>   x = {2, 3, 4};
    vector<int> y(3);
    list<int>   z = {13, 15, 17};
    transform(x.begin(), x.end(), y.begin(), h);
    assert(equal(y.begin(), y.end(), z.begin()));
    }
    }

    cout << "Done." << endl;
    return 0;}
