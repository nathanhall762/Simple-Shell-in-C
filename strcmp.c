#include "main.h"

/**
* _strcmp - compares two strings
* @s1: string 1
* @s2: string 2
*
* Return: integer
*/

int _strcmp(char *s1, char *s2)
{
	int len_s1 = 0, len_s2 = 0, pos = 0, diff = 0, lim =0;

	len_s1 = _strlen(s1);
	len_s2 = _strlen(s2);

	if (len_s1 <= len_s2)
		lim = len_s1;
	else
		lim = len_s2;

	while (pos <= lim)
	{
		if (s1[pos] == s2[pos])
		{
			pos++;
			continue;
		}
		else
		{
			diff = s1[pos] - s2[pos];
			break;
		}
		pos++;
	}
	return (diff);
}
