//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include "query.h"
//#pragma warning(disable:4996)
//#define MAX_LINE  256
//#define COURSES  3
////מערך של סטרינגים לשמות הקורסים
//typedef struct student {
//    char* FirstName;
//    char* SecondName;
//    char Id[10];
//    int courses[COURSES];
//    float average;
//    struct student* next;
//}student;
//
///*create a new node , insert the valeu , return a ponter to the node*/
//student* createNode(char* line)
//{
//    char* firsName, * secondName, * token, ch[2] = ",";
//    student* newStude;
//    int i, sum = 0, caunt = 0;
//    newStude = (student*)malloc(sizeof(student));
//    if (newStude == NULL)
//        return newStude;
//    token = strtok(line, ch);
//    firsName = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//    strcpy(firsName, token);
//    strcpy(firsName + strlen(token), "\0");
//    newStude->FirstName = firsName;
//    token = strtok(NULL, ch);
//    secondName = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//    strcpy(secondName, token);
//    strcpy(secondName + strlen(token), "\0");
//    newStude->SecondName = secondName;
//    token = strtok(NULL, ch);
//    strcpy(newStude->Id, token);
//    newStude->Id[(strlen(token) + 1)] = '\0';
//    token = strtok(NULL, ch);
//    for (i = 0; i < 3; i++)
//        newStude->courses[i] = -1;
//    if (strcmp(token, "C language") == 0)
//    {
//        token = strtok(NULL, ch);
//        newStude->courses[0] = atoi(token);
//    }
//    else if (strcmp(token, "Computer Networks") == 0)
//    {
//        token = strtok(NULL, ch);
//        newStude->courses[1] = atoi(token);
//    }
//    else if (strcmp(token, "CS Fundamentals") == 0)
//    {
//        token = strtok(NULL, ch);
//        newStude->courses[2] = atoi(token);
//    }
//    for (i = 0; i < 3; i++)
//    {
//        if (newStude->courses[i] > -1)
//        {
//            caunt++;
//            sum += newStude->courses[i];
//        }
//    }
//    newStude->average = ((float)sum / (float)caunt);
//    newStude->next = NULL;
//
//    return newStude;
//}
//
///*return 1 if the student is exist in the list or 0 if thet not exist in the list*/
//int existInList(student* head, student* stud)
//{
//    int rez = 0;
//    student* ptr = head;
//    while (ptr != NULL)
//    {
//        if (strcmp(ptr->Id, stud->Id) == 0)
//        {
//            if (strcmp(ptr->FirstName, stud->FirstName) == 0 && strcmp(ptr->SecondName, stud->SecondName) == 0)
//            {
//                rez = 1;
//                return rez;
//            }
//            else
//            {
//                rez = -1;
//                return rez;
//            }
//        }             
//        ptr = ptr->next;
//    }
//
//    return rez;
//}
//
///*return a ponter to the node thet is like to the current node*/
//student*  getPtrToNode(student *  head,student * newStud)
//{
//    student* ptr = head;
//    while (ptr != NULL)
//    {
//        if (strcmp(ptr->Id, newStud->Id) == 0 && strcmp(ptr->FirstName, newStud->FirstName) == 0 && strcmp(ptr->SecondName, newStud->SecondName) == 0)
//            return ptr;        
//        ptr = ptr->next;
//    }
//}
//
///*update the olde Student from the new student*/
//void updateStudent(student* ptrStud, student* stud1)
//{
//    int i,sum = 0, caunt = 0;    
//    ptrStud->FirstName = stud1->FirstName;    
//    ptrStud->SecondName = stud1->SecondName;
//    strcpy(ptrStud->Id, stud1->Id);
//    for (i = 0; i < 3; i++)
//    {
//        if (stud1->courses[i] > -1)        
//            ptrStud->courses[i] = stud1->courses[i];
//        if (ptrStud->courses[i] > -1)
//        {
//            caunt++;
//            sum += ptrStud->courses[i];
//        }
//    }
//    ptrStud->average = ((float)sum /(float) caunt);
//}
//
///*return the node befor the index that is where the place to put the new node*/
//student* getIndexToInsert(student* head, student* stud1)
//{
//    student* ptrCur = head, * ptrPrv = NULL;
//    if (ptrCur == NULL || strcmp(ptrCur->SecondName, stud1->SecondName) > 0)
//        return ptrPrv;
//    ptrPrv = head;
//    
//    while (ptrCur->next != NULL)
//    {        
//        ptrPrv = ptrCur;
//        ptrCur = ptrCur->next;        
//        if (strcmp(ptrCur->SecondName, stud1->SecondName) > 0)
//        return ptrPrv;
//    }
//    return ptrCur;
//}
//
///*adding a node to the list by sorted*/
//void addTolist(student** head, student* ptrPrv, student* newStud)
//{
//    if (ptrPrv == NULL)
//    {
//        newStud->next = *head;
//        *head = newStud;
//    }
//    else
//    {
//        newStud->next = ptrPrv->next;
//        ptrPrv->next = newStud;
//    }
//}
//
///*ptinted thr fildNames*/
//void printTitle()
//{
//    printf("\n--------------------------------------------------------------------------------------------------------------------\n");
//    printf("| First Name | Second Name  |     ID    |     C Language     |  Computer Networks |   CS Fundamentals  |  Average  |\n");
//    printf("--------------------------------------------------------------------------------------------------------------------\n");
//}
//
//
//void printFuter()
//{
//    printf("--------------------------------------------------------------------------------------------------------------------\n\n");
//}
//
///*printed one node */
//void printNode(student* stud)
//{
//    int i;
//    printf("|  %-8s  |  %-8s    |%10s |", stud->FirstName, stud->SecondName, stud->Id);
//    for (i = 0; i < 3; i++)
//    {
//        if (stud->courses[i] > -1)
//        {
//            printf("%11d         |", stud->courses[i]);
//        }
//        else
//            printf("         ~          |");
//    }
//    if (stud->average > -1)
//    {
//        printf(" %8.2f  |", stud->average);
//    }
//    else
//        printf("      ~    |");
//    printf("\n");
//}
//
///*printed the list */
//void printList(student* head)
//{
//    student* ptrStud = head;
//    printTitle();
//    while (ptrStud != NULL)
//    {
//        printNode(ptrStud);
//        ptrStud = ptrStud->next;
//    }
//    printFuter();
//}
///*return 0 if not found  students were like to the query and 1 if found ,
//  if found thet bild a arey of pointers to Nodes thet like to the query*/
//int selectFromList(student* head, char* fild, char* operat, char* data, student**newList)
//{
//    student* ptrStud = head;
//    int index = 0,rez = 0,i;   
//    char fildNames[7][20] = { "firstName","secondName","ID" ,"CLanguage" ,"ComputerNetworks" ,"CSFundamentals" ,"Average" };
//    while (ptrStud != NULL)
//    {
//        if (strcmp(fild, "firstname") == 0)
//        {           
//            if (strcmp(operat, "=") == 0)
//            {   
//                if (strcmp(ptrStud->FirstName, data) == 0)
//                {
//                    newList[index] = ptrStud;
//                    index++;
//                    rez = 1;
//                }
//            }
//            else if (strcmp(operat, "!=") == 0)
//            {                
//                if (strcmp(ptrStud->FirstName, data) != 0)
//                {
//                    newList[index] = ptrStud;
//                    index++;
//                    rez = 1;
//                }
//            }
//            else if (strcmp(operat, ">") == 0)
//            {
//                if (strcmp(ptrStud->FirstName, data) > 0)
//                {
//                    newList[index] = ptrStud;
//                    index++;
//                    rez = 1;
//                }
//            }
//            else if (strcmp(operat, "<") == 0)
//            {
//                if (strcmp(ptrStud->FirstName, data) < 0)
//                {
//                    newList[index] = ptrStud;
//                    index++;
//                    rez = 1;
//                }
//            }
//            else if (strcmp(operat, ">=") == 0)
//            {
//                if (strcmp(ptrStud->FirstName, data) >= 0)
//                {
//                    newList[index] = ptrStud;
//                    index++;
//                    rez = 1;
//                }
//            }
//            else if (strcmp(operat, "<=") == 0)
//            {
//                if (strcmp(ptrStud->FirstName, data) <= 0)
//                {
//                    newList[index] = ptrStud;
//                    index++;
//                    rez = 1;
//                }
//            }
//        }
//        else if (strcmp(fild, "secondname") == 0)
//        {
//            if (strcmp(operat, "=") == 0)
//            {
//                if (strcmp(ptrStud->SecondName, data) == 0)
//                {
//                    newList[index] = ptrStud;
//                    index++;
//                    rez = 1;
//                }
//            }
//            else if (strcmp(operat, "!=") == 0)
//            {
//                if (strcmp(ptrStud->SecondName, data) != 0)
//                {
//                    newList[index] = ptrStud;
//                    index++;
//                    rez = 1;
//                }
//            }
//            else if (strcmp(operat, ">") == 0)
//            {
//                if (strcmp(ptrStud->SecondName, data) > 0)
//                {
//                    newList[index] = ptrStud;
//                    index++;
//                    rez = 1;
//                }
//            }
//            else if (strcmp(operat, "<") == 0)
//            {
//                if (strcmp(ptrStud->SecondName, data) < 0)
//                {
//                    newList[index] = ptrStud;
//                    index++;
//                    rez = 1;
//                }
//            }
//            else if (strcmp(operat, ">=") == 0)
//            {
//                if (strcmp(ptrStud->SecondName, data) >= 0)
//                {
//                    newList[index] = ptrStud;
//                    index++;
//                    rez = 1;
//                }
//            }
//            else if (strcmp(operat, "<=") == 0)
//            {
//                if (strcmp(ptrStud->SecondName, data) <= 0)
//                {
//                    newList[index] = ptrStud;
//                    index++;
//                    rez = 1;
//                }
//            }
//        }
//        else if (strcmp(fild, "id") == 0)
//        {
//        if (strcmp(operat, "=") == 0)
//        {
//            if (strcmp(ptrStud->Id, data) == 0)
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "!=") == 0)
//        {
//            if (strcmp(ptrStud->Id, data) != 0)
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, ">") == 0)
//        {
//            if (strcmp(ptrStud->Id, data) > 0)
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "<") == 0)
//        {
//            if (strcmp(ptrStud->Id, data) < 0)
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, ">=") == 0)
//        {
//            if (strcmp(ptrStud->Id, data) >= 0)
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "<=") == 0)
//        {
//            if (strcmp(ptrStud->Id, data) <= 0)
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        }
//        else if (strcmp(fild, "clanguage") == 0)
//        {        
//        if (strcmp(operat, "=") == 0)
//        {
//            if (ptrStud->courses[0] == atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "!=") == 0)
//        {
//            if (ptrStud->courses[0] != atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, ">") == 0)
//        {
//            if (ptrStud->courses[0] > atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "<") == 0)
//        {
//            if (ptrStud->courses[0] < atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, ">=") == 0)
//        {
//            if (ptrStud->courses[0] >= atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "<=") == 0)
//        {
//            if (ptrStud->courses[0] <= atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        }
//        else if (strcmp(fild, "computernetworks") == 0)
//        {
//        if (strcmp(operat, "=") == 0)
//        {
//            if (ptrStud->courses[1] == atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "!=") == 0)
//        {
//            if (ptrStud->courses[1] != atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, ">") == 0)
//        {
//            if (ptrStud->courses[1] > atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "<") == 0)
//        {
//            if (ptrStud->courses[1] < atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, ">=") == 0)
//        {
//            if (ptrStud->courses[1] >= atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "<=") == 0)
//        {
//            if (ptrStud->courses[1] <= atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        }
//        else if (strcmp(fild, "csfundamentals") == 0)
//        {
//        if (strcmp(operat, "=") == 0)
//        {
//            if (ptrStud->courses[2] == atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "!=") == 0)
//        {
//            if (ptrStud->courses[2] != atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, ">") == 0)
//        {
//            if (ptrStud->courses[2] > atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "<") == 0)
//        {
//            if (ptrStud->courses[2] < atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, ">=") == 0)
//        {
//            if (ptrStud->courses[2] >= atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "<=") == 0)
//        {
//            if (ptrStud->courses[2] <= atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        }
//        else if (strcmp(fild, "average") == 0)
//        {
//        if (strcmp(operat, "=") == 0)
//        {
//            if (ptrStud->average == atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "!=") == 0)
//        {
//            if (ptrStud->average != atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, ">") == 0)
//        {
//            if (ptrStud->average > atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "<") == 0)
//        {
//            if (ptrStud->average < atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, ">=") == 0)
//        {
//            if (ptrStud->average >= atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        else if (strcmp(operat, "<=") == 0)
//        {
//            if (ptrStud->average <= atoi(data))
//            {
//                newList[index] = ptrStud;
//                index++;
//                rez = 1;
//            }
//        }
//        }
//        ptrStud = ptrStud->next;
//    }
//    return rez;
//}
