/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:09:52 by mchemakh          #+#    #+#             */
/*   Updated: 2017/01/12 19:57:44 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 32

# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct	s_line
{
	struct s_line	*next;
	char			*str;
	int				fd;
}				t_line;

int				get_next_line(const int fd, char **line);

#endif
