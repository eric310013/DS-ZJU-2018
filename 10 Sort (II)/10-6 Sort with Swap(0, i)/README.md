# 10-排序6 Sort with Swap(0, i) （25 分)

>作者: 陈越</br>
单位: 浙江大学</br>
时间限制: 400 ms</br>
内存限制: 64 MB</br>
代码长度限制: 16 KB

Given any permutation of the numbers {0, 1, 2,..., N−1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

```
Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}
```

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

## Input Specification

Each input file contains one test case, which gives a positive N (${\le}10^5$) followed by a permutation sequence of {0, 1, ..., N−1}. All the numbers in a line are separated by a space.

## Output Specification

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

## Sample Input

```bash
10
3 5 7 2 6 4 9 0 8 1
```

## Sample Output

```bash
9
```