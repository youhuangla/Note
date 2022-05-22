# C

* C语言实现在控制台同一行覆盖刷新输出，以及'\b'退格控制字符的使用https://blog.csdn.net/zhanghuoding/article/details/52041120

## Debug

### GDB

```shell
youhuangla@Ubuntu c_lab % gcc -g hello.c                                                                     [0]
youhuangla@Ubuntu c_lab % gdb a.out                                                                          [0]
GNU gdb (Ubuntu 8.1.1-0ubuntu1) 8.1.1
......
```

```gdb
(gdb) start
Temporary breakpoint 1 at 0x63e: file hello.c, line 4.
Starting program: /home/youhuangla/c_lab/a.out 

Temporary breakpoint 1, main () at hello.c:4
4           printf("lay out src\n");
(gdb) layout src
```

![image-20220516001703557](img/image-20220516001703557.png)

#### Input

[io \- How to use gdb with input redirection? \- Stack Overflow](https://stackoverflow.com/questions/4758175/how-to-use-gdb-with-input-redirection)

### CGDB

[终端调试哪家强？ - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/32843449)

[《深入理解计算机系统》配套实验：Bomblab - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/31269514)

[GDB/CGDB 入门与拆弹游戏 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/120378884)

另见CSAPP_lab中的bomb lab
