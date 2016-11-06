//
//  Person.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef Person_h
#define Person_h
#define STR_LEN     50

#include <stdio.h>

typedef struct _person
{
    int ssn;
    char name[STR_LEN];
    char addr[STR_LEN];
}Person;

int getSSN(Person *p);
void ShowPerInfo(Person *p);
Person* MakePersonData(int ssn, char *name, char *addr);
#endif /* Person_h */