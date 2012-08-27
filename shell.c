#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

char pdr[1024];

void command_line(char *pdr)
{
    char pwd[1024] , boot_dir[1024] ;
    getcwd(pwd,1024);
    strcpy(boot_dir,pdr);
    printf("boot_dir=%s,pwd=%s\n",boot_dir,pwd);
    if(strstr(pwd, boot_dir) == pwd)
    {
        strcat(boot_dir,"/%[^\n]");
        char dir[1024] = {0};
        sscanf(pwd, boot_dir, dir);
        if(strlen(dir) == 0)
        {
            printf("<%s@%s:~>",getenv("USER"),getenv("HOSTNAME"));
        }
        else
        {
            printf("<%s@%s:~/%s>",getenv("USER"),getenv("HOSTNAME"),dir);
        }
    }
    else
    {
        printf("<%s@%s:%s>",getenv("USER"),getenv("HOSTNAME"),get_current_dir_name());
    }
}

void SIG_HANDLE()
{
    printf("\n");
    command_line(pdr);
    fflush(stdout);
}

int main()
{
    signal(SIGTSTP,SIG_IGN);
    signal(SIGINT,SIG_HANDLE);
    getcwd(pdr,1024);
    command_line(pdr);
    char command[1024];
    while(scanf("%[^\n]",command) != EOF)
    {
        getchar();
        int i = 0;
        char **array = NULL;
        array = calloc(1024,sizeof(char *));
        char *word = strtok(command," \t");
        while(word != NULL)
        {
            array[i] = word;
            word = strtok(NULL , " \t");
            i++;
        }
        array[i] = NULL;
        if( strcmp( *array , "pid" ) == 0)
        {
            printf("command name: ./a.out process id: %d\n",getpid());
            fflush(stdout);
        }
        else if( strcmp( *array , "cd" ) == 0)
        {
            int success = chdir(array[1]);
        }
        else
        {
            pid_t pid;
            pid = fork();
            if(pid == 0)
            {
                int retval = execvp(array[0],array);
                exit(retval);
            }
            else
            {
                wait();
            }
        }
        command_line(pdr);
    }
    printf("\n");
    return 0;
}
