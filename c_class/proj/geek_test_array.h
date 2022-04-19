#include <stdio.h>
#include <time.h>
//这是一个线性表实现
int test_run_flag;
#define EXPECT(a, b, comp) { \
    __typeof(a) val_a = (a), val_b = (b); \
    if (!(val_a comp val_b)) { \
        printf("%s:%d: Failure\n", __FILE__, __LINE__); \
        printf("Expected (%s %s %s):\n", #a, #comp, #b); \
        printf("    Which is: (%d %s %d)\n", val_a, #comp, val_b); \
        test_run_flag = 0; \
    } \
}
#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)

typedef void (*test_function_t)();

struct test_function_info_t {
    test_function_t func;  // 测试用例函数指针，指向测试用例函数
    const char *name; // 指向测试用例名称
} test_function_arr[100];
int test_function_cnt = 0;

#define TEST(test_name, func_name) \
void test_name##_##func_name(); \
__attribute__((constructor)) \
void register_##test_name##_##func_name() { \
    test_function_arr[test_function_cnt].func = test_name##_##func_name; \
    test_function_arr[test_function_cnt].name = #func_name "." #test_name; \
    test_function_cnt++; \
} \
void test_name##_##func_name()

int RUN_ALL_TESTS() {
    for (int i = 0; i < test_function_cnt; i++) {
        printf("[ RUN      ] %s\n", test_function_arr[i].name);
        test_run_flag = 1;
        long long t1 = clock();
        test_function_arr[i].func();
        long long t2 = clock();
        if (test_run_flag) {
            printf("[       OK ] ");
        } else {
            printf("[  FAILED  ] ");
        }
        printf("%s", test_function_arr[i].name);
        printf(" (%.0lf ms)\n\n", 1.0 * (t2 - t1) / CLOCKS_PER_SEC * 1000);
    }
    return 0;
}