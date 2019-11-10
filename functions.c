//functions.c
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"functions_headers.h"

//pointers to data structres are initialised
stemNode *ROOT = NULL;
qNode *TAIL = NULL;

//Back-end functions are called by providing the neccessary hidden arguments-the data structure pointers
_Bool make_call(char *name)
{
    if( !leaf_node_exists(ROOT, name) )
        return false;
    else
    {
        enqueue(&ROOT, &TAIL, name);
        return true;
    }
}
_Bool view_contacts(char* queryString)
{
    if(ROOT == NULL)
        return false;
    view_list(ROOT, queryString);
    return true;
}
void add_contact(char *name, long int phone_num)
{
    //Traversing through the stem
    stemNode *stem_dest = return_stem_dest(&ROOT, name);

    //Traversing and inserting node among the leaves
    add_leaf_node(stem_dest, name, phone_num);
}
_Bool delete_contact(char *name)        //returns 0 if does not exist, 1 if it exists, 2 if it exists and is the last leaf for stem
{
    stemNode *stem_dest;
    _Bool exists = leaf_node_exists(ROOT, name);
    if(exists)
    {
        stem_dest = return_stem_dest(&ROOT, name);
        delete_leaf_node(&stem_dest, name);
        if(stem_dest->first == NULL)
            remove_stem_node(&ROOT, stem_dest);
        return true;
    }
    return false;       //when leaf node does not exist                  
}
void view_call_logs()
{
    view_queue(TAIL);
}
_Bool call_logs_is_empty()
{
    return queue_is_empty(TAIL);
}
void destroy_call_logs()
{
    destroy_queue(&TAIL);
}
