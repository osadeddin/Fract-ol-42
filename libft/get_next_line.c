/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:21:47 by osadeddi          #+#    #+#             */
/*   Updated: 2024/10/10 16:19:58 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_fun(char **str, char *line, char *buf)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
	if (line)
		free(line);
	if (buf)
		free(buf);
	return (NULL);
}

static void	*fill_line(char **str, char *line)
{
	size_t	i;
	char	*temp;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
	{
		line = malloc(i + 2);
		if (!line)
			return (free_fun(str, line, NULL));
		ft_strlcpy(line, *str, i + 2);
		temp = ft_strdup(*str + i + 1);
		if (!temp)
			return (free_fun(str, line, NULL));
		free(*str);
		*str = temp;
		return (line);
	}
	line = ft_strdup(*str);
	if (!line)
		return (free_fun(str, line, NULL));
	free_fun(str, NULL, NULL);
	return (line);
}

static void	*read_fun(int fd, char **str, char *line)
{
	long	bytes;
	char	*temp;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free_fun(str, line, buf));
	while (!ft_strchr(*str, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free_fun(str, line, buf));
		if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		temp = ft_strjoin(*str, buf);
		if (!temp)
			return (free_fun(str, line, buf));
		free(*str);
		*str = temp;
	}
	free(buf);
	return (fill_line(str, line));
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_fun(&str, line, NULL));
	if (!str)
	{
		str = ft_strdup("");
		if (!str)
			return (NULL);
	}
	line = read_fun(fd, &str, line);
	if (!line || *line == '\0')
		return (free_fun(&str, line, NULL));
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error: Failed to open the file\n");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	printf("EOF\n");

// 	close(fd);
// 	return (0);
// }
