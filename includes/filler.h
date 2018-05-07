/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:36:55 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/29 20:03:05 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define P1 'O'
# define P2 'X'
# define P piece
# define F fill
# define T trim

typedef struct	s_trim
{
	int			**tab;
	int			max_x;
	int			max_y;
	int			cur_x;
	int			cur_y;
	int			clean_min_x;
	int			clean_min_y;
	int			clean_max_x;
	int			clean_max_y;
}				t_trim;

typedef struct	s_piece
{
	int			**tab;
	int			max_x;
	int			max_y;
	int			choo_y;
	int			choo_x;
	int			dist;
}				t_piece;

typedef struct	s_filler
{
	int			loop;
	int			**tab;
	int			cur_y;
	int			cur_x;
	int			max_x;
	int			max_y;
	int			fd;
	int			player;
}				t_filler;

int				get_next_line(int const fd, char **line);
void			parse_player(t_filler *fill, char *str);
void			init(t_filler *fill, t_piece *piece);
void			parse_size(t_filler *fill, char *str);
void			parse_board(t_filler *fill);
int				*parse_line(t_filler *fill, char *line, int index);
void			parse_piece(t_filler *fill, t_piece *piece, char *line,
		t_trim *trim);
void			trim_piece(t_piece *piece, t_trim *trim);
void			clean_piece(t_piece *piece, t_trim *trim);
int				*parse_piece_line(t_filler *fill, t_piece *piece, char *line);
int				parse_int(t_filler *fill, char c);
void			size_piece(t_piece *piece, char *str);
void			parsing_map(t_piece *piece, t_filler *fill, char *line);
void			return_value(int choo_y, int choo_x);
void			write_log(t_filler *fill, t_piece *piece);
int				play_game(t_filler *fill, t_piece *piece, t_trim *trim);
int				find_place(t_filler *fill, t_trim *trim);
void			free_piece(t_piece *piece);

#endif
