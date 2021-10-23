#include <stdio.h>  
#include <stdlib.h> 
#include <string.h>
#include "basicStruct.h" 

int main ()
{
        int numE;
        int i;
        int j;
        int nameSpaces = 10;
        char name2[nameSpaces];
        struct EmployeeInfo *Emp;

        FILE *file;
        file = fopen("Project0Input.txt", "r");
        
        if(file == NULL)
        {
                perror("Error ");
                return(-1);
        }

        fscanf(file, "%d", &numE);
        fscanf(file, "%*[^\n]\n");

        numE = numE;

        Emp = (struct EmployeeInfo*)malloc(numE * sizeof(struct EmployeeInfo));
        
        for(i = 0; i < numE; i++)
        {       
                fscanf(file, "%s %d %lf", Emp[i].name, &Emp[i].id, &Emp[i].hrate);
                strcpy(name2, Emp[i].name);
                for(j = 0; j < nameSpaces; j++)
                {
                        if(name2[j] == '\0')
                        {
                                strcat(name2, " ");
                        }
                }       
                strcpy(Emp[i].name, name2);
                
        }

        printf("Name:      |ID:    |Hourly rate:");
        printf("\n---------------------------------\n");

        for(i = 0; i < numE; i++)
        {
                printf("%s |%d |$%.2lf\n", Emp[i].name, Emp[i].id, Emp[i].hrate);
        }

        
        fclose(file);
        free(Emp); 
		
	return 0;
}
