// 10-4 Length of Service.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 10-排序4 统计工龄 （20 分）
// 给定公司N名员工的工龄，要求按工龄增序输出每个工龄段有多少员工。

#include "iostream"
#include "cstdio"
#include "cstdlib"

const int _max = 51;

int main()
{
	int N, n = 0;
	scanf("%d", &N);
	int* age = (int*)malloc(sizeof(int)*(N));
	int result[_max];
	for (int i = 0; i <  N; i++)
		scanf("%d", &age[i]);
	for (int i = 0; i < _max; i++)
		result[i] = 0;
	for (int i = 0; i < N; i++)
		result[age[i]]++;
	for (int i = 0; i < _max; i++)
		if (result[i] > 0)
			n++;
	for (int i = 0 , j = 0; i < _max; i++)
		if (result[i] > 0) {
			if (j < n - 1)
				printf("%d:%d\n", i, result[i]);
			else
				printf("%d:%d", i, result[i]);
			j++;
		}
	free(age);
	return 0;
}
