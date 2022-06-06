//#include "vector_processing.h"
//
//Vector AddVector(Vector *firstVector);
#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
Vector* InverseLinkedList(Vector* firstVector, int isFirst);
void AddVector(Vector *firstVector, int *isFirst);
void PrintAllVectors(Vector* firstVector);
Vector* RemoveVector(Vector* firstVector, int *isFirst);
Vector* SelectVector(Vector* firstVector);
Vector* LoadFile();
void WriteToFile(Vector* firstVector, int isFirst);