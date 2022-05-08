#include "main.h"


student* getIndexToInsertQuery(student* head, student* ptrNode)
{
	student* ptrPrv = NULL, * ptrCur = head;
	if (ptrCur == NULL || strcmp(ptrCur->SecondName, ptrNode->SecondName) >= 0)
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

int select_firstname(student* head, int operator, char* data) {
	student* ptrStud = head;
	int isFirst = 0, toPrint = 0, isFind = 0;
	while (ptrStud != NULL)
	{				
		switch (operator)
		{
		case equal:
			if (strcmp(ptrStud->FirstName, data) == 0)
				toPrint = 1;
			break;
		case bigger:
			if (strcmp(ptrStud->FirstName, data) > 0)
				toPrint = 1;
			break;
		case smaller:
			if (strcmp(ptrStud->FirstName, data) < 0)
				toPrint = 1;
			break;
		case biggerEqual:
			if (strcmp(ptrStud->FirstName, data) >= 0)
				toPrint = 1;
			break;
		case smallerEqual:
			if (strcmp(ptrStud->FirstName, data) <= 0)
				toPrint = 1;
			break;
		case notEqual:
			if (strcmp(ptrStud->FirstName, data) != 0)
				toPrint = 1;
			break;
		}		
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}			
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFuter();

	return isFind;
}

int select_secondname(student* head, int operator, char* data) {
	student* ptrStud = head;
	int isFirst = 0, toPrint = 0, isFind = 0;
	while (ptrStud != NULL)
	{
		switch (operator)
		{
		case equal:
			if (strcmp(ptrStud->SecondName, data) == 0)
				toPrint = 1;
			break;
		case bigger:
			if (strcmp(ptrStud->SecondName, data) > 0)
				toPrint = 1;
			break;
		case smaller:
			if (strcmp(ptrStud->SecondName, data) < 0)
				toPrint = 1;
			break;
		case biggerEqual:
			if (strcmp(ptrStud->SecondName, data) >= 0)
				toPrint = 1;
			break;
		case smallerEqual:
			if (strcmp(ptrStud->SecondName, data) <= 0)
				toPrint = 1;
			break;
		case notEqual:
			if (strcmp(ptrStud->SecondName, data) != 0)
				toPrint = 1;
			break;
		}
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFuter();

	return isFind;
}

int select_id(student* head, int operator, char* data) {	
	student* ptrStud = head;
	int isFirst = 0, toPrint = 0, isFind = 0;
	while (ptrStud != NULL)
	{
		switch (operator)
		{
		case equal:
			if (strcmp(ptrStud->Id, data) == 0)
				toPrint = 1;
			break;
		case bigger:
			if (strcmp(ptrStud->Id, data) > 0)
				toPrint = 1;
			break;
		case smaller:
			if (strcmp(ptrStud->Id, data) < 0)
				toPrint = 1;
			break;
		case biggerEqual:
			if (strcmp(ptrStud->Id, data) >= 0)
				toPrint = 1;
			break;
		case smallerEqual:
			if (strcmp(ptrStud->Id, data) <= 0)
				toPrint = 1;
			break;
		case notEqual:
			if (strcmp(ptrStud->Id, data) != 0)
				toPrint = 1;
			break;
		}
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFuter();

	return isFind;
}

int select_clanguage(student* head, int operator, char* data) 
{	
	student* ptrStud = head;
	int isFirst = 0, toPrint = 0, isFind = 0;
	while (ptrStud != NULL)
	{
		switch (operator)
		{
		case equal:
			if (ptrStud->courses[0] == atoi(data))
				toPrint = 1;
			break;
		case bigger:
			if (ptrStud->courses[0] > atoi(data))
				toPrint = 1;
			break;
		case smaller:
			if (ptrStud->courses[0] < atoi(data))
				toPrint = 1;
			break;
		case biggerEqual:
			if (ptrStud->courses[0] >= atoi(data))
				toPrint = 1;
			break;
		case smallerEqual:
			if (ptrStud->courses[0] <= atoi(data))
				toPrint = 1;
			break;
		case notEqual:
			if (ptrStud->courses[0] != atoi(data))
				toPrint = 1;
			break;
		}
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFuter();

	return isFind;
}

int select_computernetworks(student* head, int operator, char* data) {
	student* ptrStud = head;
	int isFirst = 0, toPrint = 0, isFind = 0;
	while (ptrStud != NULL)
	{
		switch (operator)
		{
		case equal:
			if (ptrStud->courses[1] == atoi(data))
				toPrint = 1;
			break;
		case bigger:
			if (ptrStud->courses[1] > atoi(data))
				toPrint = 1;
			break;
		case smaller:
			if (ptrStud->courses[1] < atoi(data))
				toPrint = 1;
			break;
		case biggerEqual:
			if (ptrStud->courses[1] >= atoi(data))
				toPrint = 1;
			break;
		case smallerEqual:
			if (ptrStud->courses[1] <= atoi(data))
				toPrint = 1;
			break;
		case notEqual:
			if (ptrStud->courses[1] != atoi(data))
				toPrint = 1;
			break;
		}
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFuter();

	return isFind;
}

int select_csfundamentals(student* head, int operator, char* data) {
	student* ptrStud = head;
	int isFirst = 0, toPrint = 0, isFind = 0;
	while (ptrStud != NULL)
	{
		switch (operator)
		{
		case equal:
			if (ptrStud->courses[2] == atoi(data))
				toPrint = 1;
			break;
		case bigger:
			if (ptrStud->courses[2] > atoi(data))
				toPrint = 1;
			break;
		case smaller:
			if (ptrStud->courses[2] < atoi(data))
				toPrint = 1;
			break;
		case biggerEqual:
			if (ptrStud->courses[2] >= atoi(data))
				toPrint = 1;
			break;
		case smallerEqual:
			if (ptrStud->courses[2] <= atoi(data))
				toPrint = 1;
			break;
		case notEqual:
			if (ptrStud->courses[2] != atoi(data))
				toPrint = 1;
			break;
		}
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFuter();

	return isFind;
}

int select_average(student* head, int operator, char* data) {
	student* ptrStud = head;	
	int isFirst = 0, toPrint = 0, isFind = 0,i=0,isPoint = 0;
	float f_data;	
	while (data[i] != '\0')
	{
		if (strncmp(data + i,".",1) == 0)
			isPoint = 1;
			
		i++;
	}		
	if (isPoint)
		f_data = atof(data) + atof(data + i+1);
	else
		f_data = atof(data);	
	while (ptrStud != NULL)
	{
		switch (operator)
		{
		case equal:
			if (ptrStud->average == f_data)
				toPrint = 1;
			break;
		case bigger:
			if (ptrStud->average > f_data)
				toPrint = 1;
			break;
		case smaller:
			if (ptrStud->average < f_data)
				toPrint = 1;
			break;
		case biggerEqual:
			if (ptrStud->average >= f_data)
				toPrint = 1;
			break;
		case smallerEqual:
			if (ptrStud->average <= f_data)
				toPrint = 1;
			break;
		case notEqual:					
			if (ptrStud->average != f_data)
				toPrint = 1;
			break;
		}
		if (toPrint)
		{
			if (!isFirst)
			{
				printTitle();
				isFirst = 1;
				isFind = 1;
			}
			printNode(ptrStud);
			toPrint = 0;
		}
		ptrStud = ptrStud->next;
	}
	if (isFirst)
		printFuter();

	return isFind;
}

int genericSelect(student* head, int field, int operator,void* data)
{
	student* ptrStud = head;
	switch (field)
	{
	case firstname:
		return (&select_firstname)(ptrStud, operator, data);
		break;
	case secondname:
		return (&select_secondname)(ptrStud, operator, data);
		break;
	case id:
		return (&select_id)(ptrStud, operator, data);
		break;
	case clanguage:
		return (&select_clanguage)(ptrStud, operator, data);
		break;
	case computernetworks:
		return (&select_computernetworks)(ptrStud, operator, data);
		break;
	case csfundamentals:
		return (&select_csfundamentals)(ptrStud, operator, data);
		break;
	case average:
		return (&select_average)(ptrStud, operator, data);
		break;
	}

	return 0;
}

void printMenu()
{
	printf("    to querying the system enter select and the query sentence\n\n");
	printf("    (select firstName = beni)\n\n");
	printf("    to update or insert data enter set and the data\n\n");
	printf("    (set firstName = dani, secondName = haham, id = 111222333, clanguage = 45)\n\n");
	printf("    to delete a student enter deleteand the id\n\n");
	printf("    (delete id = 111222333)\n\n");
	printf("    to print the data enter print\n\n");
	printf("    to print the menu enter menu\n\n");
	printf("    to exit enter quit");
}

void deleteStudent(student** head, char* data)
{
	student* ptrCur = (*head),*ptrPrv;
	if (strcmp(ptrCur->Id, data) == 0)
	{
		(*head) = (*head)->next;
		freeStudent(ptrCur);
	}
	do
	{
		ptrPrv = ptrCur;
		ptrCur = ptrCur->next;
		if (strcmp(ptrCur->Id, data) == 0)
		{
			ptrPrv->next = ptrCur->next;
			freeStudent(ptrCur);
			break;
		}
	} while (ptrCur->next != NULL);			
}

void runQueries(student* head)
{
    int chackOpenFile=0;
    char queryLine[MAX_LINE];
	printMenu();
    do
    {
        printf("\n  ->  ");
        gets(queryLine);
    } while (checkQuery(queryLine, &head));
    chackOpenFile = updateFile(head);
	freeList(head);	
    if (chackOpenFile)
    {
        printf("cannot open the file to update");
        exit(1);        
    }
}

int checkQuery(char* queryRow, student** head)
{	
	char* token, field[20], operator[3], data[50], * line;
    int index = 0, range, fieldId , operatorId , isFind = 0, checkSyntax, isExist, checkQuery;
    student* newList[10] = { NULL }, * newStud, * ptrNode, * ptrPrv,*tail=NULL;
    
	while (queryRow[index] != '\0')
	{
		if (queryRow[index] >= 'A' && queryRow[index] <= 'Z')
			queryRow[index] += 32;
		index++;
	}
		index++;
	index = 0;
    while (queryRow[index] == ' ')
        index++;

    if (strncmp(queryRow + index, "quit", 4) == 0)
        return 0;
    else if (strncmp(queryRow + index, "print", 5) == 0)
	{				
        printf("\n");
        printList((*head));
        return 1;
    }
    else if (strncmp(queryRow + index, "select", 6) == 0)
    {
        checkQuery = validetionSelectQuery(queryRow + index + 6, field, operator,data, 0);		
        if (checkQuery)
        {                       
			getId(field, operator,&fieldId,& operatorId);			
            isFind = genericSelect((*head), fieldId, operatorId, data);
            if (!isFind)
                printf("\n  Not found students were like to the query\n\n");                
        }
        else
            printf("\n  The query is invalid\n\n");
        return 1;
    }
    else if (strncmp(queryRow + index, "set", 3) == 0)
    {        
        checkQuery = validationSetQuery(queryRow + index + 3);
        if (checkQuery)
        {            
            newStud = createNode(queryRow +3);
            isExist = existInList((*head),tail, newStud);
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
	else if (strncmp(queryRow + index, "delete", 6) == 0)
	{
		checkQuery = validationDeleteQuery(queryRow + index + 6, data);
		if (checkQuery)
		{
			isExist = ExistToDelete((*head), data);
			if (isExist)
			{
				deleteStudent(head, data);
				printf("     delete student successful");
			}
			else
			{
				printf("\n  Not found students were like to the query\n\n");
			}						
		}
		else
			printf("\n  The query is invalid\n\n");

		return 1;
	}
	else if (strncmp(queryRow + index, "menu", 4) == 0)
	{
		printMenu();
	}
	else
        printf("\n  The query is invalid\n\n");

    return 1;
}
