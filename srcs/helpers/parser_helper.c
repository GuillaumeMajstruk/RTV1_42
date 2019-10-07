/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:42:59 by gmajstru          #+#    #+#             */
/*   Updated: 2019/01/27 15:46:36 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			line_len(char **line)
{
	int			count;

	count = 0;
	if (!(line) || !(*line))
		return (0);
	while (line[count])
		count++;
	return (count);
}

void		clear_line(char **line)
{
	int			i;

	i = -1;
	if (line)
	{
		while (line[++i])
			ft_memdel((void**)&(line[i]));
		ft_memdel((void**)&(line[i]));
		ft_memdel((void**)&line);
	}
}

void		exit_if_non_ascii(char *c)
{
	if (c && !(ft_isascii(*c)))
		exit_invalid_file();
}

char		**split_new_line(int fd)
{
	char		**line;
	char		**splited_content;
	int			res;

	splited_content = NULL;
	if (!(line = (char**)malloc(sizeof(char*))))
		return (NULL);
	if ((res = get_next_line(fd, line)) < 0)
		exit_usage();
	if (res == 1)
	{
		ft_striter(*line, &(exit_if_non_ascii));
		splited_content = ft_strsplit(*line, ' ');
	}
	ft_memdel((void**)line);
	ft_memdel((void**)(&line));
	return (splited_content);
}
