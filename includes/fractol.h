/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:21:09 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/23 14:02:01 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdio.h>
# include <mlx.h>

# define WIDTH		500
# define HEIGHT		400

typedef struct s_env	t_env;
typedef struct s_img	t_img;
typedef struct s_plex	t_plex;

struct				s_plex
{
	int		re;
	int		im;
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
};

int			key_hook(int keycode, t_env *env);
int			expose_hook(t_env *env);
void		ft_put_pixel_to_image(t_env *env, int y, int x, int color);

#endif

