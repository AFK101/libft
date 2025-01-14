/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <jucollet@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 16:45:06 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 12:51:13 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_strchr_index(const char *str, int c)
{
	int		index;

	index = 0;
	if (str == NULL)
		return (-1);
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

t_lst	*ft_findlst(t_lst **lst, int fd)
{
	t_lst			*tmp;

	tmp = *lst;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		if (!(tmp = (t_lst *)malloc(sizeof(t_lst))))
			return (NULL);
		tmp->fd = fd;
		tmp->str = NULL;
		tmp->next = *lst;
		*lst = tmp;
	}
	return (tmp);
}

int		ft_read(t_lst *lst, int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	ret = 0;
	temp = NULL;
	if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!lst->str)
			lst->str = ft_strdup(buff);
		else
		{
			temp = lst->str;
			lst->str = ft_strjoin(lst->str, buff);
			free(temp);
		}
	}
	return (ret);
}

void	ft_fuck_norm(char **line, t_lst *lst, char *temp, int i)
{
	*line = ft_strsub(lst->str, 0, i);
	temp = lst->str;
	lst->str = ft_strsub(lst->str, i + 1, (ft_strlen(lst->str) - i));
	free(temp);
}

int		get_next_line(const int fd, char **line)
{
	static t_lst	*pls = NULL;
	t_lst			*lst;
	char			*temp;
	int				ret;
	int				i;

	temp = 0;
	ret = 1;
	if (fd < 0 || BUFF_SIZE < 0 || (read(fd, temp, 0) < 0))
		return (-1);
	lst = ft_findlst(&pls, fd);
	while (ft_strchr_index(lst->str, '\n') == -1 && ret > 0)
		ret = ft_read(lst, fd);
	if (ret == 0 && !lst->str)
		return (0);
	if ((i = ft_strchr_index(lst->str, '\n')) == -1)
	{
		if (*(lst->str) == '\0')
			return (0);
		*line = ft_strdup(lst->str);
		ft_strdel(&lst->str);
		return (1);
	}
	ft_fuck_norm(line, lst, temp, i);
	return (1);
}
