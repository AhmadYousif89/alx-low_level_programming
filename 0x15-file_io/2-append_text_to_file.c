#include "main.h"

/**
 * append_text_to_file - Add a text to the end of a file
 * @filename: pointer to the filename
 * @text_content: pointer to the text
 * Return: (1) on success or (-1) on failuer
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;

	/* Case filename is NULL */
	if (!filename)
		return (-1);
	/* Create a file with write only and append */
	fd = open(filename, O_WRONLY | O_APPEND);
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
