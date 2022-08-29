/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 23:14:26 by yhos              #+#    #+#             */
/*   Updated: 2022/08/15 12:28:55 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0u;
	while (src[i] != '\0')
	{
		if (i < size - 1)
			dest[i] = src[i];
		i++;
	}
	dest[size - 1] = '\0';
	printf("%s\n", dest);
	return (i);
}

int	main(void)
{
	char s[20] = "abcdefg";
	char a[9];
	printf("%d\n", ft_strlcpy(a, s, 6));
}
