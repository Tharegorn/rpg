/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
**
*/

int my_atoi(char *s)
{
    int res = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        res += s[i] - 48;
        res *= 10;
    }
    res *= 0.1;
    return (res);
}
