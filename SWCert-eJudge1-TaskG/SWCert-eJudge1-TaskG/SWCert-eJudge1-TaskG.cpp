#include <stdio.h>
#include <string.h>

int days = 0;
int number[1000];
int tasks[1000];



void bubble_sort(int *a, int length)
{
	for (int i = 0; i < length - 1; i++) {
		int swapped = 0;
		for (int j = 0; j < length - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}

}

void bubble_sort_linked_arrays(int *a, int *b, int length, int sort_column)
{
	for (int i = 0; i < length - 1; i++) {
		int swapped = 0;
		for (int j = 0; j < length - i - 1; j++) {
			if (sort_column == 1) {
				if (a[j] > a[j + 1]) {
					int tempa = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tempa;
					int tempb = b[j];
					b[j] = b[j + 1];
					b[j + 1] = tempb;
					swapped = 1;
				}
			}
			else if (sort_column == 2)
			{
				if (b[j] > b[j + 1]) {
					int tempa = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tempa;
					int tempb = b[j];
					b[j] = b[j + 1];
					b[j + 1] = tempb;
					swapped = 1;
				}
			}
		}
		if (!swapped)
			break;
	}

}


int counter(int element, int *array, int length)
{
	int i = 0, rez = 0;

	for (i = 0; i < length; i++)
		if (element == array[i])
			++rez;

	return rez;
}

int main() {
	freopen("textfile.txt", "r", stdin);

	scanf("%d\n", &days);
	int i, j, tmp;
	for (i = 0; i < days; ++i) {
		scanf("%d ", &tasks[i]);
		number[i] = i;
	}

	//bubble_sort_linked_arrays(number, tasks, days, 2);
	int count;
	int prev;

	for (i = 1; i < days; ++i) {
		prev = tasks[i-1];
		count = 1;
		printf("(new)\n%d ", prev);
		for (j = i; j < days; ++j) {
			if (tasks[j] > prev) {
				prev = tasks[j];
				printf("%d ", prev);
				count++;
			}
		}
		printf("Count: %d\n", count);
	}


	printf("%d %d\n", number[i], tasks[i]);
	printf("\n");
	return 0;
}

