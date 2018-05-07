/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:50:07 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/29 15:35:13 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		still_full(char **full, char **line)
{
	char			*tmp;
	char			*tmp2;

	if ((tmp = ft_strchr_mod(*full, '\n')))
	{
		*tmp = '\0';
		tmp++;
		*line = ft_strdup(*full);
		tmp2 = ft_strdup(tmp);
		ft_strdel(full);
		*full = ft_strdup(tmp2);
		ft_strdel(&tmp2);
		return (1);
	}
	if (!(tmp = ft_strchr_mod(*full, '\n')) && (ft_strlen(*full) > 0))
	{
		*line = ft_strdup(*full);
		ft_strclr(*full);
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*full[MAX_FD];
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1 || fd > MAX_FD)
		return (-1);
	while (!(ft_strchr_mod(full[fd], '\n')) &&
					((ret = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[ret] = '\0';
		full[fd] = ft_strjoin_mod(full[fd], buff);
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && !(full[fd]))
		return (0);
	if (still_full(&full[fd], line))
		return (1);
	return (0);
}
