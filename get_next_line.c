/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:44:22 by tadey             #+#    #+#             */
/*   Updated: 2018/01/23 16:55:36 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*cut_string(char **arr, int fd)
{
	int i;
	char *new_line;
	char	*array;
	char *new_fd_arr;
	array = *arr;
	i = 0;
	
	if (ft_strlen(*arr) == 0)
		return (0);
	//if arr[fd] has no newline but is also not empty
	else if (ft_strchr(*arr, '\n') == 0 && ft_strlen(*arr) != 0)
	{
		new_line = ft_strjoin(*arr, "\n");
		ft_strdel(arr);
		*arr = new_line;
	}
	//  printf("%s", new_line);
	return (new_line);

	//find the length of the first line
	while (array[i] && array[i] != '\n')
		i++;
	
	//allocate space for that string.
	new_line = ft_strnew(i);
	
	//copy the string into my new string
	ft_strncpy(new_line, array, i);

	// //null terminate the string
	// new_line[i] = '\0';

	//creating space after the line we want to return in our next call
	new_fd_arr = ft_strdup(ft_strchr(*arr, '\n') + 1);

	//delete line from static array
	ft_strdel(arr);

	//reassigning static array to the new static arrays
	*arr = new_fd_arr;

	
	return (new_line);
	// printf("hahah %s", new_line);
}

//func fills static array. takes in array and fd
void    fill_arr(char **arr, int fd, char **line)
{
    char buff[BUFF_SIZE + 1]; //buff array w size of BUFF_SIZE + 1 for '\0'
    int read_ret;//var to store reads ret
    char *store; //var to temp store content from static array

    read_ret = 0;//init read_ret to 0

    //loop to read each byte
    while ((read_ret = read(fd, buff, BUFF_SIZE)))
    {
        // buff[read_ret] = '\0';//null terminating my buff
        //checking if my static array is empty
        //if it is then alloc same space as my buff and send it's content
        //if it already has content then store that into a temp arr
        //..then join the pre-existing content with my content from the buff
        //..then free the temp content.
        if (arr[fd] == 0)
            arr[fd] = ft_strdup(buff);
		else
		{
			store = arr[fd];
			arr[fd] = ft_strjoin(arr[fd], buff);
			free(store);
		}
    }
}

//param 1- file descriptor that will be used to read.
//param 2 - **line is the address of a pointer to a char that will be used
//..to save the line read from the file descriptor
int get_next_line(int const fd, char **line)
{
	char buff[BUFF_SIZE + 1]; //buff array w size of BUFF_SIZE + 1 for '\0'
	static char *arr[FD_LIMIT]; //static arr w size of FD_LIMIT
	
	//error handling
    if (line == NULL || fd < 0 || read(fd, buff, 0) < 0 || fd > FD_LIMIT)
        return (-1);
	if (arr[fd] == 0)
		fill_arr(arr, fd, line);    
	*line = cut_string(&arr[fd], fd);
	if (**line)
		return (1);
	return (0);
}