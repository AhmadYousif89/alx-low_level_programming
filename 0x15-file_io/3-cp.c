#include "main.h"

/**
 * exit_werr - Helper function
 * @code: the exit number
 * @message: the error message to print upon exit
 * @arg: pointer to the optional arguments
 */
void exit_werr(int code, const char *message, const char *arg)
{
	dprintf(2, message, arg);
	exit(code);
}

/**
 * main - Copy the content of a file to another file
 * @argc: count of args
 * @argv: array of strings containing the command-line arguments.
 * Return: Always (0)
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to;
	char buffer[BUFF_SIZE];
	const char *file_from, *file_to;
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
		exit_werr(97, "Usage: cp file_from file_to\n", NULL);

	file_from = argv[1];
	file_to = argv[2];
	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		exit_werr(98, "Error: Can't read from file %s\n", file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		exit_werr(99, "Error: Can't write to file %s\n", file_to);
	}
	while ((bytes_read = read(fd_from, buffer, BUFF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close(fd_from);
			close(fd_to);
			exit_werr(99, "Error: Can't write to file %s\n", file_to);
		}
	}
	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		exit_werr(98, "Error: Can't read from file %s\n", file_from);
	}
	if (close(fd_from) == -1 || close(fd_to) == -1)
		exit_werr(100, "Error: Can't close file descriptor\n", NULL);

	return (0);
}
