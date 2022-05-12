/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:17:15 by jnicolas          #+#    #+#             */
/*   Updated: 2022/05/10 23:39:37 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx_sample.h"

void	init_map(t_data *data)
{
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = ((ft_strlen(data->map.map[0]) - 1) * IMG_SIZE);
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
}
