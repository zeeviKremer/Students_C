
int isChars(char* line);
int properId(char* line);
int checkCoursName(char* line);
int isScore(char* line);
int checkNamesData(char* data);
int checkIdData(char* data);
int checkScoresData(char* data);
int checkAverageData(char* data);
int checkFildName(char* queryRow, char* fild, int flag);
int checkOperator(char* queryRow, char* operator,int flag);
int checkData(char* queryRow, char* fild, char* data);
int validationRow(char* Row);
int validetionSelectQuery(char* queryLine, char* field, char* operator,void* data);
int validationSetQuery(char* line1);
