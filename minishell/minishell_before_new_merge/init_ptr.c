/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:33:45 by klaronda          #+#    #+#             */
/*   Updated: 2020/12/12 13:33:46 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_tcom(t_commands *com)
{
	com->command = NULL;
	com->args = NULL;
	com->output_flag = NULL;
	com->l_filename = NULL;
	com->r_filename = NULL;
	com->r_redirects = NULL;
	com->l_redirects = NULL;
	com->r_redirectsindex = 0;
	com->l_redirectsindex = 0;
	com->argsindex = 0;
	com->comflag = 0;
}

void	init_ptr_var(t_ptr *ptr)
{
	ptr->env = NULL;
	ptr->preenv = NULL;
	ptr->arr = NULL;
	ptr->arr2 = NULL;
	ptr->temp = NULL;
	ptr->ext = 0;
	ptr->countofpipes = 0;
	ptr->countofpipe_redir = 0;
	ptr->countofredirects = 0;
	ptr->cntofarrelem = 0;
	ptr->comstrindex = 0;
	ptr->comstruct = NULL;
	ptr->tcs = NULL;
	ptr->fd = NULL;
	ptr->pid = -1;
}

void	init_global_var(void)
{
	g_userpwd = NULL;
	g_pipeflag = 0;
	g_redirectflag = 0;
	g_signal = 0;
	g_errno = 0;
}

void	init_ptr(t_ptr *ptr, char **env)
{
	init_global_var();
	init_ptr_var(ptr);
	save_stdin_stdout(ptr);
	ptr->env = fill_env_var(env);
	print_username(ptr);
	ptr->ext = -1;
	ptr->home = change_pwd(ptr->env, "HOME=", 5);
}
