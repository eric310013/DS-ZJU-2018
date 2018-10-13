02-线性结构4 Pop Sequence （25 分）
==
>作者: 陈越<br>
单位: 浙江大学<br>
时间限制: 400 ms<br>
内存限制: 64 MB<br>
代码长度限制: 16 KB

Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:
--
Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:
--
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:
--
```
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
```
Sample Output:
--
```
YES
NO
NO
YES
NO
```
提交结果
--
|测试点|提示|结果|耗时|内存|
|:---|:---|:---|:---|:---|
|0|sample乱序，一般的Y&N|答案正确|2 ms|384KB|
|1|达到最大size后又溢出|答案正确|4 ms|384KB|
|2|M==N|答案正确|4 ms|384KB|
|3|最大数|答案正确|4 ms|384KB|
|4|最小数|答案正确|2 ms|384KB|
|5|卡特殊错误算法（通过比较大小判断）|答案正确|3 ms|384KB|
