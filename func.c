#include "every.h"

int	fill_map(int height, int width, int fd, t_rec **map, int *sign)
{
	int	r;
	int	c;
	int	max[3];
	char	temp;

	i = r;
	while (++r <= height)
	{
		c = 0;
		while (++c <= width)
		{
			read(fd, &temp, 1);
			if ((temp == "\n" && c != width)
			|| (fill_cell(map, r, c, sign, temp, max)))
				return (1);
		}
	}
	return (0);
}

int	fill_cell(t_rec **map, int r, int c, int *sign, char temp)
{
	if (temp == sign[1])
	{
		map[r][c].row = 0;
		map[r][c].col = 0;
	}
	else if (temp == sign[0])
	{
		map[r][c].row = map[r-1][c] + 1;
		map[r][c].col = map[r][c-1] + 1;
	}
	else
		return (1);
	if (max[2] < (map[r][c].row * map[r][c].col))
	{
		max[0] = r;
		max[1] = c;
		max[2] = (map[r][c].row * map[r][c].col);
	}
	return (0);
}

/* 0  1  r = 0 c = 1
** 2  3 
*/
int	check_vertex(int fd, int *max, int *sign)
{
	int	sq[4][2];
	int	r;
	int	c;

	sq[3][0] = max[0];
	sq[3][1] = max[1];
	r = map[max[0]][max[1]].row;
	c = map[max[0]][max[1]].col;
	sq[0][0] = r - max[0] + 1;
	sq[0][1] = c - max[1] + 1;
	sq[1][0] = r;
	sq[1][1] = c - max[1] + 1;
	sq[2][0] = r - max[0] + 1;
	sq[2][1] = c;
}

//int	fill_map(int fd, int **sq, int *sign)
//{

