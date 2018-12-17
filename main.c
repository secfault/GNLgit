#include <sys/styles.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd;
	char line[2048];
	char **lines;
	
	*lines = &line;
	if (!(fd = open(argv[1], O_RDONLY)))
		return (-1);
	get_next_line(fd, lines);
	return 0;
}
	
