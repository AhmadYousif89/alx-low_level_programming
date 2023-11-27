#include "main.h"
#define USAGE "Usage: cp file_from file_to\n"
#define ErrMsgOnR "Error: Can't read from file %s\n"
#define ErrMsgOnW "Error: Can't write to file %s\n"
#define ErrMsgOnC "Error: Can't close fd %i\n"

/**
 * handle_err - Helper function to handle errors
 * @code: the exit number
 * @message: the error message to print upon exit
 * @arg: pointer to the optional arguments
 */
void handle_err(int code, const char *message, const char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
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
	int fd_from = 0, fd_to = 0;
	char buffer[BUFF_SIZE];
	const char *file_from, *file_to;
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
		handle_err(97, USAGE, NULL);

	file_from = argv[1];
	file_to = argv[2];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		handle_err(98, ErrMsgOnR, file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		handle_err(99, ErrMsgOnW, file_to);

	while ((bytes_read = read(fd_from, buffer, BUFF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
			handle_err(99, ErrMsgOnW, file_to);
	}

	if (bytes_read == -1)
		handle_err(98, ErrMsgOnR, file_from);

	fd_from = close(fd_from);
	fd_to = close(fd_to);
	if (fd_from)
		handle_err(100, ErrMsgOnC, fd_from);
	if (fd_to)
		handle_err(100, ErrMsgOnC, fd_to);

	return (EXIT_SUCCESS);
}
