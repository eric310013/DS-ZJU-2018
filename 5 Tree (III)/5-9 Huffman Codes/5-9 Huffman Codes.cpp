// 5-9 Huffman Codes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 05-树9 Huffman Codes （30 分)
// 提示: 验证编码是否为Huffman编码只需要确认两点:
// 1. 带权路径长度(WPL)最小, 即与标准Huffman树相同
// 2. 无歧义编码: 前缀码, 任何编码不能是某一组编码的前缀

#pragma warning(disable:4996)
#pragma warning(disable:6031)

#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "queue"
#include "cstdio"

using namespace std;

struct node
{
	node* left = NULL;
	node* right = NULL;
	node* parent = NULL;
	char ch = ' ';
	int freq = 0;
	string code;
};

struct submit
{
	vector<node> list;
};

struct nodecmp
{
	bool operator()(node const* a, node const* b)
	{
		return a->freq > b->freq;
	}
};

priority_queue<node*, vector<node*>, nodecmp> Q;
int WPL = 0;

bool codecmp(node a, node b)
{
	return a.code.length() > b.code.length();
}

node* create_huffman(int N, vector<node> temp)
{
	for (int i = 0; i < N; i++)
	{
		node* n = new node;
		*n = temp[i];
		Q.push(n);
	}
	node* p = NULL, * q1, * q2;
	while (Q.size() > 1)
	{
		q1 = Q.top();
		Q.pop();
		q2 = Q.top();
		Q.pop();
		p = new node;
		p->freq = q1->freq + q2->freq;
		p->left = q1;
		p->right = q2;
		q1->parent = q2->parent = p;
		Q.push(p);
	}
	return p;
}

void huffman_wpl(node* p)
{
	if (p != NULL)
	{
		if (p->left != NULL && p->right != NULL)
		{
			WPL += p->freq;
		}
		huffman_wpl(p->left);
		huffman_wpl(p->right);
	}
}

bool is_huffman(int N, submit s)
{
	sort(&s.list[0], &s.list[0] + N, codecmp);
	int len = 0;
	for (int i = 0; i < N; i++)
	{
		// prefix encoding
		for (int j = i + 1; j < N; j++)
		{
			if (s.list[i].code.find(s.list[j].code) == 0)
				return false;
		}
		// calculate WPL
		len += s.list[i].code.length() * s.list[i].freq;
	}
	// compare WPL
	if (len > WPL)
		return false;
	return true;
};

int main()
{
	int N, M;
	vector<node> temp;
	vector<submit> result;
	node* root;
	// create the huffman tree
	scanf("%d\n", &N);
	temp.resize(N);
	for (int i = 0; i < N; i++) 
	{
		scanf("%c %d", &temp[i].ch, &temp[i].freq);
		if (i < N - 1)
			scanf(" ");
	}
	root = create_huffman(N, temp);
	huffman_wpl(root);
	// input submits
	scanf("%d\n", &M);
	result.resize(M);
	for (int i = 0; i < M; i++) 
	{
		result[i].list.resize(N);
		for (int j = 0; j < N; j++) 
		{
			scanf("%c ", &result[i].list[j].ch);
			result[i].list[j].freq = temp[j].freq;
			getline(cin, result[i].list[j].code);
		}
	}

	for (int i = 0; i < M; i++) 
	{
		if (is_huffman(N, result[i]))
			printf("Yes");
		else 
			printf("No");
		if (i < M - 1)
			printf("\n");
	}

	return 0;
}

