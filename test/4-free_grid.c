#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* free_grid - frees a 2 dim grid
* @grid: pointer to pointer grid
* @height: height of grid
*/

void free_grid(char **grid)
{
	char **temp = grid;

	if (grid)
	{
		while (*grid)
			free(*grid++);

		free(temp);
	}
}
