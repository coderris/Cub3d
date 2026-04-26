/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 01:36:01 by lanton-m          #+#    #+#             */
/*   Updated: 2026/04/06 01:36:01 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while ((s1[index] != '\0' && s2[index] != '\0')
		&& s1[index] == s2[index])
	{
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}