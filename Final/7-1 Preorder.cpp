// 7-1 根据后序和中序遍历输出先序遍历 （8 分）
// 本题要求根据给定的一棵二叉树的后序遍历和中序遍历结果，输出该树的先序遍历结果。

#include "iostream"
#include "cstdio"

const int maxn = 30;
int count = 0;

void get_preorder(int n, int* postorder, int* inorder, int* preorder) {
	if (n <= 0)
		return;
	preorder[count++] = postorder[n - 1];
	int i;
	for (i = 0; i < n; i++)
	{
		if (inorder[i] == postorder[n - 1]) {
			break;
		}
	}
	get_preorder(i, postorder, inorder, preorder);
	get_preorder(n - i - 1, postorder + i, inorder + i + 1, preorder);
}

int main()
{
	int n;
	int postorder[maxn], inorder[maxn], preorder[maxn];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &postorder[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &inorder[i]);
	}
	get_preorder(n, postorder, inorder, preorder);
	printf("Preorder:");
	for (int i = 0; i < n; i++) {
		printf(" %d", preorder[i]);
	}
	return 0;
}