#pragma once
#include"Structs.h"

void CreateField(char** field, FieldSize fieldsize);
void InitField(char** field, FieldSize fieldsize, char PatternSymbols[]);
void PrintField(char** field, FieldSize fieldsize);