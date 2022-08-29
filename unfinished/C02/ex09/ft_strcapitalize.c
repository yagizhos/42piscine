/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhos <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:53:41 by yhos              #+#    #+#             */
/*   Updated: 2022/08/15 11:40:09 by yhos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanum(char c)
{
	if (!((c > 64 && c < 91) || (c > 96 && c < 123) || (c > 47 && c < 58)))
		return (0);
	return (1);
}

void	change_char(int i, char *c)
{
	if (i == 1)
		*c += 32;
	else if (i == 2)
		*c -= 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	change_char(2, &str[0]);
	while (str[i++] != '\0')
	{
		if ((is_alphanum(str[i + 1]) == 1) && (is_alphanum(str[i]) == 0))
		{
			if (!(str[i + 1] > 47 && str[i + 1] < 58))
				change_char(2, &str[i + 1]);
		}
		else if ((is_alphanum(str[i + 1]) == 1) && (is_alphanum(str[i]) == 1))
		{
			if (str[i + 1] > 64 && str[i + 1] < 91)
				change_char(1, &str[i + 1]);
		}
	}
	return (str);
}
