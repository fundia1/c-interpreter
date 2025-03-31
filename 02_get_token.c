#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 1 인터프리터
// 02 토큰으로 분류
char command[100] = {0}; //100단어 내로 명멸어 받기
char * pointer;

void get_token(){
    

    while( *pointer == '\n' || *pointer == ' '){//포인터가 빈칸 잡으면 다음칸으로
        pointer ++;   
    }
    char r = *pointer;
    pointer ++;
    printf("token = %c\n",r);
}

int main(){
    pointer = command;
    printf(">>>");
    fgets(command,sizeof(command),stdin); //명령 받기
    
    get_token();
    return 0;
}