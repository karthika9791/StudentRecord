#include "menu.h"

/* -------- FUNCTION TABLE -------- */
static stMenu gstMainMenu[] =
{
    {STUDENT_OVERVIEW, menuStudentOverview},
    {STUDENT_ADD,      menuAddStudent},
    {STUDENT_LIST,     menuListStudent},
    {STUDENT_DELETE,   menuDeleteStudent}
};

/* -------- MAIN MENU -------- */
bool menuMain(void)
{
    uint32_t choice;

    do
    {
        printf("\n===== STUDENT MENU =====\n");
        printf("1. Overview\n2. Add\n3. List\n4. Delete\n5. Exit\n");

        choice = menuGetUserChoice();

        if (choice >= 1 && choice <= 4)
        {
            for (uint32_t i = 0; i < 4; i++)
            {
                if (gstMainMenu[i].eOption == choice)
                {
                    gstMainMenu[i].pFunc();
                }
            }
        }

    } while (choice != STUDENT_EXIT);

    return true;
}

/* -------- OVERVIEW -------- */
bool menuStudentOverview(void)
{
    uint32_t total = 0;

    printf("Total Students: %u\n", uistudentCount);

    for (uint32_t i = 0; i < uistudentCount; i++)
    {
        total += stStudent[i].uiSum;
    }

    if (uistudentCount > 0)
    {
        printf("Average: %.2f\n", (float)total / uistudentCount);
    }

    return true;
}

/* -------- ADD -------- */
bool menuAddStudent(void)
{
    if (uistudentCount >= MAX_STUDENTS)
        return false;

    student *s = &stStudent[uistudentCount];
    char buffer[100];

    menuInputString((uint8_t*)s->cName, STUDENT_NAME_SIZE, "Enter Name:");
    printf("Enter Roll:\n");
    s->uiRoll = menuGetUserChoice();

    menuInputString((uint8_t*)buffer, 100, "Enter Address:");
    s->cStdAddr = malloc(strlen(buffer) + 1);
    strcpy(s->cStdAddr, buffer);

    printf("Enter Marks:\n");
    for (int i = 0; i < TOTAL_SUB; i++)
    {
        s->uiSubMark[i] = menuGetUserChoice();
    }

    studentCalcSum(s, &s->uiSum);
    studentCalcAverage(s, &s->fStdAvg);
    studentCalcGrades(s, s->ucGrade);

    uistudentCount++;

    return true;
}

/* -------- LIST -------- */
bool menuListStudent(void)
{
    for (uint32_t i = 0; i < uistudentCount; i++)
    {
        printf("%s | Roll: %u | Avg: %.2f\n",
               stStudent[i].cName,
               stStudent[i].uiRoll,
               stStudent[i].fStdAvg);
    }
    return true;
}

/* -------- DELETE -------- */
bool menuDeleteStudent(void)
{
    uint32_t choice;

    printf("1.Delete by Name 2.Delete by Roll 3.Delete All\n");
    choice = menuGetUserChoice();

    if (choice == 1) return menuDeleteByName();
    if (choice == 2) return menuDeleteByRoll();
    if (choice == 3) return menuDeleteAll();

    return false;
}

bool menuDeleteByName(void)
{
    char name[STUDENT_NAME_SIZE];
    menuInputString((uint8_t*)name, sizeof(name), "Enter Name:");
    return studentDeleteByName((uint8_t*)name);
}

bool menuDeleteByRoll(void)
{
    printf("Enter Roll:\n");
    return studentDeleteByRoll(menuGetUserChoice());
}

bool menuDeleteAll(void)
{
    return studentDeleteAll();
}

/* -------- INPUT -------- */
uint32_t menuGetUserChoice(void)
{
    uint32_t x;
    scanf("%u", &x);
    getchar();
    return x;
}

bool menuInputString(uint8_t *buf, uint32_t size, const char *msg)
{
    printf("%s\n", msg);

    if (fgets((char*)buf, size, stdin) == NULL)
        return false;

    buf[strcspn((char*)buf, "\n")] = 0;
    return true;
}