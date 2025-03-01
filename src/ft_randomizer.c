#include "pendu.h"

char *getRandomWord(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Erreur : Impossible d'ouvrir le fichier %s\n", filename);
        return NULL;
    }

    char **words = malloc(MAX_WORDS * sizeof(char *));
    if (!words)
    {
        printf("Erreur d'allocation mémoire\n");
        fclose(file);
        return NULL;
    }

    char buffer[MAX_WORD_LENGTH];
    int count = 0;

    while (fgets(buffer, MAX_WORD_LENGTH, file) && count < MAX_WORDS)
    {
        buffer[strcspn(buffer, "\r\n")] = '\0';
        words[count] = strdup(buffer);
        if (!words[count])
        {
            printf("Erreur d'allocation mémoire\n");
            fclose(file);
            return NULL;
        }
        count++;
    }
    fclose(file);

    if (count == 0)
    {
        printf("Erreur : Aucun mot trouvé dans le fichier\n");
        return NULL;
    }

    srand(time(NULL));
    int randomIndex = rand() % count;

    char *chosenWord = strdup(words[randomIndex]);

    for (int i = 0; i < count; i++)
        free(words[i]);
    free(words);

    return chosenWord;
}