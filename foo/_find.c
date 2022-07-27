#include "main.h"

char *_find(char *name)
{
	char *file_path;

	file_path = _which(name);

	return (file_path);
}
