#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		count_end_point(char *str);
char	*ft_strjoin(char *str1, char *str2);
void	clean_buff(int count, char *buff);
char	*make_substr(int start, int end, char *str);
int		line_maker(char	**line, char **storage, int	*end_point, int	*all_size);
int		free_all(char **line, char **storage);
int		return_str(char **line, char **storage, char *buff, int *flag);
int		can_read(char *buff, char **storage, char **line, int *read_size);
char	*get_next_line(int fd);

#endif