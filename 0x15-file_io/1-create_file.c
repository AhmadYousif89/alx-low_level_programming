#include "main.h"

/**
 * create_file - Create a text file and print its content to standard output
 * @filename: pointer to the filename
 * @text_content: pointer to the text
 * Return: (1) on success or (-1) on failuer
 */
int create_file(const char *filename, char *text_content)
{
	int fd;

	/* Case filename is NULL */
	if (!filename)
		return (-1);
	/* Create a file with chmod 600 */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	/* Case of failuer */
	if (fd == -1)
		return (-1);
	/* If we have text start writing */
	if (text_content)
	{
		ssize_t res = write(fd, text_content, strlen(text_content));
		/* Case of failuer */
		if (res == -1)
		{
			close(fd);
			return (-1);
		}
	};

	close(fd);
	/* Case of success */
	return (1);
}
