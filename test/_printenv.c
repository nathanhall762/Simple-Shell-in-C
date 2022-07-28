#include "main.h"

int main(void)
{
	unsigned int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			_putchar(environ[i][j]);

		if (j != 0)
			_putchar(10);
	}
	return (0);
}