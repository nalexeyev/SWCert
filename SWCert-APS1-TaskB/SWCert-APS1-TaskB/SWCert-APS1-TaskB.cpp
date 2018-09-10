#include <stdio.h>

#define ARR_MAX 200

#define DEBUG

#ifdef DEBUG
#define printf_dbg(...) printf(__VA_ARGS__)
#define freopen_dbg(...) freopen(__VA_ARGS__)
#else
#define print_dbg(...) 
#define freopen_dbg(...)
#endif


int main()
{
	long prize;
	int reshuffles;

	freopen_dbg("inputfile.txt", "r", stdin);

	scanf("%d %d\n", &prize, &reshuffles);

	printf_dbg("%d %d\n", prize, reshuffles);

    return 0;
}

