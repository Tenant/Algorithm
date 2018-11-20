# Algorithm Design

## 1. Graph

### 1.1 MST

#### 2018-2-E

标准最小生成树题目。

一度不能accepted，因为循环条件错误。

```c++
int N;
scanf("%d",&N){
    // do processing
    scanf("%d",&N);
}
```

后修改为如下，成功accepted

```c++
int N;
while(scanf("%d",&N)!=EOF){
    
}
```

题目中有提到有多组测试用例，但未说明有几组以及全部测试用例输入完毕后有什么标识。所以==不能不写==循环，建议读取==EOF==.







## 2. Heap

#### 2018-2-A

构造一个最大堆，一个最小堆，求数列中的中位数。

求解过程中一度超时。原因未使用$cin$读入字符，后修改为如下形式时accepted

```c++
while(N--){
    getchar(); // take care of the '\n\r' from last line input
    char op;
    scanf("%c",&op);
}
```

## 3. Union

#### 2018-2-C

迷宫联通问题，通过并查集创造虚拟节点求解。同样的问题可以采用==图搜索==的方法来解决，但时间复杂度往往不能满足题目的要求。

题目求解时一度出现**顶部虚拟节点**的根节点指向自身的问题，带来segmentation fault的错误。错误时代码为：

```c++
int root_a=getRoot((x_next-1)*N+y_next);
int root_b=getRoot((x-1)*N+y);
if(root_a<root_b){
    root[root_b]=root_a;
}
else{
    root[root_a]=root_b;
}
```

通过讲**line 6**进行如下修改成功accepted.

```c++
int root_a=getRoot((x_next-1)*N+y_next);
int root_b=getRoot((x-1)*N+y);
if(root_a<root_b){
    root[root_b]=root_a;
}
if(root_a>root_b){
    root[root_a]=root_b;
}
```

## A. Loop Termination

### A.1 Loop Finishing

部分题目不给出测试样例的数量，而是通过读文件结束(EOF)来表示测试结束，或者未提及实际有一组样例或多组样例，此时可采用两种形式的循环条件写法。

第一种：

```c++
int N;
while(scanf("%d",&N)!=EOF){
    
}
```

第二种：

```c++
string S1, S2;
while(cin>>S1>>S2){
    
}
```

