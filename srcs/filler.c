/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:36:55 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/29 20:03:29 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			parsing_map(t_piece *piece, t_filler *fill, char *line)
{
	t_trim		*trim;

	if (!(trim = malloc(sizeof(t_trim))))
		return ;
	clean_piece(piece, trim);
	fill->loop += 1;
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau") != NULL)
	{
		if (fill->loop == 1)
			parse_size(fill, line);
		ft_strdel(&line);
		get_next_line(0, &line);
		ft_strdel(&line);
		parse_board(fill);
		get_next_line(0, &line);
		parse_piece(fill, piece, line, trim);
		ft_strdel(&line);
		play_game(fill, piece, trim);
	}
	else
		ft_putstr("0, 0");
}

void			return_value(int choo_y, int choo_x)
{
	ft_putnbr(choo_y);
	ft_putchar(' ');
	ft_putnbr(choo_x);
	ft_putchar('\n');
}

int				main(void)
{
	t_filler	*fill;
	t_piece		*piece;
	char		*line;
	int			i;

	i = 0;
	if (!(fill = malloc(sizeof(t_filler))))
		return (0);
	if (!(piece = malloc(sizeof(t_piece))))
		return (0);
	init(fill, piece);
	get_next_line(0, &line);
	if (line[10])
		parse_player(fill, line);
	while (1)
		parsing_map(piece, fill, line);
	free(fill);
	free(piece);
	return (0);
}
