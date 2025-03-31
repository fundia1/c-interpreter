#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 1 인터프리터
// 01 명령어 받기
char command[100] = {0}; //100단어 내로 명멸어 받기

void do_print(){
    printf("command :");
    for(int i=0;i<100;i++){
        printf("%c",command[i]);
    }
}
int main(){
    printf(">>>");
    fgets(command,sizeof(command),stdin); //명령 받기
    do_print();
    return 0;
}