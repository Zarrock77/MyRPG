/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-miguel.da-silva-andrade-de-freitas
** File description:
** destroyer
*/

#include "team.h"
#include <stdlib.h>

void destroy_team(team_t *team)
{
    free(team);
}
