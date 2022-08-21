#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void randomize(void)
{
	srand((unsigned)time(NULL));
}

void set_array_random(int* p, size_t size)
{
	while (size--)
		*p++ = rand() % 20;
}

void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void bubble_sort(int* p, int size) 
{
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size - 1 - i; ++j)
			if (p[j] > p[j + 1])
				swap(&p[j], &p[j + 1]);
}

int find_element_count(const int* p, int size, int number)
{
	int number_cnt = 0;

	while (size--)
		if ((int)*p++ == number)
			++number_cnt;	

	return number_cnt;
}

int get_max_array(const int* p, int size)
{
	int max = (int)*p;

	while (size--)
	{
		if ((int)*p > max)
			max = (int)*p;
		p++;
	}
		
	return max;
}

int main(void)
{
	int a[SIZE] = { 0 };
	int star_cnt[SIZE] = { 0 };

	randomize();
	set_array_random(a, SIZE);

	bubble_sort(a, SIZE);

	for (int i = 0; i < SIZE; ++i)
		if (i == 0 || a[i] != a[i - 1])
			star_cnt[i] = find_element_count(a, SIZE, a[i]);

	int max_star = get_max_array(star_cnt, SIZE);

	while (max_star)
	{
		for (int i = 0; i < SIZE; ++i)
			if (star_cnt[i] >= max_star)
				printf("    *");
			else
				printf("     ");

		printf("\n");
		max_star--;
	}

	for (int i = 0; i < SIZE; ++i)
	{
		if (i != 0 && a[i] == a[i - 1])
			printf("     ");
		else
			printf("%5d", a[i]);
	}

	return 0;
}