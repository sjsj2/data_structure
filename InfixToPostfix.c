//
//  InfixToPostfix.c
//  HelloWorld
//
//  Created by 유수진 on 2016. 7. 7..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "InfixToPostfix.h"
#include "stackList.h"

int GetOpPrec(char op)
{
    switch (op) {
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
            return 1;
    }
    return -1;
}
//두 연산자의 우선순위 비교
int WhoPrecOp(char op1, char op2)
{
    int opPrec1,opPrec2;
    opPrec1 = GetOpPrec(op1);
    opPrec2 = GetOpPrec(op2);
    if(opPrec1>opPrec2) {
        return 1;
    }else if(opPrec2>opPrec1) {
        return -1;
    }else {
        return 0;
    }
}
//후위 수식으로 변환
void ConvToRPNExp(char exp[])
{
    Stack stack;
    int explen = strlen(exp);
    int i,idx =0;
    char *convExp = (char*)malloc(explen+1);
    char tok,popop;
    
    memset(convExp,0,explen+1);
    StackInit(&stack);
    for(i =0; i<explen;i++)
    {
        tok = exp[i];
        if(isdigit(tok)) { //10진수 = 1반환
            convExp[idx++] = tok;
        }else {
            if(SIsEmpty(&stack)) {
                SPush(&stack, (Data)tok);
            }else {
                switch (tok) {
                    case '(':
                        SPush(&stack, tok);
                        break;
                    case ')':
                        while(1) {
                            popop = SPop(&stack);
                            if(popop == '(') {
                                break;
                            }
                            convExp[idx++] = popop;
                            
                        }
                        break;
                    case '*' : case '+' :
                    case '-' : case '/' :
                        while(!SIsEmpty(&stack) && WhoPrecOp(SPeak(&stack),tok)>0) {
                            convExp[idx++] = SPop(&stack);
                        }
                        SPush(&stack,tok);
                        break;
                }
            }
        }
    }
    
    while(!SIsEmpty(&stack)) {
        convExp[idx++] = SPop(&stack);
    }
    strcpy(exp,convExp);
    free(convExp);
}
