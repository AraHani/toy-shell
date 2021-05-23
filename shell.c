#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_LEN_LINE    100
#define BUFF_SIZE 2048

int main(void)
{
    char command[MAX_LEN_LINE];
    char *args[] = {command, NULL};
    int ret, status;
    pid_t pid, cpid;
    
    while (true) {
        char* s;
        int len;
        char buff[BUFF_SIZE];

        printf("\nMyShell $ ");
        printf("\033[1;36m(도움말 : help 입력) : \033[0m");
        s = fgets(command, MAX_LEN_LINE, stdin);
        if (s == NULL) {
            fprintf(stderr, "fgets failed\n");
            exit(1);
        }

//이스터 에그

        if (strcmp(command, "Muyaho\n") == 0) {
            printf("\n⢀⢀⢀⢀⢀⢀⢀⢀⢀⢀⢠⣴⣾⣿⣶⣶⣆⢀⢀⢀⢀⢀⢀⢀⢀⢀⢀⢀⢀\n⢀⢀⢀⣀⢀⣤⢀⢀⡀⢀⣿⣿⣿⣿⣷⣿⣿⡇⢀⢀⢀⢀⣤⣀⢀⢀⢀⢀⢀\n⢀⢀ ⣶⢻⣧⣿⣿⠇ ⢸⣿⣿⣿⣷⣿⣿⣿⣷⢀⢀⢀⣾⡟⣿⡷⢀⢀⢀⢀\n⢀⢀⠈⠳⣿⣾⣿⣿⢀⠈⢿⣿⣿⣷⣿⣿⣿⣿⢀⢀⢀⣿⣿⣿⠇⢀⢀⢀⢀\n⢀⢀⢀⢀⢿⣿⣿⣿⣤⡶⠺⣿⣿⣿⣷⣿⣿⣿⢄⣤⣼⣿⣿⡏⢀⢀⢀⢀⢀\n⢀⢀⢀⢀⣼⣿⣿⣿⠟⢀⢀⠹⣿⣿⣿⣷⣿⣿⣎⠙⢿⣿⣿⣷⣤⣀⡀⢀⢀\n⢀⢀⢀ ⢸⣿⣿⣿⡿⢀⢀⣤⣿⣿⣿⣷⣿⣿⣿⣄⠈⢿⣿⣿⣷⣿⣿⣷⡀⢀\n⢀⢀⢀⣿⣿⣿⣿⣷⣀⣀⣠⣿⣿⣿⣿⣷⣿⣷⣿⣿⣷⣾⣿⣿⣿⣷⣿⣿⣿⣆\n⣿⣿⠛⠋⠉⠉⢻⣿⣿⣿⣿⡇⡀⠘⣿⣿⣿⣷⣿⣿⣿⠛⠻⢿⣿⣿⣿⣿⣷⣦\n⣿⣿⣧⡀⠿⠇⣰⣿⡟⠉⠉⢻⡆⠈⠟⠛⣿⣿⣿⣯⡉⢁⣀⣈⣉⣽⣿⣿⣿⣷\n⡿⠛⠛⠒⠚⠛⠉⢻⡇⠘⠃⢸⡇⢀⣤⣾⠋⢉⠻⠏⢹⠁⢤⡀⢉⡟⠉⡙⠏⣹\n⣿⣦⣶⣶⢀⣿⣿⣿⣷⣿⣿⣿⡇⢀⣀⣹⣶⣿⣷⠾⠿⠶⡀⠰⠾⢷⣾⣷⣶⣿\n⣿⣿⣿⣿⣇⣿⣿⣿⣷⣿⣿⣿⣇⣰⣿⣿⣷⣿⣿⣷⣤⣴⣶⣶⣦⣼⣿⣿⣿⣷\n");
            printf("\n\n");
            printf(".,:coodkXNNNNNNNNXXXKKKKKKKKK0000000KKKK0000000000\n.';oxddOKXXXXXXXXXXXKKKKKKK0kddoolclok0K0000000000\n,cooxxxkOOOOOO00O0KXKKKKKKOl:clooc:;',cx0000000000\n';:cdkxx0XXNNWWNNNNXKKKKOxl,;codoclc,..,d000000000\n';,':ood0XKNWWWWWWNXK0Oxl;,'',,;;,,'....;x00000000\n.''.,cooO00KXNNNNNXK0Oxl;'''',,'........:k00000000\n..,;':loxOO00KKKKKK0000xlc:;;cc:,'.....'o000000OOO\n:'''.,cldkOO00000000000kxdolcllc:;;;,'';dO0OOOOOOO\nolc,,,:loxkOO000000000Okddoooolclllc:;:cdO0OOOOOO\nlddoc,;coxxkOO0000000OOkdolldolcclccccoxOOOOOOOOOO\n,:cll;,cldxkkOOOOOOOOOdlodoodolccc::okkOOOOOOOOOOO\n''',:cccldxxkkkkkxxxdc''ldddooolcc;:dOOOOOOOOOOOOO\nc:;,':llccc:::;;,,,'...':lllllc:::,.;dkOOOOOOOOOOO\nodoc;;;;,''''..........',,;:c:;;,,...':ldkkOOOOOOO\n;lc:;'...'''...........',,,,''''''......';ldkOOOOO\n.'',,..',':c,,lc........,,,,,,'''..........,cdkOOO\n....,cclooxkdxkl;,'...''',,,,,,,'............,cdkk\n:;'.,ld 그 만 큼 dol:,,'..',,,,,'..............,lx\n:;..:xO 과 제 가 kOkc'.','..',,,,'...............;d\n''':lx 즐 거 우 시 oc:;,,,'.'',:,....',;,..... .,o\n..':loooo 다 는 dooc:;,''''..'''......';,....  .,o\n...';cdxx 거 지 dool;''''''.................   .,l\n..  .,ododxdxxddl,',,'..''''...............    .,l\n");
            continue;
        }

// 이스터 에그

        if (strcmp(command, "ls\n") == 0) {

            DIR* dir = NULL;
            char* wor_dir = (char*)malloc(sizeof(char) * 320);
 
            struct dirent* entry = NULL;

            getcwd(wor_dir, 320);

            if ((dir = opendir(wor_dir)) == NULL)
            {
                printf("디렉토리 에러");
                break;
            }



            while ((entry = readdir(dir)) != NULL) {
                printf("\033[1;31m%s\n\033[0m", entry->d_name);

            }
            printf("\n");

            free(wor_dir);
            closedir(dir);
            continue;
        }


        if (strcmp(command, "help\n") == 0)
        {
            printf("\n\033[1;33m명령어 리스트 : \n\n"
                "exit : 쉘을 종료합니다. \n"
                "ls : 디렉토리에 존재하는 내용을 확인합니다. \n"
                "pwd : 현재 작동중인 디렉토리를 표시합니다. \n"
                "info : 현재 시스템 환경 버전을 출력합니다.\n"
                "Muyaho : ???\n\033[0m\n"
            );
            continue;
        }

        if (strcmp(command, "info\n") == 0)
        {
            
            FILE* ver = popen("cat /etc/issue", "r");
            fgets(buff, BUFF_SIZE, ver);

            printf("\n");
            system("hostname");
            printf("\n Your Ubuntu version : %s \n", buff);
            printf(" Compiled by Ubuntu 20.04.2 LTS \n\n");

            continue;
        }

        if (strcmp(command, "pwd\n") == 0)
  {
            char buf[BUFF_SIZE] = { 0, };
            int bufsize;

            getcwd(buf, bufsize);

            printf("\n\033[1;35m현재 작동중인 디렉토리 : \033[0m%s , \033[1;35msize : \033[0m%d \n", buf, bufsize);
            continue;

        }

        if (strcmp(command, "exit\n") == 0) {
            char tmp[3] = "";
            printf("쉘을 종료합니다.\n");
            printf("종료하시겠습니까? : [Y / N] \n");
            scanf("%s", tmp);
            if (strcmp(tmp, "Y") == 0) {
                printf("종료합니다\n");
                break;
            }
            else
                continue;

            break;

        }

        
        


            len = strlen(command);
            printf("%d\n", len);
            if (command[len - 1] == '\n') {
                command[len - 1] = '\0';
            }

            printf("[%s]\n", command);

            pid = fork();
            if (pid < 0) {
                fprintf(stderr, "fork failed\n");
                exit(1);
            }
            if (pid != 0) {  /* parent */
                cpid = waitpid(pid, &status, 0);
                if (cpid != pid) {
                    fprintf(stderr, "waitpid failed\n");
                }
                printf("Child process terminated\n");
                if (WIFEXITED(status)) {
                    printf("Exit status is %d\n", WEXITSTATUS(status));
                }
            }
            else {  /* child */
                ret = execve(args[0], args, NULL);
                if (ret < 0) {
                    fprintf(stderr, "execve failed\n");
                    return 1;
                }
                
            }
        }
        return 0;
    }

