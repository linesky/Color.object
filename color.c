#include <stdio.h>

char setr(char c){
    char cc=c;
    cc=cc | 1;
    return cc;
}
char setg(char c){
    char cc=c;
    cc=cc | 2;
    return cc;
}
char setb(char c){
    char cc=c;
    cc=cc | 4;
    return cc;
}
char setl(char c){
    char cc=c;
    cc=cc | 8;
    return cc;
}
char clearr(char c){
    char cc=c;
    char ccc=15-1;
    cc=cc & ccc;
    return cc;
}
char clearg(char c){
    char cc=c;
    char ccc=15-2;
    cc=cc & ccc;
    return cc;
}
char clearb(char c){
    char cc=c;
    char ccc=15-4;
    cc=cc & ccc;
    return cc;
}
char clearl(char c){
    char cc=c;
    char ccc=7;
    cc=cc & ccc;
    return cc;
}
char *names(char c){
    char *cc[]={"black","red","green","yellow","blue","violet","greenblue","white"};
    char ccc=c & 7;
    return cc[ccc];
}

int main(){
    char color=0;
    printf("\e[43;37m\n");
    color=setb(color);
    printf("\e[%dm %s \n",color+40,names(color));
    color=0;
    color=setg(color);
    printf("\e[%dm %s \n",color+40,names(color));
    color=0;
    color=setr(color);
    printf("\e[%dm %s \n",color+40,names(color));
    color=7;
    color=clearb(color);
    printf("\e[%dm %s \n",color+40,names(color));
    color=7;
    color=clearg(color);
    printf("\e[%dm %s \n",color+40,names(color));
    color=7;
    color=clearr(color);
    printf("\e[%dm %s \n",color+40,names(color));
    return 0;
}
