#include <stdlib.h>
#include <stdio.h>

int *ar(int min, int max);

int main()
{
	int i;
	int min;
	int max;
	int *arr;

	printf("Write min number and max number\nmin number couldn't be les or equil a max\n");
	min = 1;
	max = 0;
	i = 0;
	while (min >= max)
	{
		scanf("%d", &min);
		scanf("%d", & max);
	}
	arr = ar(min, max);
	for (int a = min; a < max; a++)
	{
		if (a + 1 < max)
			printf("%d, ", arr[i]);
		else
			printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}

int *ar(int min, int max)
{
	int i;
	int *result;

	i = 0;
	result = (int *)malloc((max - min) * sizeof(int));
	while (min < max)
	{
		result[i] = min;
		min++;
		i++;
	}

	return (result);
}