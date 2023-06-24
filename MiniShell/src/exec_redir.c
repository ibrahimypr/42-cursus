/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:13:47 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:13:48 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_redir(char *s, int fd, int i, t_envp *s_envp)
{
	int		n_pipe;

	signals(2);
	n_pipe = count(s, '|');
	dup2(fd, i);
	close(fd);
	if (n_pipe)
		pipe_handle(s, n_pipe, s_envp);
	else if (is_builtin(s))
		exec_builtin(s, s_envp);
	else
		execsimple(s, s_envp);
	exit(g_return);
}

void	execute_dir(char *s, int fd, int i, t_envp *s_envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		g_return = 127;
		ft_putstr_fd("Failed forking child", 1);
	}
	else if (pid == 0)
		exec_redir(s, fd, i, s_envp);
	waitpid(0, &g_return, 0);
	if (WIFEXITED(g_return))
		g_return = WEXITSTATUS(g_return);
	else
		g_return = 0;
}
