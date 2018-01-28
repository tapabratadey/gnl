/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:44:22 by tadey             #+#    #+#             */
/*   Updated: 2018/01/27 20:56:52 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*cut_string(char **arr, int fd)
{
	// ft_putendl("do you even");
	int i;
	char *new_line;
	char	*array;
	char *new_fd_arr;

	i = 0;

	//if arr[fd] has no newline but is also not empty
	if (ft_strchr(arr[fd], '\n') == 0 && ft_strlen(arr[fd]) != 0)
	{
		new_line = ft_strjoin(arr[fd], "\n");	
		ft_strdel(&arr[fd]);
		arr[fd] = new_line;
		// ft_putstr("whyudis");
	}
	// return (new_line);
	
		
	array = arr[fd];

	// ft_putstr("i am: \n");
	// ft_putstr(array);
	// ft_putstr("\n");

	//find the length of the first line
	while (array[i] && array[i] != '\n')
		i++;

	// ft_putstr("this is how i look:\n");
	// ft_putstr(arr[fd]);
	
	// ft_putstr("my size is: \n");
	// ft_putnbr(i);


	//allocate space for that string.
	new_line = ft_strnew(i);

	//copy the string into my new string
	ft_strncpy(new_line, array, i);

	
	// ft_putstr("\ni am before arr[fd] now: \n");
	// ft_putstr(new_line);

	// ft_putstr("\n");
	

	//null terminate the string
	// new_line[i] = '\0';

	//creating space after the line we want to return in our next call
	if (ft_strchr(arr[fd], '\n') != 0)
		new_fd_arr = ft_strdup(ft_strchr(arr[fd], '\n') + 1);
	else
		return (ft_strdup(""));
	// ft_putendl(new_line);
	//delete line from static array
	if (arr[fd] != 0)
		ft_strdel(&arr[fd]);
	
	// ft_putendl("\ndeleted");

	//reassigning static array to the new static arrays
	arr[fd] = new_fd_arr;
	
	
	return (new_line);
}

//func fills static array. takes in array and fd
int    fill_arr(char **arr, int fd)
{
	
    char buff[BUFF_SIZE + 1]; //buff array w size of BUFF_SIZE + 1 for '\0'
    int read_ret;//var to store reads ret
    char *store; //var to temp store content from static array

    read_ret = 0;//init read_ret to 0
	
    //loop to read each byte
    while ((read_ret = read(fd, buff, BUFF_SIZE)))
    {
		//null terminating my buff
        buff[read_ret] = '\0';
        
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
	
	//if my read_ret is 0 and my static array is empty then exit
	if (read_ret == 0 && (arr[fd]) == 0)
			return (0);
	return (1);
}

//param 1- file descriptor that will be used to read.
//param 2 - **line is the address of a pointer to a char that will be used
//..to save the line read from the file descriptor
int get_next_line(int const fd, char **line)
{
	char buff[BUFF_SIZE + 1]; //buff array w size of BUFF_SIZE + 1 for '\0'
	static char *arr[FD_LIMIT]; //static arr w size of FD_LIMIT
	int ret_fill_arr;

	//error handling
    if (line == NULL || fd < 0 || read(fd, buff, 0) < 0 || fd > FD_LIMIT)
        return (-1);
	
	//if my static array is empty then it'll be filled
	if ((ret_fill_arr = fill_arr(arr, fd)) == 0)
	{
		*line = "";
		return (0);
	}

	//calling cut_string. pointing line to it.
	*line = cut_string(arr, fd);
	// ft_putstr(*line);
	//if my line exists then return 1 else 0.
	// ft_putstr("heybabe");
	// ft_putstr(*line);
	// ft_putstr("hello");
	// ft_putnbr(ret_fill_arr);
	if (ret_fill_arr)
	{
		// ft_putendl("fucku");
		return (1);		
	}		
	return (0);
}
