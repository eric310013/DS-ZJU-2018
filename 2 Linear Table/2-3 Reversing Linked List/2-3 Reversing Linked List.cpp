// 02-线性结构3 Reversing Linked List （25 分）
// Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L.
// For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

#include "iostream"
#include "cstdio"
#include "algorithm"

const int maxn = 100010;
const int not_node = maxn;

typedef struct node {
	int addr;
	int data;
	int next_addr;
	int order;
}node;

bool node_cmp(node a, node b) {
	return a.order < b.order;
}

int main() {
	node a[maxn];
	for (int i = 0; i < maxn; i++) {
		a[i].order = not_node;
	}
	int first_addr, n, k;
	scanf("%d %d %d", &first_addr, &n, &k);
	for (int i = 0; i < n; i++) {
		int temp_addr;
		scanf("%d", &temp_addr);
		scanf("%d %d", &a[temp_addr].data, &a[temp_addr].next_addr);
		a[temp_addr].addr = temp_addr;
	}
	int p = first_addr, count = 0;
	while (p != -1) {
		a[p].order = count++;
		p = a[p].next_addr;
	}
	std::sort(a, a + maxn, node_cmp);
	n = count;
	for (int i = 0; i < n / k; i++) {
		for (int j = (i + 1)*k - 1; j > i*k; j--) {
			printf("%05d %d %05d\n", a[j].addr, a[j].data, a[j - 1].addr);
		}
		printf("%05d %d ", a[i*k].addr, a[i*k].data);
		if (i < n / k - 1) {
			printf("%05d\n", a[(i + 2)*k - 1].addr);
		}
		else {
			if (n%k == 0) {
				printf("-1\n");
			}
			else {
				printf("%05d\n", a[(i + 1)*k].addr);
				for (int i = n / k * k; i < n; i++) {
					printf("%05d %d ", a[i].addr, a[i].data);
					if (i < n - 1) {
						printf("%05d\n", a[i + 1].addr);
					}
					else {
						printf("-1\n");
					}
				}
			}
		}
	}
	return 0;
}
