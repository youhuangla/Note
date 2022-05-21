# C

* C语言实现在控制台同一行覆盖刷新输出，以及'\b'退格控制字符的使用https://blog.csdn.net/zhanghuoding/article/details/52041120

# Debug

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
