#include "pendu.h"

int sizeWord(char secretWord[])
{
    int i;

    i = 0;
    while (secretWord[i] != '\0')
    {
        i++;
    }

    return (i);
}

int foundLetter(char letter, char secretWord[], int *foundedLetter)
{
    int i = 0; 
    int rightLetter = 0;
    for (i = 0 ; secretWord[i] != '\0' ; i++)
    {
        if (letter == secretWord[i])
        {
                rightLetter = 1;
                foundedLetter[i] = 1;
        }
    }
    return(rightLetter);
}