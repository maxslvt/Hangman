#include "pendu.h"

t_Bool	ft_printerror(char *error_msg)
{
	printf("error: %s", error_msg);
	return (False);
}

void ft_printPendu(int essaisRestants)
{
    const char *PENDU[] = {
		"\n        \n"
        "        \n"
        "        \n"
        "        \n"
        "        \n"
        "        \n"
        "=========",

		"\n        \n"
        "        \n"
        "        \n"
        "        \n"
        "       |\n"
        "       |\n"
        "=========",

		"\n        \n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "=========",

        "\n   +---+\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "=========",

        "\n   +---+\n"
        "   |   |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "=========",

        "\n   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "=========",

        "\n   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "   |   |\n"
        "       |\n"
        "       |\n"
        "=========",

        "\n   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "  /|   |\n"
        "       |\n"
        "       |\n"
        "=========",

        "\n   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "  /|\\  |\n"
        "       |\n"
        "       |\n"
        "=========",

        "\n   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "  /|\\  |\n"
        "  /     |\n"
        "       |\n"
        "========="
    };

    int index = 10 - essaisRestants;
    if (index < 0)
        index = 0;
    if (index > 10)
        index = 10;

    printf(MAGENTA "%s\n" RESET, PENDU[index]);
}
