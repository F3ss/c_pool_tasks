#include <stdlib.h>
#include <stdio.h>

char *concat(int size, char **strs, char *sep);
int len(int size, char **strs, char *sep);

int main()
{
	char *sep;
	char *strs[3];
	char *result;

	sep = " // ";
	strs[0] = "Hello";
	strs[1] = "World";
	strs[2] = "!";
	result = concat(3, strs, sep);

	printf("%s\n", result);

	return (0);
}

int len(int size, char **strs, char *sep)
{
	int lenth;
	int a;
	int b;

	lenth = 0;
	a = 0;
	b = 0;
	while (a < size)
	{
		while (strs[a][b] != 0)
			b++;
		lenth += b;
		b = 0;
		if (a + 1 < size)
			while (sep[b] != 0)
				b++;
		lenth += b;
		b = 0;
		a++;
	}
	return (lenth);
}

char *concat(int size, char **strs, char *sep)
{
	char *result;
	int iterStr;
	int iterChar;
	int iterCharResult;
	int lenth;

	iterStr = 0;
	iterChar = 0;
	iterCharResult = 0;
	lenth = len(size, strs, sep);
	result = (char *)malloc(lenth * sizeof(char));
	while (iterStr < size)
	{
		while (strs[iterStr][iterChar] != 0)
		{
			result[iterCharResult] = strs[iterStr][iterChar];
			iterChar++;
			iterCharResult++;
		}
		iterChar = 0;
		if (iterStr + 1 < size)
			while (sep[iterChar] != 0)
			{
				result[iterCharResult] = sep[iterChar];
				iterChar++;
				iterCharResult++;
			}
		iterChar = 0;
		iterStr++;
	}
	return (result);
}