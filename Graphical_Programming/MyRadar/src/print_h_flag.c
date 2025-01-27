/*
** EPITECH PROJECT, 2025
** B-MUL-100-STG-1-1-myradar-adrien.raphanaud
** File description:
** print_h_flag
*/

#include "my.h"


void print_h(void)
{
    my_putstr(1, "Air Traffic Simulation Panel\n"
                "USAGE\n"
                "  ./my_radar path_to_script\n"
                "  \"path_to_script\" = Path to the script file.\n"
                "OPTIONS\n"
                "  -h                 Print the usage instructions and exit.\n"
                "USER INTERACTIONS\n"
                "  'L' key       Enable/disable hitboxes and areas.\n"
                "  'S' key       Enable/disable sprites.\n"
                "  'D' key       Speed up the game's execution.\n"
                "  'F' key       Slow down the game's execution.\n"
                "  'P' key       Scale up the plane sprite.\n"
                "  'O' key       Scale down the plane sprite.\n"
    );
}

int should_return(int ac, char **av)
{
    if (ac != 2) {
        my_putstr(2, "File path is missing, try \"./my_radar -h\""
        " for usage indications. \n");
        return 84;
    }
    if (my_strcmp(av[1], "-h") == 0) {
        print_h();
        return 0;
    }
    return 1;
}
