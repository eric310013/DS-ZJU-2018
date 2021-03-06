// 7-4 Harry Potter's Exam.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 07-图4 哈利·波特的考试 （25 分）
// 思路: 找到无向图中所有点之间的最短路径, 从中找出从每个点出发的最长路径, 再从这些最长路径中找到最小值

#include "iostream"
#include "cstdio"

const int MAXN = 101;
const int NR = 10001;// not reachable: distance = infinity

void find_result(int G[][MAXN], int N);// find the shortest one from N longest paths
void floyd(int G[][MAXN], int floyd_map[][MAXN], int N);// Floyd-Warshall algorithm
int find_max_dist(int _map[][MAXN], int i, int N);// find N longest paths

int main()
{
	int M, N;
	int G[MAXN][MAXN];
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			G[i][j] = NR;
	for (int k = 0; k < M; k++) {
		int i, j;
		scanf("%d %d", &i, &j);
		scanf("%d", &G[i][j]);
		G[j][i] = G[i][j];
	}
	find_result(G, N);
	return 0;
}

void find_result(int G[][MAXN], int N){
	int floyd_map[MAXN][MAXN];
	int max_dist, result_dist = NR, result;
	// find the shortest paths
	floyd(G, floyd_map, N);
	for (int i = 1; i <= N; i++) {
		// find N longest paths in floyd_map
		max_dist = find_max_dist(floyd_map, i, N);
		// if the graph is not connected
		if (max_dist >= NR) {
			printf("0");
			return;
		}
		// find the shortest one from N longest routes
		if (result_dist > max_dist) {
			result_dist = max_dist;
			result = i;
		}
	}
	printf("%d %d", result, result_dist);
}

void floyd(int G[][MAXN], int floyd_map[][MAXN], int N){
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			floyd_map[i][j] = G[i][j];
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (floyd_map[i][j] > floyd_map[i][k] + floyd_map[k][j])
					floyd_map[i][j] = floyd_map[i][k] + floyd_map[k][j];
}

int find_max_dist(int _map[][MAXN], int i, int N){
	int max_dist = 0;
	for (int j = 1; j <= N; j++)
		if (_map[i][j] > max_dist && i != j)
			max_dist = _map[i][j];
	return max_dist;
}
