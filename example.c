#include "tinyunit.h"

static int a, b;

void tu_setup()
{
    a = 66;
    b = 5;
}

void tu_teardown()
{
    return;
}

TU_TEST(test_tu_setup)
{
    TU_ASSERT_INT_EQ(a, 66);
    TU_ASSERT_INT_EQ(b, 5);
}

TU_TEST(test_add)
{
    TU_ASSERT(1 + 2 == 4, "test add() fail"); // fail
    TU_ASSERT(1 + 3 == 4, "test add() fail"); // pass

    TU_ASSERT_INT_EQ(1 + 2, 2); // fail
    TU_ASSERT_INT_EQ(1 + 2, 3); // pass

    TU_ASSERT_DOUBLE_EQ(0.1 + 0.2, 0.4); // fail
    TU_ASSERT_DOUBLE_EQ(0.1 + 0.2, 0.3); // pass

    TU_ASSERT_CHAR_EQ('a', 'b'); // fail
    TU_ASSERT_CHAR_EQ('a', 'a'); // fail

    TU_ASSERT_STR_EQ("hello", "hellow"); // fail
    TU_ASSERT_STR_EQ("hello", NULL); // fail
    TU_ASSERT_STR_EQ(NULL, "hello"); // fail
    TU_ASSERT_STR_EQ(NULL, NULL); // pass
    TU_ASSERT_STR_EQ("hello", "hello"); // pass
}

TU_TEST(test_sub)
{
    TU_ASSERT(2 - 1 == 1, "test sub() fail"); // pass
}

int main()
{
    TU_RUN(test_tu_setup);
    TU_RUN(test_add);
    TU_RUN(test_sub);
    return TU_EXIT_CODE;
}
