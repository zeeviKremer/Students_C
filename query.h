////#include <stdio.h>
////#include <string.h>
//#define COURSES  3
//
//typedef struct student {
//    char* FirstName;
//    char* SecondName;
//    char Id[10];
//    int courses[COURSES];
//    float average;
//    struct student* next;
//}student;
//
//
//int qweri(char* query, student* head)
//{
//    if (strcmp(query, "quit") == 0)
//        return 0;
//    else if (strcmp(query, "print") == 0)
//    {
//        printf("\n");
//        printList(head);
//        return 1;
//    }
//}
////
//////int func1()
//////{
//////    char query[100] = "select id=111111111", ch[3] = " ", * token, fild[20], operat[3];
//////    int i = 0, j = 0;
//////    while (query[i] == ' ')
//////        i++;
//////    if (strncmp(query + i, "print", 5) == 0)
//////    {
//////        printf("\n");
//////        printList(head);
//////        return  1;
//////    }
//////    if (strncmp(query + i, "quit", 4) == 0)
//////        return  0;
//////    if(strncmp(query + i , "select", 6) == 0)
//////    {
//////        token = strtok(query, ch);
//////        token = strtok(NULL, ch);
//////        while (token[i] >= 'a' && token[i] <= 'z')
//////            i++;
//////        strncpy(fild, token, i);
//////        if (strcmp(fild, "id") == 0)
//////        {
//////            token = token + i;
//////            puts(fild);
//////            i = 0;
//////            while (token[i] == '=' || token[i] == '>')
//////                i++;
//////            strncpy(operat, token, i);
//////            puts(operat);
//////            token = token + i;
//////            puts(token);
//////
//////        }
//////
//////    }
//////}
//////
