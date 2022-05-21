# c++

## digits

[std::ios\_base::precision \- cppreference\.com](https://zh.cppreference.com/w/cpp/io/ios_base/precision)

>  if `fixed` is not set, the `precision` setting says to the stream the *total* number of digits to display, including also the ones before the decimal point. So, in this case I think that the only way is to use the `fixed` mode (examples fixed), which will yield the same behavior of `printf`.
>
> [c\+\+ \- Set the digits after decimal point \- Stack Overflow](https://stackoverflow.com/questions/3923202/set-the-digits-after-decimal-point)

[AcWing 609. 工资 - AcWing](https://www.acwing.com/activity/content/problem/content/1826/)

```c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;


int main()
{
    int number;
    cin >> number;

    double hour;
    cin >> hour;

    double hour_salary;
    cin >> hour_salary;

    double salary = hour_salary * hour;
    cout << "NUMBER = " << number << endl;
    //cout.precision(2);
    //cout << std::fixed << "SALARY = U$ " << salary << endl;
    cout << std::fixed << std::setprecision(2) << "SALARY = U$ " << salary << endl;//fixed is important

    return 0;
}
```

## divide

### Bug

`4 / 3` and `4 / 3.0`,first one cut to int's size, that 's 1.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    double r;
    double v;
    cin >> r;
    v = 4 / 3 * 3.14159 * pow(r, 3);
    //v = 4 / 3.0 * 3.14159 * pow(r, 3);
    printf("VOLUME = %.3lf\n", v);
}
```

```shell
3
VOLUME = 84.823
```

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    double r;
    double v;
    cin >> r;
    //v = 4 / 3 * 3.14159 * pow(r, 3);
    v = 4 / 3.0 * 3.14159 * pow(r, 3);
    printf("VOLUME = %.3lf\n", v);
}
```

```shell
3
VOLUME = 113.097
```

