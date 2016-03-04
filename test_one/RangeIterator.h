// ---------------
// RangeIterator.h
// ---------------

#ifndef RangeIterator_h
#define RangeIterator_h

#include <cstddef>  // ptrdiff_t
#include <iterator> // input_iterator_tag

using namespace std;

template <typename T> //this belongs outside of the class
class Range_Iterator : public iterator<input_iterator_tag, T> {
/*
    public:
        using iterator_category = input_iterator_tag;
        using value_type        = T;
        using difference_type   = ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;
*/
    private:
        T _v;

    public:
        // single line constructor
        Range_Iterator(const T& v) :
                _v (v)
            {}

        // rhs shouldnt change so declare it as a const
        // adding const to the end of the method signature makes the stuff inside it const
        bool operator == (const Range_Iterator& rhs) const {
            return (_v == rhs._v);}

        // *this is a dereferenced pointer to this which is a RangeIterator
        // takes in a reference to a range iterator so it should be a const
        bool operator != (const Range_Iterator& rhs) const {
            return !(*this == rhs);}

        const T& operator * () const {
            return _v;}
  
        // returns a range iterator
        // returns an r value so you need the return type to be a reference to the value
        Range_Iterator& operator ++ () {
            ++_v;
            return *this;}
        
        // returns a range iterator
        // returns an l value so safe
        Range_Iterator operator ++ (int) {
            Range_Iterator x = *this; // store the value of the range iterator in a temp var
            ++*this; // increment *this
            return x;}}; // return the temp var

#endif // RangeIterator_h
