/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:40:23 by atakeddi          #+#    #+#             */
/*   Updated: 2021/12/10 14:38:44 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_buffer(int fd,char *str)
{
	char	*buff;
	int		c;
	
	if (!buff)
		return(NULL);
	c = 1;
	while (!ft_strchr(str,'\n') && c )
	{
		c = read(fd,buff,BUFFER_SIZE);
		if (c == -1)
		{
			free(buff);
			return(NULL);
		}
		buff[c] = '\0';
		str = ft_strjoin(str,buff);
	}
		free(buff);
		return(str);
	
}

char	*get_line(char *c)
{
	char	*line;
	int		i;
	int		len;
	
	if (!c)
		return(NULL);
	while (c[i] != '\n' && c[i])
		i++;
	len = i + 1;
	if (c[i] == '\n')
		len++;
	line = (char *)malloc(len);
	if (!line)
		return(NULL);
	while (c[i] && c[i] != '\n')
		{
			line[i] = c[i];
			i++;
		}
	if (c[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return(line);
}

char	get_new_rest(char *rest)
{
	
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char	*line;
	
	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	rest = read_buffer(fd,rest);
	if (!rest)
		return(NULL);
	line = get_line(rest);
	rest = get_new_rest(rest);

}