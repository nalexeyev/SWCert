/*
Problem C-[Intermediate] Роботы 1
Роботы 1
Time limit:	1 s
Memory limit:	64 M
На поле квадратной формы, которое состоит из R*R (R = 10^9) клеток, находятся R*R роботов (по одному роботу в каждой клетке).
Каждый робот находится ровно в центре клетки и его размер существенно меньше размера клетки.
Для заданной пары роботов найти количество роботов, которые находятся строго между ними на линии, соединяющей этих двух роботов.


*/

#include <stdio.h>

#define R_MAX 1000000000

#define DEBUG

#ifdef DEBUG
#define printf_dbg(...) printf(__VA_ARGS__)
#define freopen_dbg(...) freopen(__VA_ARGS__)
#else
#define printf_dbg(...) 
#define freopen_dbg(...)
#endif

unsigned x1, y1, x2, y2;
unsigned delta_x = 0, delta_y = 0;
unsigned x_min = 0, y_min = 0, x_max = 0, y_max = 0;
unsigned x, y;
int result = 0;



int main()
{
	freopen_dbg("inputfile.txt", "r", stdin);

	scanf("%u %u %u %u\n", &x1, &y1, &x2, &y2);

//	delta_x = (x2 < x1) ? x1 - x2 : x2 - x1;
//	delta_y = (y2 < y1) ? y1 - y2 : y2 - y1;
	
	if (x2 < x1) {
		delta_x = x1 - x2;
		x_min = x2;
		x_max = x1;
	}
	else {
		delta_x = x2 - x1;
		x_min = x1;
		x_max = x2;
	}

	if (y2 < y1) {
		delta_y = y1 - y2;
		y_min = y2;
		y_max = y1;
	}
	else {
		delta_y = y2 - y1;
		y_min = y1;
		y_max = y2;
	}


	printf_dbg("delta_x = %u, delta_y = %u\n", delta_x, delta_y);

	if (delta_x == 0) {
		result = delta_y-1;
		goto exit;
	}
	else if (delta_y == 0) {
		result = delta_x-1;
		goto exit;
	}

	else if (delta_x == delta_y) {
		result = delta_x-1;
		goto exit;
	}
	
	for (x = x_min+1; x < x_max/2; ++x)
	{
		for (y = y_min+1; y < y_max/2; ++y)
		{
			float xx = ((float)x - x1) / ((float)x2 - x1);
			float yy = ((float)y - y1) / ((float)y2 - y1);
			if (xx == yy) {
				result = (x_max - x_min)/(x - x_min)*2-1;
				goto exit;
			}
				//result++;
		}

	}


exit:
	if (result < 0)
		result *= -1;

	printf("%u\n", result);
	return 0;
}

