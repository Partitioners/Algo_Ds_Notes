
/************************************************************************************************************************************
=====================================================================================================================================

                  ╔═════════════════════════════════════════════════════════╗
                  ║      Name                :    Aditya Dhan Raj Singh     ║
                  ╚═════════════════════════════════════════════════════════╝

HOW TO RUN:
    Copy paste the entire code to a compiler or save as a *.cpp file
    for linux systems use g++ *fine.cpp* -o *output file name*

AIM:
    This program generates a priority queue

MAP OF FUNCTIONS:
      art();                               // just some fun art 
      push(queue, data, priority)          // function to push data in the queue
      pop(queue)                           // function to remove th head of the queue
      print_function(queue)                // function to print the stored data 
      main()                               // main function 

NOTE: 
    Best viewed in a terminal size of minimum 113x28
=====================================================================================================================================
************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//colour  scheem
#define RED       "\033[01;31m" 
#define RED_BL    "\033[06;31m"
#define GREEN     "\033[01;32m" 
#define YELLOW    "\033[01;33m" 
#define BLUE      "\033[01;34m" 
#define BOLD      "\033[01;01m" 
#define RESET     "\033[00m"   
#define PURPLE    "\033[1;95m"
#define CYAN      "\033[0;96m"
#define ONBLACK   "\033[40m"
#define UGREEN    "\033[4;29m"
#define ITALIC    "\033[03;29m"


//who hates some art!
void art()
{
    printf(GREEN "\n\t██████╗ ██████╗ ██╗ ██████╗ ██████╗ ██╗████████╗██╗   ██╗     ██████╗ ██╗   ██╗███████╗██╗   ██╗███████╗\n\t██╔══██╗██╔══██╗██║██╔═══██╗██╔══██╗██║╚══██╔══╝╚██╗ ██╔╝    ██╔═══██╗██║   ██║██╔════╝██║   ██║██╔════╝\n\t██████╔╝██████╔╝██║██║   ██║██████╔╝██║   ██║    ╚████╔╝     ██║   ██║██║   ██║█████╗  ██║   ██║█████╗  \n\t██╔═══╝ ██╔══██╗██║██║   ██║██╔══██╗██║   ██║     ╚██╔╝      ██║▄▄ ██║██║   ██║██╔══╝  ██║   ██║██╔══╝  \n\t██║     ██║  ██║██║╚██████╔╝██║  ██║██║   ██║      ██║       ╚██████╔╝╚██████╔╝███████╗╚██████╔╝███████╗\n\t╚═╝     ╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝   ╚═╝      ╚═╝        ╚══▀▀═╝  ╚═════╝ ╚══════╝ ╚═════╝ ╚══════╝\n" RESET);
}

// Initialize a linked list Node using struct
struct Node{
  int data;
  int priority;
  struct Node * next;
};

//pop function to delete the head of the queue
void pop(struct Node *& node){
    if(node==NULL){
        cout << RED "Queue is EMPTY" RESET << endl;
        return;
    }
    else{
        struct Node * temp = node;
        node = temp->next;
        cout << RED "\nPopped value -> " RESET << temp->data << endl << endl;
        free(temp);
        return;
    }
}

//push function to add data to the queue
void push(struct Node *& node, int input_data , int priority_value){
    struct Node * que = (struct Node*)malloc(sizeof(Node));
    que->data=input_data;
    que->priority = priority_value;
    if(node==NULL){
        node = que;
        return;
    }
    else if (node->next==NULL){
        struct Node *temp = node;
        if (priority_value>(temp->priority)){
            temp->next=que;
            que->next=NULL;
        }
        else{
            que->next=temp;
            temp=que;
        }
    }
    else{
        struct Node*temp = node;
        while((temp->next!=NULL) && (priority_value>=(temp->next->priority))){
            temp = temp->next;
        }
        que->next = temp->next;
        temp->next = que;
    }
}

//print functtion to print the data stored in the queue
void print_function(struct Node*node){
    struct Node * temp = node;
    if(node == NULL){
        cout << endl << RED "Queue is EMPTY" RESET << endl;
    }
    else{   
    while(temp->next!=NULL){
        cout << YELLOW "data in queue " RESET << (temp->data) << "   " << CYAN "priority " RESET << (temp->priority) << endl;
        temp = temp->next;
    }
    cout<< YELLOW "data in queue " RESET << (temp->data) << "   " << CYAN "priority " RESET << (temp->priority) << endl;
    }
}



int main()
{
  ONBLACK; //makes the background black
  art();
  struct Node* CSN102 = NULL; //initialization
  int a; //variable that takes the value from the user. This is the number of times the loop will run to take the input from user
  printf(YELLOW "Please the number of elements in the list: " RESET);
  scanf("%d", &a);

  printf(PURPLE "You entered: %d\n" RESET, a );

  int Y;
  int Z;
  for (int i = 0; i < a; ++i)
  {
    printf(BLUE "Please the value: " RESET);
    scanf("%d", &Y);
    printf(BLUE "Please the priority: " RESET);
    scanf("%d", &Z);

    push(CSN102, Y, Z);
  }
  

  pop(CSN102); // call to the pop function
  print_function(CSN102); //print all the data

  printf( "\n\nLatest version at:" ITALIC" \n\thttps://github.com/adityadrs/Data-Structures-CSN/tree/master/Priority-queue\n" RESET);

}