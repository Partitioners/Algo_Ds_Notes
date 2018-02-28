# Data Structures

## HOW TO RUN:

  Copy paste the entire code to a compiler or save as a *.c file
  for linux systems use gcc *fine.c* -o *output file name*

## AIM:
This program generates a linked list that stores n values.
Each entered value is appened to the end of the list. Other than append(), push() and insert_after() functions can be used.
to change the way data is added to the list change the function in the loop that is running in the 
```C
        int main()
```

```C
        {
            .
            int Y;
            for (int i = 0; i < a; ++i)
            {
              .
              .
              printf("Please the value: ");
              scanf("%d", &Y);
              append(&CSN102, Y); //here in place of append(), push() and insert_after() can be used.
              .
              .
            }
        }
```
## NOTE: 
  The syntax of using the ``` insert_after()  ``` function is:
 ``` insert_afte(head->next, value)```
    
## MAP OF FUNCTIONS:
```C
  art();                              // just some fun art 
  push(&List, data);                  // to push data in the list
  insert_after(head->next, data);     // to insert after a particular node
  append(&List, value);               // to add data at the end of the list
  reverse(&List);                     // to reverse the list order
  print_list(&List);                  // to print the entire list
  delete_node(&list, value);          // where the actual deletion of data occurs
  delete_node_function(&List);        // seperate function for simplistic formatting and edditing
  main();  
  ```
