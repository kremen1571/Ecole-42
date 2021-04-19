/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:18:09 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/27 17:45:18 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*cut_pwd(char *line)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = ft_strlen(line);
	while (line[count] != '/')
		count--;
	if (count == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str = ft_strdup("/\0");
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (count + 1));
		while (i < count)
		{
			str[i] = line[i];
			i++;
		}
		str[i] = '\0';
	}
	free(line);
	return (str);
}

char		*add_str(char **env, char *s1, char *s2)
{
	char	*temp;
	char	*str;
	int		len;
	int		i;

	i = 0;
	temp = change_pwd(env, s1, ft_strlen(s1));
	len = ft_strlen(temp) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * len + 1);
	len = ft_strlen(temp);
	ft_memcpy(str, temp, len);
	str[len] = '/';
	len++;
	while (s2[i] != '\0')
	{
		str[len + i] = s2[i];
		i++;
	}
	str[len + i] = '\0';
	free(temp);
	return (str);
}

char		*check_cd(char **arr, t_ptr *ptr)
{
	char	*str;

	if (arr[1][0] == '/')
		str = ft_strdup(arr[1]);
	else
		str = add_str(ptr->env, "PWD=", arr[1]);
	if ((chdir(str)) == -1)
		ft_putstr("No such file or directory\n");
	return (str);
}

char		*changes_env(t_ptr *ptr)
{
	char	*str;

	str = change_pwd(ptr->env, "PWD=", 4);
	str = cut_pwd(str);
	chdir(str);
	return (str);
}

void		ft_cd(char **arr, t_ptr *ptr)
{
	char	*str;
	char	*present;
	t_var	var;

	var = init_variable();
	var.i = find_size_arr(arr);
	present = NULL;
	if (var.i > 2)
	{
		ft_putstr("Too many arguments\n");
		return ;
	}
	if (arr[1] == NULL)
		str = home_var(ptr, &var);
	else if (ft_memcmp(arr[1], "-\0", 2) == 0)
		str = oldpwd_var(ptr, &var);
	else if (ft_strcmp(arr[1], "..") == 0)
		str = changes_env(ptr);
	else
		str = check_cd(arr, ptr);
	if (var.flag == 0)
		ft_cd1(present, ptr, str);
}
