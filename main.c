/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwlee <siwlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:56:51 by siwlee            #+#    #+#             */
/*   Updated: 2022/01/21 20:12:24 by siwlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "every.h"
#include <stdio.h>
int	main(void)
{
	int	fd;
	int	i;
	char	temp;
	char	sign[3];
	int	row;
	char	**map;

	i = 0;
	row = 0;
	fd = open("./map.txt", O_RDONLY);
	if (fd <= 0)
	{
		write(1, "Error\n",6);
		return (1);
	}
	else
	{
		while (1)
		{
			read(fd, &temp, 1);
			if (temp == '\n')
				break;
			else if ((temp >= '0') && (temp <= '9'))
				row = 10 * row + temp - 48;
			else
			{
				sign[i] = temp;
				i++;
			}
		}
		map = (char **)malloc(sizeof(map) * row);
		printf("row: %d\nsign:%s\n", row, sign);
	}
	free(map);
}
