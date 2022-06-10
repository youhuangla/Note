# leap year

## day of year

![image-20220508174244755](img/image-20220508174244755.png)

```c
#include <stdio.h>
int main() {
    int y, m, d;
    scanf("%d.%d.%d", &y, &m, &d);
    //printf("%d.%d.%d", y, m, d);
    int leap;
    //judge leap year
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        leap = 1;
    } else {
        leap = 0;
    }

    //day of month
    int month[13] = {0,/*skip 0 month*/
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    //if you forget that the febrary of leap year should be 29,you should remenber the joke that somebody
    //only have a birthday every four years.

    //leap year impact day of month 
    if (leap == 1) {
        month[2] += 1;
    }

    //count the day of year according to month
    int day_of_year = 0;
    for (int i = 1; i < m; i++) {//bug: january will not plus month[1]!
        day_of_year += month[i];
    }

    //plus day of the month
    day_of_year += d;
    printf("第%d天", day_of_year);

    return 0;
}
```

```output
2008.10.3
第277天
```



[C++实现日期相关OJ题_小赵小赵福星高照～的博客-CSDN博客](https://blog.csdn.net/attemptendeavor/article/details/121016773)

## hz_oj119

### 119. 昨天和明天

#### 题目描述

 输入一个日期，计算这个日期前一天和后一天的日期。

------

#### 输入

 输入三个整数 y,m,dy,m,d 分别表示年月日 （1000≤y≤3000,1≤m≤12,（1000≤y≤3000,1≤m≤12, 日期必合法））。

#### 输出

 第一行输出三个用空格分隔的整数，表示前一天的年月日。

 第二行输出三个用空格分隔的整数，表示后一天的年月日。

### Solution

- 跨年	
  - 年末
  - 年初
- 跨月
  - 月末
  - 月初
- 普通

```cpp
/*************************************************************************
	> File Name: std_119.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Jun  7 16:44:08 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int day_month(int y, int m) {
    switch(m) {
        case (1):
        case (3):
        case (5):
        case (7):
        case (8):
        case (10):
        case (12): return 31;
        case (4):
        case (6):
        case (9):
        case (11): return 30;
    } 
    if (y % 400 == 0 || y % 100 != 0 && y % 4 == 0) {
        return 29;
    } else {
        return 28;
    }
}
int main() {
    int y, m, d;
    cin >> y >> m >> d;
    if (m == 1 && d == 1) {
        // the beginnig of a year
        cout << y - 1 << " 12 31" << endl;
        cout << y << " " << 1 << " " << 2;
    } else if (m == 12 && d == 31) {
        // the end of a year
        cout << y << " 12 30" << endl;
        cout << y + 1 << " 1 1" << endl; 
    } else if (d == day_month(y, m)) {
        // the end of a month
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " "<< m + 1 << " " << 1 << endl;
    } else if (d == 1) {
        // the beginnig of a mongth
        cout << y << " " << m - 1 << " " << day_month(y, m - 1) << endl;
        cout << y << " " << m << " " << 2 << endl;
    } else {
        // a quite normal day
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl;
    }
    return 0;
}

```

### personal version

```c
/*************************************************************************
	> File Name: 2_119.c
	> Author: 
	> Mail: 
	> Created Time: Wed Jun  8 15:05:56 2022
 ************************************************************************/

#include <stdio.h>

int is_leap(int y) {
    if ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0) {
        return 1;
    }
    return 0;
}

int day_of_month(int y, int m) {
    switch(m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (is_leap(y)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return -1;
    } 
}

int main() {
    int y, m, d;
    scanf("%d %d %d", &y, &m, &d);

    //over a year
    if (m == 12 && d == 31) {
        //yesterday
        printf("%d %d %d\n", y, 12, 30); 
        //tomorrow 
        printf("%d %d %d\n", y + 1, 1, 1); 
    } else if (m == 1 && d == 1) {
        printf("%d %d %d\n", y - 1, 12, 31);
        printf("%d %d %d\n", y, 1, 2);
    } else if (d == day_of_month(y, m)) {
        printf("%d %d %d\n", y, m, d - 1);
        printf("%d %d %d\n", y, m + 1, 1);
    } else if (d == 1) {
        printf("%d %d %d\n", y, m - 1, day_of_month(y, m - 1));
        printf("%d %d %d\n", y, m, 2);
    } else {
        printf("%d %d %d\n", y, m, d - 1);
        printf("%d %d %d\n", y, m, d + 1);
    }
    return 0;
}
```

