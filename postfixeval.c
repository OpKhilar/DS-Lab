
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void push(char);
char pop();
char ex[50], op1, op2;
int i;

int main(){
    printf("Enter the expression: ");
    if(fgets(ex, sizeof ex, stdin) != NULL){
        size_t ln = strlen(ex) - 1;
        if(ex[ln] == '\n') ex[ln] = '\0';
    }
    for(i=0; ex[i] != '\0'; i++){
        if(isdigit((unsigned char)ex[i]))
            push(ex[i] - '0');
        else{
            op2 = pop();
            op1 = pop();
            switch(ex[i]){
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '^':
                    push(op1 ^ op2);
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}