// 04-树5 Root of AVL Tree （25 分）
// Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "algorithm"

using namespace std;

const int maxn = 20;

typedef struct node {
	int data;
	int height;
	node* left;
	node* right;
}node;

typedef node* avl;

int avl_height(avl root);
int avl_balance_factor(avl root);
void avl_height_update(avl &root);
void avl_create(avl &root, int n);
void avl_insert(avl &root, int _data);
void avl_left_rot(avl &root);
void avl_right_rot(avl &root);
void avl_free(avl& root);

int main()
{
	int n;
	avl root = NULL;
	scanf("%d", &n);
	avl_create(root, n);
	printf("%d", root->data);
	avl_free(root);
	return 0;
}

int avl_height(avl root) {
	if (root == NULL) return 0;
	return root->height;
}

int avl_balance_factor(avl root) {
	return avl_height(root->left) - avl_height(root->right);
}

void avl_height_update(avl &root) {
	root->height = max(avl_height(root->left), avl_height(root->right)) + 1;
}

void avl_create(avl &root, int n) {
	int _data;
	for (int i = 0; i < n; i++) {
		scanf("%d", &_data);
		avl_insert(root, _data);
	}
}

void avl_insert(avl &root, int _data) {
	if (root == NULL) {
		root = (avl)malloc(sizeof(node));
		root->data = _data;
		root->left = root->right = NULL;
		root->height = 1;
		return;
	}
	else {
		if (_data < root->data) {
			avl_insert(root->left, _data);
			avl_height_update(root);
			if (avl_balance_factor(root) == 2) {
				if (avl_balance_factor(root->left) == 1) // LL
					avl_right_rot(root);
				else if (avl_balance_factor(root->left) == -1) { // LR
					avl_left_rot(root->left);
					avl_right_rot(root);
				}
			}
		}
		else if(_data > root->data) {
			avl_insert(root->right, _data);
			avl_height_update(root);
			if (avl_balance_factor(root) == -2) {
				if (avl_balance_factor(root->right) == -1) // RR
					avl_left_rot(root);
				else if (avl_balance_factor(root->right) == 1) { // RL
					avl_right_rot(root->right);
					avl_left_rot(root);
				}
			}
		}
	}
}

void avl_left_rot(avl &root) {
	avl temp = root->right;
	root->right = temp->left;
	temp->left = root;
	avl_height_update(root);
	avl_height_update(temp);
	root = temp;
}

void avl_right_rot(avl &root) {
	avl temp = root->left;
	root->left = temp->right;
	temp->right = root;
	avl_height_update(root);
	avl_height_update(temp);
	root = temp;
}

void avl_free(avl& root) {
	if (root->left) avl_free(root->left);
	if (root->right) avl_free(root->right);
	free(root);
}