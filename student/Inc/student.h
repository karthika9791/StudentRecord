//*************************** String Manipulation ******************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//****************************************************************************** 
// 
// Summary : Header file with function prototypes for student operations.
// Note    : This module provides utilities to perform various student functions
//           including add, delete and sort student.
//
//****************************************************************************** 
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#define STD_NAME_SIZE       (50)
#define TOTAL_SUB           (10)
#define ZERO_INITIALIZATION (0) 
typedef struct 
{
    char cName[STD_NAME_SIZE];
    uint32_t uiRoll;
    uint32_t uiSubMark[TOTAL_SUB];
    char *cStdAddr;
    uint32_t uiSum;
    float fStdAvg;
    uint8_t ucGrade[TOTAL_SUB];
    uint32_t uiRank;
}student;
extern uint8_t ucCount;
bool studentAdd (student* pstInfo);
bool studentCalcAverage (student* pstInfo, float* pfAvg);
bool studentCalcSum (student* pstInfo, uint32_t* pulSum);
bool studentCalcGrades (student* pstInfo, uint8_t* pucSum);
bool studentUpdateRank (void);

bool studentGetCount (uint32_t* pulCount);
bool studentGetAvgMarksOfSubjects (uint8_t* pucAvgMarks);

bool studentDeleteByName (uint8_t* pucName);
bool studentDeleteByRoll (uint32_t ulRoll);
bool studentDeleteAll (void);

#endif

