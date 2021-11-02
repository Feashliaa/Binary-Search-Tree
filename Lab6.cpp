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
