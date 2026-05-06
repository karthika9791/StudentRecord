#ifndef INC_STUDENT_H
#define INC_STUDENT_H

#include <stdint.h>
#include <stdbool.h>

#define STUDENT_NAME_SIZE   (50)
#define TOTAL_SUB           (10)
#define ZERO_INITIALIZATION (0)
#define RANK_ONE            (1)
#define MAX_STUDENTS        (100)

typedef struct 
{
    char cName[STUDENT_NAME_SIZE];
    uint32_t uiRoll;
    uint32_t uiSubMark[TOTAL_SUB];
    char *cStdAddr;
    uint32_t uiSum;
    float fStdAvg;
    uint8_t ucGrade[TOTAL_SUB];
    uint32_t uiRank;
} student;

/* GLOBAL DATA (DEFINED ONLY IN student.c) */
extern student stStudent[MAX_STUDENTS];
extern uint32_t uistudentCount;

/* APIs */
bool studentCalcSum(student* pstInfo, uint32_t* pulSum);
bool studentCalcAverage(student* pstInfo, float* pfAvg);
bool studentCalcGrades(student* pstInfo, uint8_t* pucGrade);

bool studentDeleteByName(uint8_t* pucName);
bool studentDeleteByRoll(uint32_t ulRoll);
bool studentDeleteAll(void);

#endif