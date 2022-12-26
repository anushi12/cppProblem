#include<iostream>
#include<string.h>

// Include the string library to use the strcpy function

using namespace std;

int main(){
  // Initialize variables
  int choice, top = -1;
  int i;
  char box[5][10];
  char book_num[10];
  
  // Run the program in a loop
  do{
    cout<<"\nchoose the option between 1-4: \n1. insert the book.\n2. remove the book.\n3. Display the books.\n4. exit.\n"<<endl;
    cin>>choice;
  
  // Use a switch statement to handle different user choices
  switch(choice)
  {
  
    case 1: 
      // If the stack is full, display an error message
      if(top>4)
        cout<<"the box is full.\n";
      // Otherwise, insert a book by asking the user for a book number and adding it to the stack
      else {
        cout<<"enter the book num: \n";
        cin>>book_num;
        top = top+1;
        strcpy(box[top],book_num);
      }  
        
    break;
    case 2:
      // If the stack is empty, display an error message
      if(top==-1)
        cout<<"the box is empty.\n";
      // Otherwise, remove the book at the top of the stack and display a message
      else {
        cout<<"enter the book num: \n";
        cin>>book_num; 
        cout<<"the book is deleted from: "<<box[top];
        top--;
      }
      break;

    case 3:
      // If the stack is empty, display an error message
      if(top==-1)
        cout<<"the box is empty.\n";
      // Otherwise, display the books in the stack
      else
      {
        cout<<"\nthe books in the box are:";
        for(i=top;i>=0;i--){
          cout<<box[i]<<" ";
        }
      }
      break;      
      
    case 4: 
      // Exit the program
      return 0;

    default:
      // If the user enters an invalid choice, display an error message
      cout<<"INVALID NUMBER.\n"; 
  }
  }while(true);
  
  return 0;
}
