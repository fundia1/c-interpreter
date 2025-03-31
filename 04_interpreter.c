#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 1 인터프리터
// statement → id = expr → \n
//            → print → expr → \n

// <expr> → <term> + <term>
//         | <term>

// <term> → <factor> * <factor>
//         | <factor>

// <factor> → ( <expr> )
//           | number
//           | id

enum {ERR,PLUS,STAR,NUMBER,LP,RP,ID,PRINT,EQL,RET} token;

char command[100] = {0}; //100단어 내로 명멸어 받기
char * pointer;

num = 0; 
char array[26]; // a=2 할때 쓸 a 넣을 자리 
char alphabet;


int expr ( );
int term();
int factor();
void error();

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
    
    
    else if (r>='a' && r<='z') {
        alphabet = r;
        token = ID;
        if (r == 'p'){
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
    }
    else if (r =='=') token = EQL;

    else if(r!=0) token = ERR;
    printf("token = %c,\n",r);
    pointer ++;
}

void statement() {
    if (token == ID) {
        get_token();
        if (token == EQL) {
            get_token();
            array[(alphabet-'a')] = expr();
            printf("%c = %d\n", alphabet, array[(alphabet-'a')]);
        } else {
            error();
        }
    } else if (token == PRINT) {
        get_token();
        printf("print : %d\n", expr());
    } else {
        error();
    }
}

int expr ( ) {
    int r;
    r=term();
    while (token==PLUS) {
        get_token();
        r=r+term( );}
    return (r);
}
int term(){
    int r;
    r=factor();
    while (token == STAR){
        get_token();
        r=r*factor();
    }
    return (r);
}
int factor(){
    int r;
    if(token == NUMBER){
        r = num;
        get_token();
    }
    else if(token == ID){
        r=array[(alphabet-'a')];
        get_token();
    }
    else if (token == LP){
        get_token();
        r=expr();
        if (token==RP){
            get_token();
        }
        else{
            error();
        }
    }
    else{
        error();

    }
    return (r);
    
}

void error(){
    printf("error");
    exit(1);
    
}

int main(){
    while (1) {
        printf(">>> ");
        if (!fgets(command, sizeof(command), stdin)) break;
        pointer = command;
        get_token();
        statement();
    }
    return 0;
}