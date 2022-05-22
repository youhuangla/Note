# Gdb

## Compiling for Debugging

In order to debug a program effectively, you need to generate debugging information when you compile it. This debugging information is stored in the object file; it describes the <u>data type of each variable</u> or <u>function and the correspondence</u> between source line numbers and addresses in the executable code.

为了有效地调试程序，您需要在编译程序时生成调试信息。该调试信息存储在目标文件中；它描述了每个变量或函数的数据类型以及可执行代码中源行号和地址之间的对应关系。 

To request debugging information, specify the <u>‘-g’</u> option when you run the compiler.

```shell
gcc -g hello.c # common 
gcc hello.c -g # difference? use it only gcc hello.c -o hello
```

[Debugging Options \(Using the GNU Compiler Collection \(GCC\)\)](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html)

[选项目录Option Index \(Using the GNU Compiler Collection \(GCC\)\)](https://gcc.gnu.org/onlinedocs/gcc/Option-Index.html)

[总体选项3.2 控制输出类型的选项-o......（使用 GNU 编译器集合 \(GCC\)）](https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html)

Common useful Option,see also man gcc in linux.

gcc是gnu C/C++编译器，支持带或不带“-O”的“-g”，使调试优化代码成为可能。我们建议您在编译程序时始终使用“-g”。

## Starting your Program

使用run命令在gdb下启动程序。您必须首先使用gdb的参数指定程序名（参见第2章[进出gdb]，第11页），或使用file或exec  file命令（参见第18.1节[指定文件的命令]，第277页）。 

以上英文机翻