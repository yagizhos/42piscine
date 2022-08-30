/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:59:20 by yhos              #+#    #+#             */
/*   Updated: 2022/08/16 17:21:30 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*to_find == *str)
		{
			i = 0;
			while (to_find[i] != '\0')
			{
				if (to_find[i] != str[i])
					break ;
				else
					i++;
			}
			if (to_find[i] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
