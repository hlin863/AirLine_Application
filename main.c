#include "mileage.h"
#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ProgramInterface();

struct PriorityQueue *readFile(FILE* file);

int main(){

    ProgramInterface();

    return 0;

}

void ProgramInterface(){

    FILE *customers = fopen("customers.txt", "r");

    if (customers == NULL){
        printf("Error: customers.txt could not be opened.\n");
        return;
    } else {
        printf("Opening a file\n");
    }

    struct PriorityQueue *queue = readFile(customers);

}

struct PriorityQueue *readFile(FILE* file){

    // read through each line in the file.
    char line[100];

    struct PriorityQueue *queue = createPriorityQueue(10);

    int lineNumber = 0;

    // create a list to store the first names and the last names
    char firstNames[100][100];
    char lastNames[100][100];

    for (int i = 0; i < 100; i++){
        strcpy(firstNames[i], "");
        strcpy(lastNames[i], "");
    }

    printf("DEBUG CHECKPOINT 1\n");

    while (fgets(line, 100, file) != NULL){

        // gets the first two words as the characters' name
        char firstName[100];

        strcpy(firstName, "");

        int i = 0;

        while (line[i] != ' '){
            firstName[i] = line[i];
            i++;
        }

        firstName[i] = '\0';

        printf("DEBUG CHECKPOINT 2\n");

        char lastName[100];

        strcpy(lastName, "");

        i++;

        int j = 0;

        while (line[i] != ' '){
            lastName[j] = line[i];
            i++;
            j++;
        }

        lastName[j] = '\0';

        printf("DEBUG CHECKPOINT 3\n");

        // gets the next three words as the characters' mileage
        int mileage[3] = {0, 0, 0};

        i++;

        for (int k = 0; k < 2; k++){
            int m = 0;
            while (line[i] != ' '){
                mileage[k] = mileage[k] * 10 + (line[i] - '0');
                i++;
                m++;
            }
            i++;
        }

        // gets the last word as the characters' priority
        int n = 0;

        while (line[i] != '\n'){
            mileage[2] = mileage[2] * 10 + (line[i] - '0');
            i++;
            n++;
        }

        printf("DEBUG CHECKPOINT 4\n");

        printf("Mileage: %d miles.\n", mileage[0]);
        printf("Years: %d years.\n", mileage[1]);
        printf("Sequence: %d.\n", mileage[2]);

        // mileage[0] = mileage, mileage[1] = Years, mileage[2] = Sequence
        int priority = getPriority(mileage[0], mileage[1], mileage[2]);

        // test to check whether the priority value is valid.
        printf("Priority: %d.\n", priority);

        /*
            BUG FIX: unexpected termination in the later sections. 
            FIXED BUG: changing the variable index to ensure that the array indexes are within range.  
        */

        // enqueue the characters' name and mileage into the priority queue.
        queue = enqueue(queue, lineNumber, priority);

        printf("ENQUEUE SUCCESSFULLY.\n");

        lineNumber++;

        // store the characters' name into the list.
        strcpy(firstNames[lineNumber], firstName);
        strcpy(lastNames[lineNumber], lastName);

        printf("DEBUG CHECKPOINT 5\n");

        // fix bug by changing the variable name to preven variable name conflict    
        for (int index = 0; index < queue->index; index++){
            printf("%s", firstNames[index]);
            printf(" ");
            printf("%s", lastNames[index]);
            printf("\n");
        }

    }

    for (int index = 0; index < queue->index; index++){
        printf("%s", firstNames[index]);
        printf(" ");
        printf("%s", lastNames[index]);
        printf("\n");
    }

    return queue;

}