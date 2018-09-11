#include <stdio.h>

#define ARR_MAX 6

#define DEBUG

#ifdef DEBUG
#define printf_dbg(...) printf(__VA_ARGS__)
#define freopen_dbg(...) freopen(__VA_ARGS__)
#else
#define print_dbg(...) 
#define freopen_dbg(...)
#endif

int prize_arr[ARR_MAX] = { -1, -1, -1, -1, -1, -1 };
int reshuffles = 0;
int length = -1;
int prize = 0;
int i = 0, j = 0, ii = 0;


int intarr2int(int *arr, int len_arr)
{
	int i = 0;
	int result = 0;

	for (i = 0; i < len_arr; i++) {
		result *= 10;
		result += arr[i];
	}
	return result;
}

int main()
{
	freopen_dbg("inputfile.txt", "r", stdin);
	
	// read number as digits array
	for (i = 0; i < ARR_MAX; i++) {
		int c = getc(stdin);
		if ((c == EOF) || (c == ' '))
			break;
		prize_arr[i] = c - '0'; // why?
	}
	length = i;

	scanf("%d\n", &reshuffles);

	int max_item, min_item;
	int max_index, min_index;
	int tmp;

	printf_dbg("%d\n", intarr2int(prize_arr, length));

	for (i = 0; i < reshuffles; i++) {
		printf_dbg("Shuffle #%d\n", i);
		max_item = -1;
		min_item = 10;
		for (j = length - 1 - i; j >= (0 + i); j--) { // the max of similar max'es is right one
			if (prize_arr[j] > max_item) {
				max_item = prize_arr[j];
				max_index = j;
			}
			if (prize_arr[j] < min_item) {
				min_item = prize_arr[j];
				min_index = j;
			}
		}

		printf_dbg("max: %d(%d) min:%d(%d)\n", max_item, max_index+1, min_item, min_index+1);

		// move max to first
		if (1) {
			tmp = prize_arr[i];
			prize_arr[i] = prize_arr[max_index];
			prize_arr[max_index] = tmp;
		}

		printf_dbg("%d\n", intarr2int(prize_arr, length));

		// reshuffle min to last
		if (1) {
			tmp = prize_arr[length-1-i];
			prize_arr[length - 1 - i] = prize_arr[min_index];
			prize_arr[min_index] = tmp;
		}

		printf_dbg("%d\n", intarr2int(prize_arr, length));
	}
	
	printf_dbg("Answer: %d\n", printf_dbg("%d\n", intarr2int(prize_arr, length)));

    return 0;
}

