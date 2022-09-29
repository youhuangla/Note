# function

## 804

[804. n的阶乘 - AcWing题库](https://www.acwing.com/problem/content/806/)

```cpp
/*************************************************************************
	> File Name: 804.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Jun 30 21:48:08 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int fact(int n) {
	int r = 1;
	for (int i = 1; i <= n; i++) {
		r *= i;
	}
	return r;
}

int main() {
	int n;
	cin >> n;
	cout << fact(n) << endl; 
	return 0;
}
```

## 817

[817. 数组去重 - AcWing题库](https://www.acwing.com/problem/content/819/)

```cpp
/*************************************************************************
	> File Name: 817.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jul 15 08:46:11 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int get_unique_count(int a[], int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cnt++;// if i == 0, the first num must be unique, which will not excute loop body and will not make cnt++.
		}
		for (int j = 0; j < i; j++) {
			if (a[i] == a[j]) {
				break;
			}
			if (j == i - 1) {
				/*
				cout << "i = " << i << endl;
				cout << "j = " << j << endl;
				
				cout << "a[i] = " << a[i] << endl;
				cout << "a[j] = " << a[j] << endl;
				*/
				cnt++;
			}
		}
	}
	return cnt;
}

int a[1005];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << get_unique_count(a, n) << endl;
	return 0;
}
```

如果使用一个 bool 值标记是否找到则不用特判 `i == 0` 的特殊情况。

## 818

[818. 数组排序 - AcWing题库](https://www.acwing.com/problem/content/description/820/)

写着写着，差点把快排和冒泡搞混了。。

```cpp
/*************************************************************************
	> File Name: 818.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri Jul 15 23:00:27 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int a[1005];

void sort(int a[], int l, int r) {
	//bubble sort
	bool order = false;
	while (order == false) {
		order = true;
		for (int j = l; j <= r - 1; j++) {
			if (a[j] > a[j + 1]) {
				order = false;
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
	return ;
}

void quick_sort(int a[], int l, int r) {
	for (int i = l; i <= r; i++) {
		for (int j = i + 1; j <= r; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
	return ;
}

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//sort(a, l, r);	
	quick_sort(a, l, r);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
```

## 821



画出递归搜索树。

### Sol1

```cpp
/*************************************************************************
	> File Name: 821.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Jul 19 12:59:04 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int step(int n) {
	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return 1;
	}
	return step(n - 1) + step(n - 2);
}

int main() {
	int n;
	cin >> n;
	cout << step(n) << endl;// step[] store in memory
	return 0;
}
```

### Sol

记忆化

```cpp
/*************************************************************************
	> File Name: 2_821.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Jul 19 13:18:59 2022
 ************************************************************************/

#include <iostream>
using namespace std;

int step[20];

int main() {
	int n;
	cin >> n;
	step[0] = 1;
	step[1] = 1;
	for (int i = 2; i <= n; i++) {
		step[i] = step[i - 1] + step[i - 2];
	}
	cout << step[n] << endl;// step[] store in memory
	return 0;
}
```

