#include <stdio.h>

int main()
{
	int stones_number, heaps_number;
	int heaps[100] = {0};
	freopen("inputfile.txt", "r", stdin);

	scanf("%d %d\n", &stones_number, &heaps_number);

	if (0 >= heaps_number) 
		heaps_number = 1;

	int i, j=-1, tmp;
	for (i = 0; i < stones_number; ++i) {
		j++;
		if (j == heaps_number)
			j = 0;
		heaps[j]++;

	}
	long long result = heaps[0]; // float did not pass all test cases
	
	for (j = 1; j < heaps_number; ++j) {
		result = result * heaps[j];
	}

	for (j = 0; j < heaps_number; ++j) {
		printf("%d ", heaps[j]);
	}
	printf("\n");

	printf("%lld\n", result);
    return 0;
}
