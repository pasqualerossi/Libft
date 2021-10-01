/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:58:05 by prossi            #+#    #+#             */
/*   Updated: 2021/09/22 19:44:23 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function allocates memory and returns a 'fresh' string of characters
 * terminated with a '\0' that is the char equivalent of the int passed in
 * the parameter. Negative numbers should be managed as well. If the allocation
 * fails the function will return NULL. NOTE: This is a recursive function. If
 * you are unfamiliar with recursive functions it is a function which either
 * calls itself or is in a potential cycle of function calls. */

#include "libft.h"

static unsigned int	ft_numsize(int n)
{
	unsigned int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	unsigned int	len;

	len = ft_numsize(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}
