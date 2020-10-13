#include "header.h"

int main()
{
	char 		*string[3];
	stock_str 	*result;
	int			counter;

	string[0] = "Hello ";
	string[1] = "World";
	string[2] = "!";
	counter = 0;
	result = strs_to_tab(3, string);
	while (counter < 3)
	{
		printf("%s", result[counter].str);
		counter++;
	}
	printf("\n");
	return (0);
}

stock_str *strs_to_tab(int ac, char **av)
{
	stock_str *result;
	int len;

	result = (stock_str *)malloc(ac * sizeof(stock_str));
	len = 0;
	for (int counter = 0; counter < ac; counter++)
	{
		while (av[counter][len] != 0)
			len++;
		result[counter].size = len;
		result[counter].str = av[counter];
		result[counter].copy = av[counter];
		len = 0;
	}
	return (result);
}