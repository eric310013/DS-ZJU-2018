03-树2 List Leaves （25 分）
==

>作者: 陈越</br>
单位: 浙江大学</br>
时间限制: 400 ms</br>
内存限制: 64 MB</br>
代码长度限制: 16 KB</br>

Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

Input Specification
--

Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification
--

For each test case, print in one line all the leaves' indices in the order of top down, and left to right. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input
--

```bash
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
```

Sample Output
--

```bash
4 1 5
```

提交结果
--

|测试点|提示|结果|耗时|内存|
|:---|:---|:---|:---|:---|
|0|sample 编号乱序，有单边左孩子，中间层少先输出|答案正确|3 ms|372KB|
|1|最大N，有单边右孩子，多层|答案正确|3 ms|384KB|
|2|最小N|答案正确|4 ms|512KB|
|3|每层都有输出，有双孩子|答案正确|3 ms|380KB|
|4|单边树，只有1个输出|答案正确|4 ms|384KB|
