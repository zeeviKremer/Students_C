//#include "validations.h"
//
//int isChars(char* line)
//{
//	int rez = 0, i = 0;
//	if (line == NULL)
//	{
//		rez = 1;
//		return rez;
//	}
//	else
//	{
//		while (line[i] != '\0')
//		{
//			if (!(line[i] >= 'A' && line[i] <= 'Z' || line[i] >= 'a' && line[i] <= 'z'))
//			{
//				rez = 2;
//				return rez;
//			}
//			i++;
//		}
//	}
//
//	return rez;
//}
//
//int properId(char* line)
//{
//	int rez = 0, i = 0;
//	if (line == NULL)
//	{
//		rez = 1;
//		return rez;
//	}
//	else
//	{
//		while (line[i] != '\0')
//		{
//			if (!(line[i] >= '0' && line[i] <= '9'))
//			{
//				rez = 3;
//				return rez;
//			}
//			i++;
//		}
//		if (i != 9)
//		{
//			rez = 4;
//			return rez;
//		}
//	}
//
//	return rez;
//}
//
//int checkCoursName(char* line)
//{
//	int rez = 0;
//	if (line == NULL)
//	{
//		rez = 1;
//		return rez;
//	}
//	else
//	{
//		if (strcmp(line, "C language") == 0)
//			return rez;
//		else if (strcmp(line, "Computer Networks") == 0)
//			return rez;
//		else if (strcmp(line, "CS Fundamentals") == 0)
//			return rez;
//		else
//		{
//			rez = 5;
//			return rez;
//		}
//	}
//}
//
//int isScore(char* line)
//{
//	int rez = 0, i = 0, num = 0;
//	if (line == NULL)
//	{
//		rez = 1;
//		return rez;
//	}
//	else
//	{
//		while (line[i] != '\0')
//		{
//			if (!(line[i] >= '0' && line[i] <= '9'))
//			{
//				rez = 6;
//				return rez;
//			}
//			num *= 10;
//			num += line[i] - '0';
//			if (num > 100)
//			{
//				rez = 7;
//				return rez;
//			}
//			i++;
//		}
//	}
//
//	return rez;
//}
//
//int validationLine(char* line1)
//{
//	int rez = 0, i;
//	char* token, ch[2] = ",", * line;
//	line = (char*)malloc(sizeof(char) * (strlen(line1) + 1));
//	strcpy(line, line1);
//	strcpy(line + strlen(line1), "\0");
//	if (line == NULL)
//	{
//		rez = 1;
//		return rez;
//	}
//	else
//	{
//		token = strtok(line, ch);
//		/*a = 239;
//		b = 187;
//		c = 191;
//		for (i = 0; token[i] != '\0'; i++)
//		{
//			if ((token[i] & a) == a )
//				token += 1;
//			if ((token[i] & b) == b )
//				token += 1;
//			if ((token[i] & c) == c)
//				token += 1;
//		}		*/
//		/*Check the firstName*/
//		if (rez = isChars(token))
//			return rez;
//		token = strtok(NULL, ch);
//
//		/*Check the secondName*/
//		if (rez = isChars(token))
//			return rez;
//		token = strtok(NULL, ch);
//
//		/*Check the Id*/
//		if (rez = properId(token))
//			return rez;
//		token = strtok(NULL, ch);
//
//		/*Check the coursName*/
//		if (rez = checkCoursName(token))
//			return rez;
//		token = strtok(NULL, ch);
//
//		/*Check the Scor*/
//		if (rez = isScore(token))
//			return rez;
//	}
//
//	return rez;
//}
//
//int validetionSelectQuety(char* queryLine, char* fild, char* operator, char* data)
//{
//	int index = 0, range;
//	puts(queryLine);
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
//
//int validationSetQuety(char* line1)
//{
//	int rez = 0;
//	char* token, ch[2] = ",", * line;
//	line = (char*)malloc(sizeof(char) * (strlen(line1) + 1));
//	strcpy(line, line1);
//	strcpy(line + strlen(line1), "\0");
//	if (line == NULL)
//	{
//		rez = 1;
//		return rez;
//	}
//	else
//	{
//		token = strtok(line, ch);
//
//		/*Check the firstName*/
//		if (rez = isChars(token))
//			return rez;
//		token = strtok(NULL, ch);
//
//		/*Check the secondName*/
//		if (rez = isChars(token))
//			return rez;
//		token = strtok(NULL, ch);
//
//		/*Check the Id*/
//		if (rez = properId(token))
//			return rez;
//		token = strtok(NULL, ch);
//
//		/*Check the coursName*/
//		if (rez = checkCoursName(token))
//			return rez;
//		token = strtok(NULL, ch);
//
//		/*Check the Scor*/
//		if (rez = isScore(token))
//			return rez;
//	}
//
//	return rez;
//}