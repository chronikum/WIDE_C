/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:08:43 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/15 12:11:54 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "gnl/get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				f;

	i = 0;
	f = 0;
	while (f == 0 && (i < n) && (n != 0))
	{
		if ((unsigned char) s1[i] == '\0'
			&& (unsigned char) s2[i] == '\0')
			return (f);
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
			f = 1;
		else if ((unsigned char) s1[i] < (unsigned char) s2[i])
			f = -1;
		i++;
	}
	return (f);
}


void ft_print_wide(char *c)
{
	int i;
	size_t i2;
	char s = ' ';

	i = 0;
	i2 = 0;
	while (i2 != (ft_strlen(c) * 2))
	{
		if (i2 % 2 == 0)
		{
			write(1, &c[i], 1);
			i++;
		}
		else
			write(1, &s, 1);
		i2++;
	}
}
/*
	Supply with file for file and text for text!
*/
int main(int argc,char *argv[])
{
	if (argc == 3)
	{
		if (ft_strncmp(argv[1], "text", 4) == 0)
		{
			ft_print_wide(argv[2]);
		}
		if (ft_strncmp(argv[1], "file", 4) == 0)
		{
			int fd = open(argv[2], O_RDONLY);
			char *c = malloc(sizeof(char) * 1000);
			while (get_next_line(fd, &c) != -1)
			{
				ft_print_wide(c);
				free(c);
			}
			write(1, "FILE", 4);
		}
		return (0);
	}
	return (1);
}