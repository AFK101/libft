#include "libft.h"
//le free marche t-il ?
char	*ft_strjoinfree(char **source1, char **source2, int mod)
{
	size_t	counter;
	char	*new;
  char  *s1;
  char  *s2;

	if (!source1 || !source2)
		return (NULL);
  s1 = *source1;
  s2 = *source2;
	counter = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = ft_memalloc(counter + 1)))
		return (NULL);
	while (*s1)
		*new++ = *s1++;
	while (*s2)
		*new++ = *s2++;
  if (mod == 1 || mod == 3)
    ft_stdel(*source1);
  if (mod == 1 || mod == 3)
    ft_strdel(*source2);
	return (new - counter);
}
