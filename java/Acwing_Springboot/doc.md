# Doc

作者：yxc
链接：https://www.acwing.com/blog/content/22032/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

## 1.安装环境

### 1.1  安装IDEA

## 2. 基本概念

JDK、JRE、JVM的关系：

JDK：Java Development Kit，Java开发工具包

JRE: Java Runtime Environment，Java运行环境

JVM：Java Virtual Machine，Java虚拟机

JDK包含JRE，JRE包含JVM

JDK版本选择

目前JDK1.8（也叫JDK8，注意不是JDK18）用得最多

Java代码的编译运行流程

将Java源码编译成Java字节码。

使用JVM将Java字节码转化成机器码。

JVM作用：跨平台、内存管理、安全。

JSE、JEE、JME的区别

JSE: Java Standard Edition，标准版

JEE：Java Enterprise Edition，企业版

JME: Java Mirco Edition，移动版

Spring是JEE的轻量级替代品

SpringBoot是Spring + 自动化配置

1. Java语法
  3.1 变量、运算符、输入与输出
  3.2 判断语句
  3.3 循环语句
  3.4 数组
  3.5 字符串
  3.6 函数
  3.7 类与接口
  3.8 常用容器

作者：yxc
链接：https://www.acwing.com/file_system/file/content/whole/index/content/5914056/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

## 3. Java语法

类似于C#，Java的所有变量和函数都要定义在class中。

### 3.1 变量、运算符、输入与输出

#### 3.1.1 内置数据类型

类型	字节数	举例
byte	1	123
short	2	12345
int	4	123456789
long	8	1234567891011L
float	4	1.2F
double	8	1.2, 1.2D
boolean	1	true, false
char	2	‘A’

#### 3.1.2 常量

使用final修饰：

final int N = 110;

#### 3.1.3 类型转化

显示转化：int x = (int)'A';
隐式转化：double x = 12, y = 4 * 3.3;
3.1.4 表达式
与C++、Python3类似：

int a = 1, b = 2, c = 3;
int x = (a + b) * c;
x ++;

#### 3.1.5 输入

##### 方式1，效率较低，输入规模较小时使用。

```java
Scanner sc = new Scanner(System.in);
String str = sc.next();  // 读入下一个字符串
int x = sc.nextInt();  // 读入下一个整数
float y = sc.nextFloat();  // 读入下一个单精度浮点数
double z = sc.nextDouble();  // 读入下一个双精度浮点数
String line = sc.nextLine();  // 读入下一行
```

##### 方式2，效率较高，输入规模较大时使用。注意需要抛异常。

```java
package com.yxc;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        System.out.println(str);
    }
}

```

#### 3.1.6 输出

##### 方式1，效率较低，输出规模较小时使用。

```java
System.out.println(123);  // 输出整数 + 换行
System.out.println("Hello World");  // 输出字符串 + 换行
System.out.print(123);  // 输出整数
System.out.print("yxc\n");  // 输出字符串
System.out.printf("%04d %.2f\n", 4, 123.456D);  // 格式化输出，float与double都用%f输出
```

##### 方式2，效率较高，输出规模较大时使用。注意需要抛异常。

```java
package com.yxc;

import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write("Hello World\n");
        bw.flush();  // 需要手动刷新缓冲区
    }
}
```

### 3.2 判断语句

#### 3.2.1 if-else语句

与C++、Python中类似。

例如：

```java
package com.yxc;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int year = sc.nextInt();
        if (year % 100 == 0) {
            if (year % 400 == 0)
                System.out.printf("%d是闰年\n", year);
            else
                System.out.printf("%d不是闰年\n", year);
        } else {
            if (year % 4 == 0)
                System.out.printf("%d是闰年\n", year);
            else
                System.out.printf("%d不是闰年\n", year);
        }
    }
}
```



#### 3.2.2 switch语句

与C++中类似。

```java
package com.yxc;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int day = sc.nextInt();
        String name;
        switch (day) {
            case 1:
                name = "Monday";
                break;
            case 2:
                name = "Tuesday";
                break;
            case 3:
                name = "Wednesday";
                break;
            case 4:
                name = "Thursday";
                break;
            case 5:
                name = "Friday";
                break;
            case 6:
                name = "Saturday";
                break;
            case 7:
                name = "Sunday";
                break;
            default:
                name = "not valid";
        }
        System.out.println(name);
    }
}
```



#### 3.2.3 逻辑运算符与条件表达式

与C++、Python类似。

例如：

```java
package com.yxc;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int year = sc.nextInt();
        if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
            System.out.printf("%d是闰年\n", year);
        else
            System.out.printf("%d不是闰年\n", year);
    }
}
```





#### 3.3.1 while循环

与C++、Python类似，例如：

```java
int i = 0;
while (i < 5) {
    System.out.println(i);
    i ++ ;
}
```



#### 3.3.2 do while循环

与C++、Python类似，例如：

```java
int i = 0;
do {
    System.out.println(i);
    i ++ ;
} while (i < 5);
do while语句与while语句非常相似。唯一的区别是，do while语句限制性循环体后检查条件。不管条件的值如何，我们都要至少执行一次循环。

3.3.3 for循环
与C++、Python类似，例如：

for (int i = 0; i < 5; i ++ ) {  // 普通循环
    System.out.println(i);
}

int[] a = {0, 1, 2, 3, 4};
for (int x: a) {  // forEach循环
    System.out.println(x);
}
```





作者：yxc
链接：https://www.acwing.com/blog/content/22034/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



