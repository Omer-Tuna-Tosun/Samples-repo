#include <stdio.h>
#include <math.h>

#define REAL_ROOT_SUM (-b + sqrt(delta)) / (2 * a)
#define REAL_ROOT_SUBTRACT (-b - sqrt(delta)) / (2 * a)

#define IMAGINERY_ROOT_1 (double)-b / (2 * a)
#define IMAGINERY_ROOT_2 sqrt((double)abs(delta)) / (2 * a)

void root(int a, int b, int c)
{
	int delta = b * b - 4 * a * c;

	if (delta > 0)
		printf("The expression has 2 real roots. First root is %.3f, second root is %.3f.\n", REAL_ROOT_SUM, REAL_ROOT_SUBTRACT);

	else if (delta < 0)
		printf("The expression has 2 imaginery roots. First root is %.3f + %.3fi," 
			   "second root is %.3f - %.3fi.\n", IMAGINERY_ROOT_1, IMAGINERY_ROOT_2, IMAGINERY_ROOT_1, IMAGINERY_ROOT_2);

	else
		printf("The expression has a double root. The root is %.3f.\n", REAL_ROOT_SUM);
}

int main(void)
{
	while (1)
	{
		int a, b, c;
		printf("Please enter 3 numbers:");
		scanf_s("%d%d%d", &a, &b, &c);

		root(a, b, c);
	}
}