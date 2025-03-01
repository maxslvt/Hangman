#include "pendu.h"

void initBoard(int *foundedLetter, int size)
{
    for (int i = 0; i < size; i++)
    {
        foundedLetter[i] = 0;
    }
}

char readCharactere()
{
    char charactere = 0;
 
    charactere = getchar();
    charactere = toupper(charactere);
 
    while (getchar() != '\n') ;
 
    return charactere;
}

void freeMemory(t_vars *data)
{
    free(data->foundedLetter);
    free(data->secretWord);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}