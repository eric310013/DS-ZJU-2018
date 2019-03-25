// 11-2 Hashing.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 11-散列2 Hashing （25 分）
// Insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers.
// The hash function is defined to be H(key) = key % msize
// Quadratic probing (with positive increments only) is used to solve the collisions.

#include "iostream"
#include "cstdio"
#include "cmath"

const int max_n = 10010;

int next_prime(int n) { 
	if (n == 1)
		return 2;
	int prime = (n % 2 == 1) ? n + 2 : n + 1;
	while (1) {
		int i;
		for (i = 3; i*i <= prime; i += 2) {
			if (prime%i == 0)
				break;
		}
		if (i * i > prime)
			break;
		else
			prime += 2;
	}
	return prime;
}


int hashing(int msize, int input, int hash[]) {
	int old_key = input % msize;
	int key = old_key;
	int i = 1;
	while (1) {
		if (hash[key] == -1) {
			hash[key] = input;
			return key;
		}
		key = (old_key + i * i) % msize;
		i++;
		if (i > msize)
			return -1;
	}
}

int main()
{
	int msize, n, input, hash[max_n];
	for (int i = 0; i < max_n; i++)
		hash[i] = -1;
	scanf("%d %d", &msize, &n);
	msize = next_prime(msize);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		int result = hashing(msize, input, hash);
		if (result == -1)
			printf("-");
		else
			printf("%d", result);
		if (i != n - 1)
			printf(" ");
	}
	return 0;
}
