/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 20:52:40 by jye               #+#    #+#             */
/*   Updated: 2017/01/01 18:00:26 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

static int	get_to_stack(char **sbuff, char *buff)
{
	char *old;

	if ((old = *sbuff) == NULL)
	{
		if ((*sbuff = ft_strnew(BUFF_SIZE)) == NULL)
			return (1);
		ft_strcpy(*sbuff, buff);
	}
	else
	{
		if ((*sbuff = ft_strjoin(old, buff)) == NULL)
		{
			*sbuff = old;
			return (1);
		}
		free(old);
	}
	return (0);
}

static char	*get_line__(char **sbuff)
{
	char			*a;
	char			*fresh;
	unsigned long	sz_l;
	unsigned long	sz_fd;

	if (*sbuff == NULL)
		return (NULL);
	if ((a = ft_strchr(*sbuff, '\n')) == NULL)
		return (NULL);
	sz_l = a - *sbuff;
	sz_fd = ft_strlen(*sbuff);
	if ((fresh = ft_strnew(sz_l)) == NULL)
		return (NULL);
	ft_memcpy(fresh, *sbuff, sz_l);
	a = *sbuff;
	if ((*sbuff = ft_strnew(sz_fd - sz_l)) == NULL)
		return (fresh);
	ft_memcpy(*sbuff, a + sz_l + 1, sz_fd - sz_l);
	free(a);
	return (fresh);
}

static int	ret_val(char **sbuff, char **line, int ret)
{
	if (ret == -1)
		return (-1);
	if (*sbuff == NULL)
		return (0);
	if ((*line = ft_strdup(*sbuff)) == NULL)
		return (-1);
	free(*sbuff);
	*sbuff = NULL;
	if (**line)
		return (1);
	return (0);
}

int			get_line(const int fd, char **line)
{
	static char *sbuff = NULL;
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (!line)
		return (-1);
	if ((*line = get_line__(&sbuff)))
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = 0;
		if (get_to_stack(&sbuff, buff))
			return (-1);
		if ((*line = get_line__(&sbuff)))
			return (1);
	}
	return (ret_val(&sbuff, line, ret));
}
