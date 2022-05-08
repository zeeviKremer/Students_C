#include "main.h"


int main()
{    
    int checkFile = 0;
	student* head=NULL;
    head = readFile(head,&checkFile);     
    if (checkFile)
    {
        printf("cannot open the file");
        exit(checkFile);
    }
    else
    {       
        runQueries(head);
    }
            
	return 0;
}


