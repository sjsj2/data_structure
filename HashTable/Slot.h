//
//  Slot.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef Slot_h
#define Slot_h

#include <stdio.h>
#include "Person.h"

typedef int Key;
typedef Person *Value;

typedef struct _slot
{
    Key key;
    Value val;
}Slot;
#endif /* Slot_h */
