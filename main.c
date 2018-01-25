/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:43:53 by tadey             #+#    #+#             */
/*   Updated: 2018/01/23 16:45:49 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{

    char *line = NULL;
    char *file;
    int fd;
    int result;

    result = 0;
    if (argc != 2)
    {
        printf("gg");
        return (0);
    }
    file = argv[1];
    fd = open (file, O_RDONLY);
    // ft_putnbr(fd);
    result = get_next_line(fd, &line);
    // ft_putstr(line);
    // ft_putnbr(result);
    // ft_putchar('\n');
    result = get_next_line(fd, &line);
    // ft_putstr(line);
    // ft_putnbr(result);
    // ft_putchar('\n');
    result = get_next_line(fd, &line);
    // ft_putstr(line);
    // ft_putnbr(result);
    // ft_putchar('\n');
    // result = get_next_line(fd, &line);
    // ft_putstr(line);
    // ft_putnbr(result);
    // // ft_putchar('\n');
    // get_next_line(fd, &line);z
    // if (*line)
    // {
    //     ft_putendl(line);
    //     ft_strdel(&line);
    // }
    // get_next_line(fd, &line);
    // if (*line)
    // {
    //     ft_putendl(line);
    //     ft_strdel(&line);
    // }
    close(fd);
    /*
    int fd;
    char *line;

    fd = 0;
	if (argc == 1)
        fd == 0;
    else if (argc == 2)
        fd = open(argv[1], O_RDONLY);
    else
        return (2);
    while (get_next_line(fd, &line) == 1)
    {
        ft_putendl(line);
        free(line);
    }
    if (argc == 2)
        close (fd);
    */
}
