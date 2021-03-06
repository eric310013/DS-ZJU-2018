# 02-线性结构1 两个有序链表序列的合并 （15 分）

时间限制: 400 ms

内存限制: 64 MB

代码长度限制: 16 KB

本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

## 函数接口定义

```C
List Merge( List L1, List L2 );
```

其中`List`结构定义如下：

```C
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */
```

`L1`和`L2`是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数`Merge`要将`L1`和`L2`合并为一个非递减的整数序列。应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。

## 裁判测试程序样例

```C
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
```

## 输入样例

```bash
3
1 3 5
5
2 4 6 8 10
```

## 输出样例

```bash
1 2 3 4 5 6 8 10
NULL
NULL
```

## 提交结果

|测试点|提示|结果|耗时|内存|
|:---|:---|:---|:---|:---|
|0|同sample，交错归并|答案正确|1 ms|376KB|
|1|两个完全一样的链表|答案正确|1 ms|332KB|
|2|两个空链表|答案正确|1 ms|256KB|
|3|L2完全贴在L1后面|答案正确|1 ms|256KB|
|4|L1完全贴在L2后面|答案正确|1 ms|256KB|
