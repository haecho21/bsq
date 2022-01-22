/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwlee <siwlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:56:51 by siwlee            #+#    #+#             */
/*   Updated: 2022/01/21 22:03:25 by siwlee           ###   ########.fr       */
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
	int	height;
	int	width;
	t_rec	**map;

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
		map_init(height, width, map);
		printf("row: %d\nsign:%s\n", row, sign);
	}
	free(map[0]);
	free(map);
}

void	**map_init(int height, int width, t_rec **map)
{
	int	i;

	map = (t_rec **)malloc(sizeof(t_rec *) * (height + 1));
	if (!map)
		return (0);
	map[0] = (t_rec *)malloc(sizeof(t_rec) * (width + 1) * (height + 1));
	if (!map[0])
		return (0);
	i = 0;
	while (++i < height + 1){
		map[i] = map[i-1] + width;
	}
	i = -1;
	while (++i < width + 1)
	{
		map[0][i].row = 0;
		map[0][i].col = 0;
	}
	i = 0;
	while (++i < height + 1)
	{
		map[i][0].row = 0;
		map[i][0].col = 0;
	}
	return (map);
}

