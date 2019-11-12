# 11-散列2 Hashing （25 分）

时间限制: 400 ms

内存限制: 64 MB

代码长度限制: 16 KB

The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be H(key)=key%TSize where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

## Input Specification

Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (≤10​4​​) and N (≤MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.
Output Specification:

For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

## Sample Input

```bash
4 4
10 6 4 15
```

## Sample Output

```bash
0 1 4 -
```

## 提交结果

|测试点|提示|结果|耗时|内存|
|:---|:---|:---|:---|:---|
|0|sample，有无法插入的|答案正确|3 ms|512KB|
|1|最小值|答案正确|2 ms|384KB|
|2|最大MSize，测试插入边界|答案正确|3 ms|384KB|
|3|最大随机|答案正确|8 ms|404KB|