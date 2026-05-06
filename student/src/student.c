#include "student.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* GLOBAL DATA */
student stStudent[MAX_STUDENTS];
uint32_t uistudentCount = 0;

/* -------- SUM -------- */
bool studentCalcSum(student* pstInfo, uint32_t* pulSum)
{
    if (!pstInfo || !pulSum)
        return false;

    *pulSum = 0;

    for (uint32_t i = 0; i < TOTAL_SUB; i++)
    {
        *pulSum += pstInfo->uiSubMark[i];
    }

    return true;
}

/* -------- AVERAGE -------- */
bool studentCalcAverage(student* pstInfo, float* pfAvg)
{
    if (!pstInfo || !pfAvg)
        return false;

    *pfAvg = (float)pstInfo->uiSum / TOTAL_SUB;

    return true;
}

/* -------- GRADES -------- */
bool studentCalcGrades(student* pstInfo, uint8_t* pucGrade)
{
    if (!pstInfo || !pucGrade)
        return false;

    for (uint32_t i = 0; i < TOTAL_SUB; i++)
    {
        uint32_t mark = pstInfo->uiSubMark[i];

        if (mark >= 90) pucGrade[i] = 'A';
        else if (mark >= 80) pucGrade[i] = 'B';
        else if (mark >= 70) pucGrade[i] = 'C';
        else if (mark >= 60) pucGrade[i] = 'D';
        else pucGrade[i] = 'F';
    }

    return true;
}

/* -------- DELETE BY NAME -------- */
bool studentDeleteByName(uint8_t* pucName)
{
    for (uint32_t i = 0; i < uistudentCount; i++)
    {
        if (strcmp(stStudent[i].cName, (char*)pucName) == 0)
        {
            for (uint32_t j = i; j < uistudentCount - 1; j++)
            {
                stStudent[j] = stStudent[j + 1];
            }
            uistudentCount--;
            return true;
        }
    }
    return false;
}

/* -------- DELETE BY ROLL -------- */
bool studentDeleteByRoll(uint32_t ulRoll)
{
    for (uint32_t i = 0; i < uistudentCount; i++)
    {
        if (stStudent[i].uiRoll == ulRoll)
        {
            for (uint32_t j = i; j < uistudentCount - 1; j++)
            {
                stStudent[j] = stStudent[j + 1];
            }
            uistudentCount--;
            return true;
        }
    }
    return false;
}

/* -------- DELETE ALL -------- */
bool studentDeleteAll(void)
{
    uistudentCount = 0;
    return true;
}