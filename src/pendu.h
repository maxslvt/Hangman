#ifndef PENDU_H
# define PENDU_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000 

# define ERROR1 "Usage: ./hangman [file]\n"
# define ERROR2 "[LIST] Need a \".txt\" file\n"

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