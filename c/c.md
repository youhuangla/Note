# C

## Document

[cppreference\.com](https://zh.cppreference.com/w/%E9%A6%96%E9%A1%B5)

前两个字符是en则是英文，为zh则是中文

CHM下载

https://github.com/myfreeer/cppreference2mshelp

## VC6

[Win10如何安装VC6__acme_的博客-CSDN博客_win10系统安装vc6](https://blog.csdn.net/qq_18297675/article/details/52046622)

## Compile Option

```c
#include <stdio.h>
#include <stdbool.h>

bool flag() {
    int a;
}

int main() {
    flag();
    return 0;
}
```

```shell
youhuangla@Ubuntu c_lab % gcc hello.c -Wall                                                                  [1]
hello.c: In function 'flag':
hello.c:5:9: warning: unused variable 'a' [-Wunused-variable]
     int a;
         ^
hello.c:6:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
 ^
youhuangla@Ubuntu c_lab % gcc hello.c  
```

