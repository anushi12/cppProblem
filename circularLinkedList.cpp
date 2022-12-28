#include <iostream>
using namespace std;

// Class for a node in a circular linked list
class node {
 public:
  // Data stored in the node
  int data;
  // Pointer to the next node in the list
  node* next;

  // Constructor for a node, sets the data and initializes the next pointer to NULL
  node(int d) {
    this->data = d;
    this->next = NULL;
  }

  // Destructor for a node, frees the memory for the node
  ~node() {
    int value = this->data;
    if (this->next != NULL) {
      // Recursively delete the next node in the list
      delete next;
      next = NULL;
    }
    cout << "memory is free for node with data " << value << endl;
  }
};

// Inserts a new node with the given data after the node with the given element
void insertnode(node*& tail, int element, int d) {
  if (tail == NULL) {
    // If the list is empty, create a new node and set it as the tail
    node* newnode = new node(d);
    tail = newnode;
    newnode->next = newnode;
  } else {
    // Otherwise, search for the node with the given element
    node* curr = tail;
    while (curr->data != element) {
      curr = curr->next;
    }
    // Create a new node and insert it after the found node
    node* temp = new node(d);
    temp->next = curr->next;
    curr->next = temp;
  }
}

// Prints the data of all nodes in the list
void print(node* tail) {
  node* temp = tail;
  do {
    cout << tail->data << " ";
    tail = tail->next;
  } while (tail != temp);
  cout << endl;
}

int main() {
  // Initialize the tail of the list to NULL
  node* tail = NULL;

  // Insert some nodes into the list
  insertnode(tail, 5, 3);
  print(tail);
  insertnode(tail, 3, 5);
  print(tail);
  insertnode(tail, 3, 4);
  print(tail);
  insertnode(tail, 5, 7);
  print(tail);
  insertnode(tail, 7, 9);
  print(tail);
  insertnode(tail, 5, 6);
  print(tail);
}
