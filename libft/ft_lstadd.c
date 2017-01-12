/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:00:27 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/22 15:29:05 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *newlst)
{
	if (newlst != NULL)
	{
		if (*alst == NULL)
			*alst = newlst;
		newlst->next = *alst;
		*alst = newlst;
	}
}
