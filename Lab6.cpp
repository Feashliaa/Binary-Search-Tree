//----------------------------------------------------------------------------------------------------------------------
//Lab 6 Grading Block
//Name: 
//Lab Grade: 
//----------------------------------------------------------------------------------------------------------------------
//Total Possible Points -------------------------------------------------------------------------------------------> 200
//Total Points lost ----------------------------------------------------------------------------------------------->
//Lab Grade -------------------------------------------------------------------------------------------------------> 
//----------------------------------------------------------------------------------------------------------------------
//General Comments:
//  
//  
//  
//  
//----------------------------------------------------------------------------------------------------------------------
//Standard Requirements
//  Requirements met as specified for the
//  Which includes but not limited to:
//    Program Creation
//    File Requirements
//    Documentation
//    Documentation as required for Class Objects
//    Constants
//    Variables 
//    Code
//Comments:
//  
//  
//  
//Points Lost ----------------------------------------------------------------------------------------------------->
//
//Program Specifications
//-Standards.h included with the preprocessor directives
//-Course Required header & CPP file
//Comments:
//
//Points Lost ----------------------------------------------------------------------------------------------------->
//
//----------------------------------------------------------------------------------------------------------------------
//
//Class Object DEFINITION
//nodeStructType defined
//node defined
//nodePtr type def
//Object defined using UML
//
//Methods
// Accomplish the required tasks EFFICIENTLY
// Methods placed in header and c++ file in the order 
//  listed in the instructions with the constructor first and the destructor last
// Constructor
//  Calls CreateTree
// CreateTree
//  Set root to NULL & isAlpha to true
// IsEmpty 
//  returns a boolean
// GetRoot
//  returns a pointer to the root
// GetANode
//  Creates a nodePtr with letter,count and 2 pointers set to NULL// Insert
//   Inserts a node into the ordered ascending tree, either alpha or int tree
// BuildAlphaTree
//  Inputs letters, creating an alphabet ordered tree with counts set to 0
//  Recursively, In order
// BuildCountTree
//  From the updated Alpha tree, creates a count tree in ascending order, recursively
// ProcessText
//  Inputs the letters created a binary search tree from the order of the letters in the input file
// Insert
//  Inserts a node into tree based on the type of the newNode
// In order,Pre order,Postorder
//  Outputs the output file, in aligned columns the letter and the counts in the correct order, 
//    one per line
// UpdateTree
//  Using the input data from the text file, updates the count based on the occurrence of the
//   letter, recursively, In order
// FindLargestCount
//  Using the count tree & taking advantage of the order, efficiently finds the largest count
//   in the tree
// SumCounts
//  Calculates the sum of the counts in the count tree, recursively
// SearchTree
//  Non-recursive solution returns a boolean, current and parent based on the type of tree
// DeleteLeafNode, DeleteNodeLeftChildOnly, DeleteNodeRightChildOnly, DeleteNodeWithTwoChildren,
//  Deletes and updates the pointers as needed
// DeleteNode
// Delete
//  Call one of 4 deletion methods to actually delete the specific type of node
// DestroyTree
// Print
//  Outputs the tree in the specified order to the output file
// Destructor
//Friend Functions
//  PrintDivider
//
//Comments:
// 
// 
// 
// 
//Points Lost --------------------------------------------------------------------------------------------------->
//
//Main - follow this order and accomplish these tasks
// Files open
// Alpha tree built
// Alpha tree output in order, no counts updated with sum of counts
// Process Text, counts updated based on text
// Output Alpha tree in order with letters, counts & sum of counts
// Output Alpha tree pre order with letters, counts & sum of counts
// Output Alpha tree postorder with letters, counts & sum of counts
// Build the count tree, ordered in ascending order based on the counts
// Output Count tree in order with letters, counts & sum of counts
// Output Count tree postorder with letters, counts & sum of counts
// Find the largest in the Count tree and output the largest clearly labeled in the main
// Search for the letter, t in the Alpha tree and output message with letter and count or
//  message that it was not found
// Search for the letter, * in the Alpha tree and output message with letter and count or
//  message that it was not found
// Search for the letter, q in the Alpha tree and output message with letter and count or
//  message that it was not found
// Attempt to delete a node with letter, u to search and delete the node if found - leaf node
// Output deletion message in the main based on found
// Attempt to delete a node with a letter, u - search and delete the node if found - node with 2 children
// Output deletion message in the main based on found
// Attempt to delete a node with a letter, h - search and delete the node if found - node with 1 right child
// Output deletion message in the main based on found
// Attempt to delete a node with a letter, z - search and delete the node if found - node with 1 left child
// Output deletion message in the main based on found
// Attempt to delete a node with letter, x - search and delete the node if found - node not found
// Output deletion message in the main based on found
// Output the alpha tree to the output file, message "After 4 Deletions"
// Output the count tree to the output file, message "After 4 Deletions"
// Files Closed
//----------------------------------------------------------------------------------------------------------------------
//Miscellaneous Errors not anticipated by your professor
//
//
//
//Comments:
// 
//
// 
//----------------------------------------------------------------------------------------------------------------------
//
#include "treeClassType.h"

int main(void)
{
  nodePtr rootPtr;
  nodePtr tempPtr;

  treeClassType alphaTree;
  treeClassType countTree;

  // 3
  ifstream fin("letters.txt");
  // 4
  ofstream fout("output.txt");

  PrintCourseHeading(fout, COLLEGE, PROGRAMMER_NAME, COURSE);

  // 5
  alphaTree.BuildAlphaTree(fin);
  fin.close();

  // 6 
  alphaTree.Print(fout, "InOrder", "ALPHA", "Updated with Letters");

  // 7
  fin.open("info.txt");
  alphaTree.ProcessText(fin);
  fin.close();

  // 8
  alphaTree.Print(fout, "InOrder", "ALPHA", "Updated Counts");

  // 9
  alphaTree.Print(fout, "PreOrder", "ALPHA", "Letters & Counts");

  // 10
  alphaTree.Print(fout, "PostOrder", "ALPHA", "Letters & Counts");

  // 11
  rootPtr = alphaTree.GetRoot();
  countTree.BuildCountTree(rootPtr);

  // 12
  countTree.Print(fout, "InOrder", "COUNT", "Letters & Counts");

  // 13
  countTree.Print(fout, "PostOrder", "COUNT", "Letters & Counts");

  // 14
  int largestCount = countTree.FindLargestCount();
  PrintDivider(fout, '-', SCREEN_WIDTH);
  std::cout << "Largest Count" << setw(16) << largestCount << endl;
  PrintDivider(fout, '-', SCREEN_WIDTH);

  // --------------------------------------------------------------
  // Search Portion Of Lab
  // --------------------------------------------------------------

  nodeStructType searchNode;
  bool booleanFlag = false;
  // 15
  searchNode.aLetter = 't';
  rootPtr = alphaTree.GetRoot();
  alphaTree.SearchTree(searchNode, booleanFlag, rootPtr, tempPtr);
  if (booleanFlag)
  {
    std::cout << "Letter: " << rootPtr->data.aLetter
      << setw(18) << "Count: " << rootPtr->data.letterCount << endl;
    fout << "Letter: " << rootPtr->data.aLetter
      << setw(18) << "Count: " << rootPtr->data.letterCount << endl;
  }
  else
  {
    std::cout << "Letter: " << searchNode.aLetter << " was not found" << endl;
    fout << "Letter: " << searchNode.aLetter << " was not found" << endl;
  }

  PrintDivider(fout, '-', SCREEN_WIDTH);

  // 16
  PrintDivider(fout, '-', SCREEN_WIDTH);
  booleanFlag = false;
  searchNode.aLetter = '*';
  rootPtr = alphaTree.GetRoot();
  alphaTree.SearchTree(searchNode, booleanFlag, rootPtr, tempPtr);
  if (booleanFlag)
  {
    std::cout << "Letter: " << rootPtr->data.aLetter
      << setw(18) << "Count: " << rootPtr->data.letterCount << endl;
    fout << "Letter: " << rootPtr->data.aLetter
      << setw(18) << "Count: " << rootPtr->data.letterCount << endl;
  }
  else
  {
    std::cout << "Letter: " << searchNode.aLetter << " was not found" << endl;
    fout << "Letter: " << searchNode.aLetter << " was not found" << endl;
  }

  PrintDivider(fout, '-', SCREEN_WIDTH);

  // 17
  PrintDivider(fout, '-', SCREEN_WIDTH);
  booleanFlag = false;
  searchNode.aLetter = 'q';
  rootPtr = alphaTree.GetRoot();
  alphaTree.SearchTree(searchNode, booleanFlag, rootPtr, tempPtr);
  if (booleanFlag)
  {
    std::cout << "Letter: " << rootPtr->data.aLetter
      << setw(18) << "Count: " << rootPtr->data.letterCount << endl;
    fout << "Letter: " << rootPtr->data.aLetter
      << setw(18) << "Count: " << rootPtr->data.letterCount << endl;
  }
  else
  {
    std::cout << "Letter: " << searchNode.aLetter << " was not found" << endl;
    fout << "Letter: " << searchNode.aLetter << " was not found" << endl;
  }

  PrintDivider(fout, '-', SCREEN_WIDTH);

  // --------------------------------------------------------------
  // Search and Delete Portion Of Lab
  // --------------------------------------------------------------

  // 18
  searchNode.aLetter = 'u';
  searchNode.letterCount = 0;
  char tempChar = searchNode.aLetter;
  booleanFlag = false;
  alphaTree.DeleteNode(searchNode, booleanFlag);
  if (booleanFlag)
  {
    std::cout << "Deleted Node - Letter: " << tempChar << endl;
    fout << "Deleted Node - Letter: " << tempChar << endl;
  }
  else
  {
    std::cout << "Letter: " << tempChar << " was not found" << endl;
    fout << "Letter: " << tempChar << " was not found" << endl;
  }

  PrintDivider(fout, '-', SCREEN_WIDTH);

  // 19
  searchNode.aLetter = 'x';
  searchNode.letterCount = 0;
  tempChar = searchNode.aLetter;
  booleanFlag = false;
  alphaTree.DeleteNode(searchNode, booleanFlag);

  if (booleanFlag)
  {
    std::cout << "Deleted Node - Letter: " << tempChar << endl;
    fout << "Deleted Node - Letter: " << tempChar << endl;
  }
  else
  {
    std::cout << "Letter: " << tempChar << " was not found" << endl;
    fout << "Letter: " << tempChar << " was not found" << endl;
  }

  PrintDivider(fout, '-', SCREEN_WIDTH);

  // 20
  searchNode.aLetter = 'h';
  searchNode.letterCount = 0;
  tempChar = searchNode.aLetter;
  booleanFlag = false;
  alphaTree.DeleteNode(searchNode, booleanFlag);
  if (booleanFlag)
  {
    std::cout << "Deleted Node - Letter: " << tempChar << endl;
    fout << "Deleted Node - Letter: " << tempChar << endl;
  }
  else
  {
    std::cout << "Letter: " << tempChar << " was not found" << endl;
    fout << "Letter: " << tempChar << " was not found" << endl;
  }

  PrintDivider(fout, '-', SCREEN_WIDTH);

  // 21 
  searchNode.aLetter = 'z';
  searchNode.letterCount = 0;
  tempChar = searchNode.aLetter;
  booleanFlag = false;
  alphaTree.DeleteNode(searchNode, booleanFlag);
  if (booleanFlag)
  {
    std::cout << "Deleted Node - Letter: " << tempChar << endl;
    fout << "Deleted Node - Letter: " << tempChar << endl;
  }
  else
  {
    std::cout << "Letter: " << tempChar << " was not found" << endl;
    fout << "Letter: " << tempChar << " was not found" << endl;
  }

  PrintDivider(fout, '-', SCREEN_WIDTH);

  // 22
  searchNode.aLetter = 'x';
  searchNode.letterCount = 0;
  tempChar = searchNode.aLetter;
  booleanFlag = false;
  alphaTree.DeleteNode(searchNode, booleanFlag);
  if (booleanFlag)
  {
    std::cout << "Deleted Node - Letter: " << tempChar << endl;
    fout << "Deleted Node - Letter: " << tempChar << endl;
  }
  else
  {
    std::cout << "Letter: " << tempChar << " was not found" << endl;
    fout << "Letter: " << tempChar << " was not found" << endl;
  }

  PrintDivider(fout, '-', SCREEN_WIDTH);

  // 23
  alphaTree.Print(fout, "InOrder", "ALPHA", "After 4 Deletions");

  // 24
  countTree.Print(fout, "InOrder", "COUNT", "Updated Counts");

  // 25
  fin.close();
  fout.close();

  PrintDivider(fout, '-', SCREEN_WIDTH);

  alphaTree.DestroyTree();
  countTree.DestroyTree();

  system("pause");

  return 0;
}