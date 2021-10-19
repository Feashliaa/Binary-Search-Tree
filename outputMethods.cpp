#include "OutputMethods.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: OutputMenu
// Description: This function is used to output a menu to the screen
//
///////////////////////////////////////////////////////////////////////////////////////////////////
void PrintCourseHeading(ofstream &fout, string collegeName,
  string programmerName, string courseName)
{
  // calling function to output a divider for better readability;
  PrintDivider(fout, '-', SCREEN_WIDTH);

  // calling function to output the college name
  PrintCenteredMessage(fout, collegeName, SCREEN_WIDTH);

  // calling function to output the programmer name
  PrintCenteredMessage(fout, programmerName, SCREEN_WIDTH);

  // calling function to output the course name
  PrintCenteredMessage(fout, courseName, SCREEN_WIDTH);

  // calling function to output a divider for better readability;
  PrintDivider(fout, '-', SCREEN_WIDTH);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: PrintDivider
// Description: This function is used to output a divider to the screen
//
///////////////////////////////////////////////////////////////////////////////////////////////////
void PrintDivider(ofstream& fout, char symbol, int amount)
{
  // output the divider to the screen and output file
  std::cout << setfill(symbol) << setw(amount) << symbol << setfill(' ') << endl;
  fout << setfill(symbol) << setw(amount) << symbol << setfill(' ') << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: PrintCenteredMessage
// Description: This function is used to output a printed message to the screen
//
///////////////////////////////////////////////////////////////////////////////////////////////////
void PrintCenteredMessage(ofstream& fout, string message, int amount)
{
  int stringWidth;

  // calculate the centering print width for the programmer's name
  stringWidth = (amount + static_cast<int> (message.length())) / 2;

  // output the message name to the screen and the output file
  std::cout << setw(stringWidth) << message << endl;
  fout << setw(stringWidth) << message << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: PrintFileName
// Description: Outputs the type and the name of an input or output file
//
///////////////////////////////////////////////////////////////////////////////////////////////////
void PrintFileName(ofstream& fout, string fileName, string fileType)
{
  // outputting the file name, and the file type
  std::cout << fileName << setw(10) << fileType;
  fout << fileName << setw(10) << fileType;
}