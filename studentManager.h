

#define MAX_LINE  255
#define COURSES  3

typedef struct student {
    char* FirstName;
    char* SecondName;
    char Id[10];
    char courses[COURSES];
    float average;
    struct student* next;
}student;

student* raedFile(student* head, int* checkFile);
student* createNode(char* line);
int existInList(student* head, student* stud);
student* getPtrToNode(student* head, student* newStud);
void updateStudent(student* ptrNode, student* newStud);
student* getIndexToInsert(student* head, student* tail, student* newStud);
void addTolist(student** head, student** tail, student* ptrPrv, student* newStud);
student*  getIndexToInsertQuery(student* head, student*  ptrNode);
void addTolistQuery(student** head, student* ptrPrv, student* newStud);
void updateStudentQuery(student** head, student* ptrNode, student* newStud);
void updateScor(student* newStud, student* ptrNode);
int updateFile(student* head);
void printTitle();
void printFuter();
void printNode(student* stud);
void printList(student* head);
int selectFromList(student* head, char* fild, char* operat, char* data, student** newList);
