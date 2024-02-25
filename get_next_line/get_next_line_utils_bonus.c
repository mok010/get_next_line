/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emok <emok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:12:36 by emok              #+#    #+#             */
/*   Updated: 2024/01/12 18:25:21 by emok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str, int sign)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	if (sign == 0)
	{
		while (str[i] != '\0')
			i++;
	}
	else
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*return_str;
	int		i;

	i = 0;
	return_str = 0;
	return_str = (char *)malloc(ft_strlen(str1, 0) + ft_strlen(str2, 0) + 1);
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

t_list	*ft_newdel(char **line, t_list *target, t_list **head)
{
	if (line != 0)
	{
		if ((*line) != 0)
			free((*line));
		(*line) = 0;
	}
	if (target == 0 || *head == 0)
		return (0);
	if (target->front == 0)
	{
		if (target->back != 0)
			target->back->front = 0;
		*head = target->back;
	}
	else
	{
		if (target->back != 0)
			target->back->front = target->front;
		target->front->back = target->back;
	}
	if ((target->storage) != 0)
		free(target->storage);
	free(target);
	return (0);
}

t_list	*lst_add(t_list **lst, int fd)
{
	t_list	*tmp;
	t_list	*result;

	result = 0;
	result = (t_list *)malloc(sizeof(t_list));
	if (result == 0)
		return (0);
	result->storage = 0;
	result->fd = fd;
	result->back = 0;
	result->front = 0;
	tmp = (*lst);
	if (*lst == 0 || lst == 0)
	{
		(*lst) = result;
		return (result);
	}
	while (((tmp->back) != 0))
		tmp = tmp->back;
	(tmp->back) = result;
	(result->front) = tmp;
	(result->back) = 0;
	return (result);
}
