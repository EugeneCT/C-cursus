#include "pipex.h"

// run_cmd(cmd, input_fd, output_fd) {
//   dup2(input_fd, 0); // duplicate input_fd to stdin
//   dup2(output_fd, 1); // duplicate output_fd to stdout
//   // execute the command
// }

// int parse_cmd(const int argc,char**argv)

///////////////
// Test pipe ///
///////////////

// int main(int argc, char**argv, char**envp)
// {
//   int pipefd[2];
//   // char hello='a';
//   char nl ='\n';
// //   int fin;
// //   int fout;
// //   pid_t pid;
// //   struct cmd_store	cmd_lst[argc];


//   if (argc < 5)
// 		return (printf(ERR_INVALID_PARAMS));
// printf("envp is %s \n",*envp);


//   pipe(pipefd); // pipefd[1] is the write-end of the pipe
//                 // pipefd[0] is the read-end of the pipe

// // if (pipe(pipefd) < 0)
// // 	return (ft_puterr(ERR_PIPE));

// //   fin = open(argv[1], O_RDONLY); // input file descriptor
// //   fout = open(argv[10], O_WRONLY | O_CREAT | O_TRUNC, 0644); // output file descriptor
// //   if (fin < 0 || fout<0)
// // 		return (printf(ERR_INVALID_FILE));

// //   pid = fork();
// int i=2;
// char*word;
// char prev[1000];
// char*result;
// int leng;

// leng=ft_strlen(argv[i]);


// while (i < (argc-1))
// {
//     // printf("after read, prev should be:");

//     write(pipefd[1],argv[i],leng);
//     read(pipefd[0],prev,leng);
//     ft_putstr(prev,&leng);

//     printf("%s",prev);
//       write(1,&nl,1);
//     if (i ==2)
//     {
//       word=ft_strdup(prev);
//       // write(1,&hello,1);
//       // write(1,&nl,1);
//     }
    
//     else
//       word=ft_strjoin_nconst(word,prev);
//     leng=ft_strlen(word);
//     i++;


// }
// result=(char*)malloc(leng);


// printf("%s",result);
// // while


// //   if (pid == 0) // child process
// //   {
// //     printf("Child process")
// //   }
// //   else // parent process
// //   {
// //     close(pipefd[1]) // must close the write end before reading from the pipe
// //     run_cmd(cmd2, pipefd[0], fout);
// //   }

// }

////////////////////////////
// Test Access and path //
//////////////////////////

char	**ft_split_cmd_args(char *s)
{
	int		size;
	char	*p;
	char	**cmd_args;

	if (s == NULL || *s == 0)
		return (NULL);
	p = s;
	while (*p && *p != ' ')
		p++;
	if (*p == 0)
		size = 2;
	else
		size = 3;
	cmd_args = (char **)malloc(size * sizeof(char *));
	cmd_args[size - 1] = 0;
	cmd_args[0] = ft_strndup(s, p - s);
	if (*p && p[1])
		cmd_args[1] = ft_strdup_ignore(p + 1, '"');
  // if (*p && p[1])
	// 	cmd_args[1] = ft_strdup(p + 1);
	return (cmd_args);
}


// int main(int argc, char**argv, char**envp)
// {
	// char	**cmd_args;

  // if (argc <1)
  //   printf("argc error");

  // printf("argv1 is %s \n",argv[1]);

  // printf("envp is %s \n",*envp);
  
  // cmd_args = ft_split_cmd_args(argv[2]);
  // if (access(cmd_args[0], X_OK)>=0)
  // {
  //   printf("Can acess!");
  // }
  // else
  // {
  //   printf("Cannot access");
  // }
// }

  // while (*envp++ != NULL) 
  // { 
  //   if (ft_strnstr(*envp,"PATH=",5)!=NULL)
  //   {

  //       printf("%s\n", *envp); 
  //       return *(envp);
  //   }

  //   //  (*envp)++;

  // } 

char	*find_env_path(char **envp)
{
	while (envp && *envp)
	{
		if (strncmp(*envp, "PATH=", 5) == 0)
		{
			return (ft_strdup(&(*envp)[5]));
		}
		envp++;
	}
	return (NULL);
}

void	free2(char **v)
{
	char	**p;

	if (!v)
		return ;
	p = v;
	while (*v)
	{
		free(*v);
		v++;
	}
	free(p);
}

char	**find_cmd_paths(char **envp)
{
	char	**paths;
	char	*path;

	path = find_env_path(envp);
	paths = ft_split(path, ':');
	if (path)
		free(path);
	return (paths);
}


char	*locate_cmd(char **paths, char *cmd)
{
	char	*_cmd;
	char	*cmd_path;

	if (access(cmd, X_OK) >= 0)
		return (ft_strdup(cmd));
	_cmd = ft_strjoin("/", cmd);
	cmd_path = NULL;
	while (paths && *paths)
	{
		cmd_path = ft_strjoin(*paths, _cmd);
		if (access(cmd_path, X_OK) >= 0)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		paths++;
	}
	free(_cmd);
	return (cmd_path);
}

int	run_cmd(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*cmd_name;
	char	*cmd_path;
	char	**paths;
	int		status;
	// ft_putstr(ft_itoa(*i),NULL);

	  paths = find_cmd_paths(envp);

	cmd_args = ft_split_cmd_args(cmd);
	cmd_name = cmd_args[0];
	cmd_path = locate_cmd(paths, cmd_name);
	free2(paths);
	status = 0;
	if (cmd_path)
  {
  
		status = execve(cmd_path, cmd_args, envp);
    // free(cmd_path); 
  }
  else
    {
      // printf("%s",cmd);
    status=-1;
		ft_puterr(ERR_INVALID_CMD,1);
    }
	// if (cmd_path)
	free(cmd_path);
	free2(cmd_args);
	return (status);
}





char* check_path(char** envp)

{
  while (*envp++ != NULL) 
  { 
    if (ft_strnstr(*envp,"PATH=",5)!=NULL)
    {

        // printf("%s\n", *envp); 
        return *(envp);
    }
  }
  return (NULL);
}
//////////////////
//  TEST EXECV  //
/////////////////

// 5 var, 4 parameter


int	pipex(in_params in)
{
	pid_t	pid;
	int		status;
  int   i;
  int prev_pipe;
	status = 0;
  i=2;
  prev_pipe=in.fin;

  while (i < (in.argc -2))
  {
    if (pipe(in.pipefd) < 0)
		    return (ft_puterr(ERR_PIPE,1));

    // in.pipefd[1]=in.fin;
    // close(in.fin);
    // prev_pipe=in.pipefd[0];

    pid = fork();
	  if (pid < 0)
		    ft_puterr(ERR_FORK,1);

    if (pid==0){   
      if (prev_pipe != STDIN_FILENO) 
      {
        dup2(prev_pipe, STDIN_FILENO);
        close(in.fin);
   
      }
      
      dup2(in.pipefd[1], STDOUT_FILENO);
          close(in.pipefd[0]);

      status=run_cmd(in.argv[i], in.envp);

    }
  

    close(prev_pipe);
    close(in.pipefd[1]);

    prev_pipe = in.pipefd[0];

    i++;
    if (status <0)
      exit(-1);
  }
  // wait(NULL);
    waitpid(0,NULL,WNOHANG|WUNTRACED);
   if (prev_pipe != STDIN_FILENO) {
        dup2(prev_pipe, STDIN_FILENO);
        dup2(in.fout, STDOUT_FILENO);
    }
  status=run_cmd(in.argv[i], in.envp);
  close(in.fin);
  close(in.fout);
  return status;
}




int main(int argc, char**argv, char**envp)
{
  in_params	in;

	if (argc < 5)
		return (ft_puterr(ERR_INVALID_PARAMS,1));

	in.fin = open(argv[1], O_RDONLY);
  if (in.fin < 0)

  {
	ft_putstr_fd("pipex: line 1: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
    return (0);
  }
		// return (ft_puterr(ERR_INVALID_FILE,0));
	in.fout = open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (in.fout < 0)
		  return (ft_puterr(ERR_INVALID_FILE,1));
	// if ((in.fout < 0 )|| (in.fin < 0) )
	// 	return (ft_puterr(ERR_INVALID_FILE));	
	in.argv = argv;
	in.envp = envp;
  in.argc=  argc;

	if (pipex(in) < 0)
	{
    		return (1);

		// unlink(argv[argc-1]);
		// return (ft_puterr(ERR_SOMETHING_WENT_WRONG,1));
	}
	return (1);
}





  // int i =0;
  // printf("in.fin is %d \n",in.fin);
  // printf("in.fout is %d \n",in.fout);
  // while (in.argv[i])
  // {
  //   printf("argv %d is %s \n",i,in.argv[i]);
  //   i++;
  // }

// Pipex
	// char	**cmd_args;
  // char *path;
  // char	**paths;
  // char	*cmd_path;
	// char	*_cmd;
  // // int status;
  // int fout;
  // int fin;



  // if (argc <1)
  //   printf("argc error");

  // printf("argv1 is %s \n",argv[1]);

  // printf("envp is %s \n",*envp);
  
  // cmd_args = ft_split_cmd_args(argv[2]);
  // // printf("cmd_args is %s \n",*cmd_args);


  // path=check_path(envp);
  // paths=ft_split(path,':');
  // // if (access(cmd_args, X_OK) >= 0)
	// // 	return (ft_strdup(cmd));
	// _cmd = ft_strjoin("/", *cmd_args);
	// cmd_path = NULL;
  // while (path && *paths)
  // {
  //   cmd_path = ft_strjoin(*paths, _cmd);
	// 	if (access(cmd_path, X_OK) >= 0)
	// 		break ;
	// 	free(cmd_path);
	// 	cmd_path = NULL;
	// 	paths++;
  // }
  // printf("cmd_path is %s \n",cmd_path);
  // printf("cmd_args is %s \n",*cmd_args);
  // // printf("cmd_path is %s \n",cmd_path);
  // // cmd_path="/usr/bin/";
  // // printf("cmd_path is %s \n",cmd_path);
  // char* argss[]={"wc" ,NULL};
  // printf("argss is %s \n",argss[1]);
	// if (cmd_path)

  // {  
  //       fout = open("./pipex_output", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  //        fin = open("./test1", O_RDONLY);
  //       dup2(fin, 0);
  //       dup2(fout, 1);
  //     pid_t p =fork();
  //       printf("Im in child process1!");

  //     if (p==0)
  //     {


	// 	    execve(cmd_path, argss, NULL);
  //       		    // status = execve(cmd_path, argss, NULL);
   
  //       close(fin);
	//       close(fout);
  //       return(0);

  //     }
  // }

  // printf("This is the end of process");

  // } 
