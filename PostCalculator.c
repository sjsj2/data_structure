//
//  PostCalculator.c
//  HelloWorld
//
//  Created by 유수진 on 2016. 7. 7..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "PostCalculator.h"

int EvalRPNExp(char exp[])
{
    Stack stack;
    char tok,a,b;
    int i,explen;
    explen = strlen(exp);
    StackInit(&stack);
    for(i =0; i<explen;i++) {
        tok = exp[i];
        if(isdigit(tok)) {
            SPush(&stack, tok-'0');
        }else {
            a = SPop(&stack);
            b = SPop(&stack);
            switch(tok) {
                case '+':
                    SPush(&stack, a+b);
                    break;
                case '-':
                    SPush(&stack, b-a);
                    break;
                case '/':
                    SPush(&stack, b/a);
                    break;
                    case '*':
                SPush(&stack, a*b);
                    break;
            }
            
        }
    }
    return SPop(&stack);
}