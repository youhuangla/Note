#include <stdio.h>
#include "geek_test.h" // 替换掉原 gtest/gtest.h 头文件

// 判断一个数字 x 是否是素数
int is_prime(int x) {
    for (int i = 2; i * i < x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

// 第一个测试用例
TEST(test1, test_is_prime) {
    EXPECT_EQ(is_prime(3), 1);
    EXPECT_EQ(is_prime(5), 1);
    EXPECT_EQ(is_prime(7), 1);
}

// 第二个测试用例
TEST(test2, test_is_prime) {
    EXPECT_EQ(is_prime(4), 0);
    EXPECT_EQ(is_prime(0), 0);
    EXPECT_EQ(is_prime(1), 0);
}

int main() {
    return RUN_ALL_TESTS();
}