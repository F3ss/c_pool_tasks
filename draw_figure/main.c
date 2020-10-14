#include <unistd.h>
#include <stdio.h>

void draw(int len, int lines);

int main()
{
	int 	len;
	int 	lines;

	len = 0;
	lines = 0;
	while (len < 1 || lines < 1)
	{
		printf("Write the len\n");
		scanf("%d", &len);
		printf("Write the lines\n");
		scanf("%d", &lines);	
	}
	draw(len, lines);
	return (0);
}

void draw(int len, int lines)
{
	char 	leftCorn;
	char 	rightCorn;
	char 	top;
	char 	side;
	char 	inside;
	int 	lineCounter;
	int 	lenCounter;

	lineCounter = 0;
	lenCounter = 0;
	leftCorn = '/';
	rightCorn = '\\';
	top = '-';
	side = '|';
	inside = 'x';	
	while (lineCounter < lines)
	{
		while (lenCounter < len)
		{
			if ((lineCounter + 1 == lines && lineCounter != 0 && lenCounter + 1 == len) || (lineCounter == 0 && lenCounter == 0))
				write(1, &leftCorn, 1);
			else if ((lineCounter + 1 == lines && lenCounter == 0) || (lineCounter == 0 && lenCounter + 1 == len))
				write(1, &rightCorn, 1);
			else if ((lenCounter == 0 && (lineCounter > 0 || lineCounter + 1 < lines)) ||
			 (lenCounter + 1 == len && (lineCounter > 0 || lineCounter + 1 < lines)))
				write(1, &side, 1);
			else if ((lineCounter + 1 == lines && (lenCounter > 0 && lenCounter + 1 < len)) ||
			 (lineCounter == 0 && (lenCounter > 0 && lenCounter + 1 < len)))
				write(1, &top, 1);
			else
				write(1, &inside, 1);
			lenCounter++;
		}
		write(1, "\n", 1);
		lenCounter = 0;
		lineCounter++;
	}
}