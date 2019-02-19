#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;

	i = 1;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr("ligne ");
		ft_putnbr(i);
		ft_putstr(" : ");
		ft_putendl(line);
		free(line);
		i++;
	}
	if (argc == 2)
		close(fd);
}
	
