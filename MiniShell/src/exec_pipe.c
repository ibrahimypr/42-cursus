/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:13:43 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:13:44 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_pipe(int *fd, int j, t_list *temp, t_envp *s_envp)
{
	int		i;
	char	**cmd;
	char	*path;

	if (j != 0)
		if (dup2(fd[(j - 1) * 2], 0) < 0)
			exit(1);
	if (temp->next)
		if (dup2(fd[j * 2 + 1], 1) < 0)
			exit(1);
	i = -1;
	while (fd[++i])
		close(fd[i]);
	cmd = ft_split(temp->data, ' ');
	path = find_path(cmd[0]);
	if (execve(path, cmd, s_envp->envp) != 0)
	{
		g_return = 127;
		ft_putstr_fd("Could not execute command", 1);
		exit(g_return);
	}
	free(path);
	ft_free_str(cmd);
	exit(g_return);
}

static void	split_piped(int *fd, t_list *mini, t_envp *s_envp)
{
	int		j;
	int		pid;
	t_list	*temp;

	j = 0;
	temp = mini;
	while (temp)
	{
		signals(1);
		pid = fork();
		if (pid == 0)
		{
			signals(2);
			execute_pipe(fd, j, temp, s_envp);
		}
		temp = temp->next;
		j++;
	}
	free(temp);
}

void	execpiped(t_list **mini, int countpipe, t_envp *s_envp)
{
	int	i;
	int	*fd;

	i = -1;
	fd = (int *)malloc(sizeof(int) * countpipe * 2);
	while (++i < countpipe)
	{
		if (pipe(fd + i * 2) < 0)
			exit(1);
	}
	split_piped(fd, (*mini), s_envp);
	i = -1;
	while (++i < 2 * countpipe)
		close(fd[i]);
	countpipe++;
	while (countpipe--)
		waitpid(0, &g_return, WUNTRACED);
	if (WIFEXITED(g_return))
		g_return = WEXITSTATUS(g_return);
	else
		g_return = 0;
	if (fd[0] != '\0')
		free(fd);
}

void	pipe_handle(char *str, int n_pipe, t_envp *s_envp)
{
	char	**pipe_commands;
	t_list	**list;

	list = (t_list **)malloc(sizeof(char *) * 100);
	*list = NULL;
	pipe_commands = ft_split(str, '|');
	add_list(pipe_commands, list);
	execpiped(list, n_pipe, s_envp);
	ft_free_list(list);
	ft_free_str(pipe_commands);
}
