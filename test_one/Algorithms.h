// -------
// Equal.h
// -------

#ifndef Equal_h
#define Equal_h

/*
 * Qualities of an INPUT ITERATOR:
 * 1) * (read only)
 * 2) !=, == operators
 * 3) prefix ++, postfix ++
 */

/*
 * Qualities of an OUTPUT ITERATOR
 * 1) * (write only)
 * 2) prefix++, postfix++
 */

/*
 * Qualities of a FORWARD ITERATOR
 * 1) !=, ==
 * 2) * (read and write)
 * 3) prefix++, postfix++
 */
template <typename II1, typename II2>
/* b is the beggining of the 1st iterable
 * e is the end
 * c is the 2nd iterable
 */
bool my_equal (II1 b, II1 e, II2 c) {
    while (b != e) { //while (b < e) also works but it less expensive
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

#endif // Equal_h

/*
 * equal(a + 10, a + 15, b + 20); 
 * sizeof(a) >= 15
 * sizeof(b) >= 25
 */

template <typename II, typename II2>
bool my_my_equal(II b, II e, II2 c) {
	while (b != e) {
		if (*b != *c)
			return false;
		b++;
		c++;
	}
	return true;
}

template <typename II, typename OI>
OI my_copy(II b, II e, OI c) {
	while (b != e) {
		*c = *b;
		b++;
		c++;
	}
	return c;
}

template <typename FI, typename T>
void my_fill(FI b, FI e, const T& v) {
	while (b != e) { // this is why we need a forward iterator; to support the != operator
		*b = v;
		++b;
	}
}

template <typename II, typename UP>
bool my_all_of(II b, II e, UP f) {
	while (b != e) {
		if (!f(*b))
			return false;
		++b;
	}
	return true;
}
/*
 * Qualities of a BIDIRECTIONAL ITERATOR
 * <FI> :
 *		!=, ==, * read and write, prefix and postfix ++
 * prefix --, postfix --
 */

/* 
 * Qualities of a RANDOM ACCESS ITERATOR
 * <BI>
 * +=, -=
 * +, -
 * []
 * <, >, <=, >=
 */

 // ALGORITHMS should REQUIRE the WEAKEST iterators
 // CONTAINERS should PROVIDE the STRONGEST iterators