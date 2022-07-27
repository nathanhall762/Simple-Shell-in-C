#include "main.h"

typedef struct list_s
{
	char *pathname;
	struct list_s *next;
} list_t;

list_t *build_PATH_sll(void)
{
	char *env_str;
	char **env_array;

	env_str = getenv(PATH);
	env_array = split_string(env_str);

	
}
