#include <stdio.h>
#include <stdlib.h>

#ifndef HEADER
typedef struct s_stock_str
{
	int 				size;
	char 				*str;
	char 				*copy;
}						stock_str;

stock_str *strs_to_tab(int ac, char **av);
#endif