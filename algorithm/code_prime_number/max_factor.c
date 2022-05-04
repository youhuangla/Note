/*************************************************************************
	> File Name: factor.c
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Mar 2021 08:17:11 PM CST
 ************************************************************************/

#include <stdio.h>
#define MAX_N 100

int prime[MAX_N + 5] = {0};

void init_sieve_mini_fac() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) {
            continue;
        }
        for (int j = i; j <= MAX_N; j += i) {
            prime[j] = i;  //不是素数，在标记数组中存用来标记该数为合数的素数
        }
    }
    return;
}

int main() {
    init_sieve_mini_fac();
    for (int i = 2; i <= MAX_N; i++) {
        printf("max_fac[%d] = %d\n", i, prime[i]);
    }
    return 0;
}
