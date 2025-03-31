#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 1 인터프리터
// 03 토큰 타입 기입

enum {ERR,PLUS,STAR,NUMBER,LP,RP,ID,PRINT,EQL,RET} token;

char command[100] = {0}; //100단어 내로 명멸어 받기
char * pointer;

num = 0;

void get_token(){
    

    while( *pointer == '\n' || *pointer == ' '){//포인터가 빈칸 잡으면 다음칸으로
        pointer ++;   
    }
    char r = *pointer;
    

    if (r == '\0') return;

    if(r=='+') token = PLUS;
    else if (r=='*') token = STAR;
    else if (r >= '0'&& r<='9'){
        token = NUMBER;
        num = 0;
        while(*pointer >= '0'&& *pointer<='9'){
            num = num*10 + (*pointer-'0');
            pointer ++;
        }
        printf("token = %d\n",num);
        return;
    }

    else if (r=='(') token = LP;
    else if (r==')') token = RP;
    else if (r == 'p'){
        pointer ++;
        if(*pointer =='r'){
            pointer ++;
            if(*pointer =='i'){
                pointer ++;
                if(*pointer =='n'){
                    pointer ++;
                    if(*pointer =='t'){
                        token =PRINT;
                        printf("token = print\n");
                        pointer ++;
                        return;
                    }
                    else pointer -=4;
            
                }
                else pointer -=3;
            
            }
            else pointer -=2;
        }
        else pointer -=1;

        
    }
    else if (r>='a' && r<='z') token = ID;
    else if (r =='=') token = EQL;

    else if(r!=0) token = ERR;
    printf("token = %c, %d\n",r,token);
    pointer ++;
}

int main(){
    pointer = command;
    printf(">>>");
    fgets(command,sizeof(command),stdin); //명령 받기
    
    get_token();
    get_token();
    get_token();
    get_token();
 
    return 0;
}