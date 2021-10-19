//--------------------------------------------------------------------------------------------------     
//File Name:        treeClassType.h
//Associated file:  None
//--------------------------------------------------------------------------------------------------
#ifndef treeClassType_h
#define treeClassType_h
#include "outputMethods.h"

// Definition of the structure that deals with the data
struct nodeStructType
{
  char aLetter;
  int letterCount;
};

// Definition of a node with a pointer to set for the next node
struct node
{
  nodeStructType data;
  node* left;
  node* right;
};

typedef node* nodePtr;

class treeClassType
{
public:

  treeClassType();

  void CreateTree();

  bool IsEmpty();

  nodePtr GetRoot();

  nodePtr CreateNode(char aLetter, int letterCount);

  void BuildAlphaTree(ifstream& fin);

  void BuildCountTree(nodePtr parentPtr);

  void ProcessText(ifstream& fin);

  void InOrder(ofstream& fout, nodePtr currentPtr);

  void PreOrder(ofstream& fout, nodePtr currentPtr);

  void PostOrder(ofstream& fout, nodePtr currentPtr);

  void UpdateTree(char aLetter, nodePtr currentPtr);

  int FindLargestCount();

  int SumCounts(nodePtr currentPtr);

  void SearchTree(nodeStructType searchNode, bool& found, nodePtr& currentPtr, nodePtr& parentPtr);

  void DeleteNode(nodeStructType searchNode, bool& found);

  void DestroyTree();

  void Print(ofstream& fout, string traversalType, string treeType, string taskType);

  friend void PrintDivider(ofstream& fout, char symbol, int amount);

  ~treeClassType();
private:

  nodePtr root;
  bool isAlpha;
  int deleteNodeCount;

  // Methods
  void Insert(nodePtr newNode);
  void DeleteLeafNode(nodePtr& currentPtr, nodePtr& parentPtr);
  void DeleteNodeLeftChildOnly(nodePtr& currentPtr, nodePtr& parentPtr);
  void DeleteNodeRightChildOnly(nodePtr& currentPtr, nodePtr& parentPtr);
  void DeleteNodeWithTwoChildren(nodePtr& currentPtr, nodePtr& parentPtr);
  void Delete(nodePtr& currentPtr, nodePtr& parentPtr);
};
#endif