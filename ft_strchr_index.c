/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr_index.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 21:18:22 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 23:28:14 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "libft.h"

int		ft_strchr_index(const char *str, int c)
{
	int		index;

	index = 0;
	if (str == NULL)
		return (-1);
	while (str[index])
	{
		if (str[index++] == c)
			return (index);
	}
	return (-1);
}
