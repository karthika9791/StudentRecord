/* main.c - menu file to input option, calls function in student file*/

/*
* Copyright (c) 2026 Trenser Technology Solutions(P), Ltd.
*
* The right to copy, distribute, modify, or otherwise make use 
* of this software may be licensed only pursuant to the terms 
* of an applicable Trenser Technology Solutions(P), Ltd license agreement.
*/

/*
modification history
--------------------
23apr26, initial work
*/

/*
DESCRIPTION
This file is the entry point to the student mark system. It calls the menuMain 
API
INCLUDE FILES: main.h
*/
#include "main.h"
/*******************************************************************************
* 
* main.c - Entry function for student mark system
* 
* DESCRIPTION
* The function will call the API to be used to call the student record system
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: menuStdntTask
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
int main
    (
    void
    )
    {
        bool lReturnFlag = true;
        lReturnFlag = menuMain();
        if (lReturnFlag == false)
        {
            (void)printf("Unable to call menuMain\n");
        }
        return 0;
    }