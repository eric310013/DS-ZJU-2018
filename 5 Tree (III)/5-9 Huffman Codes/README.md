# 05-树9 Huffman Codes （30 分)

时间限制: 400 ms

内存限制: 64 MB

代码长度限制: 16 KB

In 1953, David A. Huffman published his paper "A Method for the Construction of Minimum-Redundancy Codes", and hence printed his name in the history of computer science. As a professor who gives the final exam problem on Huffman codes, I am encountering a big problem: the Huffman codes are NOT unique. For example, given a string "aaaxuaxz", we can observe that the frequencies of the characters 'a', 'x', 'u' and 'z' are 4, 2, 1 and 1, respectively. We may either encode the symbols as {'a'=0, 'x'=10, 'u'=110, 'z'=111}, or in another way as {'a'=1, 'x'=01, 'u'=001, 'z'=000}, both compress the string into 14 bits. Another set of code can be given as {'a'=0, 'x'=11, 'u'=100, 'z'=101}, but {'a'=0, 'x'=01, 'u'=011, 'z'=001} is NOT correct since "aaaxuaxz" and "aazuaxax" can both be decoded from the code 00001011001001. The students are submitting all kinds of codes, and I need a computer program to help me determine which ones are correct and which ones are not.

## Input Specification

Each input file contains one test case. For each case, the first line gives an integer N (2≤N≤63), then followed by a line that contains all the N distinct characters and their frequencies in the following format:

```
c[1] f[1] c[2] f[2] ... c[N] f[N]
```

where `c[i]` is a character chosen from {'0' - '9', 'a' - 'z', 'A' - 'Z', '_'}, and `f[i]` is the frequency of `c[i]` and is an integer no more than 1000. The next line gives a positive integer M (≤1000), then followed by M student submissions. Each student submission consists of N lines, each in the format:

```
c[i] code[i]
```

where `c[i]` is the i-th character and `code[i]` is an non-empty string of no more than 63 '0's and '1's.

## Output Specification

For each test case, print in each line either "Yes" if the student's submission is correct, or "No" if not.

Note: The optimal solution is not necessarily generated by Huffman algorithm. Any prefix code with code length being optimal is considered correct.

## Sample Input

```bash
7
A 1 B 1 C 1 D 3 E 3 F 6 G 6
4
A 00000
B 00001
C 0001
D 001
E 01
F 10
G 11
A 01010
B 01011
C 0100
D 011
E 10
F 11
G 00
A 000
B 001
C 010
D 011
E 100
F 101
G 110
A 00000
B 00001
C 0001
D 001
E 00
F 10
G 11
```

## Sample Output

```bash
Yes
Yes
No
No
```
## 提交结果

|测试点|提示|结果|耗时|内存|
|:---|:---|:---|:---|:---|
|0|sample 有并列、多分支，有长度错、长度对但是前缀错；仅英文大写字符|答案正确|2 ms|384 KB|
|1|小写字母，01反、且2点对换；有2点重合|答案正确|3 ms|384 KB|
|2|几组编码不等长，都对；等长但前缀错误；code长度超过N|答案正确|2 ms|360 KB|
|3|最大N&M，code长度等于63|答案正确|55 ms|4332 KB|
|4|最小N&M|答案正确|3 ms|360 KB|
|5|编码的字符是双数个，而提交采用的是等长编码。卡仅判断叶结点和度的错误算法|答案正确|2 ms|400 KB|
|6|非Huffman编码，但是正确；没有停在叶子上|答案正确|2 ms|628 KB|