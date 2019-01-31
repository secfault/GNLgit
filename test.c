#include "get_next_line.h"

int		main()
{
	char	*str = ft_strdup("un\ndeux\ntrois");
	char	*line[99];
	char	*start = ft_strchr(str, '\n') - 1;

	ft_putstr("str: ");
	ft_putendl(str);
	ft_putstr("start: ");
	ft_putendl(start);
	ft_putstr("len: ");
	ft_putnbr((int)ft_strrlen(start));
	ft_putendl("");
	line[0] = ft_strrsub(str, ft_strrlen(start));
	ft_putstr("line[0]: ");
	ft_putstr(line[0]);
	//ft_putstr("len: ");
	//ft_putendl(ft_itoa((int)ft_strrlen(ft_strchr(str, '\n'))));
	return (0);
}