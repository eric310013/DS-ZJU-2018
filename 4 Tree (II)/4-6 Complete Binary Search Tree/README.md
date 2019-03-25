04-树6 Complete Binary Search Tree （30 分）
===

>作者: 陈越</br>
单位: 浙江大学</br>
时间限制: 400 ms</br>
内存限制: 64 MB</br>
代码长度限制: 16 KB

A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.

The right subtree of a node contains only nodes with keys greater than or equal to the node's key.

Both the left and right subtrees must also be binary search trees.

A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

Input Specification
---

Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification
---

For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input
---

```bash
10
1 2 3 4 5 6 7 8 9 0
```

Sample Output
---

```bash
6 3 8 1 5 7 9 0 2 4
```

提交结果
---

|测试点|提示|结果|耗时|内存|
|:---|:---|:---|:---|:---|
0|sample 换数字，但大小顺序不变|答案正确|2 ms|576KB
1|完全平衡|答案正确|3 ms|612KB
2|右边有余|答案正确|2 ms|380KB
3|底层只多1个|答案正确|2 ms|384KB
4|只有1个|答案正确|2 ms|396KB
5|最大N随机|答案正确|3 ms|640KB
