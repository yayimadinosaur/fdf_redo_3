/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:06:47 by wfung             #+#    #+#             */
/*   Updated: 2017/07/11 18:38:23 by wfung            ###   ########.fr       */
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
#include <math.h>

#include <stdio.h>	//

typedef	struct			s_fdfstore
{
	char				*store;	//notsure what this is 4
//	char				**store_split;	//NOT NEEDED 
	int					**array_int;	//add pts struct?
	int					rot_x;
	int					rot_y;
	int					rot_z;
	int					shift_x;
	int					shift_y;
	int					shift_z;
	int					row;
	int					col;
}						t_fdfstore;

//values for the 3 pts; not sure if needed?
typedef struct			s_pts
{
	float					x;
	float					y;
	float					z;
}						t_pts;	//malloc for (**t_pts) row * col

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	int					win_x;
	int					win_y;
	int					center_x;
	int					center_y;
	int					start_x;
	int					start_y;
	int					end_x;
	int					end_y;
	int					h_gap;
	int					w_gap;
	int					gap1;
	t_pts				**pts;
}						t_env;

int			parse_fdf(char *str, char **av, t_fdfstore *store);

t_fdfstore	*create_struct1(void);
t_fdfstore	*create_struct(char **av);	//old
int			save_values(char **av, t_fdfstore *store);
void		array_int(char **result_str, int n, int *array);

t_env		*set_window(int n, t_fdfstore *store);

void		draw(void *mlx, void *win, t_env *e, t_fdfstore *store);
//ttest functions
void		print_array_int(int **array_int, t_fdfstore *store);

#endif
