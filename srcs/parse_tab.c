/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:52:41 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/29 19:44:48 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			parse_size(t_filler *fill, char *str)
{
	int			i;
	char		*num;

	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	fill->max_y = ft_atoi(str + i);
	num = ft_itoa(fill->max_y);
	i += ft_strlen(num);
	fill->max_x = ft_atoi(str + i);
}

void			parse_board(t_filler *fill)
{
	int			i;
	char		*str;

	i = 0;
	if (fill->loop == 1)
	{
		if (!(fill->tab = (int **)malloc(sizeof(int *) * fill->max_y - 1)))
			return ;
	}
	while (i < fill->max_y)
	{
		get_next_line(0, &str);
		fill->tab[i] = parse_line(fill, str, i);
		if (fill->tab[i] == NULL)
			return ;
		i++;
		ft_strdel(&str);
	}
}

int				*parse_line(t_filler *fill, char *line, int index)
{
	int			*parsed_line;
	int			i;

	if (fill->loop == 1)
	{
		if (!(parsed_line = (int *)malloc(sizeof(int) * fill->max_x - 1)))
			return (NULL);
	}
	else
		parsed_line = fill->tab[index];
	i = 0;
	while (i < fill->max_x)
	{
		parsed_line[i] = parse_int(fill, line[i + 4]);
		i++;
	}
	return (parsed_line);
}

int				parse_int(t_filler *fill, char c)
{
	if (c == '*')
		return (1);
	else if (c == 'O' || c == 'o')
		return (fill->player == 1) ? 1 : 2;
	else if (c == 'X' || c == 'x')
		return (fill->player == 2) ? 1 : 2;
	return (0);
}
