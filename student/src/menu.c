/* menu.c - menu file to input option, calls function in student file*/

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
17apr26, initial work
*/

/*
DESCRIPTION
This module inputs the user option by displaying various options and calls the 
respective function in student.c
INCLUDE FILES: menu.h
*/
#include "menu.h"

#define BUFFER_SIZE          (100)
#define INPUT_SIZE           (10)
/*******************************************************************************
* 
* menuGetUserChoice - Display various user input options
* 
* DESCRIPTION
* The function will display user input and calls the corresponding menu function
* in the file
* 
* PARAMETERS
* N/A
* 
* GLOBALS: menuStdntTask
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
static uint8_t menuGetUserChoice
    (
    void
    )
    {
        char cBuffer[BUFFER_SIZE];
        uint8_t ucInpNum = ZERO_INITIALIZATION;
        char * endPtr    = NULL;
        errno = ZERO_INITIALIZATION;
        if (fgets(cBuffer, sizeof(cBuffer),stdin)==NULL)
        {
            (void)printf("fgets failed\n");
        }
        ucInpNum = strtol(cBuffer,&endPtr,INPUT_SIZE);
        if (endPtr == cBuffer || errno != ZERO_INITIALIZATION)
        {
            (void)printf("Invalid Input\n");
        }
        return ucInpNum;        
    }
/*******************************************************************************
* 
* menuGetUserChoice - Display various user input options
* 
* DESCRIPTION
* The function will display user input and calls the corresponding menu function
* in the file
* 
* PARAMETERS
* N/A
* 
* GLOBALS: menuStdntTask
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool menuInputString(char *dest, size_t size, const char *src)
{
    bool lReturnFlag = true;
    if (dest == NULL || size == 0)
    {
        lReturnFlag = false;
    }
    else
    {
        if (fgets (dest, size, stdin) == NULL)
        {
            (void)printf("Unable to input string\n");
            lReturnFlag = false;
        }
    }
    return true;
}

/*******************************************************************************
* 
* menuMain.c - Display various user input options
* 
* DESCRIPTION
* The function will display user input and calls the corresponding menu function
* in the file
* 
* PARAMETERS
* N/A
* 
* GLOBALS: menuStdntTask
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool menuMain
    (
    void
    )
    {
        (void)printf("Enter the option:\n");
        uint8_t ucInpNum = ZERO_INITIALIZATION;
        uint8_t ucIndex  = ZERO_INITIALIZATION;
        do
        {
            printf("1. Student Overview\n2. Add Student\n3. List Student\n");
            printf(" 4. Delete Student\n5. Search Student by name\n");
            printf("6. Sort by name\n");
            printf("7. Sort by roll number\n8. Sort by Rank\n");   
            printf("9. Delete by name\n");  
            printf("10. Delete by rollno.\n11. Delete All\n 12. Exit\n");
            ucInpNum = menuGetUserChoice();
            for ( ; ucIndex < STD_DELETE; ucIndex++)
            {
                if (ucInpNum == pstStudentMenu[ucIndex].eStdOptn)
                {
                    pstStudentMenu[ucIndex].pMenuFucnHandler();
                }   
            }
        }while (STD_EXIT != ucInpNum);
        //printf("error\n");  
    }
/*******************************************************************************
* 
* menuStudentOverview - Displays number of students, average mark of the class
* 
* DESCRIPTION
* The function calls the corresponding function to display the student info
* 
* PARAMETERS
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: N/A
* 
* ERRNO: N/A
*
*/
static bool menuStudentOverview
    (
    void
    )
    {
        uint8_t ucIndex     = ZERO_INITIALIZATION;
        uint32_t uiTotalSum = ZERO_INITIALIZATION;
        float fAvgTotal     = ZERO_INITIALIZATION;
        bool lReturnFlag    = true;
        student *pstStudent = NULL;
        (void)printf("Total Students: %d\n",ucCount);  
        if (ucCount <= ZERO_INITIALIZATION)
        {
            (void)printf("Average = 0\n");
        }
        else
        {
            for ( ; ucIndex < ucCount; ucIndex++)
            {
                uiTotalSum += pstStudent[ucIndex].uiSum;
            }
            fAvgTotal = (float)uiTotalSum/(float)ucCount;
            (void)printf("Average = %f\n",fAvgTotal);
        }
        return lReturnFlag; 
    }
/*******************************************************************************
* 
* menuAddStudent - Function to add student to the list
* 
* DESCRIPTION
* The function calls the corresponding function in student.c to add the student
* info
* 
* PARAMETERS
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: N/A
* 
* ERRNO: N/A
*
*/
static bool menuAddStudent
    (
    void
    )
    {
        student *stStudent = (student*)malloc(sizeof(student));
        char cBuffer[BUFFER_SIZE];
        bool lReturnFlag = true;
        uint32_t ucIndex  = ZERO_INITIALIZATION;
        (void)printf("Enter Name:\n");
        lReturnFlag = menuInputString(stStudent->cName, STD_NAME_SIZE, 
            "Enter name:");
        stStudent->uiRoll = menuGetUserChoice();
        stStudent->cStdAddr = (char *)malloc(strlen(cBuffer)+1);
        if (stStudent->cStdAddr == NULL)
        {
            (void)printf("Address memory failed\n");
            lReturnFlag = false;
        }
        else
        {
            strncpy(stStudent->cStdAddr,cBuffer,strlen(cBuffer)+1);
        }
        for(; ucIndex < TOTAL_SUB; ucIndex++)
        {
            (void)printf("Enter mark of each subject:\n");
            stStudent->uiSubMark[ucIndex] = menuGetUserChoice();
        }
        studentAdd (stStudent);
        studentCalcAverage (stStudent, &stStudent->fStdAvg);
        studentCalcSum (stStudent, &stStudent->uiSum);
        studentCalcGrades (stStudent, stStudent->ucGrade);
        studentUpdateRank ();
        ucCount++;
        return lReturnFlag;  
    }
/*******************************************************************************
* 
* menuListStudent - Function to print students name based on Student List
* 
* DESCRIPTION
* The function calls the corresponding function to display student list
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
static bool menuListStudent
    (
    void
    )
    {
        uint32_t uiInpNum = ZERO_INITIALIZATION;
        uint32_t uiIndex  = ZERO_INITIALIZATION;
        bool lReturnFlag  = true;
        (void)printf("LIST STUDENT MENU\n");
        (void)printf("1. Search by name\n2. Sort by name\n3. Sort by Roll no:");
        (void)printf("\n4. Sort by Rank\n");
        uiInpNum = menuGetUserChoice();
        if(uiInpNum < STD_SRCH_NAME && uiInpNum > STD_SRT_RANK)
        {
            (void)printf("Choice out of range\n");
            lReturnFlag = false;
        }
        for(uiIndex = STD_SRCH_NAME; uiIndex <= STD_SRT_RANK; uiIndex++)
        {
            if(uiInpNum == uiIndex)
            {
                pstStudentMenu[uiIndex].pMenuFucnHandler();
            }
        }
        return lReturnFlag;
    }
/*******************************************************************************
* 
* menuDeleteStudent - Function to delete student record
* 
* DESCRIPTION
* The function is used to delete student record from based on delete student 
* menu. It provides options to delete menu.
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

static bool menuDeleteStudent
    (
    void
    )
    {
        uint32_t uiInpNum = ZERO_INITIALIZATION;
        uint32_t uiIndex  = ZERO_INITIALIZATION;
        bool lReturnFlag  = true;
        (void)printf("DELETE STUDENT MENU\n");
        (void)printf("1. Delete by name\n2. Delete by Roll no:");
        (void)printf("\n3. Delete all\n");
        uiInpNum = menuGetUserChoice();
        if(uiInpNum < STD_DLT_NAME && uiInpNum > STD_DLT_ALL)
        {
            (void)printf("Choice out of range\n");
            lReturnFlag = false;
        }
        for(uiIndex = STD_DLT_NAME; uiIndex <= STD_DLT_ALL; uiIndex++)
        {
            if(uiInpNum == uiIndex)
            {
                pstStudentMenu[uiIndex].pMenuFucnHandler();
            }
        }
        return lReturnFlag;
    }
/*******************************************************************************
* 
* menuListSearchByName - Function to search by name
* 
* DESCRIPTION
* The function will search the student record based on name given by user.
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

static bool menuListSearchByName
    (
    void
    )
    {
        bool lReturnFlag = true;
        uint32_t ucIndex = ZERO_INITIALIZATION;
        char cInpName[STD_NAME_SIZE];
        uint8_t uiStrcmp   = ZERO_INITIALIZATION;
        student stStudent[ucCount];
        lReturnFlag = menuInputString(cInpName, sizeof(cInpName),"Enter name:");
        for(; ucIndex<ucCount; ucIndex++)
        {
            uiStrcmp = strncmp(stStudent[ucIndex].cName, cInpName, 
                (strlen(cInpName)+1));
            if (uiStrcmp == ZERO_INITIALIZATION)
            {
                (void)printf("%s\n",stStudent[ucIndex].cName);
                (void)printf("%d\n",stStudent[ucIndex].uiRoll);
                (void)printf("%.2f\n",stStudent[ucIndex].fStdAvg);
                (void)printf("%d\n",stStudent[ucIndex].uiRank);
                (void)printf("%s\n",stStudent[ucIndex].cStdAddr);
            }
            else
            {
                lReturnFlag = false;
            }
        }
        return lReturnFlag;
    }
/*******************************************************************************
* 
* menuListSortByName - Function to sort bsed on name of the student
* 
* DESCRIPTION
* The function will sort the student record based on the name of student entered
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: ucStdntCnt
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
static bool menuListSortByName
    (
    void
    )
    {
        bool lReturnFlag = true;
        uint32_t ucOutIndex = ZERO_INITIALIZATION;
        uint8_t uiStrcmp   = ZERO_INITIALIZATION;
        uint32_t ucInIndex = ucOutIndex + 1;
        student stStudent[ucCount];
        if(ucCount == ZERO_INITIALIZATION)
        {
            printf("No students added\n");
        }
        else
        {
            for(; ucOutIndex < ucCount; ucOutIndex++)
            {
                for( ;ucInIndex<ucCount; ucInIndex++)
                {
                    uiStrcmp = strncmp(stStudent[ucOutIndex].cName,
                        stStudent[ucInIndex].cName,
                        strlen(stStudent[ucOutIndex].cName));
                    if(uiStrcmp > ZERO_INITIALIZATION)
                    {
                        student stTemp          = stStudent[ucOutIndex];
                        stStudent[ucOutIndex] = stStudent[ucInIndex];
                        stStudent[ucInIndex]  = stTemp;
                    } 
                    else
                    {
                        lReturnFlag = false;
                    }  
                }
            }
            for(ucOutIndex=ZERO_INITIALIZATION; ucOutIndex < ucCount;ucOutIndex)
            {
                (void)printf("%s\nRoll: %d\nRank: %d\n",
                    stStudent[ucOutIndex].cName,
                    stStudent[ucOutIndex].uiRoll,
                    stStudent[ucOutIndex].uiRank);
            }
        }
        return lReturnFlag;
    }
/*******************************************************************************
* 
* menuListSortByRoll - Function to sort bsed on roll number
* 
* DESCRIPTION
* The function will sort the student record based on the roll number
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: ucStdntCnt
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

bool menuListSortByRoll
    (
    void
    )
    {
        bool lReturnFlag = true;
        uint32_t ucOutIndex = ZERO_INITIALIZATION;
        uint8_t uiStrcmp   = ZERO_INITIALIZATION;
        uint32_t ucInIndex = ucOutIndex + 1;
        student stStudent[ucCount];
        if(ucCount == ZERO_INITIALIZATION)
        {
            printf("No students added\n");
        }
        else
        {
            for(; ucOutIndex < ucCount; ucOutIndex++)
            {
                for( ;ucInIndex<ucCount; ucInIndex++)
                {
                    if(stStudent[ucOutIndex].uiRoll>stStudent[ucInIndex].uiRoll)
                    {
                        student stTemp        = stStudent[ucOutIndex];
                        stStudent[ucOutIndex] = stStudent[ucInIndex];
                        stStudent[ucInIndex]  = stTemp;
                    } 
                    else
                    {
                        lReturnFlag = false;
                    }  
                }
            }
            for(ucOutIndex=ZERO_INITIALIZATION; ucOutIndex < ucCount;ucOutIndex)
            {
                (void)printf("%s\nRoll: %d\nRank: %d\n",
                    stStudent[ucOutIndex].cName,
                    stStudent[ucOutIndex].uiRoll,
                    stStudent[ucOutIndex].uiRank);
            }
        }
        return lReturnFlag;
    }
/*******************************************************************************
* 
* menuListSortByRank - Function to sort bsed on rank
* 
* DESCRIPTION
* The function will sort the student record based on the rank
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: ucStdntCnt
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool menuListSortByRank
    (
    void
    )
    {
        bool lReturnFlag = true;
        uint32_t ucOutIndex = ZERO_INITIALIZATION;
        uint8_t uiStrcmp   = ZERO_INITIALIZATION;
        uint32_t ucInIndex = ucOutIndex + 1;
        student stStudent[ucCount];
        if(ucCount == ZERO_INITIALIZATION)
        {
            printf("No students added\n");
        }
        else
        {
            for(; ucOutIndex < ucCount; ucOutIndex++)
            {
                for( ;ucInIndex<ucCount; ucInIndex++)
                {
                    if(stStudent[ucOutIndex].uiRank>stStudent[ucInIndex].uiRank)
                    {
                        student stTemp        = stStudent[ucOutIndex];
                        stStudent[ucOutIndex] = stStudent[ucInIndex];
                        stStudent[ucInIndex]  = stTemp;
                    } 
                    else
                    {
                        lReturnFlag = false;
                    }  
                }
            }
            for(ucOutIndex=ZERO_INITIALIZATION; ucOutIndex < ucCount;ucOutIndex)
            {
                (void)printf("%s\nRoll: %d\nRank: %d\n",
                    stStudent[ucOutIndex].cName,
                    stStudent[ucOutIndex].uiRoll,
                    stStudent[ucOutIndex].uiRank);
            }
        }
        return lReturnFlag;
    }
/*******************************************************************************
* 
* menuDeleteByName - Function to delete student record based on Name
* 
* DESCRIPTION
* The function is used to delete student record from based on the name given by
* the user. 
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

bool menuDeleteByName
    (
    void
    )
    {
        bool lReturnFlag = true;
        char cInpName[STD_NAME_SIZE];
        lReturnFlag = menuInputString(cInpName,STD_NAME_SIZE,"Enter name");
        if (lReturnFlag == true)
        {
            lReturnFlag = studentDeleteByName(cInpName);
            if(lReturnFlag == false)
            {
                (void)printf("Unable to call delete api\n");
            }
        }
        else
        {
            (void)printf("Unable to call delete function\n");
        }
        return lReturnFlag;
    }
/*******************************************************************************
* 
* menuDeleteByRoll - Function to delete student record based on Roll No:
* 
* DESCRIPTION
* The function is used to delete student record from based on the roll no: given 
* by the user. 
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

bool menuDeleteByRoll
    (
    void
    )
    {
        bool lReturnFlag  = true;
        uint8_t uiInpRoll = ZERO_INITIALIZATION;
        uiInpRoll         = menuGetUserChoice();
        if (uiInpRoll >= ZERO_INITIALIZATION)
        {
            lReturnFlag = studentDeleteByRoll(uiInpRoll);
            if(lReturnFlag == false)
            {
                (void)printf("Unable to call delete api\n");
            }
        }
        else
        {
            (void)printf("Unable to call delete function\n");
        }
        return lReturnFlag;

    }
/*******************************************************************************
* 
* menuDeleteAll - Function to delete all the student record 
* 
* DESCRIPTION
* The function is used to delete all the student record fromthe structure table
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

bool menuDeleteAll
    (
    void
    )
    {
        bool lReturnFlag = true;
        uint32_t ucIndex = ZERO_INITIALIZATION;
        student stStudent[ucCount];
        if (ucCount == ZERO_INITIALIZATION)
        {
            (void)printf("No students record\n");
        }
        for ( ; ucIndex < ucCount; ucIndex++)
        {
            if (stStudent[ucIndex].cStdAddr != NULL)
            {
                free(stStudent[ucIndex].cStdAddr);
                stStudent[ucIndex].cStdAddr = NULL;
            }
            
        }
        
        

    }

