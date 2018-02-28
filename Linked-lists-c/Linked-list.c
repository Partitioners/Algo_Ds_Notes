
/************************************************************************************************************************************
=====================================================================================================================================

                  ╔═════════════════════════════════════════════════════════╗
                  ║      Name                :    Aditya Dhan Raj Singh     ║
                  ╚═════════════════════════════════════════════════════════╝

HOW TO RUN:
    Copy paste the entire code to a compiler or save as a *.c file
    for linux systems use gcc *fine.c* -o *output file name*

AIM:
    This program generates a linked list that stores n values.
    Each entered value is appened to the end of the list. Other than append(), push() and insert_after() functions can be used.
    to change the way data is added to the list change the function in the loop that is running in the 
        int main()
        {
            .
            int Y;
            for (int i = 0; i < a; ++i)
            {
              printf("Please the value: ");
              scanf("%d", &Y);
      =====>    append(&CSN102, Y); 
        here in place of append(), push() and insert_after() can be used.
            .
            }
        }

NOTE: The syntax of using the insert_after() function is:
        insert_afte(head->next, value)
    
       MAP OF FUNCTIONS:
            art();                              // just some fun art 
            push(&List, data);                  // to push data in the list
            insert_after(head->next, data);     // to insert after a particular node
            append(&List, value);               // to add data at the end of the list
            reverse(&List);                     // to reverse the list order
            print_list(&List);                  // to print the entire list
            delete_node(&list, value);          // where the actual deletion of data occurs
            delete_node_function(&List);        // seperate function for simplistic formatting and edditing
            main();                             //main funstion

=====================================================================================================================================
************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

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
    printf(GREEN "\n\t██╗     ██╗███╗   ██╗██╗  ██╗███████╗██████╗     ██╗     ██╗███████╗████████╗███████╗\n\t██║     ██║████╗  ██║██║ ██╔╝██╔════╝██╔══██╗    ██║     ██║██╔════╝╚══██╔══╝██╔════╝\n\t██║     ██║██╔██╗ ██║█████╔╝ █████╗  ██║  ██║    ██║     ██║███████╗   ██║   ███████╗\n\t██║     ██║██║╚██╗██║██╔═██╗ ██╔══╝  ██║  ██║    ██║     ██║╚════██║   ██║   ╚════██║\n\t███████╗██║██║ ╚████║██║  ██╗███████╗██████╔╝    ███████╗██║███████║   ██║   ███████║\n\t╚══════╝╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝╚═════╝     ╚══════╝╚═╝╚══════╝   ╚═╝   ╚══════╝\n"RESET);
}

// Initialize a linked list node using struct
struct Node
{
  int data;
  struct Node *next;
};

//The push function adds a new node in the front of the linked list 
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 
//The insert_after function adds a new node in after a perticular node in the linked list
void insert_after(struct Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
 
//the append function adds a new node at the end of the liked list
//(add to the end)
void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;  /* used in step 5*/
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
 
//function to reverse the linked list
void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}


//this is the print function that prints the data stored in the linked list
//colour has been added into this so when ever it is called the output will be YELLOW
void print_list(struct Node *node)
{
  while (node != NULL)
  {
     printf(YELLOW" %d "RESET, node->data);
     node = node->next;
  }
}

//this function is called by the delete_node_function()
//this is the actual place where the node is being deleted
void delete_node(struct Node **head_ref, int key)
{
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp); 
}

//This depends on the delete_node() function
//I have seperated it from the main() for neatness and flexiblity of formatting

void delete_node_function(struct Node *node)
{
    printf(RED"\nEnter the element to delete: "RESET );
    int del;
    scanf("%d", &del);
    printf(UGREEN GREEN"You have entered:"RESET);
    printf(GREEN" %d\n"RESET,del);
    printf(RED"Are you sure? y/n: "RESET);
    char condition_1;
    scanf(" %c", &condition_1);
    if (condition_1 == 'y' || condition_1 == 'Y')
      {
          printf(CYAN"\nYou have chosen"RESET);
          printf(YELLOW ITALIC" Yes"RESET);
          printf(CYAN"\n\nUpdated list is:\n"RESET);
          delete_node(&node, del);
          print_list(node);
      }
    else if (condition_1 == 'n')
      {
          printf("NO");
          printf("You have chosen No\n");
          print_list(node);
      }
    else
      {
        printf("Invalid Input\n");
      }
    

}

int main()
{
    ONBLACK;
    art();
    struct Node* CSN102 = NULL;
    int a;
    printf(YELLOW"Please the number of elements in the list: "RESET);
    scanf("%d", &a);

    printf(PURPLE"You entered: %d\n"RESET, a );

    int Y;
    for (int i = 0; i < a; ++i)
    {
      printf(BLUE"Please the value: "RESET);
      scanf("%d", &Y);
      append(&CSN102, Y);
    }

    printf(CYAN"\nThe current list is: \n"RESET);
    print_list(CSN102);
    printf(CYAN"\nThe reversed list is: \n"RESET);
    reverse(&CSN102);
    print_list(CSN102);
    delete_node_function(CSN102);
    printf("latest version at: \n\thttps://github.com/adityadrs/Data-Structures-CSN/tree/master/Linked-lists\n");


    return 0;
}

