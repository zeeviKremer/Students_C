#include "main.h"



/*create a new node , insert the valeu , return a ponter to the node*/
student* createNode(char* row)
{
    char* token;
    student* newStude;
    int i, sum = 0, caunt = 0;
    newStude = (student*)malloc(sizeof(student));
    if (newStude == NULL)
    {
        free(newStude);
        return NULL;
    }        
    token = strtok(row, ",");
    newStude->FirstName = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(newStude->FirstName, token);
    strcpy(newStude->FirstName + strlen(token), "\0");    
    token = strtok(NULL, ",");
    newStude->SecondName = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(newStude->SecondName, token);
    strcpy(newStude->SecondName + strlen(token), "\0");    
    token = strtok(NULL, ",");
    strcpy(newStude->Id, token);
    newStude->Id[(strlen(token) + 1)] = '\0';
    token = strtok(NULL, ",");
    for (i = 0; i < 3; i++)
        newStude->courses[i] = -1;
    if (strcmp(token, "C language") == 0 || strcmp(token, "clanguage") == 0 )
    {
        token = strtok(NULL, ",");
        newStude->courses[0] = atoi(token);
    }
    else if (strcmp(token, "Computer Networks") == 0 || strcmp(token, "ComputerNetworks") == 0)
    {
        token = strtok(NULL, ",");
        newStude->courses[1] = atoi(token);
    }
    else if (strcmp(token, "CS Fundamentals") == 0 || strcmp(token, "CSFundamentals") == 0)
    {
        token = strtok(NULL, ",");
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
int existInList(student* head, student* tail, student* stud)
{   
    student* ptr = head;
    if (tail != NULL && strcmp(tail->Id, stud->Id) == 0)
    {
        if (strcmp(tail->FirstName, stud->FirstName) == 0 && strcmp(tail->SecondName, stud->SecondName) == 0)
            return 1;
        else
            return -1;
    }
    else
    {
        while (ptr != NULL)
        {            
            if (strcmp(ptr->Id, stud->Id) == 0)
            {                
                if (strcmp(ptr->FirstName, stud->FirstName) == 0 && strcmp(ptr->SecondName, stud->SecondName) == 0)
                    return 1;
                else
                    return -1;
            }
            ptr = ptr->next;
        }
    }    

    return 0;
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

    return ptr;
}

/*update the olde Student from the new student*/
void updateStudent(student* ptrStud, student* newStud)
{
    int i, sum = 0, caunt = 0;
    /*strcpy(ptrStud->FirstName , newStud->FirstName);
    strcpy(ptrStud->SecondName , newStud->SecondName);
    strcpy(ptrStud->Id, newStud->Id);*/
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
student* readFile(student* head, int* checkFile)
{
    char row[MAX_LINE];
    int checkSyntax = 0, isExist, countRows = 0;
    student* newStud, * ptrPrv, * ptrNode, * tail = NULL;
    FILE* fRead;
    fRead = fopen(FILE_NAME, "rt");
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
                isExist = existInList(head, tail, newStud);                
                
                if (isExist == -1) 
                {
                    printf("error in file line number %d error number is %d", countRows, isExist);
                    freeStudent(newStud);                   
                }
                else if (isExist == 1)
                {
                    ptrNode = getPtrToNode(head, newStud);                    
                    updateStudent(ptrNode, newStud);
                    freeStudent(newStud);

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
    fWrite = fopen(FILE_NAME, "w+");
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

void getId(char* field, char* operator,int* fieldId, int* operatorId)
{       
    int arrFields[7] = { "firstname", "secondname", "id", "clanguage", "computernetworks", "csfundamentals", "average" }, arrOperators[6] = { "=", ">", "<", ">=", "<=", "!=" };
    int i;
    for (i = 0; i < 7; i++)
    {
        if (strcmp(arrFields[i], field) == 0)
            *fieldId = i+1;
    }
    for (i = 0; i <6; i++)
    {
        if (strcmp(arrOperators[i], operator) == 0)
            *operatorId = i;
    }    
}


void freeStudent(student* ptrStud)
{
    free(ptrStud->FirstName);
    free(ptrStud->SecondName);
    free(ptrStud);
}


void freeList(student* head)
{
    student* ptrStud;
    while (head)
    {
        ptrStud = head;
        head = head->next;
        freeStudent(ptrStud);        
    }    
}


int ExistToDelete(student* head, char* data)
{
    student* ptrStud = head;
    while (ptrStud != NULL)
    {
        if (strcmp(ptrStud->Id, data) == 0)
            return 1;
        ptrStud = ptrStud->next;
    }
    return 0;
}
