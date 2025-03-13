#include "pendu.h"

char *getRandomWord(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("%s %s\n",ERROR3, filename);
        return (NULL);
    }

    char **words = malloc(MAX_WORDS * sizeof(char *));
    if (!words)
    {
        printf("%s", ERROR4);
        fclose(file);
        return (NULL);
    }

    char buffer[MAX_WORD_LENGTH];
    int count = 0;

    while (fgets(buffer, MAX_WORD_LENGTH, file) && count < MAX_WORDS)
    {
        buffer[strcspn(buffer, "\r\n")] = '\0';
        words[count] = strdup(buffer);
        if (!words[count])
        {
            printf("%s", ERROR4);
            fclose(file);
            return (NULL);
        }
        count++;
    }
    fclose(file);

    if (count == 0)
    {
        printf("%s", ERROR5);
        return (NULL);
    }

    srand(time(NULL));
    int randomIndex = rand() % count;

    char *chosenWord = strdup(words[randomIndex]);

    for (int i = 0; i < count; i++)
        free(words[i]);
    free(words);

    return chosenWord;
}