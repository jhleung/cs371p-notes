// ---------
// Vector1.h
// ---------

#ifndef Vector1_h
#define Vector1_h

#include <algorithm> // fill
#include <cstddef>   // ptrdiff_t, size_t

template <typename T>
class my_vector {
    public:
        using value_type      = T;

        using size_type       = std::size_t;
        using difference_type = std::ptrdiff_t;

        using       pointer   =       value_type*;
        using const_pointer   = const value_type*;

        using       reference =       value_type&;
        using const_reference = const value_type&;

        using       iterator  =       pointer;
        using const_iterator  = const_pointer;

    private:
        const pointer _b;
        const pointer _e;

    public:
        explicit my_vector (size_type s = 0, const_reference v = T()) :
                _b ((s == 0) ? nullptr : new T[s]),
                _e ((s == 0) ? nullptr : _b + s) {
            std::fill(_b, _e, v);}

        ~my_vector () {
            delete [] begin();}

        reference operator [] (size_type i) {
            return begin()[i];}

        const_reference operator [] (size_type i) const {
            return (*const_cast<my_vector<T>*>(this))[i];}

        iterator begin () {
            return _b;}

        const_iterator begin () const {
            return const_cast<my_vector<T>*>(this)->begin();}

        iterator end () {
            return _e;}

        const_iterator end () const {
            return const_cast<my_vector<T>*>(this)->end();}

        size_type size () const {
            return (begin() == nullptr) ? 0 : end() - begin();}};

#endif // Vector1_h
