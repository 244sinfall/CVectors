#include <stdio.h>
#include <stdlib.h>

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
        printf_s("Welcome to the vector calculator!\n");
        printf_s("Please select the action:\n");
        printf_s("1. Current vectors menu\n");
        printf_s("2. Add vector\n");
        printf_s("3. Remove vector\n");
        printf_s("4. Inverse vectors' list\n");
        printf_s("0. Quit\n");
        int selection;
        scanf_s("%d", &selection);
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
