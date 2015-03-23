/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_motion_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 23:45:05 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/23 23:46:15 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		pointer_motion_hook(int x, int y, t_env *env)
{
	env = env;
	dprintf(1, "%d %d\n", x, y);
}
