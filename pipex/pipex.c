#include "pipex.h"

// run_cmd(cmd, input_fd, output_fd) {
//   dup2(input_fd, 0); // duplicate input_fd to stdin
//   dup2(output_fd, 1); // duplicate output_fd to stdout
//   // execute the command
// }

// int parse_cmd(const int argc,char**argv)

int main(int argc, char**argv, char**envp)
{
  int pipefd[2];
//   int fin;
//   int fout;
//   pid_t pid;
//   struct cmd_store	cmd_lst[argc];


  if (argc < 5)
		return (printf(ERR_INVALID_PARAMS));
printf("envp is %s \n",*envp);


  pipe(pipefd); // pipefd[1] is the write-end of the pipe
                // pipefd[0] is the read-end of the pipe
// if (pipe(pipefd) < 0)
// 	return (ft_puterr(ERR_PIPE));

//   fin = open(argv[1], O_RDONLY); // input file descriptor
//   fout = open(argv[10], O_WRONLY | O_CREAT | O_TRUNC, 0644); // output file descriptor
//   if (fin < 0 || fout<0)
// 		return (printf(ERR_INVALID_FILE));

//   pid = fork();
int i=3;
char*word;
char*prev;
char*result;


prev=ft_strdup(argv[2]);
while (i < (argc-1))
{

    write(pipefd[1],argv[i],ft_strlen(word));
    read(pipefd[0],prev,1000);

                word=ft_strjoin_nconst(prev,argv[i]);;
    i++;


        

}
result=(char*)malloc(1000);

read(pipefd[0],result,1000);
printf("%s",result);
// while


//   if (pid == 0) // child process
//   {
//     printf("Child process")
//   }
//   else // parent process
//   {
//     close(pipefd[1]) // must close the write end before reading from the pipe
//     run_cmd(cmd2, pipefd[0], fout);
//   }

}



