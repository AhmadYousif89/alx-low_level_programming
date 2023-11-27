#include "main.h"

/**
 * read_textfile - Read a text file and prints it to the POSIX standard output
 * @filename: pointer to the filename
 * @letters: count of letters to read
 * Return: The count of letter or (0) on failuer
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nb = 0;
	char buffer[BUFF_SIZE * 8];

	if (!filename || !letters)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	nb = read(fd, &buffer, letters);
	nb = write(STDOUT_FILENO, &buffer, nb);
	close(fd);

	return (nb);
}
