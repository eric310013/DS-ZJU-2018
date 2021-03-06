// 02-线性结构1 两个有序链表序列的合并 （15 分）
// 本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。
// L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数Merge要将L1和L2合并为一个非递减的整数序列。
// 应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main() {
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}

/* 你的代码将被嵌在这里 */

List Merge(List L1, List L2) {
	List i = L1->Next, j = L2->Next;
	List L = (List)malloc(sizeof(struct Node));
	List p = L;
	while (i != NULL && j != NULL) {
		if (i->Data < j->Data) {
			p->Next = i;
			i = i->Next;
		}
		else {
			p->Next = j;
			j = j->Next;
		}
		p = p->Next;
	}
	if (i != NULL)
		p->Next = i;
	else if (j != NULL)
		p->Next = j;
	else p->Next = NULL;
	L1->Next = NULL;
	L2->Next = NULL;
	return L;
}

/* 输入样例 */

List Read() {
	int n;
	scanf("%d", &n);
	List L = (List)malloc(sizeof(PtrToNode));
	L->Next = NULL;
	if (n)
	{
		List p = L;
		for (int i = 0; i < n; i++)
		{
			List n = (List)malloc(sizeof(struct Node));
			scanf("%d", &(n->Data));
			p->Next = n;
			p = p->Next;
		}
		p->Next = NULL;
	}
	return L;
}

void Print(List L) {
	L = L->Next;
	if (L == NULL) {
		printf("NULL\n");
		return;
	}
	while (L != NULL) {
		printf("%d ", L->Data);
		L = L->Next;
	}
	printf("\n");
}