#include <stdio.h>
#include <ctype.h>
#include <string.h>
int stack[100];
int top=-1;
void main() {
    char exp[100];
    int i,a,b;
    printf("Enter prefix expression: ");
    scanf("%s",exp);
    for(i=strlen(exp)-1;i>=0;i--) {
        if(isdigit(exp[i])) {
            stack[++top]=exp[i]-'0';
        }
        else {
            a=stack[top--];
            b=stack[top--];
            if(exp[i]=='+')
            stack[++top]=a+b;
            else if(exp[i]=='-')
            stack[++top]=a-b;
            else if(exp[i]=='*')
            stack[++top]=a*b;
            else if(exp[i]=='/')
            stack[++top]=a/b;
        }
    }
    printf("Result = %d",stack[top]);
}
