/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyapar <iyapar@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:15:00 by iyapar            #+#    #+#             */
/*   Updated: 2023/01/27 14:15:02 by iyapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> //open()
# include <sys/types.h> //pid_t
# include <sys/wait.h> //waitpid
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define TMP_FILE "./text.txt" //heredoc'a yazdıklarımızın gideceği text dosyası

typedef struct s_envp
{	
	char	**envp;
	int		env_len;
}			t_envp;

typedef struct s_list
{
	char	*current_path;
	void	*next;
	char	*data;
	int		is_path;
}			t_list;

typedef struct s_utils
{
	int	quote_flag;
	int	n_flag;
	int	cnt_pipe;
	int	split_start;
	int	split_last;
}					t_utils;

typedef struct s_redir_var
{
	char	*temp;
	int		fd;
	int		k;
	int		flags;
	char	*file;
	int		j;
	int		m;

}			t_redir_var;

extern int		g_return;

//builtin
void			mini_cd(char *tmp);
int				is_builtin(char *tmp);
void			exec_builtin(char *command, t_envp *s_envp);
void			export_handle(char *str, t_envp *s_envp);
void			print_dir(char *str);
void			print_env(char **envp);
void			print_export(t_envp *s_envp);
int				get_index(char *var_name, t_envp *s_envp);
char			**realloc_env(char **str, int size);
void			export(char *var_name, char *var_val, t_envp *s_envp);
void			unset_handle(char *str, t_envp *s_envp);
int				env_len(char **envp);
int				ft_isstartswith(char *s1, char *s2);

//echo
void			print_echo(char *s, int flag);
void			finder_dollar_env(char *s, int *i, t_envp *s_envp);
void			echo_canalizer(char *str, t_envp *s_envp);
void			echo_handle(char *s, t_utils utils, t_envp *s_envp);
char			*ft_echo_substr(char *str, int start, int end);
void			sngle_quote_incheck(char *s, int *i);
void			dble_quote_incheck(char *s, int *i);
void			echo_withn(char *s, t_envp *s_envp);
void			echo_withoutn(char *s, t_envp *s_envp);
int				n_check(char *str);
int				check_quotes(char *s, t_utils utils);
int				is_echo(char *s);
char			*check(char *s, int i);

//libft
t_list			*ft_lstlast(t_list *lst);
unsigned int	ft_strlcpy(char *dest, char const *src, unsigned int size);
void			ft_putchar(char c);
char			**ft_split(const char *s, char c);
void			ft_putstr(char *str);
void			ft_putnstr_fd(char const *str, int str_len, int fd);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstnew(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, unsigned int len);
void			ft_putchar_fd(char c, int fd);
char			*ft_strchr(const char *s, int c);
int				ft_strlen(const char *str);
char			*ft_strcpy(char *dest, char *src);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(const char *s1);
int				ft_strncmp(const char *s1, const char *s2, int len);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstrendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

//minishell
t_envp			*init(char **envp);
void			init_shell(void);
t_envp			*init_envp(char **envp);
char			*takeinput(t_envp *s_envp);
void			execsimple(char *parse, t_envp *s_envp);
void			execpiped(t_list **mini, int countpiped, t_envp *s_envp);
void			pipe_handle(char *str, int n_pipe, t_envp *s_envp);
void			analysis_command(char *str, t_envp *s_envp);
void			ft_free_str(char **str);
void			ft_free_list(t_list **list);
void			ft_free_env(t_envp *s_envp);
void			signals(int signum);

//utils
int				count(char *str, char c);

//list
t_list			**add_list(char **str, t_list **mini);

//directions
void			check_dir(char *str, t_envp *s_envp);
void			execute_dir(char *s, int fd, int i, t_envp *s_envp);
int				redirect_in(char **str, int i, t_envp *s_envp);
int				redirect_out(char **str, int i, t_envp *s_envp);
void			exec_redir(char *s, int fd, int i, t_envp *s_envp);
void			redir2_out_handle(char **str, int i, t_envp *s_envp);
void			redir_out_handle(char **str, int i, t_envp *s_envp);
void			redir2_in_handle(char **str, int i, t_envp *s_envp);
void			redir_in_handle(char **str, int i, t_envp *s_envp);
void			here_doc(char *file, char *eof);
char			*sub_redir(char **str, int i);

//path
char			*find_path_simple(char *cmd);
char			*verify_path_simple(char *cmd, int i);
char			*find_path(char *cmd);
char			*verify_path(char *cmd, int i);

//export
void			realloc_envp(t_envp *s_envp);
void			export_run_exist(char *var_name, char *var_val,
					t_envp *s_envp, int i);

void			export_run_nonexistent(char *var_name, char *var_val,
					t_envp *s_envp, int i);
#endif