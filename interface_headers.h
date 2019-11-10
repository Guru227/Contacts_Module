// interface_headers.h
// Has the set of header files for interface.c 
// (that level of abstraction and one level below)

//menu functions (interface.c)
void top_level_menu();
void contact_menu();
void call_logs_menu();

//prompt for user input and passes them as args (prompts.c)
void make_call_prompt();
void view_contacts_prompt();
void add_contact_prompt();
void delete_contact_prompt();
void destroy_call_logs_prompt();
void view_call_logs_prompt();
