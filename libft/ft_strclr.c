/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:16:14 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 21:57:53 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_strclr(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
}
