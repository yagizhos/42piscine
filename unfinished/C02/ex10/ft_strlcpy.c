/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 23:14:26 by yhos              #+#    #+#             */
/*   Updated: 2022/08/15 14:45:29 by yhos             ###   ########.fr       */
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

int main(void)
{
	char s1[100] = "";
	char s2[100];
	printf("%d\n", ft_strlcpy(s2, s1, 20));
}
