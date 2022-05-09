
#define MAX_LINE  255
#define SUM_COURSES  3
#define FILE_NAME "students.csv"
#define NOT_TESTED  -1


typedef struct student {
    char* FirstName;
    char* SecondName;
    char Id[10];
    char marks[SUM_COURSES];
    float average;
    struct student* next;
}student;


typedef struct studManagar {
    student* head;
    student* tail;
    char isSorted;
    char countAdded;
    char countUpdate;
    char countDeleted;
}studManagar;


typedef enum {

    firstname = 1, secondname, id, clanguage, computernetworks, csfundamentals, average

} enumFields;



studManagar* readFile(char* fileName);
student* createNode(char* row);
int existInList(studManagar* studentsManager, student* stud);
student* getPtrToNode(studManagar* studentsManager, student* newStud);
void updateStudent(student* ptrNode, student* newStud);
student* getIndexToInsert(studManagar* studentsManager,student* newStud);
void addTolist(studManagar* studentsManager, student* ptrPrv, student* newStud);
void updateMark(student* newStud, student* ptrNode);
int updateFile(studManagar* studentsManager);
void printTitle();
void printFuter();
void printNode(student* stud);
void printList(studManagar* studentsManager);
void printError(int countRows,int checkSyntax);
void getId(char* field,char* operator,int* fieldId, int* operatorId);
void freeStudent(student* ptrStud);
void freeList(studManagar* studentsManager);
int ExistToDelete(student*  head, char* data);
