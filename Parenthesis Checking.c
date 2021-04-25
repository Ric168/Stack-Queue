#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define cakupan 100

struct Stack{
    int atas;
    char arr[cakupan];
} Stack;

void inisialisasi(){
    Stack.atas = 0;
}

bool isEmpty(){
    if(Stack.atas == 0){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if(Stack.atas == cakupan-1){
        return true;
    }else{
        return false;
    }
}

void push(char data){
    if(isFull()){
            printf("Stack is full");
    }else{
        Stack.atas++;
        Stack.arr[Stack.atas] = data;
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack is empty");
    }else{
        Stack.atas--;
    }
}

char gettop(){
    return Stack.arr[Stack.atas];
}

bool cek(char pembuka,char penutup)
{
	if(pembuka == '(' && penutup == ')') return true;
	else if(pembuka == '{' && penutup == '}') return true;
	else if(pembuka == '[' && penutup == ']') return true;
	else return false;
}

int main()
{
    char input[cakupan];
    input[cakupan] = '{'||'('||'['||']'||')'||'}';
    int panjang=0,i,j, opsi;

    inisialisasi();
do{
    printf("\nMasukan 1 untuk melanjutkan\nMasukan -1 untuk exit\nMasukan opsi: ");
    scanf("%d",&opsi);

    fflush(stdin);

    switch(opsi){

    case 1:

    printf("\nMasukan pola: ");
    scanf("%[^\n]",input);

    panjang = strlen(input);

    for(i=0;i<panjang;i++){
        if(input[i] == '(' || input[i] == '{' || input[i] == '['||input[i]=='-'||input[i]=='_'||input[i]=='0'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'||input[i]=='10'||input[i] == 'a'||input[i]=='b'||input[i]=='c'||input[i]=='d'||input[i]=='e'||input[i]=='f'||input[i]=='g'||input[i]=='h'||input[i]=='i'||input[i]=='j'||input[i]=='k'||input[i]=='l'||input[i]=='m'||input[i]=='n'||input[i]=='o'||input[i]=='p'||input[i]=='q'||input[i]=='r'||input[i]=='s'||input[i]=='t'||input[i]=='u'||input[i]=='v'||input[i]=='w'||input[i]=='x'||input[i]=='y'||input[i]=='z'){
                push(input[i]);

        }else if(input[i] == ')' || input[i] == '}' || input[i] == ']'){
            char a = gettop();
            printf("%c",a);
            if(isEmpty() || !cek(gettop(),input[i])){
                printf("\nInvalid parenthesis expression ");
                return 0;
            }else{
                pop();
            }
        }
    }

    if(isEmpty()){
        printf("\nvalid parenthesis expression\n");
    }else{
        printf("\nInvalid parenthesis expression\n");
    }
    }

}while (opsi != -1 );
return 0;
    }
