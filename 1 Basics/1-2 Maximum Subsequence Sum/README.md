01-复杂度2 Maximum Subsequence Sum （25 分）
==

>作者: 陈越</br>
单位: 浙江大学</br>
时间限制: 200 ms</br>
内存限制: 64 MB</br>
代码长度限制: 16 KB

Given a sequence of K integers { N​1​​, N​2​​, ..., N​K​​ }. A continuous subsequence is defined to be { N​i​​, N​i+1​​, ..., N​j​​ } where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification
--

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

Output Specification
--

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
--

```bash
10
-10 1 2 3 4 -5 -23 3 7 -21
```

Sample Output
--

```bash
10 1 4
```

提交结果
--

测试点|提示|结果|耗时|内存
|:---|:---|:---|:---|:---|
|0|sample换1个数字。有正负，负数开头结尾，有并列最大和|答案正确|3 ms|372KB|
|1|最大和序列中有负数|答案正确|2 ms|384KB|
|2|并列和对应相同i但是不同j，即尾是0|答案正确|2 ms|512KB|
|3|1个正数|答案正确|4 ms|508KB|
|4|全是负数|答案正确|4 ms|376KB|
|5|负数和0|答案正确|3 ms|372KB|
|6|最大和前面有一段是0|答案正确|4 ms|384KB|
|7|最大N|答案正确|5 ms|508KB|
