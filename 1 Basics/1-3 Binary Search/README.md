01-复杂度3 二分查找 （20 分）
==
>作者: 陈越<br>
单位: 浙江大学<br>
时间限制: 100 ms<br>
内存限制: 64 MB<br>
代码长度限制: 16 KB

本题要求实现二分查找算法。

函数接口定义：
--
```
Position BinarySearch( List L, ElementType X );
```
其中`List`结构定义如下：
```
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
```
`L`是用户传入的一个线性表，其中`ElementType`元素可以通过>、==、<进行比较，并且题目保证传入的数据是递增有序的。函数`BinarySearch`要查找`X`在`Data`中的位置，即数组下标（注意：元素从下标1开始存储）。找到则返回下标，否则返回一个特殊的失败标记`NotFound`。

裁判测试程序样例：
--
```
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
```
输入样例1：
--
```
5
12 31 55 89 101
31
```
输出样例1：
--
```
2
```
输入样例2：
--
```
3
26 78 233
31
```
输出样例2：
--
```
0
```
提交结果
--
|测试点|提示|结果|耗时|内存|
|:---|:---|:---|:---|:---|
|0|sample1 等价|答案正确|1 ms|256KB|
|1|sample2 等价，但NotFound重新定义|答案正确|1 ms|400KB|
|2|奇数个，正中间找到，MAXSIZE重新定义|答案正确|1 ms|256KB|
|3|偶数个，正中间找到|答案正确|2 ms|276KB|
|4|大数据，在头部找到|答案正确|21 ms|512KB|
|5|大数据，在尾部找到|答案正确|20 ms|660KB|
|6|大数据，找不到|答案正确|21 ms|640KB|