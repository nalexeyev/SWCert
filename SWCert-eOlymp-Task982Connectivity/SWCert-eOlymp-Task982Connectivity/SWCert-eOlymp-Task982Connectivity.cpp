#include <stdio.h>

#define DEBUG

#ifdef DEBUG
#define printf_dbg(...) printf(__VA_ARGS__)
#define freopen_dbg(...) freopen(__VA_ARGS__)
#else
#define printf_dbg(...) {}
#define freopen_dbg(...) {}
#endif

#define N_MAX 100
#define M_MAX 10000

unsigned short N = 0, M = 0;

typedef struct vertex_s {
	unsigned short visited;
	unsigned short number;
	unsigned short num_linked;
	unsigned short linked[M_MAX+1];
} vertex;

FILE * fp;
vertex vert[N_MAX + 1];



void check(vertex *vertex) {

	if (vertex->visited == 1)
		return;
	
	vertex->visited = 1;

	int i = 0;
	int temp;
	while (i <= vertex->num_linked) {
		i++;
		temp = vertex->linked[i];
		check(&vert[temp]);
	}

	return;
}


int main()
{
	unsigned short  a, b;
	unsigned short  a_prev = M_MAX + 2, b_prev = M_MAX + 2;

#ifdef DEBUG	
	fp = freopen_dbg("input.txt", "r", stdin);
	if (!fp) {
		fprintf(stderr, "Error opening file");
		return 1;
	}
#endif

	for (int i = 1; i <= N_MAX; ++i) {
		for (int j = 1; j <= M_MAX; ++j) {
			vert[i].number = 0;
			vert[i].num_linked = 0;
			vert[i].linked[j] = 0;
			vert[i].visited = 0;
		}
	}
	
	scanf("%hu %hu", &N, &M);


	for (int i = 1; i <= M; i++)
	{
		scanf("%hu %hu", &a, &b);
		if (a == a_prev && b == b_prev)
			continue;

		vert[a].num_linked++;
		vert[a].linked[vert[a].num_linked] = b;

		vert[b].num_linked++;
		vert[b].linked[vert[b].num_linked] = a;

		a_prev = a;
		b_prev = b;

	}

#ifdef DEBUG
	for (int i = 1; i <= N; ++i)
	{
		printf_dbg("#%u, %u: ", i, vert[i].num_linked);
		for (int j = 1; j <= vert[i].num_linked; j++)
			printf_dbg("%u ", vert[i].linked[j]);
		printf_dbg("\n");
	}
#endif

	check(&vert[1]);


	for (int i = 1; i <= N; ++i)
	{
		if (vert[i].visited == 0) {
			printf("NO");
			printf_dbg("\n");
			return 1;
		}

	}

	printf("YES");
	printf_dbg("\n");

	return 0;
}

