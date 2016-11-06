//
//  stackMain.c
//  HelloWorld
//
//  Created by 유수진 on 2016. 7. 6..
//  Copyright © 2016년 유수진. All rights reserved.
//

//#include "stackArray.h"
#include "stackList.h"
#include "InfixToPostfix.h"
#include "PostCalculator.h"
int main(void)
{
    /*
    Stack stack;
    StackInit(&stack);
    
    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 4);
    SPush(&stack, 16);
    
    while(SIsEmpty(&stack) == FALSE)
    {
        printf("%d\n",SPop(&stack));
    }
    printf("%d\n",SPeak(&stack));
     */
    char ch1[]= "1+2+(3-2*3)";
    char ch2[] = "((1-2)+3)*(5-2)";
    ConvToRPNExp(ch1);
    ConvToRPNExp(ch2);
    
    printf("%s = %d \n",ch1,EvalRPNExp(ch1));
    printf("%s = %d \n",ch2,EvalRPNExp(ch2));
}