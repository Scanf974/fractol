/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 13:30:09 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/23 13:31:02 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		expose_hook(t_env *env)
{
	(void)env;
	//mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
	return (0);
}
