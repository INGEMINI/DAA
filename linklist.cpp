#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node *next;
  node(int value)
  {
    data = value;
    next = nullptr;
  }
};

class linklist
{
private:
  node *head;

public:
  linklist()
  {
    head = nullptr;
  }

  void insertatbegin(int val)
  {
    node *newnode = new node(val);
    newnode->next = head;
    head = newnode;
  }

  void insertatend(int val)
  {
    node *newnode = new node(val);
    if (!head)
    {
      head = newnode;
      return;
    }

    node *temp = head;
    while (temp->next)
    {
      temp = temp->next;
    }
    temp->next = newnode;
  }

  void deletenode(int val)
  {
    if (!head)
    {
      return;
    }

    if (head->data == val)
    {
      node *temp = head;
      head = head->next;
      delete temp;
      return;
    }
    node *temp = head;
    while (temp->next && temp->next->data != val)
    {
      temp = temp->next;
    }

    if (temp->next)
    {
      node *todel = temp->next;
      temp->next = temp->next->next;
      delete todel;
    }
  }

  bool search(int val)
  {
    // temp; → Condition: The loop continues as long as temp is not nullptr (i.e., we haven't reached the end of the list).
    for (node *temp = head; temp; temp = temp->next)
    {
      if (temp->data == val)
      {
        return true;
      }
    }
    return false;
  }

  void display()
  {
    for (node *temp = head; temp; temp = temp->next)
    {
      cout << temp->data << " -> ";
    }

    cout << "NULL" << endl;
  }
};

int main()
{

  linklist l;
  int ch, val;

  do
  {
    cout << "\n lisked list operations:" << endl
         << "1.insert at beginning" << endl
         << "2. insert at end" << endl
         << "3.delete a node" << endl
         << "4. search for value " << endl
         << "5.display list " << endl
         << "6. exit " << endl
         << "enter yr choice";
    cin >> ch;
    string ss;

    switch (ch)
    {

    case 1:
      cout << "enter value";
      cin >> val;
      l.insertatbegin(val);
      break;

    case 2:
      cout << "enter value";
      cin >> val;
      l.insertatend(val);
      break;

    case 3:
      cout << "enter value";
      cin >> val;
      l.deletenode(val);
      break;

    case 4:
      cout << "enter value";
      cin >> val;

      ss = (l.search(val) ? "found " : "not found");

      cout << ss;
      break;

    case 5:
      l.display();
      break;

    case 6:
      cout << "exit done ";
      break;

    default:
      cout << "invalid choice ..try again dear";
      break;
    }
  } while (ch != 6);
  return 0;
}