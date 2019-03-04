/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_integer.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 15:18:03 by jucollet     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 15:18:09 by jucollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_integer(int n)
{
	size_t		counter;

	counter = 0;
	while ((n /= 10))
		counter++;
	return (counter);
}
