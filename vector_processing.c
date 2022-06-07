#include <math.h>
#include <stdio.h>
#include "structures.h"
#include "linked_list_processing.h"

void GenerateNewVector(Vector* newVector) {
    printf("Enter X coordinate of vector's START point:");
    scanf("%f", &newVector->start.x);
    printf("Enter Y coordinate of vector's START point:");
    scanf("%f", &newVector->start.y);
    printf("Enter X coordinate of vector's END point:");
    scanf("%f", &newVector->end.x);
    printf("Enter Y coordinate of vector's END point:");
    scanf("%f", &newVector->end.y);
}

Coordinate GetVectorCoordinates(Vector vectorToCount) {

    Coordinate newCoordinate;
    newCoordinate.x = vectorToCount.end.x - vectorToCount.start.x;
    newCoordinate.y = vectorToCount.end.y - vectorToCount.start.y;
    return newCoordinate;
}

Coordinate FindOXVector(Vector vectorToCount) {
    Coordinate OXVector;
    OXVector.x = vectorToCount.end.x;
    OXVector.y = vectorToCount.start.y;
    return OXVector;
}


float FindVectorLength(Vector vectorToCount) {

    Coordinate vectorCoordinates = GetVectorCoordinates(vectorToCount);
    float length = sqrtf(powf(vectorCoordinates.x, 2) + powf(vectorCoordinates.y, 2));
    return length;
}

float GetVectorAngleToOX(Vector vectorToCount) {
    Coordinate OXVector = FindOXVector(vectorToCount);
    Coordinate givenVector = GetVectorCoordinates(vectorToCount);

    float OXVectorLength = sqrtf(powf(OXVector.x, 2) + powf(OXVector.y, 2));

    float cosBetweenAngles = cosf((OXVector.x * givenVector.x + OXVector.y * givenVector.y)/(OXVectorLength *
    FindVectorLength(vectorToCount)));
    return cosBetweenAngles * (180/3.14);
}

void VectorMenu(Vector* firstVector) {
    while(1) {

        printf("Please select the action:\n");
        printf("1. Print vectors'.\n");
        printf("2. Count vector length and OX angle.\n");
        printf("3. Sort by...\n");
        printf("4. Filter by...\n");
        printf("0. To main menu\n");
        int selection;
        Vector* vectorToCount;
        scanf("%d", &selection);
        switch (selection) {
            case 0:
                return;
            case 1:
                PrintAllVectors(firstVector);
                break;
            case 2:
                vectorToCount = SelectVector(firstVector);
                if(vectorToCount == NULL) {
                    printf("Incorrect vector number.\n");
                    break;
                }
                printf("Selected vector length is: %f. Angle to OX is %f degrees.\n", FindVectorLength(*vectorToCount),
                       GetVectorAngleToOX(*vectorToCount));
                break;
            case 3:
                // TO DO
                break;
            case 4:
                // TO DO
                break;
            default:
                break;
        }
    }
}