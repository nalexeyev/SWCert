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

unsigned char N;
unsigned char answer = 0;
unsigned char gj = 0;
unsigned char queen_n[N_MAX] = { 0 };
unsigned char queen_i[N_MAX] = { 0 };
unsigned char queen_j[N_MAX] = { 0 };


unsigned char check2(unsigned char position_i1, unsigned char position_j1, unsigned char position_i2, unsigned char position_j2) {
	// if in the same line or column
	if ((position_i1 == position_i2) || (position_j1 == position_j2))
		return 1;
	// if in the same diagonal (one of)
	if ((position_i1 - position_i2 == position_j2 - position_j1) ||
		(position_i1 - position_i2 == position_j1 - position_j2) ||
		(position_i2 - position_i1 == position_j1 - position_j2) ||
		(position_i2 - position_i1 == position_j2 - position_j1))
		return 1;
	return 0;
}

unsigned char check(unsigned queens_n, unsigned char *queens_i, unsigned char *queens_j, unsigned char position_i2, unsigned char position_j2) {
	queens_n++;
	for (int n = 1; n < queens_n; n++) // we will not check the first queen 
	{
		if (check2(queens_i[n], queens_j[n], position_i2, position_j2))
			return 1;
	}
	return 0;
}

void put_queen(unsigned number, unsigned char pos_i, unsigned char pos_j) {

	if (check(number, queen_i, queen_j, pos_i, pos_j))
		return;

	if (number == N-1) {
		answer++;
		return;
	}

	queen_i[number] = pos_i;
	queen_j[number] = pos_j;

	number++;
	pos_i++;

	for (int j = 0; j < N; ++j)
		put_queen(number, pos_i, j);


	return;
}


int main()
{
	unsigned char result, answer = 0;

	freopen_dbg("inputfile.txt", "r", stdin);
	scanf("%hhu", &N);

	for (unsigned char i = 0; i < N; i++) {
		put_queen(0, i, 0); // set 0-th queen in every cell of the first row
	}
	

	printf("%hhu\n", answer);

    return 0;
}

