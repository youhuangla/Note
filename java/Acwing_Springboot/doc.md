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

显示转化：`int x = (int)'A';`
隐式转化：`double x = 12, y = 4 * 3.3;`
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



### 3.3 循环语句

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



### 3.4 数组

Java中的数组与C++中的数组类似。

#### 3.4.1 初始化

与C++类似。
初始化定长数组，长度可以是变量，可以在初始化时赋值。

```java
int[] a = new int[5];  // 初始化长度为5的int数组，初始值为0
int n = 10;
float[] b = new float[n];  // 初始化长度为n的float数组，初始值为0.0F
char[] c = {'a', 'b', 'c'};  // 初始化长度为3的char数组，初始值为：'a', 'b', 'c'
char[] d = c;  // d与c地址相同，更改c中的元素，d中的元素也会改变
```

#### 3.4.2 数组元素的读取与写入

与C++类似。

```java
int[] a = new int[5];

for (int i = 0; i < 5; i++) {
    a[i] = i;
}
for (int i = 0; i < 5; i ++ ) {
    System.out.println(a[i] * a[i]);
}
```

##### acw_813

```java

import java.util.Scanner;

public class Main {
    private static void print2D(int row, int col, int[][] a) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                System.out.printf("%d ", a[i][j]);
            }
            System.out.println();
        }
    }
    private static void input2D(int row, int col, int[][] a) {
        //System.out.println("now input");
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                a[i][j] = sc.nextInt();
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int row = sc.nextInt(), col = sc.nextInt();
        int[][] a = new int[row][col];
        input2D(row, col, a);
        print2D(row, col, a);
    }
}

```

```
Exception in thread "main" java.util.NoSuchElementException
	at java.base/java.util.Scanner.throwFor(Scanner.java:937)
	at java.base/java.util.Scanner.next(Scanner.java:1594)
	at java.base/java.util.Scanner.nextInt(Scanner.java:2258)
	at java.base/java.util.Scanner.nextInt(Scanner.java:2212)
	at Main.input2D(Main.java:18)
	at Main.main(Main.java:26)
	
```

该程序在 Idea 中可以通过先输入两 int ，再输入数列解决，但是直接复制数据会报错

>   这个错误通常出现在 `Scanner.nextInt()` 方法被调用时，输入的格式不符合要求，或者没有输入，导致 `Scanner` 类无法读取下一个整数。这可能会导致 `NoSuchElementException` 异常的抛出，从而导致程序终止运行。
>
>   在这个程序中，异常很可能是由于输入的行数或列数不足引起的。例如，如果输入只有一行，而程序需要读取两行，那么就会出现这个错误。可以在读取输入之前，先检查输入是否存在，或者输入的格式是否正确，以避免这个错误的发生。
>
>   另外，可能还有其他原因导致了这个错误的发生，具体取决于程序运行的环境和输入的情况。如果无法确定问题的具体原因，可以在程序中添加调试信息，以帮助诊断问题所在。
>
>   参考文档：[Java Tutorials - Scanner](https://docs.oracle.com/javase/tutorial/essential/io/scanning.html)。

输入

```
3 4 
1 3 4 5
2 6 9 4
1 4 7 5
```

为什么会报错？

>   该输入包含了 3 行 4 列的矩阵数据，但是在程序中只读取了前两个整数，即 row 和 col，程序没有读取完整的矩阵数据。因此当程序运行到读取矩阵数据的部分时会抛出 "java.util.NoSuchElementException" 异常。要解决这个问题，可以在读取 row 和 col 后，再添加一个循环来读取完整的矩阵数据。

我应该怎么改？

>   你可以将 `Scanner` 对象作为参数传递给 `input2D` 函数，而不是在函数内部创建一个新的 `Scanner` 对象。这样就可以避免多个 `Scanner` 对象对同一个输入流进行读取而导致的异常。修改后的代码如下所示：
>
>   ```java
>   import java.util.Scanner;
>   
>   public class Main {
>       private static void print2D(int row, int col, int[][] a) {
>           for (int i = 0; i < row; i++) {
>               for (int j = 0; j < col; j++) {
>                   System.out.printf("%d ", a[i][j]);
>               }
>               System.out.println();
>           }
>       }
>       private static void input2D(int row, int col, int[][] a, Scanner sc) {
>           for (int i = 0; i < row; i++) {
>               for (int j = 0; j < col; j++) {
>                   a[i][j] = sc.nextInt();
>               }
>           }
>       }
>       public static void main(String[] args) {
>           Scanner sc = new Scanner(System.in);
>           int row = sc.nextInt(), col = sc.nextInt();
>           int[][] a = new int[row][col];
>           input2D(row, col, a, sc);
>           print2D(row, col, a);
>       }
>   }
>   ```
>
>   这样修改后就可以正常读取输入了。
>
>   如果不传入Scanner对象，那么在`input2D`方法中无法进行输入操作，会抛出`NoSuchElementException`异常，因为Scanner无法从System.in中读取任何输入。





#### 3.4.3 多维数组

与C++类似。

```java
int[][] a = new int[2][3];
a[1][2] = 1;
int[][] b = {
        {1, 2, 3},
        {4, 5, 6},
};
System.out.println(a[1][2]);
System.out.println(b[0][1]);
```



#### 3.4.4 常用API

属性`length`：返回数组长度，注意不加小括号

`Arrays.sort()`：数组排序

`Arrays.fill(int[] a, int val)`：填充数组

`Arrays.toString()`：将数组转化为字符串

`Arrays.deepToString()`：将多维数组转化为字符串

数组不可变长





### 3.5 字符串

#### 3.5.1 String类

初始化：

```java
String a = "Hello World";
String b = "My name is";
String x = b;  // 存储到了相同地址
String c = b + "yxc";  // String可以通过加号拼接
String d = "My age is " + 18;  // int会被隐式转化成字符串"18"
String str = String.format("My age is %d", 18);  // 格式化字符串，类似于C++中的sprintf
String money_str = "123.45";
double money = Double.parseDouble(money_str);  // String转double
只读变量，不能修改，例如：

String a = "Hello ";
a += "World";  // 会构造一个新的字符串
访问String中的字符：

String str = "Hello World";
for (int i = 0; i < str.length(); i ++ ) {
    System.out.print(str.charAt(i));  // 只能读取，不能写入
}
```


常用API：

```java
length()：返回长度
split(String regex)：分割字符串
indexOf(char c)、indexOf(String str)：查找，找不到返回-1
equals()：判断两个字符串是否相等，注意不能直接用==
compareTo()：判断两个字符串的字典序大小，负数表示小于，0表示相等，正数表示大于
startsWith()：判断是否以某个前缀开头
endsWith()：判断是否以某个后缀结尾
trim()：去掉首尾的空白字符
toLowerCase()：全部用小写字符
toUpperCase()：全部用大写字符
replace(char oldChar, char newChar)：替换字符
replace(String oldRegex, String newRegex)：替换字符串
substring(int beginIndex, int endIndex)：返回[beginIndex, endIndex)中的子串
```



#### 3.5.2 StringBuilder、StringBuffer

String不能被修改，如果打算修改字符串，可以使用StringBuilder和StringBuffer。

StringBuffer线程安全，速度较慢；StringBuilder线程不安全，速度较快。

```java
StringBuilder sb = new StringBuilder("Hello ");  // 初始化
sb.append("World");  // 拼接字符串
System.out.println(sb);

for (int i = 0; i < sb.length(); i ++ ) {
    sb.setCharAt(i, (char)(sb.charAt(i) + 1));  // 读取和写入字符
}

System.out.println(sb);
```


常用API：

reverse()：翻转字符串

### 3.6 函数



Java的所有变量和函数都要定义在类中。

函数或变量前加static表示静态对象，类似于全局变量。
静态对象属于class，而不属于class的具体实例。

静态函数中只能调用静态函数和静态变量。

示例：

```java
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        System.out.println(max(3, 4));
        int[][] a = new int[3][4];
        fill(a, 3);
        System.out.println(Arrays.deepToString(a));

        int[][] b = getArray2d(2, 3, 5);
        System.out.println(Arrays.deepToString(b));
    }

    private static int max(int a, int b) {
        if (a > b) return a;
        return b;
    }

    private static void fill(int[][] a, int val) {
        for (int i = 0; i < a.length; i ++ )
            for (int j = 0; j < a[i].length; j ++ )
                a[i][j] = val;
    }

    private static int[][] getArray2d(int row, int col, int val) {
        int[][] a = new int[row][col];
        for (int i = 0; i < row; i ++ )
            for (int j = 0; j < col; j ++ )
                a[i][j] = val;
        return a;
    }
}
```

### 3.7 类与接口

#### 3.7.1 类

class与C++、Python类似。

##### 3.7.1.1 源文件声明规则

一个源文件中只能有一个public类。
一个源文件可以有多个非public类。
源文件的名称应该和public类的类名保持一致。
每个源文件中，先写package语句，再写import语句，最后定义类。

##### 3.7.1.2 类的定义

public: 所有对象均可以访问

private: 只有自己可以访问

```java
class Point {
    private int x;
    private int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public String toString() {
        return String.format("(%d, %d)", x, y);
    }
}

```

##### 3.7.1.3 类的继承

每个类只能继承一个类。

```java
class ColorPoint extends Point {
    private String color;

    public ColorPoint(int x, int y, String color) {
        super(x, y);
        this.color = color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String toString() {
        return String.format("(%d, %d, %s)", super.getX(), super.getY(), this.color);
    }
}
```

##### 3.7.1.4 类的多态



#### 3.7.2 接口

interface与class类似。主要用来定义类中所需包含的函数。

接口也可以继承其他接口，一个类可以实现多个接口。

##### 3.7.2.1 接口的定义

```java
interface Role {
    public void greet();
    public void move();
    public int getSpeed();
}
```

##### 3.7.2.2 接口的继承

每个接口可以继承多个接口

```java
interface Hero extends Role {
    public void attack();
}
```

##### 3.7.2.3 接口的实现

每个类可以实现多个接口

```java
class Zeus implements Hero {
    private final String name = "Zeus";
    public void attack() {
        System.out.println(name + ": Attack!");
    }

    public void greet() {
        System.out.println(name + ": Hi!");
    }

    public void move() {
        System.out.println(name + ": Move!");
    }

    public int getSpeed() {
        return 10;
    }
}

作者：yxc
链接：https://www.acwing.com/blog/content/22092/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

##### 3.7.2.4 接口的多态

```java
class Athena implements Hero {
    private final String name = "Athena";
    public void attack() {
        System.out.println(name + ": Attack!");
    }

    public void greet() {
        System.out.println(name + ": Hi!");
    }

    public void move() {
        System.out.println(name + ": Move!");
    }

    public int getSpeed() {
        return 10;
    }
}

public class Main {
    public static void main(String[] args) {
        Hero[] heros = {new Zeus(), new Athena()};
        for (Hero hero: heros) {
            hero.greet();
        }
    }
}
```





#### 3.7.3 泛型

类似于C++的template，Java的类和接口也可以定义泛型，即同一套函数可以作用于不同的对象类型。
泛型只能使用对象类型，不能使用基本变量类型。







作者：yxc
链接：https://www.acwing.com/blog/content/22037/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。























作者：yxc
链接：https://www.acwing.com/blog/content/22034/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



