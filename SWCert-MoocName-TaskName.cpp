#include <stdio.h>

#define DEBUG

#ifdef DEBUG
#define printf_dbg(...) printf(__VA_ARGS__)
#define freopen_dbg(...) freopen(__VA_ARGS__)
#else
#define printf_dbg(...) 
#define freopen_dbg(...)
#endif

#define N_MAX 11

unsigned char answer = 0;

int main()
{


	freopen_dbg("inputfile.txt", "r", stdin);
	scanf("%hhu", &N);


	printf("%hhu\n", answer);

    return 0;
}

