//
//  Person.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "Person.h"
#include <stdlib.h>
#include <string.h>

int getSSN(Person *p)
{
    return p->ssn;
}
void ShowPerInfo(Person *p)
{
    printf("ssn : %d, name : %s, addr : %s",p->ssn,p->name,p->addr);
}
Person* MakePersonData(int ssn, char *name, char *addr)
{
    Person * p = (Person *)malloc(sizeof(Person));
    p->ssn = ssn;
    strcpy(p->name,name);
    strcpy(p->addr, addr);
    
    return p;
}