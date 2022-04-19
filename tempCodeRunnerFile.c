#include <stdio.h>

int main(int argc, char *argv[]) {
    int a = 0x61626364;
    int *p = &a;
    char *q = (char *)&a;
    printf("%x %c\n", *p, *q);
    return 0;
}