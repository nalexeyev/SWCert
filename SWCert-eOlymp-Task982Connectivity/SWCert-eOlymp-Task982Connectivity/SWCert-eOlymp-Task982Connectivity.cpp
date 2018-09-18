#include <stdio.h>

//#define DEBUG

#ifdef DEBUG
#define printf_dbg(...) printf(__VA_ARGS__)
#define freopen_dbg(...) freopen(__VA_ARGS__)
#else
#define printf_dbg(...) {}
#define freopen_dbg(...) {}
#endif

#define N_MAX 100
#define M_MAX 10000

int N = 0, M = 0;
int matrix[N_MAX][N_MAX] = { { 0 },{ 0 } };
int visited[N_MAX] = { 0 };
FILE * fp;

void check(int v) {
	int i;
	visited[v] = 1;
	printf_dbg("Vertex %d is visited\n", v);
	for (i = 1; i <= N; i++)
		if (matrix[v][i] && !visited[i]) 
			check(i);
	return;
}

int main()
{
	int a, b;

#ifdef DEBUG	
	fp = freopen_dbg("input.txt", "r", stdin);
	if (!fp) {
		fprintf(stderr, "Error opening file");
		return 1;
	}
#endif

	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		matrix[a][b] = matrix[b][a] = 1;
	}

	check(1);

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			printf("NO");
			printf_dbg("\n");
			return 1;
		}
	}
	printf("YES");
	printf_dbg("\n");
	return 0;
}

