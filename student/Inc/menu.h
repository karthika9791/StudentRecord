//*************************** String Manipulation ******************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//****************************************************************************** 
// 
// Summary : Header file with function prototypes for menu operations.
// Note    : This module provides utilities to perform menu functions which is 
//           used to call the corresponding student functions
//
//******************************************************************************
#ifndef _MENU_H_
#define _MENU_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "student.h"


typedef enum
    {
        STD_OVERVIEW = 1,
        STD_ADD,
        STD_LIST,
        STD_DELETE,
        STD_SRCH_NAME,
        STD_SRT_NAME,
        STD_SRT_ROLL,
        STD_SRT_RANK,
        STD_DLT_NAME,
        STD_DLT_ROLL,
        STD_DLT_ALL,
        STD_EXIT
    }STD_OPTION;
    
typedef struct
{
    STD_OPTION eStdOptn;
    bool (*pMenuFucnHandler) (void);
}StudentMenu;


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
StudentMenu pstStudentMenu[STD_DLT_ALL] = 
    {
        {STD_OVERVIEW, menuStudentOverview},
        {STD_ADD, menuAddStudent},
        {STD_LIST, menuListStudent},
        {STD_DELETE, menuDeleteStudent},
        {STD_SRCH_NAME,menuListSearchByName},
        {STD_SRT_NAME, menuListSortByName},
        {STD_SRT_ROLL, menuListSortByRoll},
        {STD_SRT_RANK, menuListSortByRank},
        {STD_DLT_NAME, menuDeleteByName},
        {STD_DLT_ROLL, menuDeleteByRoll},
        {STD_DLT_ALL, menuDeleteAll},
    };

#endif