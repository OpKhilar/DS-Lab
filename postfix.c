#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100

char stack[SIZE];
int top=-1;

void push(char item){
    if(top >= SIZE-1){
        printf("\nStack Overflow.");
    }
    else{
        top = top+1;
        stack[top]=item;
    }
}

char pop(){
    char item;
    if(top<0){
        printf("\nStack Underflow.");
        return '\0';
    }
    else{
        item=stack[top];
        top--;
        return(item);
    }
}

int is_operator(char symbol){
    if(symbol=='^'||symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/')
        return 1;
    else
        return 0;
}

int precedence(char symbol){
    if(symbol == '^'){
         return 3;
    }
    else if (symbol=='*'||symbol=='/'){
        return 2;
    }
    else if(symbol=='+'||symbol=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

void infixtoPostfix(char infix_exp[], char postfix_exp[]){
    int i=0, j=0;
    char item=infix_exp[0];
    char x;

    push('(');
    /* ensure there is room for the appended ')' */
    if (strlen(infix_exp) >= SIZE-1) {
        printf("\nExpression too long to convert.\n");
        exit(1);
    }
    strcat(infix_exp,")");

    while(item!='\0'){
        if(item=='('){
            push (item);
        }
        else if(isdigit(item)||isalpha(item)){
            postfix_exp[j]=item;
            j++;
        }
        else if(is_operator(item)==1){
            x=pop();
            while(is_operator(x)==1 && precedence(x)>=precedence(item)){
                postfix_exp[j]=x;
                j++;
                x=pop();
            }
            push(x);
            push(item);
        }
        else if (item==')'){
            x=pop();
            while(x!='('){
                postfix_exp[j]=x;
                j++;
                x=pop();
            }
        }
        else{
            printf("\nInvalid infix expression.\n");
            exit(1);
        }
        i++;
        item=infix_exp[i];
    }
    postfix_exp[j]='\0';
}

int main(){
    char infix[SIZE],postfix[SIZE];
    printf("\nEnter infix expression:");
    if(fgets(infix, SIZE, stdin) != NULL){
        size_t ln = strlen(infix) - 1;
        if(infix[ln] == '\n') infix[ln] = '\0';
    }
    infixtoPostfix(infix,postfix);
    printf("Postfix Expression:- ");
    puts(postfix);
    return 0;
}