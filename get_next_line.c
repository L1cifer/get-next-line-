/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:40:23 by atakeddi          #+#    #+#             */
/*   Updated: 2021/12/08 18:35:27 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_buffer(int fd,char *str)
{
	char	*buff;
	int		r;
	
	if (!buff)
		return(NULL);
	r = 1;
	while (!ft_strchr(str,'\n') && r )
	{
		r = read(fd,buff,BUFFER_SIZE);
		if (r == -1)
		{
			free(buff);
			return(NULL);
		}
		buff[r] = '\0';
		str = ft_strjoin(str,buff);
	}
		free(buff);
		return(str);
	
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
	line = 
	

}