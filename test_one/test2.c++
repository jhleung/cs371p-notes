#include <array>
#include <algorithm>
#include <cassert>
#include <iostream> 

using namespace std;
                                                                                                   
void increment_one_a(int array[]) {
    cout << "size in func: " << sizeof(array) << endl;
      for (int i = 0; i < sizeof(array)/sizeof(*array); ++i) {
                      ++*(array+i);  
                                    cout << i <<  " ";
                                                   
                                             }
              cout << endl;
               }
 
 int main() {
      int a [] = {1, 2, 3};
         int b [] = {2, 3, 4};
            increment_one_a(a);
               for (int i = 0; i < sizeof(a)/sizeof(*a); ++i)
                      cout << i << " " << endl;
                    cout << "size in main: " << sizeof(a) << endl;
                         assert(equal(a, a+3, b));
                              return 0;
                               } 
