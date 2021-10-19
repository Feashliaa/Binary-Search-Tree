//-------------------------------------------------------------------------------------------------
//File Name:       OutputMethods.h
//Associated File: OutputMethods.cpp
//Contains: Print Divider, Output Menu, and a Centered Message
//-------------------------------------------------------------------------------------------------
#ifndef OutputMethods_h
#define OutputMethods_h

#include "Standards.h"

// functions to output items to the screen/file
void PrintDivider(ofstream& fout, char symbol, int amount);
void PrintCourseHeading(ofstream &fout, string collegeName,
  string programmerName, string courseName);
void PrintCenteredMessage(ofstream& fout, string message, int amount);
void PrintFileName(ofstream& fout, string fileName, string fileType);

#endif