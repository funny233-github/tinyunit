#ifndef __TINYUNIT_H__
#define __TINYUNIT_H__

#include <math.h>
#include <stdio.h>
#include <string.h>

static int tu_exit_code = 0;
#define TU_EXIT_CODE tu_exit_code
#define TU_EXIT_FAIL TU_EXIT_CODE = -1

#define TU_ASSERT(condition, message)                                          \
    do {                                                                       \
        if (!(condition)) {                                                    \
            printf("%s faild--l:%d--%s\n", __FUNCTION__, __LINE__, message);   \
            TU_EXIT_FAIL;                                                      \
        }                                                                      \
    } while (0)

#define TU_ASSERT_INT_EQ(result, expected)                                     \
    do {                                                                       \
        if ((result) != (expected)) {                                          \
            printf("%s faild--l:%d--result:%d,expected:%d\n",                  \
                   __FUNCTION__,                                               \
                   __LINE__,                                                   \
                   result,                                                     \
                   expected);                                                  \
            TU_EXIT_FAIL;                                                      \
        }                                                                      \
    } while (0)

#define TU_ASSERT_DOUBLE_EQ(result, expected)                                  \
    do {                                                                       \
        if (fabs((result) - (expected)) > 1E-12) {                             \
            printf("%s faild--l:%d--result:%f,expected:%f\n",                  \
                   __FUNCTION__,                                               \
                   __LINE__,                                                   \
                   result,                                                     \
                   expected);                                                  \
            TU_EXIT_FAIL;                                                      \
        }                                                                      \
    } while (0)

#define TU_ASSERT_CHAR_EQ(result, expected)                                    \
    do {                                                                       \
        if ((result) != (expected)) {                                          \
            printf("%s faild--l:%d--result:%c,expected:%c\n",                  \
                   __FUNCTION__,                                               \
                   __LINE__,                                                   \
                   result,                                                     \
                   expected);                                                  \
            TU_EXIT_FAIL;                                                      \
        }                                                                      \
    } while (0)

#define STR_NULL "__STRING_NULL__"
#define TU_ASSERT_STR_EQ(result, expected)                                     \
    do {                                                                       \
        char* result_p = result;                                               \
        char* expected_p = expected;                                           \
        if (!result_p)                                                         \
            result_p = STR_NULL;                                               \
        if (!expected_p)                                                       \
            expected_p = STR_NULL;                                             \
        if (!(strcmp(result_p, expected_p) == 0)) {                            \
            printf("%s faild--l:%d--result:%s,expected:%s\n",                  \
                   __FUNCTION__,                                               \
                   __LINE__,                                                   \
                   result_p,                                                   \
                   expected_p);                                                \
            TU_EXIT_FAIL;                                                      \
        }                                                                      \
    } while (0)

#define TU_RUN(test)                                                           \
    do {                                                                       \
        tu_setup();                                                            \
        test();                                                                \
        tu_teardown();                                                         \
    } while (0)

#define TU_TEST(test) static void test()

#endif
