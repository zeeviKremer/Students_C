#include "main.h"


int main() 
{			
    int checkFile = 0;
	student* head=NULL;
    FILE* fRead;
    
    head = raedFile(head,&checkFile);       
    if (checkFile)
    {
        printf("cannot open the file");
        exit(1);
    }
    else
    {       
        runQueries(head);       
    }
            
	return 0;
}


