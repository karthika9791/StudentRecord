//************************** Student Record System *****************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//****************************************************************************** 
// 
// Summary : Header file with function prototypes for menu operations.
// Note    : This module provides utilities to perform menu functions which is 
//           used to call the corresponding student functions
//
//******************************************************************************
#ifndef _INCmenuh
#define _INCmenuh

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "student.h"

typedef enum
    {
        STUDENT_OVERVIEW = 1,
        STUDENT_ADD,
        STUDENT_LIST,
        STUDENT_DELETE,
        STUDENT_EXIT,
        STUDENT_SRCH_NAME,
        STUDENT_SRT_NAME,
        STUDENT_SRT_ROLL,
        STUDENT_SRT_RANK,
        STUDENT_DLT_NAME,
        STUDENT_DLT_ROLL,
        STUDENT_DLT_ALL    
    }STUDENT_OPTION;
    
typedef struct
{
    STUDENT_OPTION eStdOptn;
    bool (*pMenuFucnHandler) (void);
}StudentMenu;

#define DLT_OFFSET    (9)
#define SEARCH_OFFSET (5)

bool menuMain(void);
static bool menuStudentOverview(void);
static bool menuAddStudent(void);
static bool menuListStudent(void);
static bool menuDeleteStudent(void);
static bool menuListSearchByName(void);
static bool menuListSortByName(void);	
static bool menuListSortByRoll(void);
static bool menuListSortByRank(void);
static bool menuDeleteByName(void);
static bool menuDeleteByRoll(void);
static bool menuDeleteAll(void);
static uint8_t menuGetUserChoice(void);
static bool menuInputString(uint8_t *dest, size_t size, const char *src);

StudentMenu pstStudentMenu[STUDENT_DLT_ALL] = 
    {
        {STUDENT_OVERVIEW, menuStudentOverview},
        {STUDENT_ADD, menuAddStudent},
        {STUDENT_LIST, menuListStudent},
        {STUDENT_DELETE, menuDeleteStudent},
        {STUDENT_EXIT, NULL},
        {STUDENT_SRCH_NAME,menuListSearchByName},
        {STUDENT_SRT_NAME, menuListSortByName},
        {STUDENT_SRT_ROLL, menuListSortByRoll},
        {STUDENT_SRT_RANK, menuListSortByRank},
        {STUDENT_DLT_NAME, menuDeleteByName},
        {STUDENT_DLT_ROLL, menuDeleteByRoll},
        {STUDENT_DLT_ALL, menuDeleteAll},
    };

#endif