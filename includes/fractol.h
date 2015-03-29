/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:21:09 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/30 00:00:17 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <myx.h>
# include <stdio.h>
# include <mlx.h>

# define WIDTH		500
# define HEIGHT		400
# define ESP		53
# define PLUS		24

typedef struct s_env	t_env;
typedef struct s_img	t_img;
typedef struct s_plex	t_plex;
typedef struct s_frac	t_frac;

struct				s_frac
{
	double	lim_x1;
	double	lim_x2;
	double	lim_y1;
	double	lim_y2;
	double	zoom_x;
	double	zoom_y;
	double	image_x;
	double	image_y;
	int		iteration_max;
};

struct				s_plex
{
	double		re;
	double		im;
};

struct				s_img
{
	void	*ptr;
	char	*char_img;
	int		bpp;
	int		size_line;
	int		endian;
};

struct				s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_frac	mandel;
	double	zoom;
};

int			key_hook(int keycode, t_env *env);
int			expose_hook(t_env *env);
int			pointer_motion_hook(int x, int y, t_env *env);
void		ft_put_pixel_to_image(t_env *env, int y, int x, int color);
void		ft_draw(t_env *env, char *name);
void		ft_mandelbrot(t_env *env);

#endif

