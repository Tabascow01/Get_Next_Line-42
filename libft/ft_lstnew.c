/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:05:10 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/22 15:27:21 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;
	void	*newdata;

	if ((newdata = (void *)ft_memalloc(sizeof(content_size + 1))) == NULL)
		return (0);
	if (content == NULL)
	{
		newdata = NULL;
		content_size = 0;
	}
	else
		ft_memcpy(newdata, content, content_size);
	if ((newlst = (t_list *)ft_memalloc(sizeof(t_list))) == NULL)
		return (0);
	newlst->content = newdata;
	newlst->content_size = content_size;
	newlst->next = NULL;
	return (newlst);
}
