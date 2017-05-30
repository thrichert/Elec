#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*file = "/dev/tty.usbserial-FTHHXEHF";
	int	fd;
	char	buffer[10];

	fd = open(file, O_RDONLY);
	write(1, "flag", 4);
	while (read(fd, buffer, 10) < 1);
	write(1, buffer, 10);
	return (0);
}
