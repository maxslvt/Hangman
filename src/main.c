#include "pendu.h"

int main(int ac, char **av)
{
    t_vars data;

    if (ac != 2)
		return (ft_printerror(ERROR1));
    if (!ft_check_filename(av[1]))
		return (ft_printerror(ERROR2));
    ft_check_start(&data, av[1]);
    ft_check_game(&data);
    freeMemory(&data);
    return(0);
}