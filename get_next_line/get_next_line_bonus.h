/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emok <emok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:15:25 by emok              #+#    #+#             */
/*   Updated: 2024/01/12 18:27:31 by emok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*storage;
	struct s_list	*front;
	struct s_list	*back;
}	t_list;

int		ft_strlen(char *str, int sign);
char	*ft_strjoin(char *str1, char *str2);
char	*make_substr(int start, int end, char *str);
t_list	*ft_newdel(char **line, t_list *target, t_list **head);
t_list	*lst_add(t_list **lst, int fd);
int		line_maker(char	**line, char **storage, int	*end_point, int	*all_size);
int		return_str(char **line, char **storage, char *buff, int *flag);
int		can_read(char *buff, char **storage, char **line, int *r_size);
t_list	*pre_check(int *r_size, char *buff, int *fd, t_list **lst);
char	*get_next_line(int fd);

#endif