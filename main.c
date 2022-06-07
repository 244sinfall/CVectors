#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "vector_processing.h"
#include "linked_list_processing.h"



int main() {
    int programState = 1;
    int isFirst = 1;
    Vector *firstVector;
    firstVector = LoadFile();
    if(firstVector == NULL) {
        firstVector = (Vector*) malloc(sizeof(Vector));
    }
    else {
        isFirst = 0;
    }
//    firstVector->next = NULL;
//    firstVector->previous = NULL;
    while(programState) {
        printf("Welcome to the vector calculator!\n");
        printf("Please select the action:\n");
        printf("1. Current vectors menu\n");
        printf("2. Add vector\n");
        printf("3. Remove vector\n");
        printf("4. Inverse vectors' list\n");
        printf("0. Quit\n");
        int selection;
        scanf("%d", &selection);
        switch (selection) {
            case 0:
                programState = 0;
                WriteToFile(firstVector, isFirst);
                break;
            case 1:
                if(isFirst == 1) {
                    printf("No vectors available.\n");
                    break;
                }
                VectorMenu(firstVector);
                break;
            case 2:
                AddVector(firstVector, &isFirst);
                break;
            case 3:
                firstVector = RemoveVector(firstVector, &isFirst);
                break;
            case 4:
                firstVector = InverseLinkedList(firstVector, isFirst);
                break;
            default:
                break;
        }
    }
    return 0;
}

