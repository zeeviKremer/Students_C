#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include "query.h"




//studendManger
//--------------------------------------------------------------------------------------------

#define MAX_LINE  256
#define COURSES  3
//מערך של סטרינגים לשמות הקורסים
typedef struct student {
    char* FirstName;
    char* SecondName;
    char Id[10];
    int courses[COURSES];
    float average;
    struct student* next;
}student;

student* raedFile(student* head,int* checkFile);
student* createNode(char* line);
int existInList(student* head, student* stud);
student* getPtrToNode(student* head, student* newStud);
void updateStudent(student* ptrStud, student* stud1);
student* getIndexToInsert(student* head, student* tail, student* newStud);
void addTolist(student** head, student** tail, student* ptrPrv, student* newStud);
void printTitle();
void printFuter();
void printNode(student* stud);
void printList(student* head);
int selectFromList(student* head, char* fild, char* operat, char* data, student** newList);


//validtions
//----------------------------------------------------------------------------------------

int isChars(char* line);
int properId(char* line);
int checkCoursName(char* line);
int isScore(char* line);
int checkOperator(char* operator);
int checkNamesData(char* data);
int checkIdData(char* data);
int checkScoresData(char* data);
int checkFildName(char* data);
int validationRow(char* Row);
int validetionSelectQuety(char* queryLine, char* fild, char* operator, char* data);
int validationSetQuety(char* line1);



//qweri
//------------------------------------------------------------------------------
void runQueries(student* head);
int checkQweri(char* query, student* head);
char* convertToFileSyntax(char* queryLine);


int main() {		
	char  queryLine[100];
    int checkFile = 0;
	student* head=NULL;	
    FILE* fRead;
    
    head = raedFile(head,&checkFile);   
    if (checkFile)
    {
        printf("error in file error number");//אם הקובץ לא נפתח או שהוא ריק
        exit(1);
    }
    else
    {
        runQueries(head);
        //upsate the file;;;;;
    }
            
	return 0;
}



//studendManger
//--------------------------------------------------------------------------------------------

/*open the file , read the data , bild the list , clos the file*/
student* raedFile(student* head, int* checkFile)
{
    char row[MAX_LINE];
    int checkSyntax = 0, isExist, countRows = 0;    
    student* tail=NULL, * newStud, * ptrPrv, * ptrNode;
    FILE* fRead;
    
    fRead = fopen("students.csv", "rt");
    if (fRead == NULL)
    {
        *checkFile = 1;
        return head;
    }       
    do
    {
        if (countRows > 0)
        {
            fseek(fRead, -1, SEEK_CUR);
        }
        fgets(row, MAX_LINE, fRead);
        countRows++;
        if (row[strlen(row) - 1] == '\n')
        {
            row[strlen(row) - 1] = '\0';        
            checkSyntax = validationRow(row);
            if (checkSyntax)
                printf("error in file line number %d error number is %d", countRows, checkSyntax);
            else
            {
            
                newStud = createNode(row);                   
                isExist = existInList(head, newStud);            
                if (isExist == -1) {
                    printf("error in file line number %d error number is %d", countRows, isExist);
                    free(newStud);
                }
                else if (isExist == 1)
                {                                
                    ptrNode = getPtrToNode(head, newStud);                       
                    updateStudent(ptrNode, newStud);
                    free(newStud);
                    
                }
                else if (!(isExist))
                {               
                    ptrPrv = getIndexToInsert(head,tail, newStud);
                    addTolist(&head,&tail, ptrPrv, newStud);                        
                }                
            }
        }
        else
        {
            while (fgetc(fRead) != '\n');
            printf("error in file line number %d error number is %d", countRows, 2);
        }
    } while (fgetc(fRead) != EOF);
    fclose(fRead);
    printList(head);       
    return head;
}

/*create a new node , insert the valeu , return a ponter to the node*/
student* createNode(char* line)
{
    char* firsName, * secondName, * token, ch[2] = ",";
    student* newStude;
    int i, sum = 0, caunt = 0;
    newStude = (student*)malloc(sizeof(student));
    if (newStude == NULL)
        return newStude;
    token = strtok(line, ch);
    firsName = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(firsName, token);
    strcpy(firsName + strlen(token), "\0");
    newStude->FirstName = firsName;
    token = strtok(NULL, ch);
    secondName = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(secondName, token);
    strcpy(secondName + strlen(token), "\0");
    newStude->SecondName = secondName;
    token = strtok(NULL, ch);
    strcpy(newStude->Id, token);
    newStude->Id[(strlen(token) + 1)] = '\0';
    token = strtok(NULL, ch);
    for (i = 0; i < 3; i++)
        newStude->courses[i] = -1;
    if (strcmp(token, "C language") == 0)
    {
        token = strtok(NULL, ch);
        newStude->courses[0] = atoi(token);
    }
    else if (strcmp(token, "Computer Networks") == 0)
    {
        token = strtok(NULL, ch);
        newStude->courses[1] = atoi(token);
    }
    else if (strcmp(token, "CS Fundamentals") == 0)
    {
        token = strtok(NULL, ch);
        newStude->courses[2] = atoi(token);
    }
    for (i = 0; i < 3; i++)
    {
        if (newStude->courses[i] > -1)
        {
            caunt++;
            sum += newStude->courses[i];
        }
    }
    newStude->average = ((float)sum / (float)caunt);
    newStude->next = NULL;

    return newStude;
}

/*return 1 if the student is exist in the list or 0 if thet not exist in the list
 or -1 if exist a student with tis id and firstName or secondName is different*/
int existInList(student* head, student* stud)
{
    int rez = 0;
    student* ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(ptr->Id, stud->Id) == 0)
        {
            if (strcmp(ptr->FirstName, stud->FirstName) == 0 && strcmp(ptr->SecondName, stud->SecondName) == 0)
            {               
                rez = 1;
                return rez;
            }
            else
            {
                rez = -1;
                return rez;
            }
        }
        ptr = ptr->next;
    }

    return rez;
}

/*return a ponter to the node thet is like to the current node*/
student* getPtrToNode(student* head, student* newStud)
{
    student* ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(ptr->Id, newStud->Id)==0)
            return ptr;
        ptr = ptr->next;
    }
}

/*update the olde Student from the new student*/
void updateStudent(student* ptrStud, student* newStud)
{
    int i, sum = 0, caunt = 0;    
    ptrStud->FirstName = newStud->FirstName;
    ptrStud->SecondName = newStud->SecondName;
    strcpy(ptrStud->Id, newStud->Id);
    for (i = 0; i < 3; i++)
    {
        if (newStud->courses[i] > -1)
            ptrStud->courses[i] = newStud->courses[i];
        if (ptrStud->courses[i] > -1)
        {
            caunt++;
            sum += ptrStud->courses[i];
        }
    }
    ptrStud->average = ((float)sum / (float)caunt);
}

/*return the node befor the index that is where the place to put the new node*/
student* getIndexToInsert(student* head, student* tail, student* newStud)
{
    student* ptrCur = head, * ptrPrv = NULL;
    if (ptrCur == NULL || strcmp(ptrCur->SecondName, newStud->SecondName) > 0)
        return ptrPrv;
    else if (strcmp(tail->SecondName, newStud->SecondName) > 0)
        return tail;
    else
    {
        ptrPrv = head;

        while (ptrCur->next != NULL)
        {           
            ptrPrv = ptrCur;
            ptrCur = ptrCur->next;
            if (strcmp(ptrCur->SecondName, newStud->SecondName) > 0)
                return ptrPrv;
        }
        return ptrCur;
    }    
}

/*adding a node to the list by sorted*/
void addTolist(student** head, student** tail, student* ptrPrv, student* newStud)
{
    student* ptrStud ;
    if (ptrPrv == NULL)
    {
        if (*head == NULL)
        {
            newStud->next = *head;
            *head = newStud;
            *tail = newStud;
        }
        else
        {
            ptrStud = newStud;
            newStud->next = *head;
            *head = newStud;  
            while (ptrStud->next != NULL)
                ptrStud = ptrStud->next;
            *tail = ptrStud;
        }        
       
    }
    else
    {
        if (ptrPrv->next == NULL)
        {
            *tail = newStud;
            newStud->next = ptrPrv->next;
            ptrPrv->next = newStud;
        }
        else
        {
            newStud->next = ptrPrv->next;
            ptrPrv->next = newStud;
            ptrStud = *head;
            while (ptrStud->next != NULL)
                ptrStud = ptrStud->next;
            *tail = ptrStud;
        }                
    }
}

/*ptinted thr fildNames*/
void printTitle()
{
    printf("\n--------------------------------------------------------------------------------------------------------------------\n");
    printf("| First Name | Second Name  |     ID    |     C Language     |  Computer Networks |   CS Fundamentals  |  Average  |\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
}

void printFuter()
{
    printf("--------------------------------------------------------------------------------------------------------------------\n\n");
}

/*printed one node */
void printNode(student* stud)
{
    int i;
    printf("|  %-8s  |  %-8s    |%10s |", stud->FirstName, stud->SecondName, stud->Id);
    for (i = 0; i < 3; i++)
    {
        if (stud->courses[i] > -1)
        {
            printf("%11d         |", stud->courses[i]);
        }
        else
            printf("         ~          |");
    }
    if (stud->average > -1)
    {
        printf(" %8.2f  |", stud->average);
    }
    else
        printf("      ~    |");
    printf("\n");
}

/*printed the list */
void printList(student* head)
{
    student* ptrStud = head;
    printTitle();
    while (ptrStud != NULL)
    {
        printNode(ptrStud);
        ptrStud = ptrStud->next;
    }
    printFuter();
}

/*return 0 if not found  students were like to the query and 1 if found ,
  if found thet bild a arey of pointers to Nodes thet like to the query*/
int selectFromList(student* head, char* fild, char* operat, char* data, student** newList)
{
    student* ptrStud = head;
    int index = 0, rez = 0, i;
    char fildNames[7][20] = { "firstName","secondName","ID" ,"CLanguage" ,"ComputerNetworks" ,"CSFundamentals" ,"Average" };
    while (ptrStud != NULL)
    {
        if (strcmp(fild, "firstname") == 0)
        {
            if (strcmp(operat, "=") == 0)
            {
                if (strcmp(ptrStud->FirstName, data) == 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "!=") == 0)
            {
                if (strcmp(ptrStud->FirstName, data) != 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">") == 0)
            {
                if (strcmp(ptrStud->FirstName, data) > 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<") == 0)
            {
                if (strcmp(ptrStud->FirstName, data) < 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">=") == 0)
            {
                if (strcmp(ptrStud->FirstName, data) >= 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<=") == 0)
            {
                if (strcmp(ptrStud->FirstName, data) <= 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
        }
        else if (strcmp(fild, "secondname") == 0)
        {
            if (strcmp(operat, "=") == 0)
            {
                if (strcmp(ptrStud->SecondName, data) == 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "!=") == 0)
            {
                if (strcmp(ptrStud->SecondName, data) != 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">") == 0)
            {
                if (strcmp(ptrStud->SecondName, data) > 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<") == 0)
            {
                if (strcmp(ptrStud->SecondName, data) < 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">=") == 0)
            {
                if (strcmp(ptrStud->SecondName, data) >= 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<=") == 0)
            {
                if (strcmp(ptrStud->SecondName, data) <= 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
        }
        else if (strcmp(fild, "id") == 0)
        {
            if (strcmp(operat, "=") == 0)
            {
                if (strcmp(ptrStud->Id, data) == 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "!=") == 0)
            {
                if (strcmp(ptrStud->Id, data) != 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">") == 0)
            {
                if (strcmp(ptrStud->Id, data) > 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<") == 0)
            {
                if (strcmp(ptrStud->Id, data) < 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">=") == 0)
            {
                if (strcmp(ptrStud->Id, data) >= 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<=") == 0)
            {
                if (strcmp(ptrStud->Id, data) <= 0)
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
        }
        else if (strcmp(fild, "clanguage") == 0)
        {
            if (strcmp(operat, "=") == 0)
            {
                if (ptrStud->courses[0] == atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "!=") == 0)
            {
                if (ptrStud->courses[0] != atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">") == 0)
            {
                if (ptrStud->courses[0] > atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<") == 0)
            {
                if (ptrStud->courses[0] < atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">=") == 0)
            {
                if (ptrStud->courses[0] >= atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<=") == 0)
            {
                if (ptrStud->courses[0] <= atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
        }
        else if (strcmp(fild, "computernetworks") == 0)
        {
            if (strcmp(operat, "=") == 0)
            {
                if (ptrStud->courses[1] == atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "!=") == 0)
            {
                if (ptrStud->courses[1] != atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">") == 0)
            {
                if (ptrStud->courses[1] > atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<") == 0)
            {
                if (ptrStud->courses[1] < atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">=") == 0)
            {
                if (ptrStud->courses[1] >= atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<=") == 0)
            {
                if (ptrStud->courses[1] <= atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
        }
        else if (strcmp(fild, "csfundamentals") == 0)
        {
            if (strcmp(operat, "=") == 0)
            {
                if (ptrStud->courses[2] == atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "!=") == 0)
            {
                if (ptrStud->courses[2] != atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">") == 0)
            {
                if (ptrStud->courses[2] > atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<") == 0)
            {
                if (ptrStud->courses[2] < atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">=") == 0)
            {
                if (ptrStud->courses[2] >= atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<=") == 0)
            {
                if (ptrStud->courses[2] <= atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
        }
        else if (strcmp(fild, "average") == 0)
        {
            if (strcmp(operat, "=") == 0)
            {
                if (ptrStud->average == atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "!=") == 0)
            {
                if (ptrStud->average != atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">") == 0)
            {
                if (ptrStud->average > atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<") == 0)
            {
                if (ptrStud->average < atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, ">=") == 0)
            {
                if (ptrStud->average >= atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
            else if (strcmp(operat, "<=") == 0)
            {
                if (ptrStud->average <= atoi(data))
                {
                    newList[index] = ptrStud;
                    index++;
                    rez = 1;
                }
            }
        }
        ptrStud = ptrStud->next;
    }
    return rez;
}



//validtions
//----------------------------------------------------------------------------------------
/*return 0 if the syntax of the line is good , 1 if the line is null ,
  2 if the line including chars thet not letters*/
int isChars(char* line)
{
    int rez = 0, i = 0;
    if (line == NULL)
    {
        rez = 1;
        return rez;
    }
    else
    {
        while (line[i] != '\0')
        {
            if (!(line[i] >= 'A' && line[i] <= 'Z' || line[i] >= 'a' && line[i] <= 'z'))
            {
                rez = 2;
                return rez;
            }
            i++;
        }
    }

    return rez;
}

/*return 0 if the syntax of the line is good , 1 if the line is null ,
  3 if the line including chars thet not numbers , 4 if the length of the line is not 9 chars */
int properId(char* line)
{
    int rez = 0, i = 0;
    if (line == NULL)
    {
        rez = 1;
        return rez;
    }
    else
    {
        while (line[i] != '\0')
        {
            if (!(line[i] >= '0' && line[i] <= '9'))
            {
                rez = 3;
                return rez;
            }
            i++;
        }
        if (i != 9)
        {
            rez = 4;
            return rez;
        }
    }

    return rez;
}

/*return 0 if the syntax of the line is good , 1 if the line is null ,
  5 if not exist a coursName like the line  */
int checkCoursName(char* line)
{
    int rez = 0;
    if (line == NULL)
    {
        rez = 1;
        return rez;
    }
    else
    {
        if (strcmp(line, "C language") == 0)
            return rez;
        else if (strcmp(line, "Computer Networks") == 0)
            return rez;
        else if (strcmp(line, "CS Fundamentals") == 0)
            return rez;
        else
        {
            rez = 5;
            return rez;
        }
    }
}

/*return 0 if the syntax of the line is good , 1 if the line is null ,
  6 if the line including chars thet not numbers , 7 if the sum of the numbers in the line is greater than 100  */
int isScore(char* line)
{
    int rez = 0, i = 0, num = 0;
    if (line == NULL)
    {
        rez = 1;
        return rez;
    }
    else
    {
        while (line[i] != '\0')
        {
            if (!(line[i] >= '0' && line[i] <= '9'))
            {
                rez = 6;
                return rez;
            }
            num *= 10;
            num += line[i] - '0';
            if (num > 100)
            {
                rez = 7;
                return rez;
            }
            i++;
        }
    }

    return rez;
}

int checkOperator(char* operator)
{
    int rez = 1;
    if (strlen(operator) == 1)
    {
        if (strcmp(operator,"=") != 0 && strcmp(operator,"<") != 0 && strcmp(operator,">") != 0)
            rez = 0;
    }
    else if (strlen(operator) == 2)
    {
        if (strcmp(operator,"!=") != 0 && strcmp(operator,"<=") != 0 && strcmp(operator,">=") != 0)
            rez = 0;
    }
    else if (strlen(operator) > 2)
        rez = 0;


    return rez;
}

int checkNamesData(char* data)
{
    int i = 0, rez = 1;
    while (data[i] != '\0')
    {
        if (data[i] < 'a' || data[i]>'z')
            rez = 0;
        i++;
    }
    return rez;
}

int checkIdData(char* data)
{
    int i = 0, rez = 1, caunt = 0;
    while (data[i] != '\0')
    {
        if (data[i] < '0' || data[i]>'9')
            rez = 0;
        i++;
        caunt++;
    }
    if (caunt != 9)
        rez = 0;
    return rez;
}

int checkScoresData(char* data)
{
    int scor, rez = 1;
    scor = atoi(data);
    if (scor < -1 || scor > 100)
        rez = 0;
    return rez;
}


int checkFildName(char* queryRow)
{
    char* temp,*fild;
    int index = 0, range, i = 0, j = 0, isProper = 0;
    while (queryRow[index] == ' ')
        index++;
    range = index;
    while (queryRow[range] >= 'a' && queryRow[range] <= 'z' || queryRow[range] >= 'A' && queryRow[range] <= 'Z' || queryRow[range] == ' ')
        range++;
    temp = (char*)malloc(sizeof(char) * range - index + 1);
    if (temp == NULL)
    {
        printf("problem in memory");
        return 0;
    }
    fild = (char*)malloc(sizeof(char) * range - index + 1);
    if (fild == NULL)
    {
        printf("problem in memory");
        return 0;
    }
    strncpy(temp, queryRow + index, range - index);
    temp[range - index] = '\0';
    while (temp[i] != '\0')
    {
        if (temp[i] != ' ')
        {
            if (temp[i] >= 'A' && temp[i] <= 'Z')
            {
                fild[j] = tolower(temp[i]);
                j++;
            }
            else
            {
                fild[j] = temp[i];
                j++;
            }
        }

        i++;
    }
    fild[j] = '\0';
    queryRow += range;
    return 1;
}

/*return 0 if the syntax of the line is good , 1 if the line is null or does not contain five columns,
  2 if the firstName or secondName including chars thet not letters ,
  3 if the Id including chars thet not numbers , 4 if the length of the Id is not 9 chars ,
  5 if not exist a coursName in the courses like the coursName ,
  6 if the scor including chars thet not numbers , 7 if the sum of the scor is greater than 100  */
int validationRow(char* Row)
{
    char* token,* row;
    int rez = 0, i;    
    row = (char*)malloc(sizeof(char) * (strlen(Row) + 1));
    strcpy(row, Row);
    strcpy(row + strlen(Row), "\0");
    if (row == NULL)
    {
        rez = 1;
        return rez;
    }
    else
    {
        token = strtok(row, ",");
        /*Check the firstName*/
        if (rez = isChars(token))
            return rez;
        token = strtok(NULL, ",");

        /*Check the secondName*/
        if (rez = isChars(token))
            return rez;
        token = strtok(NULL, ",");

        /*Check the Id*/
        if (rez = properId(token))
            return rez;
        token = strtok(NULL, ",");

        /*Check the coursName*/
        if (rez = checkCoursName(token))
            return rez;
        token = strtok(NULL, ",");

        /*Check the Scor*/
        if (rez = isScore(token))
            return rez;
    }
    free(row);
    return rez;
}

int validetionSelectQuety(char* queryLine, char* fild, char* operator, char* data)
{
    char* temp;
    int index = 0, range, i = 0, j = 0, isProper = 0;
    isProper = checkFildName(queryLine);
    if (!isProper)
        return 0;
    while (queryLine[index] == ' ')
        index++;
    range = index;
    while (queryLine[range] >= 'a' && queryLine[range] <= 'z' || queryLine[range] >= 'A' && queryLine[range] <= 'Z' || queryLine[range] == ' ')
        range++;
    temp = (char*)malloc(sizeof(char) * range - index + 1);
    if (temp == NULL)
    {
        printf("problem in memory");
        return 0;
    }
    strncpy(temp, queryLine + index, range - index);
    temp[range - index] = '\0';
    while (temp[i] != '\0')
    {
        if (temp[i] != ' ')
        {
            if (temp[i] >= 'A' && temp[i] <= 'Z')
            {
                fild[j] = tolower(temp[i]);
                j++;
            }
            else
            {
                fild[j] = temp[i];
                j++;
            }
        }

        i++;
    }
    fild[j] = '\0';    
    queryLine += range;
    index = range = i = j = 0;    
    range = index;
    while (queryLine[range] == '=' || queryLine[range] == '!' || queryLine[range] == '<' || queryLine[range] == '>' || queryLine[range] == ' ')
        range++;   
    temp = (char*)malloc(sizeof(char) * range - index + 1);
    if (temp == NULL)
    {
        printf("problem in memory");
        return 0;
    }
    strncpy(temp, queryLine + index, range - index);
    temp[range - index] = '\0';
    while (temp[i] != '\0')
    {
        if (temp[i] != ' ')
        {
            operator[j] = temp[i];
            j++;
        }
        i++;
    }
    operator[j] = '\0';
    isProper = checkOperator(operator);
    if (!isProper)
        return isProper;    
    queryLine += range;
    /*index = 0;
    while (queryLine[index] == ' ')
        index++;
    queryLine += index;*/
    index = 0;
    while (queryLine[index] >= 'a' && queryLine[index] <= 'z' || queryLine[index] >= 'A' && queryLine[index] <= 'Z' || queryLine[index] >= '0' && queryLine[index] <= '9' || queryLine[index] == '-')
        index++;
    data = (char*)malloc(sizeof(char) * index + 1);
    if (data == NULL)
    {
        printf("problem in memory");
        return 0;
    }
    strncpy(data, queryLine, index);
    data[index] = '\0';
    if (strcmp(fild, "firstname") == 0 || strcmp(fild, "secondname") == 0)
        isProper = checkNamesData(data);
    else if (strcmp(fild, "id") == 0)
        isProper = checkIdData(data);
    else if (strcmp(fild, "clanguage") == 0 || strcmp(fild, "computernetworks") == 0 || strcmp(fild, "csfundamentals") == 0 || strcmp(fild, "average") == 0)
        isProper = checkScoresData(data);
    return isProper;
}

/*return 0 if the syntax of the line is good and chang the syntax like a line in the file ,
  1 if the line is null or does not contain five columns,
  2 if the firstName or secondName including chars thet not letters ,
  3 if the Id including chars thet not numbers , 4 if the length of the Id is not 9 chars ,
  5 if not exist a coursName in the courses like the coursName ,
  6 if the scor including chars thet not numbers , 7 if the sum of the scor is greater than 100  */
int validationSetQuety(char* line1)
{
    int rez = 0;
    char* token, ch[2] = ",", * line;
    line = (char*)malloc(sizeof(char) * (strlen(line1) + 1));
    strcpy(line, line1);
    strcpy(line + strlen(line1), "\0");
    if (line == NULL)
    {
        rez = 1;
        return rez;
    }
    else
    {
        token = strtok(line, ch);

        /*Check the firstName*/
        if (rez = isChars(token))
            return rez;
        token = strtok(NULL, ch);

        /*Check the secondName*/
        if (rez = isChars(token))
            return rez;
        token = strtok(NULL, ch);

        /*Check the Id*/
        if (rez = properId(token))
            return rez;
        token = strtok(NULL, ch);

        /*Check the coursName*/
        if (rez = checkCoursName(token))
            return rez;
        token = strtok(NULL, ch);

        /*Check the Scor*/
        if (rez = isScore(token))
            return rez;
    }

    return rez;
}



//qweri
//------------------------------------------------------------------------------
void runQueries(student* head)
{
    char queryLine[MAX_LINE];
    printf("  to querying the system enter select and the query sentence\n  to update or insert data enter set and the data\n  to print the data enter print\n  to exit enter quit");
    do
    {
    	printf("\n   ->  ");
    	gets(queryLine);
    } while (checkQweri(queryLine, head));
}

int checkQweri(char* queryLine, student* head)
{
    char fild[20], operat[3], data[50], * line;
    int index = 0, range, i, j, isFound = 0, checkSyntax, isExist, checkQuery;    
    student* newList[10] = { NULL }, * newStud, * ptrNode, * ptrPrv;
    student** tail = NULL;
    
    while (queryLine[index] == ' ')
        index++;

    if (strncmp(queryLine + index, "quit", 4) == 0)
        return 0;
    else if (strncmp(queryLine + index, "print", 5) == 0)
    {
        printf("\n");
        printList(head);
        return 1;
    }
    else if (strncmp(queryLine + index, "select", 6) == 0)
    {        
        checkQuery = validetionSelectQuety(queryLine + index + 6, fild, operat, data);
        if (checkQuery)
        {
            isFound = selectFromList(head, fild, operat, data, newList);
            if (isFound)
            {
                printTitle();
                for (i = 0; i < 10; i++)
                    if (newList[i] != NULL)
                        printNode(newList[i]);
                printFuter();
            }
            else
                printf("\n  No found students were like to the query\n\n");
        }
        else
            printf("\n  The query is invalid\n\n");                    
        return 1;
    }
    else if (strncmp(queryLine + index, "set", 3) == 0)
    {
        line = convertToFileSyntax(queryLine + 3);
        newStud = createNode(line);
        isExist = existInList(head, newStud);
        if (isExist)
        {
            ptrNode = getPtrToNode(head, newStud);
            updateStudent(ptrNode, newStud);
            free(newStud);
        }
        else
        {
            //ptrPrv = getIndexToInsert(head, newStud);
            ptrPrv = head;
            addTolist(&head, &tail, ptrPrv, newStud);
        }
        printList(head);
        return 1;
    }
    else
        printf("\n  The query is invalid\n\n");
}






char* convertToFileSyntax(char* queryLine)
{
    int index = 0, i, caunt = 0;
    char* token, ch[2] = ",", * cpyQueryLine, * line;
    line = (char*)malloc(sizeof(char) * (strlen(queryLine) + 1));
    token = strtok(queryLine, ch);
    while (token != NULL)
    {
        if (caunt == 3)
        {
            i = 0;
            while (token[i] != '=')
            {
                strncpy(line + index, token + i, 1);
                i++;
                index++;
            }
            strcpy(line + index, ",");
            index++;
            i++;
            caunt++;
        }
        else
        {
            i = 0;
            while (token[i] != '=')
                i++;
            strncpy(line + index, token + i + 1, strlen(token) - i - 1);
            strcpy(line + index + strlen(token) - i - 1, ",");
            index += strlen(token) - i;
            token = strtok(NULL, ch);
            caunt++;
        }
    }
    strcpy(line + index - 1, "\0");
    return line;
}

