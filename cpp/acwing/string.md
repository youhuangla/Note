# string

## ASCII

'A' 65

'a' 97

'0' 48

## input

scanf，cin 这两个输入都不计入空格

```cpp
char s[100];
scanf("%s", s + 2);
cin >> s + 2;
```

计入空格

- cpp string
  - std::getline

- c char array 
  - cin.getline
  - fgets

```cpp
/*************************************************************************
	> File Name: input.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Jun  6 10:17:52 2022
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
//using namespace std;
using std::string;
using std::cout;
using std::endl;
using std::cin;
int main() {
    string cpp_string;
    char c_string[100];

    std::getline(cin, cpp_string);
    cout << cpp_string << endl;

    cin.getline(c_string, 1000);//一个较大的数
    cout << c_string << endl;

    fgets(c_string, 1000, stdin);
    cout << c_string << endl;

    return 0;
}
```

```shell
youhuangla@Ubuntu string % ./a.out                                                              [0]
abc def
abc def
def ghi
def ghi
opq rst
opq rst
```

## output

```cpp
char s[100];
puts(s);
//equal
printf("%s\n", s);
```

## char array string operation

`#include <string.h>`

- strlen

求字符串长度，可用 for 循环替代。

- strcmp

字典序比较。若 a < b ，返回 -1 ，a == b 返回 0 ，否则返回 1 。

字典序本身带有“贪心”性质。

- strcpy

`strcpy(a, b)`把 b 拷贝给 a 。

- 遍历字符数组

```c
char s1[100];
for (int i = 0; i < strlen(s1); i++) {
    s1[i];//double loop in function strlen, less effective
}

for (int i = 0，len = strlen(s1); i < len; i++) {
    s1[i];//more effective
}
```

### 722

[772. 只出现一次的字符 - AcWing题库](https://www.acwing.com/problem/content/774/)

```cpp
/*************************************************************************
	> File Name: 772.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Jun  6 15:41:57 2022
 ************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

int cnt[26];
char str[100005];

int main() {
    cin >> str;
    for (int i = 0, len = strlen(str); i < len; i++) {// for (...; str[i]; ...)//更快
        cnt[str[i] - 'a']++;
    }
    for (int i = 0, len = strlen(str); i < len; i++) {// for (...; str[i]; ...)
        if (cnt[str[i] - 'a'] == 1) {
            cout << str[i] << endl;
            return 0;
        }    
    }
    puts("no");
    return 0;
}
```

#### Bug

cin 与 scanf 的区别

```cpp
/*************************************************************************
	> File Name: 2_769.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Jun  6 16:04:47 2022
 ************************************************************************/

#include <iostream>
using namespace std;
// a wrong input example
int main() {
    char str[31];
    scanf("%s", str);//这里并不会读入回车

    char c;
    //scanf("\n%c", &c);//应该这样写
    scanf("%c", &c);//若不改为注释掉的代码，读入输入后，c = '回车符'，原因如上

    cout << c << endl;
    return 0;
}

```

如果用 cin 就没有该问题。

> scanf() wait char-string, separated by whitespaces, enters, etc. 
>
> [c \- scanf reading "Enter" key \- Stack Overflow](https://stackoverflow.com/questions/19794268/scanf-reading-enter-key)

## string

标准库类型，可变长的字符序列。

```cpp
/*************************************************************************
	> File Name: string.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Jun  6 16:23:07 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    string s1;// by default,s1 is an empty string
    string s2 = s1;// s2 is a copy of s1
    string s3 = "hiya";// s3 is one of the literal string's copy
    string s4(10, 'c');// 10 c "cccccccccc" 
     
    return 0;
}

```

### input

string 无法用 scanf 读入，但可以用 printf 输出，当然同理也可以用 puts。当我们的输出比较占时间时，可以用 printf 。

```cpp
/*************************************************************************
	> File Name: string_io.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Jun  6 16:33:56 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    string s1;

    scanf("%s", &s1);//segment
    //cin >> s1;
    return 0;
}
```

```shell
youhuangla@Ubuntu string % g++ string_io.cpp                                                    [0]
string_io.cpp: In function 'int main()':
string_io.cpp:14:20: warning: format '%s' expects argument of type 'char*', but argument 2 has type 'std::__cxx11::string* {aka std::__cxx11::basic_string<char>*}' [-Wformat=]
     scanf("%s", &s1);//segment
                 ~~~^
youhuangla@Ubuntu string % ./a.out                                                              [0]
abc
[1]    15915 segmentation fault  ./a.out
```

```cpp
/*************************************************************************
	> File Name: string_io.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Jun  6 16:33:56 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    string s1;

    //scanf("%s", &s1);//segment
    cin >> s1;

    printf("%s\n", s1.c_str());//member function c_str() return a char string 's first address
    return 0;
}
```

```shell
youhuangla@Ubuntu string % ./a.out                                                              [0]
abc
abc
```

### Operation

#### striing 的 size 和 empty

size 是 O(1) 的，注意size是无符号整数，因此 s.size() <= -1一定成立。

```cpp
/*************************************************************************
	> File Name: string_op.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Jun  9 09:28:21 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    string s1, s2 = "abc";

    cout << s1.empty() << endl;
    cout << s2.empty() << endl;

    cout << s2.size() << endl;
    return 0;
}
```

```shell
1
0
3
```

#### string 的比较

支持 > < >= <= == !=等所有比较操作，按字典序进行比较。

#### 为 string 对象赋值

 ```cpp
 string s1(10, ‘c’), s2;       // s1的内容是 cccccccccc；s2是一个空字符串
 s1 = s2;                // 赋值：用s2的副本替换s1的副本
                        // 此时s1和s2都是空字符串
 ```

#### 字面值和 string 对象相加：

做加法运算时，字面值和字符都会被转化成 string 对象，因此直接相加就是将这些字面值串联起来：

当把string对象和字符字面值及字符串字面值混在一条语句中使用时，必须确保每个加法运算符的两侧的运算对象至少有一个是string：

 ```cpp
 string s4 = s1 + ",";  // 正确：把一个string对象和有一个字面值相加
 
 string s5 = "hello" +", " ; // 错误：两个运算对象都不是string
 
 string s6 = s1 + ", " + "world"; // 正确，每个加法运算都有一个运算符是string
 
 string s7 = "hello" + “, “ + s2; // 错误：不能把字面值直接相加，运算是从左到右进行的
 ```

### 处理string对象中的字符

可以将string对象当成字符数组来处理（注释中）或者使用基于范围的for语句：：

```cpp
/*************************************************************************
	> File Name: string_deal.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Jun  9 09:48:52 2022
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "hello world";
    /*
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }
    */
    for (char c : s) {
        cout << c << endl;
    }
    return 0;
}
```

```shell
h
e
l
l
o
 
w
o
r
l
d
```

使用基于范围的 for 语句时，在，输出的结果不变

```cpp
/*************************************************************************
	> File Name: string_deal.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Jun  9 09:48:52 2022
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "hello world";
    /*
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }
    */
    /*
    for (char c : s) {
        cout << c << endl;
    }
    */
    for (char c : s) {
        c = 'a';
    }
    cout << s << endl;
    return 0;
}
```

```shell
hello world
```

因为该循环等价于

```cpp
for (int i = 0; i < s.size(); i++) {
    char c = str[i];
    c = 'a';
}
```

如果想直接改变，可使用 “引用” 改为

```cpp
for (char &c : s) {
    c = 'a';
}
```

等价于

```cpp
for (int i = 0; i < s.size(); i++) {
    char &c = str[i];
    c = 'a';
}
```

等价于

```cpp
for (auto &c : s) {
    c = 'a';
}
```

auto 使得编译器可以猜类型，这样一些长的类型就可以不用写，但是如果一个类型有多种可能，就不应用 auto 。



### 767

[767. 信息加密 - AcWing题库](https://www.acwing.com/problem/content/769/)

```cpp
/*************************************************************************
	> File Name: 767.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Jun  9 10:17:21 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (auto &c : s) {
        if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z')) {
            c++;
        } else if (c == 'z') {
            c = 'a';
        } else if (c == 'Z') {
            c = 'A';
        }
    }
    cout << s << endl;
    return 0;
}

```

```shell
输入
Hello! How are you!
输出
Ifmmp! Ipx bsf zpv!
```

也可以不用判断那么多次，只需两个 if ，将循环语句分别改为

```cpp
(c - 'a' + 1) % 26 + 'a';
(c - 'A' + 1) % 26 + 'A';
```

### 760

[AcWing 760. 字符串长度 - AcWing](https://www.acwing.com/activity/content/problem/content/1950/)

y总受难计之 fgets ：

该算法不加 16 行的 `&& s[i] != '\n'` 时，在终端会多读入一个 `\n`，所以要加。后面 yxc 也发现输出了一个 ASCII 码 10， 即 LF 。

```shell
       012   10    0A    LF  '\n' (new line)         112   74    4A    J
```

在 Linux 中是 `\n` 。

之后， y总也说了 fgets 是不会过滤掉回车的。

```cpp
/*************************************************************************
	> File Name: 928.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 10 08:19:11 2022
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	char s[101];
	fgets(s, 101, stdin);
	int len = 0;
	for (int i = 0; s[i] && s[i] != '\n'; i++) {
		len++;
	}
	cout << len << endl;
	return 0;
}
```

### 763

[763. 循环相克令 - AcWing题库](https://www.acwing.com/problem/content/765/)

```cpp
/*************************************************************************
	> File Name: 763.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Jun  9 10:38:48 2022
 ************************************************************************/

#include <iostream>

#define Hunter 2 // win Gun
#define Gun 1 // win Bear
#define Bear 0  // win Hunter

using namespace std;

int get(string s1) {
	int n;
	if (s1 == "Hunter") {
		n = (Hunter);
	} else if (s1 == "Gun") {
		n = (Gun);
	} else if (s1 == "Bear") {
		n = (Bear);
	}
	return n;
}

int main() {
	int t; 
	cin >> t;
	string s1, s2;
	for (int i = 0; i < t; i++) {
		cin >> s1 >> s2;
        int x = get(s1), y = get(s2);

        if ((x + 1) % 3 == y) {
            printf("Player2\n");
        } else if ((x % 3) == y) {
            printf("Tie\n");
        } else if ((x + 2) % 3 == y) {
            printf("Player1\n");
        }
    }
    return 0;
}
```

### 765

[765. 字符串加空格 - AcWing题库](https://www.acwing.com/problem/content/767/)

这道题初步显示了 string 的优势。

yxc：能用 char string 做的字符串一定可以用 string 做。

#### Bug

```cpp
/*************************************************************************
	> File Name: 765.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 10 09:17:47 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string b;
	getline(cin, s);
	for (auto &c : s) {
		b += c + ' ';// appears
	}
	cout << b << endl;
	return 0;
}
```

```shell
youhuangla@Ubuntu 765 % ./a.out                                                                                                     [0]
hello
�����
```

若将 17 行 ` ' '`改为 `" "` 。

```shell
youhuangla@Ubuntu 765 % ./a.out                                                                                                     [0]
hello
���H
```

在第 17 行中，由于运算符优先级，`+=` 优先级小于 `+` ，故先计算 `c + ' '`，两个 char 相加，计算出的结果是两个 char 的 ASCII 码之和的 char 。

#### Solution

我们应该让编译器先让 string 和一个 char 相加，得到一个 string 。所以应该改为：

```cpp
/*************************************************************************
	> File Name: 765.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 10 09:17:47 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string b;
	getline(cin, s);
	for (auto &c : s) {
		b = b + c + ' ';
	}
	b.pop_back();//由于该题是每个字符间都加一个空格，所以如果最后的 \n 不算的话，可以将最后多余的一个空格pop_back
	cout << b << endl;
	return 0;
}
```

```shell
youhuangla@Ubuntu 765 % ./a.out                                                                                                     [0]
hello
h e l l o 
```

仔细体会其中的不同。

### substr

#### 755

[773. 字符串插入 - AcWing题库](https://www.acwing.com/problem/content/775/)

函数 substr 的使用。

找最大数索引的 O(n) 方法。

##### Bug

substr 使用的参数 pos 和 npos 是左闭右开的，也就是返回的 string 中不包括 `str[npos]` 。

```shell
constexpr basic_string substr( size_type pos = 0, size_type count = npos ) const (since C++20)

Returns a substring [pos, pos+count). If the requested substring extends past the end of the string, or if count == npos, the returned substring is [pos, size()).
```

```cpp
str.substr(0, i);// not include i
```

##### Solution

```cpp
/*************************************************************************
	> File Name: 773.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 10 09:57:39 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	string str, substr;
	while (cin >> str >> substr) {
		/*	
		char max_c = 0;
		for (auto c : str) {
			if (c > max_c) {
				max_c = c;
			}
		}
		int i = 0;
		for (auto c : str) {
			i++;
			if (c == max_c) {
				break;
			}
		}
		*/
		int i = 0;
		for (int j = 1; j < str.size(); j++) {
			if (str[j] > str[i]) {
				i = j;
			}
		}
		i++;
		//cout << str.substr(0, i) + substr.substr(0, substr.size()) + str.substr(i/*not i + 1*/, str.size()) << endl;
		cout << str.substr(0, i) + substr.substr(0, substr.size()) + str.substr(i/*not i + 1*/) << endl;// if substr to end, the second parameter can be ignore
	}
	return 0;
}
```

### 762

[762. 字符串匹配 - AcWing题库](https://www.acwing.com/problem/content/764/)

string 在 iostream 头文件中有，所以可以不用单独加 string 头文件。

```cpp
/*************************************************************************
	> File Name: 762.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 10 11:39:30 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	double k;
	cin >> k;
	string a, b;
	cin >> a >> b;
	double n = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) {
			n++;
		}
	}
	if (n / a.size() >= k) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}

	return 0;
}
```

### 768

[AcWing 768. 忽略大小写比较字符串大小 - AcWing](https://www.acwing.com/activity/content/problem/content/1958/)

这里使用 fgets 再次出现了计算回车的问题，若不删除回车符，则第一个测试用例就不对了。

```cpp
/*************************************************************************
	> File Name: 768.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 10 11:54:40 2022
 ************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char a[100], b[100];// if all the 100 is another number less than 82, than will fail
	fgets(a, 100, stdin);
	fgets(b, 100, stdin);
	if (a[strlen(a) - 1] == '\n') {
		a[strlen(a) - 1] = 0;// delete the end's '\n'
	}
	if (b[strlen(b) - 1] == '\n') {
		b[strlen(b) - 1] = 0;
	}
	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			a[i] += 32;
		}
	}
	for (int i = 0; b[i] != '\0'; i++) {
		if (b[i] >= 'A' && b[i] <= 'Z') {
			b[i] += 32;
		}
	}
	int r = strcmp(a, b);
	if (r == 0) {
		puts("=");
	} else if (r < 0) {
		puts("<");
	} else {
		puts(">");
	} 
	return 0;
}
```



