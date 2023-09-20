#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

void handle_interactive_mode(void);
void prompt_user(void);
char *read_input();
int execute_command(char **args);
int execute_builtin(char **args);
int execute_exit(void);
int execute_env(void);
int execute_cd(char **args);
void execute_setenv(char **args);
void execute_unsetenv(char **args);
void execute_alias(int argc, char **args);
void print_aliases(void);
void print_alias(const char *name);
char *replace_variables(char *input);
void execute_with_separators(char *input);
char *remove_comments(char *input);
void print_prompt(void);
extern char **environ;
void *allocate_mem(size_t size);
int handle_file_mode(const char *filename);
void install_signal_handlers(void);
void handle_signal(int signo);
void add_history(const char *command);
void print_history(void);
int handle_script_mode(const char *filename);
int redirect_output(const char *filename);
int redirect_input(const char *filename);
int str_starts_with(const char *str, const char *prefix);
char *str_trim(char *str);
int check_permissions(const char *filename, int mode);
int change_permissions(const char *filename, int mode);
char *read_input();
char **parse_input(const char *input);
int execute_logical_and(int left_status, int right_status);
int execute_logical_or(int left_status, int right_status);
int check_background(char **args);
void handle_child_process(char **args, int pipes[2]);
void handle_parent_process(pid_t pid, char **args, int background);

#endif
