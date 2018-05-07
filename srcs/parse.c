/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 00:04:17 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/29 20:02:17 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	clean_piece(t_piece *piece, t_trim *trim)
{
	int			x;
	int			y;

	y = 0;
	trim->clean_min_x = P->max_x;
	trim->clean_min_y = P->max_y;
	trim->clean_max_x = 0;
	trim->clean_max_y = 0;
	while (y < P->max_y)
	{
		x = -1;
		while (++x < P->max_x)
			if (P->tab[y][x])
			{
				T->clean_min_x = (x <= T->clean_min_x) ? x : T->clean_min_x;
				T->clean_min_y = (y <= T->clean_min_y) ? y : T->clean_min_y;
				T->clean_max_x = (x >= T->clean_max_x) ? x : T->clean_max_x;
				T->clean_max_y = (y >= T->clean_max_y) ? y : T->clean_max_y;
			}
		y++;
	}
	trim->max_x = trim->clean_max_x - trim->clean_min_x + 1;
	trim->max_y = trim->clean_max_y - trim->clean_min_y + 1;
}

void	trim_piece(t_piece *piece, t_trim *trim)
{
	int			y;
	int			x;

	clean_piece(piece, trim);
	if (!(T->tab = (int **)malloc(sizeof(int *) * T->max_y - 1)))
		return ;
	y = trim->clean_min_y;
	while (y <= trim->clean_max_y)
	{
		x = trim->clean_min_x;
		T->tab[y - T->clean_min_y] = (int *)malloc(sizeof(int) * T->max_x - 1);
		while (x <= trim->clean_max_x)
		{
			trim->tab[y - trim->clean_min_y][x - trim->clean_min_x] = 0;
			if (P->tab[y][x])
			{
				trim->tab[y - trim->clean_min_y][x - trim->clean_min_x] = 1;
			}
			x++;
		}
		y++;
	}
}

void	size_piece(t_piece *piece, char *str)
{
	int			i;
	char		*num;

	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	piece->max_y = ft_atoi(str + i);
	num = ft_itoa(piece->max_y);
	i += ft_strlen(num);
	free(num);
	piece->max_x = ft_atoi(str + i);
}

void	parse_piece(t_filler *fill, t_piece *piece, char *line, t_trim *trim)
{
	int			i;
	char		*str;

	i = 0;
	if (!(piece->max_y == 0 && piece->max_x == 0))
	{
		free_piece(piece);
	}
	size_piece(piece, line);
	if (!(piece->tab = (int **)malloc(sizeof(int *) * piece->max_y - 1)))
		return ;
	while (i < piece->max_y)
	{
		get_next_line(0, &str);
		piece->tab[i] = parse_piece_line(fill, piece, str);
		ft_strdel(&str);
		if (piece->tab[i] == NULL)
			return ;
		i++;
	}
	trim_piece(piece, trim);
}

int		*parse_piece_line(t_filler *fill, t_piece *piece, char *line)
{
	int			*parsed_line;
	int			i;

	if (!(parsed_line = (int *)malloc(sizeof(int) * piece->max_x - 1)))
		return (NULL);
	i = 0;
	while (i < piece->max_x)
	{
		parsed_line[i] = parse_int(fill, line[i]);
		i++;
	}
	return (parsed_line);
}
