# Recursion

[什么是尾递归？ - 知乎](https://www.zhihu.com/question/20761771/answer/19996299)

<https://blog.51cto.com/nxlhero/1231228>

## 欧几里德(辗转相除)算法

### 求最大公因数和最小公倍数

#### 朴实版

```c
#include <stdio.h>

int exhaustion_gcd(int a, int b) {
    int small, big, gcd = -1;
    if (a < b) {
        small = a;
        big = b;
    } else {
        small = b;
        big = a;
    }
    for (int i = 2; i < small; i++) {
        if (small % i == 0 && big % i == 0) {
            if (gcd < i) {
                gcd = i;
            }
        }
    }
    return gcd;
}

int euclidean_gcd(int a, int b) {
    int temp;
    while (a % b != 0) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}

int recursive_euclidean_gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    } else {
        return recursive_euclidean_gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    int gcd = euclidean_gcd(a, b);
    return a / gcd * b;//a * b / gcd则先计算a * b,可能溢出
}

int main() {
    //输入两个整数值
    int a, b;
    scanf("%d,%d", &a, &b);

    //穷举法
    int ex_gcd_r = exhaustion_gcd(a, b);

    //欧几里得算法，辗转相除Euclidean algorithm
    //循环
    int eu_gcd_r = euclidean_gcd(a, b);
    //递归recursive
    int re_eu_gcd_r = recursive_euclidean_gcd(a, b);

    //最小公倍数 Least Common Multiple
    int lcm_r = lcm(a, b);

    printf("穷举法求最大公约数:%d\n", ex_gcd_r);
    printf("辗转相除法求最大公约数:%d\n", eu_gcd_r);
    printf("递归辗转相除法求最大公约数:%d\n", re_eu_gcd_r);
    printf("最小公倍数:%d\n", lcm_r);
    return 0;
}
```

```shell
24,36
穷举法求最大公约数:12
辗转相除法求最大公约数:12
递归辗转相除法求最大公约数:12
最小公倍数:72
```

#### 一行简版

```c
/*************************************************************************
	> File Name: 3.gcd.c
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Mar 2021 03:18:49 PM CST
 ************************************************************************/

#include <stdio.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int a, b;
    while (~scanf("%d %d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
        printf("lcm(%d, %d) = %d", a, b, lcm(a, b));
    }
    return 0;
}

```

```shell
24 36
gcd(24, 36) = 12
lcm(24, 36) = 72
```

### 求方程$ax + by = 1$的一组整数值解

```c
#include <stdio.h>

int ex_gcd(int a, int b, int *x, int *y){//利用指针记录函数中两个数的值，这样在main中也可以读，弥补了函数只能返回一个值的缺点
    if (!b) {
        *x = 1, *y = 0;
        return a;
    }
    int ret = ex_gcd(b, a % b, y, x);//省去了声明一个新变量的开销
    *y -= a / b * (*x);
    return ret;
}
#if 0
int ex_gcd(int a, int b, int *x, int *y){
    if (!b) {
        *x = 1, *y = 0;
        return a;
    }
    int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
    *x = yy;
    *y = xx - a / b * yy;
    return ret;
}
#endif
int main() {
    int a, b, x, y;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
        printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
    }
    return 0;
}
```

```shell
2 3
gcd(2, 3) = 1
2 * -1 + 3 * 1 = 1
```

