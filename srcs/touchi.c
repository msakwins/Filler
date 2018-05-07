/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touchi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 19:40:24 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/29 18:56:39 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				ft_abs(int a)
{
	return (a < 0) ? -a : a;
}

static int		choo_dist(t_filler *fill, int y, int x)
{
	int			map_x;
	int			map_y;
	int			min_dist_from_enemy;
	int			tmp;

	map_y = 0;
	min_dist_from_enemy = -1;
	while (map_y < fill->max_y)
	{
		map_x = 0;
		while (map_x < fill->max_x)
		{
			if (fill->tab[map_y][map_x] == 2)
			{
				tmp = ft_abs(map_y - y) + ft_abs(map_x - x);
				if (min_dist_from_enemy == -1 || tmp < min_dist_from_enemy)
					min_dist_from_enemy = tmp;
			}
			map_x++;
		}
		map_y++;
	}
	return (min_dist_from_enemy);
}

int				find_place(t_filler *fill, t_trim *trim)
{
	int			touchi;

	touchi = 0;
	T->cur_y = 0;
	while (T->cur_y < T->max_y)
	{
		T->cur_x = 0;
		while (T->cur_x < T->max_x)
		{
			if (T->tab[T->cur_y][T->cur_x])
			{
				if (F->tab[F->cur_y + T->cur_y][F->cur_x + T->cur_x] == 1)
					touchi++;
				if (F->tab[F->cur_y + T->cur_y][F->cur_x + T->cur_x] == 2)
					touchi += 2;
			}
			T->cur_x++;
		}
		T->cur_y++;
	}
	return ((touchi == 1) ? 1 : 0);
}

int				play_game(t_filler *fill, t_piece *piece, t_trim *trim)
{
	int			tmpdist;

	piece->choo_y = 0;
	piece->choo_x = 0;
	piece->dist = -1;
	fill->cur_y = 0;
	while (fill->cur_y++ < fill->max_y - T->max_y)
	{
		fill->cur_x = 0;
		while (fill->cur_x++ < fill->max_x - T->max_x)
			if (find_place(fill, trim))
			{
				tmpdist = choo_dist(fill, fill->cur_y, fill->cur_x);
				if (tmpdist < piece->dist || piece->dist == -1)
				{
					piece->choo_y = fill->cur_y - trim->clean_min_y;
					piece->choo_x = fill->cur_x - trim->clean_min_x;
					piece->dist = tmpdist;
				}
			}
	}
	return_value(piece->choo_y, piece->choo_x);
	return (0);
}
