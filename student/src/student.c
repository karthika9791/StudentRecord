/* student.c - student functions are provided in this file*/

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
24apr26, initial work
*/

/*
DESCRIPTION
This module is called by the menu file to perform various student operations
INCLUDE FILES: student.h
*/
#include "student.h"

student *ststudentInfoTable = NULL;
uint32_t ucCount = ZERO_INITIALIZATION;

/*******************************************************************************
* 
* studentAdd - Function enter new student
* 
* DESCRIPTION
* The function will add a new student entry to the list of students
* 
* PARAMETERS: pstInfo
* 
* GLOBALS: ucCount
*          ststudentInfoTable
*
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentAdd 
    (
    student* pstInfo
    )
    {
        uint8_t ucIndex   = ZERO_INITIALIZATION;
        student *stNewStd = (student*)malloc(sizeof(student));
        bool lReturnFlag  = true;
        if(stNewStd != NULL)
        {
            strncpy((char *)stNewStd[ucCount].cName,(const char*)pstInfo->cName,
                strlen(pstInfo->cName));
            stNewStd[ucCount].uiRoll   = pstInfo->uiRoll;
            stNewStd[ucCount].cStdAddr = (char *)malloc(strlen(pstInfo->cStdAddr));
            stNewStd[ucCount].cStdAddr = pstInfo->cStdAddr;
            for ( ; ucIndex < TOTAL_SUB; ucIndex++)
            {
                stNewStd->uiSubMark[ucIndex] = pstInfo->uiSubMark[ucIndex];
            }
            ucCount++;
        }
        else
        {
            lReturnFlag = false;
        }
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentCalcAverage - Function to calculate the averge of the mark of student
* 
* DESCRIPTION
* The function will calculate the average of mark of each student
* 
* PARAMETERS: pstInfo,
*             pfAvg
* 
* GLOBALS: ucCount, ststudentInfoTable
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentCalcAverage
    (
    student* pstInfo,
    float* pfAvg
    )
    {
        //calculate the average mark of all students
        uint32_t ulSum = ZERO_INITIALIZATION;
        bool lReturnFlag = true;
        lReturnFlag = studentCalcSum(pstInfo, &ulSum);
        if (lReturnFlag == true)
        {
            *pfAvg = (float)ulSum/(float)TOTAL_SUB;
            (void)printf("Average = %f\n",*pfAvg);
        }
        else
        {
            (void)printf("unable to calculate average\n");
            lReturnFlag = false;
        }
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentCalcSum - Function to calculate the sum of the mark of a student
* 
* DESCRIPTION
* The function will calculate the total sum of marks of all subject of each 
* student
* 
* PARAMETERS: pstInfo,
*             pfAvg
* 
* GLOBALS: ucCount, ststudentInfoTable
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentCalcSum
    (
    student* pstInfo, 
    uint32_t* pulSum
    )
    {
        uint8_t ucIndex = ZERO_INITIALIZATION;
        bool lReturnFlag= true;
        if(pstInfo == NULL || pulSum == NULL)
        {
            (void)printf("Invalid pointers\n");
            lReturnFlag = false;
        }
        else
        {
            *pulSum = ZERO_INITIALIZATION;
            for(ucIndex = ZERO_INITIALIZATION; ucIndex < TOTAL_SUB; ucIndex++)
            {
                *pulSum += pstInfo->uiSubMark[ucIndex];
            }
            (void)printf("Sum = %u\n",*pulSum);
        }
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentCalcGrades - Function calculate the grade of the student
* 
* DESCRIPTION
* The function will calculate the grade a student based on the total mark
* 
* PARAMETERS: pstInfo,
*             pucSum
* 
* GLOBALS: ucCount, ststudentInfoTable
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentCalcGrades
    (
    student* pstInfo, 
    uint8_t* pucSum
    )
    {
        //calculate grades based on mark
        bool lReturnFlag = true;
        if ((pucSum != NULL) && (pstInfo != NULL))
        {
            switch (*pucSum /TOTAL_SUB)
            {
            case 10:
            case 9:
                printf("A\n");
                break;
            case 8:
                printf("B\n");
                break;
            case 7:
                printf("C\n");
                break;
            case 6:
                printf("D\n");
                break;
            case 5:
                printf("E\n");
                break;
            default:
                printf("F\n");
                break;
            }
        }
        else
        {
            lReturnFlag = false;
        }
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentUpdateRank - Function to update the rank of student in the list
* 
* DESCRIPTION
* The function will update the a student's rank based on the mark
* 
* PARAMETERS: N/A
* 
* GLOBALS: ucCount, ststudentInfoTable
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentUpdateRank
    (
    void
    )
    {
        bool lReturnFlag   = true;
        uint8_t ucInIndex  = ZERO_INITIALIZATION;
        uint8_t ucOutIndex = ZERO_INITIALIZATION;
        uint32_t uiRank    = RANK_ONE;
        student stTempstudentInfo;
        if (ucCount == ZERO_INITIALIZATION)
        {
            lReturnFlag = false;
        }
        
        for (ucOutIndex = 0; ucOutIndex < ucCount ; ucOutIndex++)
        {
            for (ucInIndex =ucOutIndex+1; ucInIndex < ucCount; ucInIndex++)
            {
                if (ststudentInfoTable[ucOutIndex].uiSum < 
                    ststudentInfoTable[ucInIndex].uiSum)
                {
                    stTempstudentInfo = ststudentInfoTable[ucOutIndex];
                    ststudentInfoTable[ucOutIndex] = 
                        ststudentInfoTable[ucInIndex];
                    ststudentInfoTable[ucInIndex] = stTempstudentInfo;
                }
                
            }   
        }
        ststudentInfoTable[ZERO_INITIALIZATION].uiRank = uiRank;
        for (ucOutIndex = ZERO_INITIALIZATION; ucOutIndex < ucCount; 
            ucOutIndex++)
        {
            if (ststudentInfoTable[ucOutIndex].uiSum ==
                ststudentInfoTable[ucOutIndex + RANK_ONE].uiSum)
            {
                ststudentInfoTable[ucOutIndex].uiRank = uiRank;
            }
            else
            {
                uiRank = ucOutIndex + RANK_ONE;
                ststudentInfoTable[ucOutIndex].uiRank = uiRank;
            }
            
        }
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentGetCount - Function to get the count of students in the list 
* 
* DESCRIPTION
* The function will update the pointer for student number with the number of st-
* udents
* 
* PARAMETERS: pulCount
*            
* GLOBALS: ucCount, ststudentInfoTable
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentGetCount
    (  
    uint32_t* pulCount
    )
    {
        bool lReturnFlag = true;
        if(pulCount == NULL)
        {
            lReturnFlag = false;
        }
        else
        {
            *pulCount = ucCount;
        } 
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentGetAvgMarksOfSubjects - Function to get average mark of students
* 
* DESCRIPTION
* The function will find the average mark of all students 
* 
* PARAMETERS: N/A
*            
* GLOBALS: ucCount, ststudentInfoTable
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentGetAvgMarksOfSubjects
    (  
    uint8_t* pucAvgMarks
    )
    {
        bool lReturnFlag = true;
        if(pucAvgMarks == NULL)
        {
            lReturnFlag = false;
        }
        else
        {
            (void)printf("Average of subjects: %d\n",*pucAvgMarks);
        }
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentDeleteByName - Function to delete the student record based on name
* 
* DESCRIPTION
* The function will delete the student record from the list based on name given
* by the user
* 
* PARAMETERS: pucName
*            
* GLOBALS: ucCount, ststudentInfoTable
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentDeleteByName
    (  
    uint8_t* pucName
    )
    {
        uint8_t ucIndex       = ZERO_INITIALIZATION;
        uint32_t uiPucNamelen = ZERO_INITIALIZATION;
        uint8_t ucDelIndex    = ZERO_INITIALIZATION;
        uint32_t uiStrRtn     = ZERO_INITIALIZATION;
        bool lReturnFlag      = true;
        bool lNameFound       = false;
        //student ststudentInfoTable[ucCount];
        if (pucName != NULL && *pucName != '\0')
        {
            uiPucNamelen = strlen((const char*)pucName);
            for (; ucIndex < ucCount; ucIndex++)
            {
                uiStrRtn = strncmp((const char*)ststudentInfoTable[ucIndex].cName, 
                    (const char*)pucName, uiPucNamelen);
                if (uiStrRtn ==ZERO_INITIALIZATION)
                    {
                        lNameFound = true;
                        for (ucDelIndex = ucIndex; ucDelIndex < ucCount; 
                            ucDelIndex++)
                        {
                            ststudentInfoTable[ucDelIndex] = 
                                ststudentInfoTable[ucDelIndex + 1];
                        }
                        ucCount--;
                        break;
                    }
            }
            if (!lNameFound)
            {
                printf ("Name not found\n");
                lReturnFlag = false;
            }           
        }
        else
        {
            lReturnFlag = false;
        }
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentDeleteByRoll - Function to delete the student record based on roll no:
* 
* DESCRIPTION
* The function will delete the student record from the list based on roll number
* given by the user
* 
* PARAMETERS: ulRoll
*            
* GLOBALS: ucCount, ststudentInfoTable
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool  studentDeleteByRoll
    (  
    uint32_t ulRoll
    )
    {
        uint8_t ucIndex    = ZERO_INITIALIZATION;
        uint8_t ucDelIndex = ZERO_INITIALIZATION;
        bool lReturnFlag   = true;
        bool lRollnoFound  = false;
        if (ulRoll <= 0 )
        {
            for (ucIndex    = ZERO_INITIALIZATION; ucIndex < ucCount; ucIndex++)
            {
                if (ststudentInfoTable[ucIndex].uiRoll == ulRoll)
                {
                    lRollnoFound = true;
                    for (ucDelIndex = ZERO_INITIALIZATION; 
                        ucDelIndex < (ucCount - 1); ucDelIndex++)
                    {
                        ststudentInfoTable[ucDelIndex] =
                            ststudentInfoTable[ucDelIndex + 1];
                    }
                    ucCount--;    
                }
                
            }  
            if (!lRollnoFound)
            {
                printf ("Roll number not found\n");
                lReturnFlag = false;
            }
              
        }
        else
        {
            lReturnFlag = false;
        }
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentDeleteAll - Function to delete all the student record 
* 
* DESCRIPTION
* The function will delete all the student record from the list 
* given by the user
* 
* PARAMETERS: N/A
*            
* GLOBALS: ucCount, ststudentInfoTable
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentDeleteAll
    (  
    void
    )
    {
        bool lReturnFlag = true;
        //student ststudentInfoTable[ucCount];
        if (ststudentInfoTable != NULL)
        {
            memset (ststudentInfoTable, 0, ucCount*sizeof(student));
            ucCount = ZERO_INITIALIZATION;
        }
        else
        {
            lReturnFlag = false;
        }   
        return lReturnFlag;
    }