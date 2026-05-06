#ifndef INC_MENU_H
#define INC_MENU_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "student.h"

/* ENUM */
typedef enum
{
    STUDENT_OVERVIEW = 1,
    STUDENT_ADD,
    STUDENT_LIST,
    STUDENT_DELETE,
    STUDENT_EXIT
} eStudentMenu;

/* FUNCTION POINTER STRUCT */
typedef struct
{
    eStudentMenu eOption;
    bool (*pFunc)(void);
} stMenu;

/* APIs */
bool menuMain(void);

uint32_t menuGetUserChoice(void);
bool menuInputString(uint8_t *pucBuf, uint32_t uiSize, const char *pcMsg);

bool menuStudentOverview(void);
bool menuAddStudent(void);
bool menuListStudent(void);
bool menuDeleteStudent(void);

bool menuListSearchByName(void);
bool menuListSortByName(void);
bool menuListSortByRoll(void);
bool menuListSortByRank(void);

bool menuDeleteByName(void);
bool menuDeleteByRoll(void);
bool menuDeleteAll(void);

#endif