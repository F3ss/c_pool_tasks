void print(char *str);

int main(int argc, char **argv)
{
	if(argc > 1)
		for (int counter = 1; counter < argc; counter++)
			print(argv[counter]);
	return (0);
}