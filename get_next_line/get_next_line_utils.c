/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emok <emok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:58:48 by emok              #+#    #+#             */
/*   Updated: 2024/01/05 15:41:40 by emok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	count_end_point(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*return_str;
	int		i;

	i = 0;
	return_str = 0;
	return_str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (return_str == 0)
		return (0);
	while (str1 != 0 && *str1 != '\0')
	{
		return_str[i] = (*str1);
		i++;
		str1++;
	}
	while (str2 != 0 && *str2 != '\0')
	{
		return_str[i] = (*str2);
		i++;
		str2++;
	}
	return_str[i] = '\0';
	return (return_str);
}

void	clean_buff(int count, char *buff)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		buff[i] = '\0';
		i++;
	}
}

char	*make_substr(int start, int end, char *str)
{
	char	*substr;
	int		i;

	i = 0;
	substr = 0;
	substr = (char *)malloc(end - start + 2);
	if (substr == 0)
		return (0);
	while (start <= end)
	{
		substr[i] = str[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
