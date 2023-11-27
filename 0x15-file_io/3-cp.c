#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
#define ErrMsgOnR "Error: Can't read from file %s\n"
#define ErrMsgOnW "Error: Can't write to %s\n"
#define ErrMsgOnC "Error: Can't close fd %i\n"
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 * handle_err - Helper function to handle errors
 * @code: the exit number
 * @message: the error message to print upon exit
 * @p_arg: pointer to print optional argument
 * @n_arg: number to print optional argument
 */
void handle_err(int code, const char *message, const void *p_arg, int n_arg)
{
	if (n_arg)
		dprintf(STDERR_FILENO, message, n_arg);
	else
		dprintf(STDERR_FILENO, message, p_arg);
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
	char buffer[BUFF_SIZE];
	char *file_from, *file_to;
	int fd_from = 0, fd_to = 0;
	ssize_t bytes;

	if (argc != 3)
		handle_err(97, USAGE, NULL, 0);

	file_from = argv[1];
	file_to = argv[2];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		handle_err(98, ErrMsgOnR, file_from, 0);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (fd_to == -1)
		handle_err(99, ErrMsgOnW, file_to, 0);

	while ((bytes = read(fd_from, buffer, BUFF_SIZE)) > 0)
	{
		if (write(fd_to, buffer, bytes) != bytes)
			handle_err(99, ErrMsgOnW, file_to, 0);
	}

	if (bytes == -1)
		handle_err(98, ErrMsgOnR, file_from, 0);

	fd_from = close(fd_from);
	fd_to = close(fd_to);

	if (fd_from)
		handle_err(100, ErrMsgOnC, NULL, fd_from);
	if (fd_to)
		handle_err(100, ErrMsgOnC, NULL, fd_from);

	return (EXIT_SUCCESS);
}
