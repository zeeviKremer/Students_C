
#define MAX_LINE  255
#define COURSES  3
#define FILE_NAME "students.csv"


typedef struct student {
    char* FirstName;
    char* SecondName;
    char Id[10];
    char courses[COURSES];
    float average;
    struct student* next;
}student;


typedef enum {

    firstname = 1, secondname, id, clanguage, computernetworks, csfundamentals, average

} enumFields;


student* readFile(student* head, int* checkFile);
student* createNode(char* row);
int existInList(student* head, student* tail, student* stud);
student* getPtrToNode(student* head, student* newStud);
void updateStudent(student* ptrNode, student* newStud);
student* getIndexToInsert(student* head, student* tail, student* newStud);
void addTolist(student** head, student** tail, student* ptrPrv, student* newStud);
void updateScor(student* newStud, student* ptrNode);
int updateFile(student* head);
void printTitle();
void printFuter();
void printNode(student* stud);
void printList(student* head);
void getId(char* field,char* operator,int* fieldId, int* operatorId);
