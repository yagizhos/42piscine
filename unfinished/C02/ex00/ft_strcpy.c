/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:32:00 by yhos              #+#    #+#             */
/*   Updated: 2022/08/12 12:18:29 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *star);

char	*ft_strcpy(char *dest, char *src)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	while (str[l])
		l++;
	while (i < l)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
