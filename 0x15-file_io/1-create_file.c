#include "main.h"

/**
 * create_file - create a new file.
 * @filename: the name of the file.
 * @text_content: content in the file.
 *
 * Return: 1 if success, else -1
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0, i;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_APPEND | O_TRUNC, 00600);
	if (fd < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;
		i = write(fd, text_content, len);
		if (len != i)
			return (-1);
	}

	close(fd);
	return (1);
}
