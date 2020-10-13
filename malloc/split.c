#include <stdlib.h>
#include <stdio.h>

char 	**ft_split(char *str, char *charset);
char 	**createArr(char *str, char *sep);

int main()
{
	int 	iterStr;
	char 	*str;
	char 	**result;

	iterStr = 0;
	str = "Hello World! // Split example // Is it work? :-)";
	result = ft_split(str, " // ");
	while (result[iterStr] != NULL)
	{
		printf("%s\n", result[iterStr]);
		iterStr++;
	}
	return (0);
}

char **ft_split(char *str, char *charset)
{
	char 	**result;
	int 	checker;
	int		counter;
	int 	lenSep;
	int 	indexResult;
	int 	indexCharResult;

	result = createArr(str, charset);
	checker = 0;
	counter = 0;
	indexResult = 0;
	indexCharResult = 0;
	lenSep = 0;
	while (charset[lenSep] != 0)
		lenSep++;
	while (str[counter] != 0)
	{
		while (str[counter] == charset[checker])
		{
			counter++;
			checker++;
		}
		if (checker == lenSep)
		{
			result[indexResult][indexCharResult + 1] = '\0';
			indexResult++;
			indexCharResult = 0;
			counter--;
		}
		else
		{
			counter -= checker;
			result[indexResult][indexCharResult] = str[counter];
			indexCharResult++;
		}
		checker = 0;
		counter++;
	}

	return (result);
}

char **createArr(char *str, char *sep)
{
	int 	indexSep;
	int 	indexChar;
	int 	quantityStr;
	int 	lenSep;
	int 	lenStr;
	char 	**result;

	lenStr = 0;
	indexSep = 0;
	indexChar = 0;
	quantityStr = 0;
	lenSep = 0;
	result = (char **)malloc(sizeof(int *));
	while (sep[lenSep] != 0)
		lenSep++;
	while (str[indexChar] != 0)
	{
		lenStr++;
		while (str[indexChar] == sep[indexSep] && str[indexChar] != 0)
		{
			indexChar++;
			indexSep++;
		}
		if (indexSep == lenSep)
		{
			result[quantityStr] = (char *)malloc(lenStr * sizeof(char));
			quantityStr++;
			lenStr = 0;
		}
		else
			indexChar -= indexSep;
		indexSep = 0;
		indexChar++;
	}
	result[quantityStr] = (char *)malloc(lenStr * sizeof(char));
	result[quantityStr + 1] = NULL;
	return (result);
}