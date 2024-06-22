#include <stdio.h>
#include <string.h>

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
    char *cc[]={"black","red","green","yellow","blue","magenta","cyan","white"};
    char ccc=c & 7;
    return cc[ccc];
}
char value(char *c){
    int i=0;
    for(i=0;i<8;i++){
        if(strcmp(c,names(i))==0)return (char)i;
    }
    return 0;
}

int main(){
    char color=0;
    printf("\e[43;37m\n");
    color=setb(color);
    printf("\e[%xm %s \n",color+0x40,names(color));
    color=0;
    color=setg(color);
    printf("\e[%xm %s \n",color+0x40,names(color));
    color=0;
    color=setr(color);
    printf("\e[%xm %s \n",color+0x40,names(color));
    color=7;
    color=clearb(color);
    printf("\e[%xm %s \n",color+0x40,names(color));
    color=7;
    color=clearg(color);
    printf("\e[%xm %s \n",color+0x40,names(color));
    color=7;
    color=clearr(color);
    printf("\e[%xm %s \n",color+0x40,names(color));
    color=value("black");
    printf("\e[%xm",color+0x30,names(color));
    color=value("white");
    printf("\e[%xm %s \n",color+0x40,names(color));
    return 0;
}
