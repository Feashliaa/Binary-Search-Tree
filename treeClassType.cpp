#include "treeClassType.h"
#include <queue>

// Constructor - Calls CreateTree
treeClassType::treeClassType()
{
  CreateTree();
  deleteNodeCount = 0;
}

// CreateTree – Set the root to NULL and isAlpha to true
void treeClassType::CreateTree()
{
  root = nullptr;
  isAlpha = true;
}

// IsEmpty - Tests the root, returns true if NULL otherwise returns false
bool treeClassType::IsEmpty()
{
  if (root == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// GetRoot – returns the pointer to the root of the tree
nodePtr treeClassType::GetRoot()
{
  return root;
}

// GetANode – stores a letter and the count in a node pointer, set the two links to NULL and returns the pointer
nodePtr treeClassType::CreateNode(char aLetter, int letterCount)
{
  nodePtr tempNode = new node();

  tempNode->data.aLetter = aLetter;
  tempNode->data.letterCount = letterCount;
  tempNode->left = nullptr;
  tempNode->right = nullptr;

  return tempNode;
}

// BuildAlphaTree – Reads from the input file, letters until the input file is empty,
// creates a binary search tree ordered alphabetically
void treeClassType::BuildAlphaTree(ifstream& fin)
{
  char tempChar;
  nodePtr tempNode;

  // sets boolean flag to true
  isAlpha = true;

  // primer
  fin >> tempChar;

  if (IsEmpty())
  {
    // creates a new node
    tempNode = CreateNode(tempChar, 0);
    // and inserts it into the alpha tree
    Insert(tempNode);
    // changer
    fin >> tempChar;
  }
  // while file isn't empty
  while (!fin.eof())
  {
    // creates a new node
    tempNode = CreateNode(tempChar, 0);
    // and inserts it into the alpha tree
    Insert(tempNode);
    // changer
    fin >> tempChar;
  }
}

// Insert - Inserts a node into a binary tree based on whether or not its a letter, or a digit count
void treeClassType::Insert(nodePtr newNode)
{
  nodePtr currentNode;
  nodePtr parentNode;
  // if the tree is empty, set the new node as the root
  if (root == nullptr)
  {
    nodePtr tempNode = new node;
    tempNode->data = newNode->data;
    tempNode->left = nullptr;
    tempNode->right = nullptr;

    root = tempNode;
    currentNode = root;
  }
  else
  {
    // if the value is a character
    if (isAlpha)
    {
      currentNode = root;
      while (currentNode != nullptr)
      {
        if (newNode->data.aLetter < (currentNode->data.aLetter))
        {
          parentNode = currentNode;
          currentNode = currentNode->left;
        }
        else
        {
          parentNode = currentNode;
          currentNode = currentNode->right;
        }
      }
      nodePtr tempNode = new node;
      tempNode->data.aLetter = newNode->data.aLetter;
      tempNode->left = nullptr;
      tempNode->right = nullptr;
      // checking for parent value to determine if
      // the Node is a left or right child  
      if (newNode->data.aLetter < (parentNode->data.aLetter))
      {
        parentNode->left = newNode;
      }
      else
      {
        parentNode->right = newNode;
      }
    }
    // otherwise insert based on the letterCount
    else
    {
      currentNode = root;
      while (currentNode != nullptr)
      {
        if (newNode->data.letterCount < (currentNode->data.letterCount))
        {
          parentNode = currentNode;
          currentNode = currentNode->left;
        }
        else
        {
          parentNode = currentNode;
          currentNode = currentNode->right;
        }
      }
      nodePtr tempNode = new node;
      tempNode->data.letterCount = newNode->data.letterCount;
      tempNode->left = nullptr;
      tempNode->right = nullptr;
      // checking for parent value to determine if
      // the Node is a left or right child  
      if (newNode->data.letterCount < (parentNode->data.letterCount))
      {
        parentNode->left = newNode;
      }
      else
      {
        parentNode->right = newNode;
      }
    }
  }
}

// ProcessText - Processes the text file, info.txt, if the character is a letter it calls UpdateTree
void treeClassType::ProcessText(ifstream& fin)
{
  char tempChar;
  while (!fin.eof())
  {
    // read in first character
    fin >> tempChar;

    // if the character is a letter, update the tree with a new count
    if (isalpha(tempChar))
    {
      tempChar = tolower(tempChar);
      UpdateTree(tempChar, root);
    }
  }
}

// Searches the alpha tree, updates the count of the tree
void treeClassType::UpdateTree(char aLetter, nodePtr currentPtr)
{
  // if the current pointer isn't null
  if (currentPtr == nullptr)
  {
    return;
  }

  UpdateTree(aLetter, currentPtr->left);
  if (currentPtr->data.aLetter == aLetter)
  {
    currentPtr->data.letterCount++;
    return;
  }
  UpdateTree(aLetter, currentPtr->right);

}

// BuildCountTree - Builds the count tree via a copy of the alpha tree
void treeClassType::BuildCountTree(nodePtr parentPtr)
{
  isAlpha = false;

  if (parentPtr == nullptr)
  {
    return;
  }

  this->BuildCountTree(parentPtr->left);
  this->Insert(CreateNode(parentPtr->data.aLetter, parentPtr->data.letterCount));
  this->BuildCountTree(parentPtr->right);
}

// InOrder - Given the binary tree, print its nodes in order 
void treeClassType::InOrder(ofstream& fout, nodePtr currentPtr)
{
  if (currentPtr == nullptr)
  {
    return;
  }

  InOrder(fout, currentPtr->left);

  std::cout << setw(14) << currentPtr->data.aLetter << right << setw(15) << currentPtr->data.letterCount << endl;
  fout << setw(14) << currentPtr->data.aLetter << right << setw(15) << currentPtr->data.letterCount << endl;

  InOrder(fout, currentPtr->right);
}

// PreOrder - Given the binary tree, print its nodes in pre order 
void treeClassType::PreOrder(ofstream& fout, nodePtr currentPtr)
{
  if (currentPtr == nullptr)
  {
    return;
  }

  std::cout << setw(14) << currentPtr->data.aLetter << right << setw(15) << currentPtr->data.letterCount << endl;
  fout << setw(14) << currentPtr->data.aLetter << right << setw(15) << currentPtr->data.letterCount << endl;

  PreOrder(fout, currentPtr->left);
  PreOrder(fout, currentPtr->right);
}

// PostOrder - Given the binary tree, print its nodes in post order 
void treeClassType::PostOrder(ofstream& fout, nodePtr currentPtr)
{
  if (currentPtr == nullptr)
  {
    return;
  }

  PostOrder(fout, currentPtr->left);
  PostOrder(fout, currentPtr->right);

  std::cout << setw(14) << currentPtr->data.aLetter << right << setw(15) << currentPtr->data.letterCount << endl;
  fout << setw(14) << currentPtr->data.aLetter << right << setw(15) << currentPtr->data.letterCount << endl;
}

// FindLargestCount - Searches the tree for the for largest count
int treeClassType::FindLargestCount()
{
  nodePtr current = root;
  int maxValue = current->data.letterCount;;

  while (current->right != nullptr)
  {
    current = current->right;
    maxValue = current->data.letterCount;
  }
  return maxValue;
}

// SumCounts - Sums all the counts within the tree
int treeClassType::SumCounts(nodePtr currentPtr)
{
  if (currentPtr == nullptr)
  {
    return 0;
  }
  else
  {
      return (currentPtr->data.letterCount + SumCounts(currentPtr->left) + SumCounts(currentPtr->right));
  }
}

// SearchTree - Searches the tree for a specific node
void treeClassType::SearchTree(nodeStructType searchNode, bool& found, nodePtr& currentPtr, nodePtr& parentPtr)
{
  if (isAlpha)
  {
    while (currentPtr != nullptr && found != true)
    {
      if (searchNode.aLetter > currentPtr->data.aLetter)
      {
        parentPtr = currentPtr;
        currentPtr = currentPtr->right;
      }
      else if (searchNode.aLetter < currentPtr->data.aLetter)
      {
        parentPtr = currentPtr;
        currentPtr = currentPtr->left;
      }
      else
      {
        parentPtr = parentPtr;
        currentPtr = currentPtr;
        found = true;
        return;
      }
    }
  }
  else
  {
    while (currentPtr != nullptr && found != true)
    {
      if (searchNode.letterCount > currentPtr->data.letterCount)
      {
        parentPtr = currentPtr;
        currentPtr = currentPtr->right;
      }
      else if (searchNode.letterCount < currentPtr->data.letterCount)
      {
        parentPtr = currentPtr;
        currentPtr = currentPtr->left;
      }
      else
      {
        parentPtr = parentPtr;
        currentPtr = currentPtr;
        found = true;
        return;
      }
    }
  }
  found = false;
}

// DeleteNode - Search's the tree, if found, deletes the searched for node
void treeClassType::DeleteNode(nodeStructType searchNode, bool& found)
{
  nodePtr currentPtr = root;
  nodePtr parentPtr = nullptr;

  SearchTree(searchNode, found, currentPtr, parentPtr);

  if (found == true)
  {
    Delete(currentPtr, parentPtr);
  }
}

// DestroyTree - While the tree isn't empty, delete the nodes
void treeClassType::DestroyTree()
{
  bool tempBool;
  if (root == nullptr)
  {
    return;
  }
  while (root != nullptr)
  {
    tempBool = false;

    std::cout << "Destroy #" << ++this->deleteNodeCount << endl;
    std::cout << "Deleted Node - Letter: " << root->data.aLetter << " Count: " << root->data.letterCount << endl;
    DeleteNode(root->data, tempBool);
  }
}

// Delete - Based on the current node passed in, call either, DeleteLeafNode, DeleteNodeWithLeftChild, 
// DeleteNodeWithRightChild, DeleteNodeWithTwoChildren
void treeClassType::Delete(nodePtr& currentPtr, nodePtr& parentPtr)
{
  if (currentPtr->left != nullptr && currentPtr->right != nullptr)
  {
    DeleteNodeWithTwoChildren(currentPtr, parentPtr);
  }
  else if (currentPtr->left != nullptr && currentPtr->right == nullptr)
  {
    DeleteNodeLeftChildOnly(currentPtr, parentPtr);
  }
  else  if (currentPtr->left == nullptr && currentPtr->right != nullptr)
  {
    DeleteNodeRightChildOnly(currentPtr, parentPtr);
  }
  else
  {
    DeleteLeafNode(currentPtr, parentPtr);
  }
}

// DeleteLeafNode - Deletes only a leaf
void treeClassType::DeleteLeafNode(nodePtr& currentPtr, nodePtr& parentPtr)
{
  // vi.1 if parent is not null then determine which of left or right is pointing to current
  if (parentPtr != nullptr)
  {
    if (parentPtr->right == currentPtr)
    {
      parentPtr->right = nullptr;
    }
    else if (parentPtr->left == currentPtr)
    {
      parentPtr->left = nullptr;
    }
  }
  else // vi.2. - if its the root, set root to null
  {
    root = nullptr;
  }
  // deallocate the memory
  delete currentPtr;
  currentPtr = nullptr;
}

// DeleteNodeLeftChildOnly - Deletes nodes with a left child only
void treeClassType::DeleteNodeLeftChildOnly(nodePtr& currentPtr, nodePtr& parentPtr)
{
  if (parentPtr != nullptr) // parent not null, current is not root
  {
    if (parentPtr->left == currentPtr)
    {
      parentPtr->left = currentPtr->left;
    }
    else
    {
      parentPtr->right = currentPtr->left;
    }
  }
  else
  {
    root = root->left;
  }
  // deallocate the memory
  delete currentPtr;
  currentPtr = nullptr;
}

// DeleteNodeRightChildOnly - Deletes nodes with a right child only
void treeClassType::DeleteNodeRightChildOnly(nodePtr& currentPtr, nodePtr& parentPtr)
{
  if (parentPtr != nullptr)
  {
    if (parentPtr->left == currentPtr)
    {
      parentPtr->left = currentPtr->right;
    }
    else
    {
      parentPtr->right = currentPtr->right;
    }
  }
  else
  {
    root = root->right;
  }
  // deallocate the memory
  delete currentPtr;
  currentPtr = nullptr;
}

// DeleteNodeWithTwoChildren - Deletes nodes with both left and right children
void treeClassType::DeleteNodeWithTwoChildren(nodePtr& currentPtr, nodePtr& parentPtr)
{
  nodePtr ptr;

  // use parentPtr to track parent of next node
  parentPtr = currentPtr;

  // find largest value before currentPtr value (successor)
  ptr = currentPtr->left;
  while (ptr->right != nullptr)
  {
    parentPtr = ptr;
    ptr = ptr->right;
  }

  // ix.4 if parent never changed, left was max value
  // then set parent's left to ptrs left
  if (parentPtr == currentPtr)
  {
    parentPtr->left = ptr->left;
  }
  // ix.5. else found max on right, set parents right child to ptr left child
  else
  {
    parentPtr->right = ptr->left;
  }
  // ix.6. swap data only, not left/right pointers (current and ptr)
  swap(currentPtr->data, ptr->data);
  // ix.7. set ptr left child to null
  ptr->left = nullptr;
  // ix.8. delete ptr
  delete ptr;
  ptr = nullptr;
}

// Print - Outputs a column
void treeClassType::Print(ofstream& fout, string traversalType, string treeType, string taskType)
{
  PrintDivider(fout, '-', SCREEN_WIDTH);
  std::cout << "This is the " << treeType << endl;
  std::cout << traversalType << " traversal of the Tree" << endl;
  std::cout << "Task Preformed: " << taskType << endl;
  std::cout << setw(14) << "Letter" << setw(15) << "Count" << endl;
  fout << "This is the " << treeType << endl;
  fout << traversalType << " traversal of the Tree" << endl;
  fout << "Task Preformed: " << taskType << endl;
  fout << setw(14) << "Letter" << setw(15) << "Count" << endl;
  PrintDivider(fout, '-', SCREEN_WIDTH);

  int sumOfCounts = SumCounts(root);

  if (traversalType == "InOrder")
  {
    InOrder(fout, root);
  }
  else if (traversalType == "PreOrder")
  {
    PreOrder(fout, root);
  }
  else if (traversalType == "PostOrder")
  {
    PostOrder(fout, root);
  }
  PrintDivider(fout, '-', SCREEN_WIDTH);
  std::cout << "Sum of Counts" << setw(16) << sumOfCounts << endl;
  fout << "Sum of Counts" << setw(16) << sumOfCounts << endl;
  PrintDivider(fout, '-', SCREEN_WIDTH);
}

treeClassType::~treeClassType()
{
  DestroyTree();
}