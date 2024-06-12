#include "get_next_line_bonus.h"

int	line_maker(char	**line, char **storage, int	*end_point, int	*all_size)
{
	char	*tmp_stg;

	tmp_stg = 0;
	(*line) = make_substr(0, (*end_point), (*storage));
	if (*line == 0)
	{
		free((*storage));
		(*storage) = 0;
		return (0);
	}
	if (((*end_point) < (*all_size)) && (*storage)[(*end_point) + 1] != '\0')
	{
		tmp_stg = make_substr(((*end_point) + 1), (*all_size), (*storage));
		if (tmp_stg == 0)
		{
			free(*line);
			(*line) = 0;
			free((*storage));
			(*storage) = 0;
			return (0);
		}
	}
	free((*storage));
	(*storage) = tmp_stg;
	return (1);
}

int	return_str(char **line, char **storage, char *buff, int *flag)
{
	int		end_point;
	int		all_size;
	char	*all_str;

	all_str = 0;
	all_str = ft_strjoin((*storage), buff);
	if (all_str == 0)
		return (0);
	if ((*storage) != 0)
		free((*storage));
	(*storage) = all_str;
	end_point = ft_strlen((*storage), 1);
	all_size = ft_strlen((*storage), 0);
	if ((end_point == all_size) && (*flag) == 1)
	{
		(*line) = (*storage);
		(*storage) = 0;
		return (1);
	}
	if ((*flag) == 1 || (end_point < all_size))
	{
		(*flag) = 1;
		return (line_maker(line, storage, &end_point, &all_size));
	}
	return (1);
}

int	can_read(char *buff, char **storage, char **line, int *r_size)
{
	int	flag;

	flag = 0;
	if ((*r_size) == 0 && (*storage) == 0)
		return (0);
	if (((*r_size) == 0) || (buff[(*r_size) - 1] == '\0'))
		flag = 1;
	if (return_str(line, storage, buff, &flag) == 0)
		return (0);
	if (flag == 1)
	{
		if ((*storage) != 0 && (*storage)[0] == '\0')
		{
			free((*storage));
			(*storage) = 0;
		}
		return (1);
	}
	return (2);
}

t_list	*pre_check(int *r_size, char *buff, int *fd, t_list **lst)
{
	t_list	*find_lst;

	if (*lst == 0 || fd < 0 || BUFFER_SIZE <= 0)
		find_lst = 0;
	while (++(*r_size) <= BUFFER_SIZE)
			buff[(*r_size)] = '\0';
	(*r_size) = read((*fd), buff, BUFFER_SIZE);
	find_lst = (*lst);
	while (find_lst != 0)
	{
		if ((find_lst->fd) == (*fd))
			break ;
		find_lst = (find_lst->back);
	}
	if (find_lst == 0 && (*r_size) > 0)
	{
		find_lst = lst_add(lst, (*fd));
		if (find_lst == 0)
			return (ft_newdel(0, find_lst, lst));
	}
	if (find_lst == 0)
		return (0);
	if ((find_lst->storage == 0) && (*r_size) == 0)
		return (ft_newdel(0, find_lst, lst));
	return (find_lst);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			buff[BUFFER_SIZE + 1];
	static t_list	*lst = 0;
	int				r_size;
	t_list			*find_lst;

	line = 0;
	r_size = -1;
	find_lst = pre_check(&r_size, &buff[0], &fd, &lst);
	if (find_lst == 0)
		return ((char *)ft_newdel(&line, find_lst, &lst));
	while (1)
	{
		if ((r_size < 0))
			return ((char *)ft_newdel(&line, find_lst, &lst));
		r_size = can_read(&(buff[0]), &(find_lst->storage), &line, &r_size);
		if (r_size == 0)
			return ((char *)ft_newdel(&line, find_lst, &lst));
		else if (r_size == 1)
			return (line);
		r_size = -1;
		while (++r_size <= BUFFER_SIZE)
			buff[r_size] = '\0';
		r_size = read(fd, buff, BUFFER_SIZE);
	}
}
