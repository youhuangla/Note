# Array

## 753

[753. 平方矩阵 I - AcWing题库](https://www.acwing.com/problem/content/755/)

### Description

输入整数 N，输出一个 N 阶的回字形二维数组。

数组的最外层为 1，次外层为 2，以此类推。

### Solution

#### Thought

我只能说这也太聪明了，我估计只会想着找规律推。

```shell
1 1 1 1 1 1 
1 2 2 2 2 1 
1 2 3 3 2 1 
1 2 3 3 2 1 
1 2 2 2 2 1 
1 1 1 1 1 1 
```

如上图的六阶平方矩阵，随便找一个点 (i, j) 。

该点的数值 = 层数。

那么，如何由 i, j 确认层数？

首先，无论该点在矩阵的四条边中的哪条，层数都 = 最靠近边的坐标与边的“距离”。

若起点为 (0, 0) ，距离可以用 i , j 分别表示为 ：

左：`i + 1`

右：`n - 1 - i + 1`，`n - 1` 行最后一个点横坐标

上：`j + 1`

下：`n - 1 - j + 1`

找出四个距离中的最小距离即点的层数，即矩阵在该坐标上的元素。

由于 y 总起点设置为 (1, 1)，故有细微不同。

#### Code

```cpp
/*************************************************************************
	> File Name: 755.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun  3 21:54:03 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int up = i, down = n - i + 1, left = j, right = n - j + 1;
				cout << min(min(up, down), min(left,right)) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
```

```shell
youhuangla@Ubuntu 755 % g++ 755.cpp                                                             [0]
youhuangla@Ubuntu 755 % ./a.out < input                                                         [0]
1 

1 1 
1 1 

1 1 1 
1 2 1 
1 1 1 

1 1 1 1 
1 2 2 1 
1 2 2 1 
1 1 1 1 

1 1 1 1 1 
1 2 2 2 1 
1 2 3 2 1 
1 2 2 2 1 
1 1 1 1 1 

```

## 754

### Description

[754. 平方矩阵 II - AcWing题库](https://www.acwing.com/problem/content/description/756/)

输入整数 N，输出一个 N 阶的二维数组。

数组的形式参照样例。

### Solution1

视作一个二维数组，然后我们向里面插入元素。

除了对角线上的 1 外，其他数的插入均要分别向下延展和向右延展。

```cpp
/*************************************************************************
	> File Name: 754.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun  3 22:38:55 2022
 ************************************************************************/

#include <iostream>
#define N 105
using namespace std;

int main() {
    int a[N][N];
    int n;
    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) {
            for (int j = i, k = 1; j <= n; j++, k++) {
                a[i][j] = k;// right expand 
                a[j][i] = k;// down expand 
            } 
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

```



### Solution2

一行一行输出。

```clike
for (i : 行)
    for ()
```

for 遍历每一行

​	for 第一列元素易得，即从 (第一个循环索引) 递减直到 1 

​		当前索引

​	for 从 2 递增到 (n - 第一个循环索引 + 1)

​		当前索引

```cpp
/*************************************************************************
	> File Name: 754.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jun  3 22:38:55 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) {
            for (int j = i; j >= 1; j--) {
                cout << j << " "; 
            }
            for (int k = 2; k <= n - i + 1; k++) {
                cout << k << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

```

```shell
1
2
3
4
5
0
```

```shell
1 

1 2 
2 1 

1 2 3 
2 1 2 
3 2 1 

1 2 3 4 
2 1 2 3 
3 2 1 2 
4 3 2 1 

1 2 3 4 5 
2 1 2 3 4 
3 2 1 2 3 
4 3 2 1 2 
5 4 3 2 1 

```

## 755

[755. 平方矩阵 III - AcWing题库](https://www.acwing.com/problem/content/description/757/)

```cpp
/*************************************************************************
	> File Name: 757.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Jun  6 08:26:35 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n, n != 0) {
        for (int i = 0, k = 1; i < n; i++, k *= 2) {
            for (int j = 0, l = k; j < n; j++, l *= 2) {
                cout << l << " ";         
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

```

## 756

[756. 蛇形矩阵 - AcWing题库](https://www.acwing.com/problem/content/758/)

网格图的技巧，可应用于各种图，bfd、dfs等。

```cpp
/*************************************************************************
	> File Name: 756.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Jun  6 08:34:19 2022
 ************************************************************************/

#include <iostream>
using namespace std;

const int N = 110;
int n, m;
int q[N][N];

int main() {
    //网格题，定义方向格子，4个或8个，判断四个方向是否成立，将偏移量记下来
    //(-1, 0) (0, 1) (1, 0) (0, -1)
    //易扩展，不易出错
    int n, m;
    cin >> n >> m;
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    int x = 0, y = 0, d = 1;
    for (int i = 1; i <= n * m; i++) {
        q[x][y] = i;
        int a = x + dx[d], b = y + dy[d];
        if (a < 0 || a >= n || b < 0 || b >= m || q[a][b]) {
            d = (d + 1) % 4;
            a = x + dx[d];
            b = y + dy[d];
        }
        x = a; 
        y = b;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << q[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
```

[【寒假每日一题】Day-3（《 756. 蛇形矩阵》偏移量技巧）_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1mK411M7Ng)

[844. 走迷宫 - AcWing题库](https://www.acwing.com/problem/content/846/)

flood fill 类，在题库搜索该标签。

[1102. 移动骑士 - AcWing题库](https://www.acwing.com/problem/content/1104/)

[1421. 威斯康星方形牧场 - AcWing题库](https://www.acwing.com/problem/content/1423/)
