# 05-树8 File Transfer （25 分）

>作者: 陈越</br>
单位: 浙江大学</br>
时间限制: 150 ms</br>
内存限制: 64 MB</br>
代码长度限制: 16 KB

We have a network of computers and a list of bi-directional connections. Each of these connections allows a file transfer from one computer to another. Is it possible to send a file from any computer on the network to any other?

## Input Specification

Each input file contains one test case. For each test case, the first line contains N (2≤N≤10​4​​), the total number of computers in a network. Each computer in the network is then represented by a positive integer between 1 and N. Then in the following lines, the input is given in the format:

```bash
I c1 c2
```  

where I stands for inputting a connection between c1 and c2; or

```bash
C c1 c2    
```

where C stands for checking if it is possible to transfer files between c1 and c2; or

```bash
S
```

where S stands for stopping this case.

## Output Specification

For each C case, print in one line the word "yes" or "no" if it is possible or impossible to transfer files between c1 and c2, respectively. At the end of each case, print in one line "The network is connected." if there is a path between any pair of computers; or "There are k components." where k is the number of connected components in this network.
Sample Input 1:

```bash
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S
```

## Sample Output 1

```bash
no
no
yes
There are 2 components.
```

## Sample Input 2

```bash
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
I 1 3
C 1 5
S
```

## Sample Output 2

```bash
no
no
yes
yes
The network is connected.
```

## 提交结果

|测试点|提示|结果|耗时|内存|
|:---|:---|:---|:---|:---|
0|sample 1 合并2个集合，最后不连通|答案正确|3 ms|256KB
1|sample 2 最后连通|答案正确|3 ms|384KB
2|最小N，无连通操作|答案正确|3 ms|384KB
3|最大N，无操作|答案正确|3 ms|384KB
4|最大N，递增链，卡不按大小union的|答案正确|14 ms|512KB
5|最大N，递减链，卡不按大小union的|答案正确|15 ms|404KB
6|最大N，两两合并，反复查最深结点，卡不压缩路径的|答案正确|15 ms|384KB