#include "main.h"

/*create a new node , insert the valeu , return a ponter to the node*/
student* createNode(char* line)
{
    char* firsName , * secondName, * token, ch[2] = ",";
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
    if (strcmp(token, "C language") == 0 || strcmp(token, "clanguage") == 0 )
    {
        token = strtok(NULL, ch);
        newStude->courses[0] = atoi(token);
    }
    else if (strcmp(token, "Computer Networks") == 0 || strcmp(token, "ComputerNetworks") == 0)
    {
        token = strtok(NULL, ch);
        newStude->courses[1] = atoi(token);
    }
    else if (strcmp(token, "CS Fundamentals") == 0 || strcmp(token, "CSFundamentals") == 0)
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
        if (strcmp(ptr->Id, newStud->Id) == 0)
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
    if (ptrCur == NULL || strcmp(ptrCur->SecondName, newStud->SecondName) >= 0)
        return ptrPrv;
    else if (strcmp( newStud->SecondName,tail->SecondName) >= 0)    
        return tail;          
    else
    {
        ptrPrv = head;

        while (ptrCur->next != NULL)
        {
            ptrPrv = ptrCur;
            ptrCur = ptrCur->next;
            if (strcmp(ptrCur->SecondName, newStud->SecondName) >= 0)
                return ptrPrv;
        }
        return ptrCur;
    }
}

/*adding a node to the list by sorted*/
void addTolist(student** head, student** tail, student* ptrPrv, student* newStud)
{
    student* ptrStud;
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


student* getIndexToInsertQuery(student* head, student* ptrNode)
{
    student* ptrPrv = NULL , *ptrCur = head;
    if (ptrCur == NULL|| strcmp(ptrCur->SecondName, ptrNode->SecondName) >= 0)
        return ptrPrv;    
    ptrPrv = head;
    while (ptrCur->next != NULL)
    {
        ptrPrv = ptrCur;
        ptrCur = ptrCur->next;
        if (strcmp(ptrCur->SecondName, ptrNode->SecondName) >= 0)
            return ptrPrv;
    }       
    return ptrCur;
}

void addTolistQuery(student** head, student* ptrPrv, student* newStud)
{

    if (ptrPrv == NULL)
    {                
        newStud->next = *head;
        *head = newStud;          
    }
    else
    {
        newStud->next = ptrPrv->next;
        ptrPrv->next = newStud;
    }

}


void updateStudentQuery(student** head, student* ptrNode, student* newStud)
{
    student* ptrPrv;
    if ((*head)->next == NULL)
       {
          updateStudent((*head), newStud);
       }
    else
       {
          ptrPrv = getIndexToInsertQuery((*head), ptrNode);
          if (ptrNode == (*head))
             {                           
              (*head) = (*head)->next;                
                updateScor(ptrNode, newStud);
                ptrPrv = getIndexToInsertQuery((*head), newStud);
                addTolistQuery(head, ptrPrv, newStud);               
             }
          else
             {                                         
                ptrPrv->next = ptrNode->next;                  
                updateScor(ptrNode, newStud);
                ptrPrv = getIndexToInsertQuery((*head), newStud);
                addTolistQuery(head, ptrPrv, newStud);                
             }          
      }                                                       
}

void updateScor(student* newStud, student* ptrNode)
{
    int i,sum=0,caunt=0;
    for (i = 0; i < COURSES; i++)
    {
        if (ptrNode->courses[i] > -1)
            newStud->courses[i] = ptrNode->courses[i];
        if (newStud->courses[i] > -1)
        {
            caunt++;
            sum += newStud->courses[i];
        }
    }  
    newStud->average = ((float)sum / (float)caunt);
    newStud->next = NULL;
}

/*open the file , read the data , bild the list , clos the file*/
student* raedFile(student* head, int* checkFile)
{
    char row[MAX_LINE];
    int checkSyntax = 0, isExist, countRows = 0;
    student* newStud, * ptrPrv, * ptrNode, * tail = NULL;
    FILE* fRead;
    fRead = fopen("students.csv", "rt");
    if (fRead == NULL)
    {        
        *checkFile = 1;
        return head;
    }
    if (fgetc(fRead) == EOF)
    {
        *checkFile = 2;
        return head;
    }
    do
    {        
        fseek(fRead, -1, SEEK_CUR);               
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
                    ptrPrv = getIndexToInsert(head, tail, newStud);
                    addTolist(&head, &tail, ptrPrv, newStud);
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


int updateFile(student* head)
{
    FILE* fWrite;    
    int i;      
    fWrite = fopen("students.csv", "w+");
    if (fWrite == NULL)
    {        
        return 1;
    }
    while (head != NULL)
    {        
        for (i = 0; i < COURSES; i++)
        {
            if (head->courses[i] > -1)
            {
                if (i == 0)
                    fprintf(fWrite, "%s,%s,%s,C language,%d\n", head->FirstName, head->SecondName, head->Id, head->courses[i]);
                else if (i == 1)
                    fprintf(fWrite, "%s,%s,%s,Computer Networks,%d\n", head->FirstName, head->SecondName, head->Id, head->courses[i]);
                else if (i == 2)
                    fprintf(fWrite, "%s,%s,%s,CS Fundamentals,%d\n", head->FirstName, head->SecondName, head->Id, head->courses[i]);
            }
        }
        head = head->next;
    }
    fclose(fWrite);
    return 0;
}


/*ptinted thr fildNames*/
void printTitle()
{
    printf("\n+------------+--------------+-----------+--------------------+--------------------+--------------------+-----------+\n");    
      printf("| First Name | Second Name  |     ID    |     C Language     |  Computer Networks |   CS Fundamentals  |  Average  |\n");
      printf("+------------+--------------+-----------+--------------------+--------------------+--------------------+-----------+\n");
}

void printFuter()
{
    printf("+------------+--------------+-----------+--------------------+--------------------+--------------------+-----------+\n\n");
}

/*printed one node */
void printNode(student* stud)
{
    int i;
    printf("| %-8s   | %-8s     |%10s |", stud->FirstName, stud->SecondName, stud->Id);
    for (i = 0; i < 3; i++)
    {
        if (stud->courses[i] > -1)
        {
            printf("         %-11d|", stud->courses[i]);
        }
        else
            printf("         --         |");
    }
    if (stud->average > -1)
    {
        printf(" %-8.2f  |", stud->average);
    }
    else
        printf("      -    |");
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
    int index = 0, rez = 0, i, indexOfOperator;
    char oper[6][2] = { "=","!=",">" ,">=" ,"<" ,"<=" },fildNames[7][20] = { "firstName","secondName","ID" ,"CLanguage" ,"ComputerNetworks" ,"CSFundamentals" ,"Average" };
    for (i = 0; i < 6; i++)
    {
        if (strcmp(operat, oper + i) == 0)
            indexOfOperator = i;
    }
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
