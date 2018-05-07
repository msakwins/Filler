/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:51:47 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/29 20:02:51 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		init(t_filler *fill, t_piece *piece)
{
	fill->loop = 0;
	fill->player = 0;
	fill->max_y = 0;
	fill->max_x = 0;
	fill->cur_y = 0;
	fill->cur_x = 0;
	fill->fd = 0;
	piece->max_y = 0;
	piece->max_x = 0;
}

void		free_tab_ints(int **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_memdel((void **)&tab[i++]);
	ft_memdel((void **)&tab);
}

void		parse_player(t_filler *fill, char *str)
{
	if (str[10] == '1')
		fill->player = 1;
	else if (str[10] == '2')
		fill->player = 2;
	else
		ft_putstr("bad player");
}

void		free_piece(t_piece *piece)
{
	int		i;

	i = 0;
	while (i < piece->max_y)
		free(piece->tab[i++]);
	free(piece->tab);
}
