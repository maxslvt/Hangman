#include "pendu.h"

t_Bool	ft_check_filename(char *dir)
{
	int	i;

	i = 0;
	while (dir[i])
		i++;
	if (i >= 4)
		return (ft_strncmp(dir + i - 4, ".txt", 4) == 0);
	return (False);
}

void ft_check_start(t_vars *data, const char *filename)
{
    data->secretWord = getRandomWord(filename);
    if (!data->secretWord)
    {
        printf("%s", ERROR5);
        exit(1);
    }

    data->qLetters = sizeWord(data->secretWord);
    data->tryRemaining = 10;

    data -> foundedLetter = (int *)malloc(data->qLetters * sizeof(int));
    if (!data->foundedLetter)
    {
        printf("%s", ERROR4);
        free(data->secretWord);
        exit(1);
    }

    initBoard(data->foundedLetter, data->qLetters);
}

int ft_check_win(int *foundedLetter, int qLetters)
{
    int i;
    int playerWin;

    i = 0;
    playerWin = 1;
    while (i < qLetters)
    {
        if (foundedLetter[i] == 0)
            playerWin = 0;
        i++;
    }
    
    return(playerWin);
}

void ft_check_game(t_vars *data)
{
    char letter = 0;

    while (data->tryRemaining > 0 && !ft_check_win(data->foundedLetter, data->qLetters))
    {
        printf(YELLOW "\n\nIl vous reste %d coups a jouer" RESET, data->tryRemaining);
        ft_printPendu(data->tryRemaining);
        printf(YELLOW "\nQuel est le mot secret ? " RESET);

        for (int i = 0 ; i < data->qLetters ; i++)
        {
            if (data->foundedLetter[i])
                printf(GREEN "%c" RESET, data->secretWord[i]);
            else
                printf(RED "*" RESET);
        }

        printf(YELLOW "\nProposez une lettre : " RESET);
        letter = readCharactere();

        if (!foundLetter(letter, data->secretWord, data->foundedLetter))
            data->tryRemaining--; // On enlève un coup au joueur
    }

    if (ft_check_win(data->foundedLetter, data->qLetters))
        printf(GREEN "\n\nGagne ! Le mot secret etait bien : %s\n" RESET, data->secretWord);
    else
        printf(RED "\n   +---+\n   |   |\n   O   |\n  /|\\  |\n  / \\  |\n       |\n=========\n\nPerdu ! Le mot secret etait : %s\n" RESET, data->secretWord);
}