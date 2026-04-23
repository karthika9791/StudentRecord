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
17apr26, initial work
*/

/*
DESCRIPTION
This module is called by the menu file to perform various student operations
INCLUDE FILES: student.h
*/
#include "student.h"

uint8_t ucCount = ZERO_INITIALIZATION;
/*******************************************************************************
* 
* studentAdd - Function enter new student
* 
* DESCRIPTION
* The function will add a new student entry to the list of students
* 
* PARAMETERS: pstInfo
* 
* GLOBALS: menuStdntTask
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
        //add the structure inside the student info table
        return true;
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
* GLOBALS: N/A
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
        return true;
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
* GLOBALS: menuStdntTask
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
        //calculate the sum of all students
        return true;
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
* GLOBALS: N/A
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
        return true;
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
* GLOBALS: menuStdntTask
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
        //update rank based on marks
        return true;
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
* GLOBALS: N/A
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
        //get the total count of students
        return true;
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
* GLOBALS: N/A
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
        //get average marks of each subjects
        return true;
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
* GLOBALS: N/A
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
        return true;
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
* GLOBALS: N/A
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
        return true;
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
* GLOBALS: N/A
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
        return true;
    }