### STL(Standard Template Library)

**Invoking `sort()`**

```c++
# include <algorithm>
using namespace std; // sort() resides in std;
...
sort(start_address, end_address); // recall library-function sort(); sort() depends on operator <, sorting rules can be defined by overloading // operator <
...
bool cmp(T a, T b) 
{
    ...
}
sort(start_address, end_address, cmp); // if cmp(a, b)==true, then put a ahead of b

stable_sort(); //用法同sort()，但不交换相等元素的先后位置
```

