// prompts_headers.h
// header file for prompts.c
// (Contains all the prototypes for abstractions of one layer below)

//passes user inputs and hidden arguments to back-end functions (functions.c)
_Bool make_call(char *name);   //returns false if contact not found
_Bool view_contacts(char *queryString);         //returns false if list is empty
void add_contact(char *name, long int phone_num);
_Bool delete_contact(char *name); //returns false if contact not found
void view_call_logs();
void destroy_call_logs(); 
_Bool call_logs_is_empty();
