/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** main
*/

#include "../include/malloc.h"
#include <unistd.h>
#include <string.h>

int main(void)
{
    char *str2 = malloc(sizeof(char) * 2);
    str2 = strcpy(str2, "y");
    printf("|%s|\t\t%p\n", str2, str2);
    free(str2);
    char *str4 = malloc(sizeof(char) * 10);
    str4 = strcpy(str4, "accccccca");
    printf("|%s|\t%p\n", str4, str4);
    char *str5 = malloc(sizeof(char) * 10);
    str5 = strcpy(str5, "bcccccccb");
    printf("|%s|\t%p\n", str5, str5);
    char *str6 = malloc(sizeof(char) * 10);
    str6 = strcpy(str6, "ccccccccc");
    printf("|%s|\t%p\n", str6, str6);
    char *str7 = malloc(sizeof(char) * 10);
    str7 = strcpy(str7, "dcccccccd");
    printf("|%s|\t%p\n", str7, str7);
    char *str8 = malloc(sizeof(char) * 10);
    str8 = strcpy(str8, "eccccccce");
    printf("|%s|\t%p\n", str8, str8);
    return (0);
}