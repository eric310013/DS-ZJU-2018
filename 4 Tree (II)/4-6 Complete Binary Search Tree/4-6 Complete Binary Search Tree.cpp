// 04-树6 Complete Binary Search Tree （30 分）
// Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT.
// You are supposed to output the level order traversal sequence of this BST.

#include "iostream"
#include "cstdio"
#include "algorithm"

const int maxn = 1001;
const int _max = 2000;
int index = 1;

// tips: 如果完全二叉树的中序遍历序列下标是从1开始的, 那么节点i的左右孩子分别是 i*2 和 i*2+1;

// 递归建立完全二叉(查找)树的中序遍历序列
void build(int *nodes, int *tree, int root, int n) {
	if (root > n) return;
	build(nodes, tree, root * 2, n);
	tree[root] = nodes[index++];
	build(nodes, tree, root * 2 + 1, n);
}

int main()
{
	int n; int nodes[maxn]; int tree[maxn];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &nodes[i]);
	}
	std::sort(nodes + 1, nodes + n + 1); // 递增排序, 使完全二叉树同时是一棵二叉查找树
	build(nodes, tree, 1, n);
	for (int i = 1; i < n; i++)
		printf("%d ", tree[i]);
	printf("%d", tree[n]);
	return 0;
}

