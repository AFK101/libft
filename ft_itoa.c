/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 15:19:27 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 17:41:46 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t		index;
	size_t		sign;
	char		*str;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	index = ft_count_integer(n);
	(n == 0) ? index = 1 : index;
	if (n < 0)
	{
		n *= -1;
		index++;
		sign = 1;
	}
	if (!(str = ft_strnew(index)))
		return (NULL);
	str[index] = '\0';
	while (index)
	{
		str[--index] = (n % 10) + 48;
		n /= 10;
	}
	(sign) ? *str = '-' : *str;
	return (str);
}
