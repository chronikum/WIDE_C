/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:08:43 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/15 11:10:13 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

int main(int argc,char *argv[])
{
	char *str;
	int i;
	int i2;
	char s = ' ';

	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		i2 = 0;
		while (i2 != (ft_strlen(str) * 2))
		{
			if (i2 % 2 == 0)
			{
				write(1, &str[i], 1);
				i++;
			}
			else
				write(1, &s, 1);
			i2++;
		}
		return (0);
	}
	return (1);
}