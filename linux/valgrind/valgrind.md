# Valgrind
## First valgrind
* When I learn about a dictionary program,I meet an error.It occur to me that valgrind can be use to check memory in OSTEP,so I learn about valgrind.
```shell
free(): double free detected in tcache 2
```
* From:https://valgrind.org/docs/manual/quick-start.html#quick-start.intro
* vim test.c
```c
/*************************************************************************
> File Name: test.c
> Author: 
> Mail: 
> Created Time: Mon 17 Jan 2022 01:16:55 PM CST
************************************************************************/

#include <stdlib.h>

void f(void)
{
    int* x = malloc(10 * sizeof(int));
    x[10] = 0;        // problem 1: heap block overrun
}                    // problem 2: memory leak -- x not freed

int main(void)
{
    f();
    return 0;
}
```
* Compile and use valgrind
```shell
youhuangla@Ubuntu valgrind_lab % gcc test.c -o myprog                                          [0]
youhuangla@Ubuntu valgrind_lab % ls                                                            [0]
myprog  test.c
youhuangla@Ubuntu valgrind_lab % valgrind --leak-check=yes ./myprog                            [0]
==15556== Memcheck, a memory error detector
==15556== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==15556== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==15556== Command: ./myprog
==15556== 
==15556== Invalid write of size 4
==15556==    at 0x108668: f (in /home/youhuangla/valgrind_lab/myprog)
==15556==    by 0x108679: main (in /home/youhuangla/valgrind_lab/myprog)
==15556==  Address 0x522f068 is 0 bytes after a block of size 40 alloc'd
==15556==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==15556==    by 0x10865B: f (in /home/youhuangla/valgrind_lab/myprog)
==15556==    by 0x108679: main (in /home/youhuangla/valgrind_lab/myprog)
==15556== 
==15556== 
==15556== HEAP SUMMARY:
==15556==     in use at exit: 40 bytes in 1 blocks
==15556==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==15556== 
==15556== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==15556==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==15556==    by 0x10865B: f (in /home/youhuangla/valgrind_lab/myprog)
==15556==    by 0x108679: main (in /home/youhuangla/valgrind_lab/myprog)
==15556== 
==15556== LEAK SUMMARY:
==15556==    definitely lost: 40 bytes in 1 blocks
==15556==    indirectly lost: 0 bytes in 0 blocks
==15556==      possibly lost: 0 bytes in 0 blocks
==15556==    still reachable: 0 bytes in 0 blocks
==15556==         suppressed: 0 bytes in 0 blocks
==15556== 
==15556== For counts of detected and suppressed errors, rerun with: -v
==15556== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```
