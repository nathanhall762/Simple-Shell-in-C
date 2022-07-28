#include "main.h"

char *_getenv(const char *name);

int main(void)
{
	printf("Test 1:");
	printf("%s", _getenv(PATH));

	return (0);
}

char *_getenv(const char *name)
{
	
}
