02-线性结构3 Reversing Linked List （25 分）
==
>作者: 陈越<br>
单位: 浙江大学<br>
时间限制: 400 ms<br>
内存限制: 64 MB<br>
代码长度限制: 16 KB

Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:
--
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10​5​​) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:
```
Address Data Next
```
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
--
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
--
```
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
```
Sample Output:
--
```
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
```
提交结果
--
|测试点|提示|结果|耗时|内存|
|:---|:---|:---|:---|:---|
|0|sample|有尾巴不反转, 地址取上下界|答案正确|7 ms|1916KB|
|1|正好全反转|答案正确|7 ms|2048KB|
|2|K=N全反转|答案正确|7 ms|1792KB|
|3|K=1不用反转|答案正确|7 ms|1792KB|
|4|N=1 最小case|答案正确|8 ms|2048KB|
|5|最大N,最后剩K-1不反转|答案正确|56 ms|3584KB|
|6|有多余结点不在链表上|答案正确|8 ms|1908KB|
