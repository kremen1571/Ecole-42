/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 22:44:53 by jrosemar          #+#    #+#             */
/*   Updated: 2020/12/12 22:45:00 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*create_path1(char **env, t_var *var)
{
	char	*str;

	str = NULL;
	var->len = ft_strlen(env[var->i]);
	str = (char *)malloc(sizeof(char) * var->len - 4);
	while (env[var->i][var->j + 5] != '\0')
	{
		str[var->j] = env[var->i][var->j + 5];
		var->j++;
	}
	str[var->j] = '\0';
	return (str);
}

char		**create_path(char **env)
{
	t_var	var;
	char	*str;
	char	**arr;

	var = init_variable();
	arr = NULL;
	while (env[var.i])
	{
		if (ft_strncmp(env[var.i], "PATH=", 5) == 0)
			break ;
		var.i++;
	}
	if (var.i != find_size_arr(env))
	{
		str = create_path1(env, &var);
		arr = ft_split(str, ':');
		free_str(str);
	}
	return (arr);
}

char		**change_path(char **arr, char *str)
{
	int		i;
	int		j;
	char	**new;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (arr[i])
		i++;
	new = (char **)malloc((sizeof(char *) * (i + 1)));
	while (j < i)
	{
		new[j] = (char *)malloc(sizeof(char) * (ft_strlen(arr[j]) + len + 2));
		j++;
	}
	new[j] = NULL;
	i = 0;
	while (arr[i])
	{
		fill_new_line(new[i], arr[i], str);
		i++;
	}
	free_arr(arr);
	return (new);
}

char		*pathnotnull(char **path, int i, int fd)
{
	char	*temp;

	temp = NULL;
	while (path[i])
	{
		fd = open(path[i], O_RDONLY);
		if (fd >= 0)
		{
			close(fd);
			temp = ft_strdup(path[i]);
			break ;
		}
		i++;
	}
	return (temp);
}

char		*exist_file(char *str, char **env)
{
	int		i;
	char	**path;
	int		fd;
	char	*temp;

	fd = -1;
	temp = NULL;
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd >= 0)
	{
		close(fd);
		temp = ft_strdup(str);
		return (temp);
	}
	path = create_path(env);
	if (path != NULL)
	{
		path = change_path(path, str);
		temp = pathnotnull(path, i, fd);
	}
	if (path)
		free_arr(path);
	return (temp);
}
