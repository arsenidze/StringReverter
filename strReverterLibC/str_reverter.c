#include <stdlib.h>
#include <string.h>

#define FALSE	0
#define TRUE	1

static	char	*g_storage = NULL;
static	size_t	g_size;

static int	_save_and_revert(char *str)
{
	size_t	len;

	if (!str) {
		return (FALSE);
	}
	len = strlen(str);
	if (g_storage && g_size < len) {
		//allocated memory from previous calls
		free(g_storage);
		g_storage = NULL;
	}
	if (!g_storage) {
		g_storage = malloc(sizeof(char) * (len + 1));
		if (!g_storage) {
			return (FALSE);
		}
	}
	for (size_t i = 0; i < len; ++i)
	{
		g_storage[i] = str[len - 1 - i];
	}
	g_storage[len] = '\0';
	g_size = len;
	return (TRUE);
}

int			Write(char *str)
{
	return (_save_and_revert(str));
}

char		*Read(void)
{
	return (g_storage);
}