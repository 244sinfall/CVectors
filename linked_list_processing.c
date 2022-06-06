#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "vector_processing.h"



Vector* LoadFile() {
    FILE* savedVectors;

    if((savedVectors = fopen("savedVectors.txt", "r")) == NULL) {
        return NULL;
    }

    if(savedVectors != NULL || feof(savedVectors) != 0) {
        Vector* returnVector = (Vector*) malloc(sizeof(Vector));
        int isFirst = 1;
        int loaded = 0;
        while(feof(savedVectors) == 0) {
            int success;
            if(isFirst == 1) {
                success = fscanf_s(savedVectors, "(%f, %f) (%f, %f)\n",&returnVector->start.x,
                         &returnVector->start.y, &returnVector->end.x, &returnVector->end.y);
                returnVector->next = NULL;
                returnVector->previous = NULL;
                if(success < 4) {
                    continue;
                }
                isFirst = 0;
                loaded += 1;
            }
            else {
                Vector *newVector = (Vector*) malloc(sizeof(Vector));
                success = fscanf_s(savedVectors, "(%f, %f) (%f, %f)\n",&newVector->start.x,
                         &newVector->start.y, &newVector->end.x, &newVector->end.y);
                if(success < 4) {
                    free(newVector);
                    continue;
                }
                Vector *lastVector = returnVector;
                while (lastVector->next != NULL) {
                    lastVector = lastVector->next;
                }
                lastVector->next = newVector;
                newVector->previous = lastVector;
                newVector->next = NULL;
                loaded += 1;
            }
        }
        if(loaded == 0) { return NULL; }
        fclose(savedVectors);
        printf("%d vectors loaded from file!\n", loaded);
        return returnVector;
    }
    return NULL;
}

void WriteToFile(Vector* firstVector, int isFirst) {
    FILE* savedVectors;
    Vector* selectedVector = firstVector;
    savedVectors = fopen("savedVectors.txt", "w");
    if(isFirst == 1) {
        fclose(savedVectors);
        return;
    }
    while(selectedVector != NULL) {
        fprintf(savedVectors, "(%f, %f) (%f, %f)\n",selectedVector->start.x, selectedVector->start.y, selectedVector->end.x, selectedVector->end.y);
        selectedVector = selectedVector->next;
    }
    fclose(savedVectors);
}

void PrintAllVectors(Vector* firstVector) {
    Vector* selectedVector = firstVector;

    int counter = 0;


    while(selectedVector != NULL) {
        if(selectedVector->previous != NULL) {
            printf("DEBUG LINE: Previous exist! ");
        }
        if(selectedVector->next != NULL) {
            printf("DEBUG LINE: Next exist! ");
        }
        printf("%d: Vector start point: (%f, %f). End point: (%f, %f).\n", counter,selectedVector->start.x, selectedVector->start.y, selectedVector->end.x, selectedVector->end.y);
        if(selectedVector->next == NULL) {
            break;
        }
        selectedVector = selectedVector->next;
        counter += 1;
    }
    printf("Linked list length is: %d\n", counter+1);
}

Vector* InverseLinkedList(Vector* firstVector, int isFirst) {
    if(isFirst == 1 || (firstVector->next == NULL && firstVector->previous == NULL)) {
        printf("Nothing to inverse.\n");
        return firstVector;
    }
    Vector* currentVector = firstVector;
    Vector* temp = currentVector;
    while (currentVector != NULL) {
        temp = currentVector->previous;
        currentVector->previous = currentVector->next;
        currentVector->next = temp;
        currentVector = currentVector->previous;
    }
    return temp->previous;
}

Vector* SelectVector(Vector* firstVector) {
    int selected;
    Vector* selectedVector = firstVector;
    PrintAllVectors(firstVector);
    printf("Select Vector:\n");
    scanf_s("%d", &selected);
    for(int i = 0; i<selected; i++) {
        selectedVector = selectedVector->next;
        if(selectedVector == NULL) {
            return NULL;
        }
    }
    return selectedVector;
}

Vector* RemoveVector(Vector* firstVector, int *isFirst) {
    if(*isFirst == 1) {
        printf("Nothing to delete.\n");
        return firstVector;
    }
    Vector* vectorToDelete = SelectVector(firstVector);
    if(vectorToDelete == NULL) {
        printf("Incorrect vector number.\n");
        return firstVector;
    }
    if(vectorToDelete->previous != NULL && vectorToDelete->next != NULL) {
        vectorToDelete->previous->next = vectorToDelete->next;
        vectorToDelete->next->previous = vectorToDelete->previous;
    }
    else if (vectorToDelete->previous == NULL && vectorToDelete->next == NULL) {
        realloc(firstVector, sizeof (Vector));
        *isFirst = 1;
        return firstVector;
    }
    else if (vectorToDelete->previous == NULL) {
        firstVector = vectorToDelete->next;
        firstVector->previous = NULL;
    }
    else if (vectorToDelete->next == NULL) {
        vectorToDelete->previous->next = NULL;
    }
    free(vectorToDelete);
    return firstVector;
}

void AddVector(Vector* firstVector, int *isFirst) {
    if (*isFirst == 1) {// first
        //firstVector = (Vector*) malloc(sizeof(Vector));
        GenerateNewVector(firstVector);
        printf_s("New vector added successfully.\n");
        firstVector->next = NULL;
        firstVector->previous = NULL;
        *isFirst = 0;
    }
    else {
        Vector *newVector = (Vector*) malloc(sizeof(Vector));
        GenerateNewVector(newVector);
        Vector *lastVector = firstVector;
        while (lastVector->next != NULL) {
            lastVector = lastVector->next;
        }
        lastVector->next = newVector;
        newVector->previous = lastVector;
        newVector->next = NULL;
        printf_s("New vector added successfully.\n");
    }
}

