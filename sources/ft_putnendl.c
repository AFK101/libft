#include "libft.h"

void	ft_putnendl(char const *s, size_t nb)
{
	if (!s || !nb)
		return ;
	while (*s && nb--)
		ft_putchar(*s++);
	ft_putchar('\n');
}
