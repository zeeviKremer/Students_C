

typedef enum {

	equal, bigger, smaller, biggerEqual, smallerEqual, notEqual

} enumOperators;


student* getIndexToInsertQuery(student* head, student* ptrNode);
void addTolistQuery(student** head, student* ptrPrv, student* newStud);
void updateStudentQuery(student** head, student* ptrNode, student* newStud);
int select_firstname(student* head, int operator, char* data);
int select_secondname(student* head, int operator, char* data);
int select_id(student* head, int operator, char* data);
int select_clanguage(student* head, int operator, char* data);
int select_computernetworks(student* head, int operator, char* data);
int select_csfundamentals(student* head, int operator, char* data);
int select_average(student* head, int operator, float* data);
void deleteStudent(student** head, char* data);
int genericSelect(student* head, int field, int operator,void* data);
void printMenu();
void runQueries(student* head);
int checkQuery(char* query, student** head);
