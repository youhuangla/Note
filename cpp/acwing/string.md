# string

## ASCII

'A' 65

'a' 97

'0' 48

## input

### ignore space

scanf，cin 这两个输入都不计入空格

```cpp
char s[100];
scanf("%s", s + 2);
cin >> s + 2;
```

### count space

- cpp string

  - std::getline 

    [std::getline \- cppreference\.com](https://zh.cppreference.com/w/cpp/string/basic_string/getline) 

    ```cpp
    getline(cin, str);
    ```

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

[std::basic\_string<CharT,Traits,Allocator>::substr \- cppreference\.com](https://zh.cppreference.com/w/cpp/string/basic_string/substr)

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



### 766

[766. 去掉多余的空格 - AcWing题库](https://www.acwing.com/problem/content/768/)

#### Solution1

利用 cin 和 scanf 忽略读入空字符。

```cpp
/*************************************************************************
	> File Name: 2_766.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Jun 14 15:34:29 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		cout << s << ' ';
	}
	return 0;
}
```

#### Solution2

##### 第一类双指针算法

```cpp
/*************************************************************************
	> File Name: 766.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Jun 14 15:25:11 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string r;	
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			r += s[i];
		} else {
			r += ' ';
			int j = i;
			while (j < s.size() && s[j] == ' ') {
				j++;
			}
			i = j - 1;
		}
	}
	cout << r << endl;
    return 0;
}

```

#### Solution3

判断局部性，每次只判断相邻两个字符。

```cpp
/*************************************************************************
	> File Name: 766.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Jun 14 15:25:11 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string r;	
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			r += s[i];
		} else {
		/*
			r += ' ';
			int j = i;
			while (j < s.size() && s[j] == ' ') {
				j++;
			}
			i = j - 1;
		*/
			if (!i || s[i - 1] != ' ') {//i not the first char of string OR s[i] is the first space
				r += ' ';
			}	
		}
	}
	cout << r << endl;
    return 0;
}

```

#### 764

```cpp
/*************************************************************************
	> File Name: 764.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Jun 14 15:58:45 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string r;
	getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
		if (i == s.size() - 1) {
			r += (s[i] + s[0]);
		} else {
            r += (s[i] + s[i + 1]);
        }
    }
    cout << r << endl;
	return 0;
}
```

### stringstream

#### 770

[770. 单词替换 - AcWing题库](https://www.acwing.com/problem/content/772/)

从 `<sstream>` 头文件引入。

把一个 string 当作 cin 读入。

类似 sscanf ，但是不限制读入的数目。所以我们可以命名为 `ssin` 。

弹幕说可以用

```cpp
getline(cin, str, ' ');
//b) the next available input character is delim, as tested by Traits::eq(c, delim),in which case the delimiter character is extracted from input, but is not appended to str.
```

```cpp
/*************************************************************************
	> File Name: 774.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 17 15:29:59 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s, '.');
	cout << s << endl;
	return 0;
}
```

```shell
youhuangla@Ubuntu 774 % ./a.out                                                                                             [0]
hello world.
hello world
```

##### Solution

```cpp
/*************************************************************************
	> File Name: 770.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 17 11:12:55 2022
 ************************************************************************/

#include <iostream> 
#include <sstream>

using namespace std;

int main() {
	string s, a, b;
	getline(cin, s);
	cin >> a >> b;

	stringstream ssin(s);// like cin, can read from s like s is a cin
	string str;
	while (ssin >> str) {
		if (str == a) {
			cout << b << ' ';
		} else {
			cout << str << ' ';
		}
	}

	return 0;
}
```

```shell
输入
You want someone to help you
You
I

输出
I want someone to help you 
```

##### 774

[774. 最长单词 - AcWing题库](https://www.acwing.com/problem/content/description/776/)

如果不用`getline(cin, s, '.');` ，则最后一个单词要特殊判断：

```cpp
if (str.back() == '.') {
    str.pop_back();//C++ 11
}
```

 这样做的好处是可以不用 `stringstream` 。

可以直接比较当前单词和上一个最大长度单词的长度，不用单独存上一个最大长度单词的长度。

```cpp
/*************************************************************************
	> File Name: 774.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 17 15:29:59 2022
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s, '.');
	int max_len = 0;
	string longest_w;
	stringstream ssin(s);
	string w;
	while (ssin >> w) {
		/*
		if (w.size() > max_len) {
			max_len = w.size();
			longest_w = w;
		}
		*/
		if (w.size() > longest_w.size()) {
			longest_w = w;
		}
	}
	cout << longest_w << endl;


	/*
	//below: first I think about double pointer,but the longest word's string is difficult to store
	for (int i = 0; i < s.size(); i++) {
		int j = i;
		while (j < s.size() && s[j] != ' ') {
			j++;
		}
		int cur_len = j - i;
		if (cur_len > max_len) {
			max_len = cur_len;
		}
	}
	*/
	return 0;
}
```

### 771

#### 第一类双指针

见 [766](##766) 。

```cpp
for (int i = 0; i < s.size(); i++) {
    int j = i;
    while (j < s.size() && s[j] == s[i]) {
        j++;
    }
    r = j - i;
}
```

```cpp
/*************************************************************************
	> File Name: 771.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 17 13:58:51 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {//can be replace: while (n--)
		cin >> s;
		int j = 0;
		int max = 0;
		char c_max;
		while (j != s.size()) {
			int k = j;
			while (s[k] == s[k + 1]) {//different from yxc here
				k++;
			}
			int len = k - j + 1;// as I compare s[k] with s[k + 1],length should + 1.
			if (len > max) {
				max = len;
				c_max = s[k];
			}
			j = k + 1;
		}
		cout << c_max << ' ' << max << endl;
	}
    return 0;
}

```

### 775

[775. 倒排单词 - AcWing题库](https://www.acwing.com/problem/content/777/)

#### Solution1

`stringstream` 将所有单词存入一个 vector 中，使用库 `<algorithm>`函数 `reverse(begin, end)` 快速反转。

```cpp
/*************************************************************************
	> File Name: 775.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 17 16:23:47 2022
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	stringstream ssin(s);
	string w;
	vector<string> w_vec;
	while (ssin >> w) {
		w_vec.push_back(w);
	}
	reverse(w_vec.begin(), w_vec.end());
	for (string t : w_vec) {
		if (t == w_vec.back()) {
            cout << t;
        } else {
            cout << t << " ";
        } 
	}
	cout << endl;
	return 0;
}

```

#### Solution2

将所有单词存入数组后逆序输出。

```cpp
/*************************************************************************
	> File Name: 2_775.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 17 16:40:40 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	string s_a[105];
	int n = 0;
	while (cin >> s_a[n]) {
		n++;
	}
	n--;// important ,without this line will print one more space in the begining.
	do {
		cout << s_a[n] << " ";
		n--;
	} while (n != -1);
	cout << endl;
#if 0	
	for (int i = n - 1; i >= 0; i--) {
		cout << s_a[i] << ' ';
	}
	cout << endl;
#endif	
	return 0;
}
```

### 776

#### Solution1

```cpp
/*************************************************************************
	> File Name: 776.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 17 17:30:53 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, n_s;
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() > s2.size()) {
		s = s1;
		n_s = s2;
	} else {
		s = s2;
		n_s = s1;
	}
	bool is_true = false;
	// "abcd" 's fifth loop move, back to it self, so only need to loop s.size() times.
	int s_size = s.size();
	for (int i = 0; i < s_size; i++) {
		for (int j = 0, k = n_s.size(); k <= s_size; j++, k++) {
			if (s.substr(j, k) == n_s) {
				is_true = true;
				break;
			}
		}
		if (is_true) {
			break;
		} else {
			s = s.substr(1, s_size) + s.substr(0, 1);// not (2, size), substr [)
			//cout << s << endl;
		}
	}
	if (is_true) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	return 0;
}
```

#### Solution2

yxc

```clike
for () {
    //当前循环移位得到 a' ,判断 b 是否是 a' 的子串
    for(起点) {
        for(枚举对应位置) {
        	//字符不一致则终止
        }
        //判断索引位置是否等于字符串长度，等于则“包含”，结束程序
    }
}
//不包含
```

理解该算法是 KMP 算法的基础。KMP 算法卡住 80% 的学生。

##### substr(count)

[std::basic\_string<CharT,Traits,Allocator>::substr \- cppreference\.com](https://zh.cppreference.com/w/cpp/string/basic_string/substr)

```cpp
    std::string a = "0123456789abcdefghij";
 
    // count 为 npos ，返回 [pos, size())
    std::string sub1 = a.substr(10);
    std::cout << sub1 << '\n';
```

> 这是特殊值，等于 `size_type` 类型可表示的最大值。准确含义依赖于语境，但通常，期待 string 下标的函数以之为字符串尾指示器，返回 string 下标的函数以之为错误指示器。
>
> [std::basic\_string<CharT,Traits,Allocator>::npos \- cppreference\.com](https://zh.cppreference.com/w/cpp/string/basic_string/npos)

##### code

```cpp
/*************************************************************************
	> File Name: std_776.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Jun 28 09:23:25 2022
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	if (a.size() < b.size()) {
		swap(a, b);
	}
	for (int i = 0; i < a.size(); i++) {
		a = a.substr(1) + a[0];// count 为 npos ，返回 [pos, size())
		//cout << a << endl;
		for (int j = 0; j + b.size() <= a.size(); j++) {
			int k = 0;
			for (; k < b.size(); k++) {
				if (a[j + k] != b[k]) {
					break;
				}
            }
            if (k == b.size()) {
                puts("true");
                return 0;
            }
        }
    }
    puts("false");
    return 0;
}
```

```cpp
/*************************************************************************
	> File Name: 2_776.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed Jun 29 08:54:58 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;// assume that s2 is s1's substring after some shift loop.
	cin >> s1 >> s2;
	if (s1.size() < s2.size()) {
		string temp;
		temp = s1;
		s1 = s2;
		s2 = temp;
	}
    //cout << s1 << " " << s2 << endl;
	for (int i = 0; i < s1.size(); i++) {
		//shift loop
		s1 = s1.substr(1) + s1[0];
		//judge if s2 is s1's substr
		for (int j = 0; j < s1.size() - s2.size() + 1; j++) {// the + 1 is important. if s1.size = s2.size, j < 0, than loop will not execute
			int k = 0;
			for (; k < s2.size(); k++) {
                if (s2[k] != s1[j + k]) {
					break;
				}
            }
			if (k == s2.size()) {
				cout << "true" << endl;
				return 0;
			}
		}
	}
	cout << "false" << endl;
    return 0;
}
```

### 777

[AcWing 777. 字符串乘方 - AcWing](https://www.acwing.com/activity/content/problem/content/1967/)

```clike
for (从字符串str的长度开始递减到1，作为段数) {
    if (该段数可以等分str) {
       	计算每个子串长度;
        建立空字符串r;
        for (段数次) {
            r与每个子串拼接一次;
        }
        if (拼接后的字符串与str相同) {
            输出结果;
        }
    }
}
```



```cpp
/*************************************************************************
	> File Name: std_777.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Jun 28 12:01:21 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	string str;
	while (cin >> str, str != ".") {
		int len = str.size();
		for (int n = len; n != 0; n--) {//count from max, so if a (r == str) is find, the n is max,no need to loop and compare
			if (len % n == 0) {
				int m = len / n;
				string s = str.substr(0, m);
				string r;
				for (int i = 0; i < n; i++) {
					r += s;
				}
				if (r == str) {
					cout << n << endl;
					break;
				}
			}
		}
	}
	return 0;
}
```

```cpp
/*************************************************************************
	> File Name: 777.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed Jun 29 09:46:35 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (cin >> s, s != ".") {
		int max = 0;
		for (int i = 1; i <= s.size(); i++) {
			int n = 0;
			if (s.size() % i == 0) {
				//may be the connection factor, judge if it is
				string f = s.substr(0, i);
				string s1 = "";
				while (s1.size() <= s.size()) {
					if (s1 == s) {
                        if (n > max) {
                            max = n;
                        }
                        break;
                    } else {
                        s1 = s1 + f;
						n++;
                    }
				}
			}

		}
		cout << max << endl;
	}	
	return 0;
}
```



### 778

[AcWing 778. 字符串最大跨距 - AcWing](https://www.acwing.com/activity/content/problem/content/1968/)

强烈建议自己去实现一遍，不用库函数，如 find 等。

```cpp
/*************************************************************************
	> File Name: std_778.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Jun 28 12:14:43 2022
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2, s;
	char c;
	while (cin >> c, c != ',') {
		s += c;
	}
	while (cin >> c, c != ',') {
		s1 += c;
	}
	while (cin >> c) {
		s2 += c;
	}
	if (s.size() < s1.size() || s.size() < s2.size()) {
		puts("-1");
    } else {
		// search s1 from left, get the left first s1
        int l = 0;
        while (l + s1.size() <= s.size()) {
            int k = 0;
            while (k < s1.size()) {//search s1
                if (s[l + k] != s1[k]) {
                    break;
                }
                k++;
            }
            if (k == s1.size()) {
                break;
            }
            l++;
        }
		// search s2 from right, get the right first s2
		int r = s.size() - s2.size();
        while (r >= 0) {
            int k = 0;
            while (k < s2.size()) {
                if (s[r + k] != s2[k]) {
                    break;
                }
                k++;
            }
            if (k == s2.size()) {
                break;
            }
            r--;
        }
        l += s1.size() - 1;
		if (l >= r) {
			puts("-1");
		} else {
			printf("%d\n", r - l - 1);
		}
    }
    return 0;
}
```

```cpp
/*************************************************************************
	> File Name: 778.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed Jun 29 20:16:18 2022
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, s1, s2;
	char c;
	while (cin >> c, c != ',') {
		s += c;
	}
	while (cin >> c, c != ',') {
		s1 += c;
	}
	while (cin >> c) {
		s2 += c;
	}
	//search for s1
	int f_s1 = 0;
	int i;
	for (i = 0; i <= s.size() - s1.size(); i++) {// <=
		int j;
		for (j = 0; j < s1.size(); j++) {
			if (s[i + j] != s1[j]) {
				//f_s1 = i;// need this when s1 cannot found
				break;
			}
		}
		if (j == s1.size()) {
			f_s1 = i;
			break;
		}
	}
	//when s1 not found, yxc is simpler but not common
	if (i == s.size() - s1.size() + 1) {
		cout << -1 << endl;
		return 0;
	}
	
	// reverse search for s2
	int f_s2 = 0;
	for (i = s.size() - s2.size(); i >= 0; i--) {
		int j;
		for (j = 0; j < s2.size(); j++) {
			if (s[i + j] != s2[j]) {
				//f_s2 = i;
				break;
			}
		}
		if (j == s2.size()) {
			f_s2 = i;
			break;
		}
	}
	//when s2 not found
	if (i == -1) {
		cout << -1 << endl;
		return 0;
	}
	
/*
	cout << f_s1 << endl;
	cout << f_s2 << endl;
*/
	int len = f_s2 - (f_s1 + s1.size());
	if (len < 0) {
		cout << -1 << endl;
	} else {
		cout << len << endl;
	}
	return 0;
}
```

### 779

[779. 最长公共字符串后缀 - AcWing题库](https://www.acwing.com/problem/content/781/)

弹幕说这是 KMP 算法里找 k 的最大后缀的前身

```clike
for (枚举后缀长度) {
    for(r = 1; r < n; r++) {
        for (枚举比较str[0]与str[i]的第n个字符) {
            若有不同则终止比较,n即最长后缀的长度;
        }
    }
}
```

yxc

```cpp
/*************************************************************************
	> File Name: std_779.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed Jun 29 22:53:19 2022
 ************************************************************************/

#include <iostream>
using namespace std;

const int N = 200; // constant

int n;
string str[N]; // don't write a variable inside an array as the array length

int main() {
    while (cin >> n, n) {
        int len = 1000;
        for (int i = 0; i < n; i++) {
            cin >> str[i];
            if (len > str[i].size()) {
                len = str[i].size();
            }
        }
        while (len) {
            //with suffix
            bool success = true;
            for (int i = 1; i < n; i++) {
                bool is_same = true;
                for (int j = 1; j <= len; j++) {
                    if (str[0][str[0].size() - j] != str[i][str[i].size() - j]) {
                        is_same = false;
                        break;
                    }
                }
                if (!is_same) {
                    success = false;
                    break;
                }
            }
            if (success) {
                break;
            }
            len--;
        }
        cout << str[0].substr(str[0].size() - len) << endl;
    }
    return 0;
}
```

```cpp
/*************************************************************************
	> File Name: 779.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed Jun 29 22:44:14 2022
 ************************************************************************/

#include <iostream>
#include <string>

#define N 205

using namespace std;

string str[N];

int main() {
	int n;
	while (cin >> n, n) {
		//input and find the smallest length to decide the suffix's possible max length
		int len = 1000; // a big num
		for (int i = 0; i < n; i++) {
			cin >> str[i];
			if (str[i].size() < len) {
				len = str[i].size();
			}
		}

		int l;
		string s0;
		for (l = len; l >= 0; l--) {
			//enumerate every length possible
			s0 = str[0].substr(str[0].size() - l); // first string 's suffix
			int i;
			for (i = 1; i < n; i++) {
				//compare each string
				if (l > str[i].size()) {
					break;
				}
				string s1 = str[i].substr(str[i].size() - l);
				if (s0 != s1) {
					// not the same
					// string 's "==", can be replace easily, like in yxc's code
					break;
				}
			}
			if (i == n) {
				break;
			}
		}
		cout << s0 << endl;
	}
	return 0;
}
```

