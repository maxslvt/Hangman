#ifndef PENDU_H
# define PENDU_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <time.h>
# include <string.h>

# define MAX_WORD_LENGTH 50
# define MAX_WORDS 1000

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1b[0m"

# define ERROR1 RED "\x1b[31mUsage: ./hangman [file]\n" WHITE
# define ERROR2 RED "Need a \".txt\" file\n" WHITE
# define ERROR3 RED "File can't be reached:" WHITE
# define ERROR4 RED "Malloc error.\n" WHITE
# define ERROR5 RED "No word founded in this file.\n" WHITE

typedef enum Bool
{
	False,
	True
}				t_Bool;

typedef struct s_vars
{
    char *secretWord;
    int *foundedLetter;
    int tryRemaining;
    int qLetters;
}               t_vars;

int sizeWord(char secretWord[]);
void initBoard(int *foundedLetter, int size);
int ft_check_win(int *foundedLetter, int qLetters);
char readCharactere();
int foundLetter(char letter, char secretWord[], int *foundedLetter);
char *getRandomWord(const char *filename);
void ft_check_start(t_vars *data, const char *filename);
void ft_check_game(t_vars *data);
void freeMemory(t_vars *data);
t_Bool	ft_printerror(char *error_msg);
t_Bool	ft_check_filename(char *dir);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void ft_printPendu(int essaisRestants);

#endif
