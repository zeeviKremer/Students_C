#include <string.h>

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
	else if(strlen(operator) > 2)
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
/*return 0 if the syntax of the line is good , 1 if the line is null or does not contain five columns,
  2 if the firstName or secondName including chars thet not letters ,
  3 if the Id including chars thet not numbers , 4 if the length of the Id is not 9 chars ,
  5 if not exist a coursName in the courses like the coursName ,
  6 if the scor including chars thet not numbers , 7 if the sum of the scor is greater than 100  */
int validationLine(char* line1)
{
	int rez = 0,i;
	char* token, ch[2] = ",",* line;
	line = (char*)malloc(sizeof(char) * (strlen(line1) + 1));	
	strcpy(line,line1);
	strcpy(line + strlen(line1), "\0");
	if (line == NULL)
	{
		rez = 1;
		return rez;
	}
	else
	{
		token = strtok(line, ch);
		/*a = 239;
		b = 187;
		c = 191;
		for (i = 0; token[i] != '\0'; i++)
		{
			if ((token[i] & a) == a )
				token += 1;
			if ((token[i] & b) == b )
				token += 1;
			if ((token[i] & c) == c) 
				token += 1;
		}		*/
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



int validetionSelectQuety(char* queryLine, char* fild, char* operator, char* data)
{
	int index = 0, range, i = 0, j = 0, isProper = 0;
	char temp[20];
	while (queryLine[index] == ' ')
		index++;
	range = index;
	while (queryLine[range] >= 'a' && queryLine[range] <= 'z' || queryLine[range] >= 'A' && queryLine[range] <= 'Z' || queryLine[range] == ' ')
		range++;
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
	
	/*strncpy(fild, queryLine + index, range - index);
	fild[range - index] = '\0';
	i = 0;
	while (fild[i] != '\0')
	{
		if (fild[i] >= 'A' && fild[i] <= 'Z')
			fild[i] = tolower(fild[i]);
		i++;
	}*/
	queryLine += range;
	index = range = 0;
	while (queryLine[index] == ' ')
		index++;
	range = index;
	while (queryLine[range] == '=' || queryLine[range] == '!' || queryLine[range] == '<' || queryLine[range] == '>' || queryLine[range] == ' ')
		range++;	
	i = 0,j=0;
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
	//strncpy(operator, queryLine + index, range - index);
	//operator[range - index] = '\0';
	queryLine += range;
	index = 0;
	while (queryLine[index] == ' ')
		index++;
	queryLine += index;
	index = 0;
	while (queryLine[index] >= 'a' && queryLine[index] <= 'z' || queryLine[index] >= 'A' && queryLine[index] <= 'Z' || queryLine[index] >= '0' && queryLine[index] <= '9' || queryLine[index] == '-')
		index++;
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

//int validetionSelectQuety(char* queryLine, char* fild, char* operator, char* data)
//{
//	int index = 0, range;	
//	while (queryLine[index] == ' ')
//		index++;
//	range = index;
//	while (queryLine[range] >= 'a' && queryLine[range] <= 'z' || queryLine[range] >= 'A' && queryLine[range] <= 'Z')
//		range++;
//	strncpy(fild, queryLine + index, range - index);
//	fild[range - index] = '\0';
//	queryLine += range;
//	index = range = 0;
//	while (queryLine[index] == ' ')
//		index++;
//	range = index;
//	while (queryLine[range] == '=' || queryLine[range] == '!' || queryLine[range] == '<' || queryLine[range] == '>')
//		range++;
//	strncpy(operator, queryLine + index, range - index);
//	operator[range - index] = '\0';
//	queryLine += range;
//	index = 0;
//	while (queryLine[index] == ' ')
//		index++;
//	queryLine += index;
//	index = 0;
//	while (queryLine[index] >= 'a' && queryLine[index] <= 'z' || queryLine[index] >= 'A' && queryLine[index] <= 'Z' || queryLine[index] >= '0' && queryLine[index] <= '9' || queryLine[index] == '-')
//		index++;
//	strncpy(data, queryLine, index);
//	data[index] = '\0';
//	return 1;
//}


/*return 0 if the syntax of the line is good and chang the syntax like a line in the file ,
  1 if the line is null or does not contain five columns,
  2 if the firstName or secondName including chars thet not letters ,
  3 if the Id including chars thet not numbers , 4 if the length of the Id is not 9 chars ,
  5 if not exist a coursName in the courses like the coursName ,
  6 if the scor including chars thet not numbers , 7 if the sum of the scor is greater than 100  */
int validationSetQuety(char* line1)
{
	int rez = 0;
	char* token, ch[2] = ",",* line;
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