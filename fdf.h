/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:06:47 by wfung             #+#    #+#             */
/*   Updated: 2017/07/01 17:34:29 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__

#include <unistd.h> 
#include <stdlib.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "minilibx_macos/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

typedef	struct			s_fdfstore
{
	char				*store;	//notsure what this is 4
	char				**store_strsplit;	//needed?
	int					**array_int;	//pts
	int					rot_x;
	int					rot_y;
	int					rot_z;
	int					shift_x;
	int					shift_y;
	int					shift_z;
}						t_fdfstore;

typedef struct			s_pts
{
	int					x;
	int					y;
	int					z;
}						t_pts;

int			parse_fdf(char *str, char **av);
t_fdfstore	*create_struct(char *str, char **av);

#endif
