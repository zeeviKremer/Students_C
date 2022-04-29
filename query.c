#include "main.h"

void runQueries(student* head)
{
    int chackOpenFile=0;
    char queryLine[MAX_LINE];
    printf("    to querying the system enter select and the query sentence\n    to update or insert data enter set and the data\n    to print the data enter print\n    to exit enter quit");
    do
    {
        printf("\n  ->  ");
        gets(queryLine);
    } while (checkQweri(queryLine, &head));
    chackOpenFile = updateFile(head);
    if (chackOpenFile)
    {
        printf("cannot open the file to update");
        exit(1);        
    }
}

int checkQweri(char* queryLine, student** head)
{
    char fild[20], operat[3], data[50], * line,str[100];
    int index = 0, range, i, j, isFound = 0, checkSyntax, isExist, checkQuery;
    student* newList[10] = { NULL }, * newStud, * ptrNode, * ptrPrv,*tail=NULL;
    
    while (queryLine[index] == ' ')
        index++;

    if (strncmp(queryLine + index, "quit", 4) == 0)
        return 0;
    else if (strncmp(queryLine + index, "print", 5) == 0)
    {
        printf("\n");
        printList((*head));
        return 1;
    }
    else if (strncmp(queryLine + index, "select", 6) == 0)
    {
        checkQuery = validetionSelectQuety(queryLine + index + 6, fild, operat, data);
        if (checkQuery)
        {
            isFound = selectFromList((*head), fild, operat, data, newList);
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
        checkQuery = validationSetQuety(queryLine + index + 3);
        checkQuery = 1;
        if (checkQuery)
        {                       
            newStud = createNode(queryLine +3);
            isExist = existInList((*head), newStud);
            if (isExist)
            {
                ptrNode = getPtrToNode((*head), newStud);
                updateStudentQuery(head, ptrNode, newStud);
                printf("     update student successful");               
            }
            else
            {
                ptrPrv = getIndexToInsertQuery((*head), newStud);
                addTolistQuery(head, ptrPrv, newStud);
                printf("     insert student successful");
            }           
        }
        else
            printf("\n  The query is invalid\n\n");
        
        return 1;              
    }
}
