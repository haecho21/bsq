/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   every.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwlee <siwlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:09:20 by siwlee            #+#    #+#             */
/*   Updated: 2022/01/21 22:56:20 by siwlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	__EVERY_H__
 #define __EVERY_H__

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_rectangle {
	int	row;
	int	col;
}t_rec;

int     rectangle(int height, int width, int fd, t_rec **map, int *sign);



#endif
