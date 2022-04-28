////#include <stdio.h>
////#include <string.h>
//#include "query.h"
//
//
//
//int qweri(char* queryLine, student* head)
//{
//	int index = 0, range, i, j, isFound = 0, checkSyntax, isExist, checkQuery;
//	char* token, ch[2] = " ", fild[20], operat[3], data[50], * line;
//	student* newList[10] = { NULL }, * newStud, * ptrNode, * ptrPrv;
//	while (queryLine[index] == ' ')
//		index++;
//	if (strncmp(queryLine + index, "quit", 4) == 0)
//		return 0;
//	else if (strncmp(queryLine + index, "print", 5) == 0)
//	{
//		printf("\n");
//		printList(head);
//		return 1;
//	}
//	else if (strncmp(queryLine + index, "select", 6) == 0)
//	{
//		//פירוק השאילתה ל3 שם שדה,אופרטור,דטה כולל התמודדות עם רווחים בין מילה למילה חוץ משם השדה שחייב להיות מילה אחת				
//		checkQuery = validetionSelectQuety(queryLine + 6, fild, operat, data);
//		if (checkQuery)
//			isFound = selectFromList(head, fild, operat, data, newList);
//		if (isFound)
//		{
//			printTitle();
//			for (i = 0; i < 10; i++)
//				if (newList[i] != NULL)
//					printNode(newList[i]);
//		}
//		else
//			printf("\n  No found students were like to the query\n\n");
//		//צריך לבדוק האם קיים שם שדה כמו שנקלט 
//		/*token = strtok(query, ch);//select
//		token = strtok(NULL, ch);//fildName
//		index = 0;
//		while (token[index] >= 'a' && token[index] <= 'z' || token[index] >= 'A' && token[index] <= 'Z')
//			index++;
//		strncpy(fild, token, index);
//		fild[index] = '\0';
//		puts(fild);
//		token += index;
//		puts(token);
//		index = 0;
//		while (token[index] == ' ')
//		{
//			index++;
//			token+=1;
//		}
//		index = 0;
//		while (token[index] == '=' || token[index] == '>')
//			index++;
//		strncpy(operat, token, index);
//		operat[index] = '\0';
//		puts(operat);
//		token += index;
//		index = 0;
//		while (token[index] == ' ')
//		{
//			index++;
//			token+=1;
//		}
//		puts(token);*/
//		return 1;
//	}
//	else if (strncmp(queryLine + index, "set", 3) == 0)
//	{
//		line = convertToFileSyntax(queryLine + 3);
//		newStud = createNode(line);
//		isExist = existInList(head, newStud);
//		if (isExist)
//		{
//			ptrNode = getPtrToNode(head, newStud);
//			updateStudent(ptrNode, newStud);
//			free(newStud);
//		}
//		else
//		{
//			ptrPrv = getIndexToInsert(head, newStud);
//			addTolist(&head, ptrPrv, newStud);
//		}
//		printList(head);
//		return 1;
//	}
//	else
//		printf("\n  The query is invalid\n\n");
//}
//
//
//
//char* convertToFileSyntax(char* queryLine)
//{
//	int index = 0, i, caunt = 0;
//	char* token, ch[2] = ",", * cpyQueryLine, * line;
//	line = (char*)malloc(sizeof(char) * (strlen(queryLine) + 1));
//	token = strtok(queryLine, ch);
//	while (token != NULL)
//	{
//		if (caunt == 3)
//		{
//			i = 0;
//			while (token[i] != '=')
//			{
//				strncpy(line + index, token + i, 1);
//				i++;
//				index++;
//			}
//			strcpy(line + index, ",");
//			index++;
//			i++;
//			caunt++;
//		}
//		else
//		{
//			i = 0;
//			while (token[i] != '=')
//				i++;
//			strncpy(line + index, token + i + 1, strlen(token) - i - 1);
//			strcpy(line + index + strlen(token) - i - 1, ",");
//			index += strlen(token) - i;
//			token = strtok(NULL, ch);
//			caunt++;
//		}
//	}
//	strcpy(line + index - 1, "\0");
//	return line;
//}
////#include "studentManager.h"
////#define COURSES  3
////
////typedef struct student {
////    char* FirstName;
////    char* SecondName;
////    char Id[10];
////    int courses[COURSES];
////    float average;
////    struct student* next;
////}student;
