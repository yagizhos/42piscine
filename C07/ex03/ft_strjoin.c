/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:04:54 by yhos              #+#    #+#             */
/*   Updated: 2022/08/30 12:26:48 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	find_final_size(int size, char **strs, char *sep)
{
	int	final_size;
	int	i;

	final_size = 0;
	i = 0;
	while (i < size)
		final_size += ft_strlen(strs[i++]) + ft_strlen(sep);
	if (size > 0)
		final_size -= ft_strlen(sep);
	return (final_size);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*r;
	int		i;
	int		fs;

	i = 0;
	fs = find_final_size(size, strs, sep);
	r = malloc(sizeof(char) * (fs + 1));
	if (r == NULL)
		return (0);
	r[0] = '\0';
	if (size == 0)
		return (r);
	while (i < size)
	{
		ft_strcat(r, strs[i]);
		if (i < size - 1)
			ft_strcat(r, sep);
		i++;
	}
	r[ft_strlen(r)] = '\0';
	return (r);
}
/*
int main()
{
	char *s[100] = {"hocxzzxczxc", "hisdfsd", "goqqweqwe"};
	char sep[100] = "/    /";
	char *r = ft_strjoin(3, s, sep);
	printf("%s\n", r);
	free(r);
}*/
