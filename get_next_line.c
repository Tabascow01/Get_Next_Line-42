/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:04:54 by mchemakh          #+#    #+#             */
/*   Updated: 2017/01/12 18:50:36 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

/*
**	re-arrange lst->str (cut copied line)
*/

void	ft_cut_str(t_line **lst, char *newstr)
{
	int		j;
	char	*tmp;
	size_t	size;
	char	*c;

	size = ft_strlen(newstr);
	tmp = NULL;
	if (((*lst)->str[size] == '\n' || (*lst)->str[size + 1] != '\0'))
		size++;
	j = 0;
	if ((*lst)->str[0] == '\n' && (*lst)->str[1] == '\0')
		return ;
	if (size > 0)
	{
		tmp = ft_strnew((ft_strlen((*lst)->str) - size) + 1);
		while ((*lst)->str[size] != '\0')
		{
			tmp[j++] = (*lst)->str[size];
			size++;
		}
		tmp[j] = '\0';
		c = (*lst)->str;
		(*lst)->str = ft_realloc(tmp, 1);
		ft_strdel(&c);
	}
}

/*
** Concatenate buf in lst->str
*/

void	ft_memcat(t_line **lst, char *buf, int sizeread)
{
	int	i;

	i = 0;
	if (sizeread == 0)
	{
		while (buf[i])
		{
			if (buf[i] == '\n' && buf[i + 1] == '\0')
				buf[i] = '\0';
			i++;
		}
	}
	(*lst)->str = ft_realloc((*lst)->str, ft_strlen(buf) + 1);
	if (buf[0] != '\0')
		(*lst)->str = ft_strcat((*lst)->str, buf);
	ft_bzero(buf, ft_strlen(buf) + 1);
}

/*
** Copy line from fd
*/

char	*ft_get_line(t_line *lst, char *buf, int sizeread)
{
	int		i;
	char	*newstr;
	int		size;

	size = 0;
	newstr = NULL;
	i = 0;
	if (ft_strlen(buf) > 0)
		ft_memcat(&lst, buf, sizeread);
	while ((lst->str[size] != '\n' && lst->str[size] != '\0'))
		size++;
	newstr = ft_strnew(size);
	while (lst->str[i] != '\n' && lst->str[i] != '\0')
	{
		newstr[i] = lst->str[i];
		i++;
	}
	newstr[i] = '\0';
	if (ft_strlen(lst->str) > 0)
		ft_cut_str(&lst, newstr);
	ft_strdel(&buf);
	return (newstr);
}

/*
**  Get next line of file
*/

int		get_next_line(const int fd, char **line)
{
	static t_line	*lst;
	int				sizeread;
	char			*buf;
	int				size;

	if (fd < 0)
		return (-1);
	if (lst == NULL)
	{
		lst = (t_line *)malloc(sizeof(t_line));
		lst->fd = fd;
		lst->str = NULL;
		lst->next = NULL;
	}
	if (lst->str == NULL)
		lst->str = (char *)ft_memalloc(BUFFER_SIZE + 1);
	size = 0;
	sizeread = 0;
	buf = (char *)ft_memalloc(BUFFER_SIZE + 1);
	while ((sizeread = read(fd, buf + size, BUFFER_SIZE)) &&
			(ft_strchr(buf + size, '\n') == 0))
	{
		if (sizeread == -1)
			return (-1);
		size += sizeread;
		buf = ft_realloc(buf, sizeread);
	}
	if (sizeread > 0)
	{
		size += sizeread;
		buf = ft_realloc(buf, sizeread);
	}
	buf[size] = '\0';
	*line = ft_get_line(lst, buf, sizeread);
	if (ft_strlen(lst->str) != 0 || sizeread != 0 || *line[0] != '\0')
	{
		if (sizeread > 0)
			size--;
		if (lst->str[0] == '\n' && lst->str[1] == '\0' && size == 0)
			lst->str[0] = '\0';
		return (1);
	}
	return (0);
}
