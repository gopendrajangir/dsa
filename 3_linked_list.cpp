// Q3. Create a linked list and perform all the related operations?

#include <iostream>

using namespace std;

class Node
{

public:
  int data;
  Node *next = NULL;

  Node(int data)
  {
    this->data = data;
  }
};

class NodeList
{
  Node *head = NULL;
  int size = 0;

public:
  Node *insertAtStart(int num)
  {
    Node *newNode = new Node(num);

    if (head == NULL)
    {
      head = newNode;
      size++;
      return newNode;
    }

    newNode->next = head;
    head = newNode;

    size++;
    return newNode;
  }

  Node *insertAtEnd(int num)
  {
    if (head == NULL)
    {
      return insertAtStart(num);
    }

    Node *temp = head;
    Node *newNode = new Node(num);

    while (temp->next != NULL)
    {
      temp = temp->next;
    }

    temp->next = newNode;

    size++;
    return newNode;
  }

  Node *insertAtPosition(int num, int pos = -1)
  {

    if (pos < 0 || pos > size)
      throw "Invalid position";

    if (pos == 0)
      return insertAtStart(num);

    if (pos == size)
      return insertAtEnd(num);

    if (head == NULL)
      throw "Position is out of bound";

    int currentPos = 1;
    Node *temp = head;

    Node *newNode = new Node(num);

    while (currentPos < pos)
    {
      temp = temp->next;
      currentPos++;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    size++;
    return newNode;
  }

  void deleteAtStart()
  {
    if (head == NULL)
      throw "No node exist in the list";

    Node *temp = head;

    head = temp->next;
    size--;
    delete temp;
  }

  void deleteAtEnd()
  {
    if (head == NULL)
      throw "No node exist in the list";

    if (head->next == NULL)
    {
      size--;
      delete head;
      head = NULL;
      return;
    }

    Node *temp = head;
    Node *tempLast = NULL;

    while (temp->next != NULL)
    {
      tempLast = temp;
      temp = temp->next;
    }

    size--;
    delete temp->next;
    tempLast->next = NULL;
  }

  void deleteAtPosition(int pos)
  {
    if (pos < 0 || pos > size - 1)
    {
      throw "Position out of bound";
    }
    if (pos == 0)
    {
      return deleteAtStart();
    }
    if (pos == size - 1)
    {
      return deleteAtEnd();
    }

    int currentPos = 0;
    Node *temp = head;
    Node *tempLast = head;

    while (currentPos < pos)
    {
      tempLast = temp;
      temp = temp->next;
      currentPos++;
    }

    tempLast->next = temp->next;
    size--;
    delete temp;
  }

  Node *search(int num)
  {
    Node *temp = head;

    while (temp != NULL)
    {
      if (temp->data == num)
      {
        return temp;
      }
      temp = temp->next;
    }

    return NULL;
  }

  void traverse()
  {
    Node *temp = head;

    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main()
{
  NodeList *list = new NodeList();

  try
  {
    list->insertAtEnd(5);
    list->insertAtEnd(6);
    list->insertAtEnd(7);
    list->insertAtStart(4);
    list->insertAtPosition(10, 2);

    int n = 10;

    Node *searchNode = list->search(n);

    if (searchNode == NULL)
    {
      cout << n << " is not found in list" << endl;
    }
    else
    {
      cout << n << " is found" << endl;
    }

    list->traverse();

    list->deleteAtStart();
    list->deleteAtEnd();
    list->deleteAtPosition(1);

    list->traverse();
  }
  catch (const char *s)
  {
    cout << s << endl;
  }

  return 0;
}