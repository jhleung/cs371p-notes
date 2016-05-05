// -----------
// Vector2.c++
// -----------

// http://www.cplusplus.com/reference/vector/vector/

#include <utility> // !=
#include <vector>  // vector

#include "gtest/gtest.h"

#include "Vector2.h"

using namespace std;
using namespace testing;

using rel_ops::operator!=;

template <typename T>
struct Vector_Fixture : Test {
    using vector_type = T;};

using
    vector_types =
    Types<
           vector<int>,
        my_vector<int>>;

TYPED_TEST_CASE(Vector_Fixture, vector_types);

TYPED_TEST(Vector_Fixture, test_1) {
    using vector_type = typename TestFixture::vector_type;

    const vector_type x(10, 2);
    const vector_type y = x;
    ASSERT_NE(x.begin(), y.begin());
    ASSERT_EQ(x, y);}

TYPED_TEST(Vector_Fixture, test_2) {
    using vector_type = typename TestFixture::vector_type;

    const vector_type x(20, 3);
          vector_type y(10, 2);
    y = x;
    ASSERT_NE(x.begin(), y.begin());
    ASSERT_EQ(x, y);}
