#include "main.h"



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


int checkFildName(char* queryRow, char* fild)
{
    char* temp;
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
    /*fild = (char*)malloc(sizeof(char) * range - index + 1);
    if (fild == NULL)
    {
        printf("problem in memory");
        return 0;
    }*/
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
    strncpy(queryRow, queryRow + range, strlen(queryRow) - range);
    strcpy(queryRow + strlen(queryRow) - range, "\0");
    return 1;
}

int checkOperator(char* queryRow, char* operator)
{
    char* temp;
    int index = 0, range, i, j, rez = 1;
    while (queryRow[index] == ' ')
        index++;
    range = index;
    while (queryRow[range] == '=' || queryRow[range] == '!' || queryRow[range] == '<' || queryRow[range] == '>' || queryRow[range] == ' ')
        range++;
    i = 0, j = 0;
    temp = (char*)malloc(sizeof(char) * range - index + 1);
    if (temp == NULL)
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
            operator[j] = temp[i];
            j++;
        }
        i++;
    }
    operator[j] = '\0';
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

    strncpy(queryRow, queryRow + range, strlen(queryRow) - range);
    strcpy(queryRow + strlen(queryRow) - range, "\0");
    return rez;
}

int checkData(char* queryRow, char* fild, char* data)
{
    int index = 0, isProper = 0;
    while (queryRow[index] >= 'a' && queryRow[index] <= 'z' || queryRow[index] >= 'A' && queryRow[index] <= 'Z' || queryRow[index] >= '0' && queryRow[index] <= '9' || queryRow[index] == '-')
        index++;
    strncpy(data, queryRow, index);
    data[index] = '\0';
    if (strcmp(fild, "firstname") == 0 || strcmp(fild, "secondname") == 0)
        isProper = checkNamesData(data);
    else if (strcmp(fild, "id") == 0)
        isProper = checkIdData(data);
    else if (strcmp(fild, "clanguage") == 0 || strcmp(fild, "computernetworks") == 0 || strcmp(fild, "csfundamentals") == 0 || strcmp(fild, "average") == 0)
        isProper = checkScoresData(data);
    return isProper;
}

/*return 0 if the syntax of the line is good , 1 if the line is null or does not contain five columns,
  2 if the firstName or secondName including chars thet not letters ,
  3 if the Id including chars thet not numbers , 4 if the length of the Id is not 9 chars ,
  5 if not exist a coursName in the courses like the coursName ,
  6 if the scor including chars thet not numbers , 7 if the sum of the scor is greater than 100  */
int validationRow(char* Row)
{
    char* token, * row;
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


/*return 0 if the quety is not good and 1 if the is good*/
int validetionSelectQuety(char* queryLine, char* fild, char* operator, char* data)
{    
    int index = 0, isProper = 0;
    char temp[20];
    while (queryLine[index] == ' ')
        index++;
    isProper = checkFildName(queryLine + index, fild);
    if (!isProper)
        return isProper;
    isProper = checkOperator(queryLine, operator);
    if (!isProper)
        return isProper;
    isProper = checkData(queryLine, fild, data);
    return isProper;

}

/*return 0 if the syntax of the line is good and chang the syntax like a line in the file ,
  1 if the line is null or does not contain five columns,
  2 if the firstName or secondName including chars thet not letters ,
  3 if the Id including chars thet not numbers , 4 if the length of the Id is not 9 chars ,
  5 if not exist a coursName in the courses like the coursName ,
  6 if the scor including chars thet not numbers , 7 if the sum of the scor is greater than 100  */
int validationSetQuety(char* queryRow)
{   
    int isProper = 1,j=0 ,index=0;
    char* token, fild[20], operat[3], data[50], * line;
    line = (char*)malloc(sizeof(char) * (strlen(queryRow) + 1));    
    if (line == NULL)
    {
        isProper = 0;
        return isProper;
    }    
    strcpy(line, queryRow);    
    strcpy(line + strlen(queryRow), "\0");
    
    while (queryRow[index] != '=')
        index++;
    index++;
    while (queryRow[index] != ',')
    {
        index++;
        j++;
    }
    strncpy(line, queryRow + index - j, j);
    strcpy(line + j, "\0");
    while (queryRow[index] != '=')
        index++;
    index++;
    j = 0;
    while (queryRow[index] != ',')
    {
        index++;
        j++;
    }
    strcat(line, ",");
    strncat(line, queryRow + index - j, j);
    strcat(line, ",");
    strcpy(line + strlen(line), "\0");
    while (queryRow[index] != '=')
        index++;
    index++;
    j = 0;
    while (queryRow[index] != ',')
    {
        index++;
        j++;
    }    
    strncat(line, queryRow + index - j, j);
    strcat(line, ",");
    strcpy(line + strlen(line), "\0");
    index++;
    while (queryRow[index] == ' ')
        index++;
    j = 0;
    while (queryRow[index] != ' ')
    {
        index++;
        j++;
    }
    strncat(line, queryRow + index - j, j);
    strcat(line, ",");
    strcpy(line + strlen(line), "\0");
    index++;
    while (queryRow[index] != ' ')
        index++;
    while (queryRow[index] == ' ')
        index++;
    j = 0;
    while (queryRow[index] != '\0')
    {
        index++;
        j++;
    }
    strncat(line, queryRow + index - j, j);    
    strcpy(line + strlen(line), "\0");   
    strcpy(queryRow ,"\0");    
    j = 0;
    while (line[j] != '\0')
    {
        if(line[j]!= ' ')
            strncat(queryRow, line + j, 1);
        j++;
    }   

    return isProper;
}
