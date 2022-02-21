#include <stdio.h>
#include <string.h>

char	*ft_strchr(char *str)
{
	int		i;
	char	c;

	c = '.';
	i = strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}

int main()
{
    char *s1;
    char *str = "test.zber";
    s1 = ft_strchr(str);
    printf("%s\n", s1);
}