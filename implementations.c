//implementations.c
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"implementations_headers.h"
_Bool leaf_node_exists(stemNode *ROOT, char *name)
{
    stemNode *stem_iter = ROOT;
    leafNode *leaf_iter = NULL;
    int i = 0;
    while(stem_iter != NULL && stem_iter->index != (char)name[0])
        stem_iter = stem_iter->next;
    
    if(stem_iter != NULL)   //if stem node exists
    {
        leaf_iter = stem_iter->first;
        while(leaf_iter != NULL) 
        {
            if( strcmp(leaf_iter->name, name) == 0)     //leaf node exists
                return true;
            leaf_iter = leaf_iter->next;
        }
    }
    return false;               //returns 0 if stem node does not exist
}

stemNode* return_stem_dest(stemNode **ROOT, char *name)
{
        stemNode *stem_iter = *ROOT;
        //iterates to find the stem node with the index we are looking for
        while(stem_iter != NULL && stem_iter->index != name[0])
        {
         stem_iter = stem_iter->next;
        }
        
        if(stem_iter != NULL)           //this block is executed if index we are seaching for exists
        {
            return stem_iter;
        }    
        else                            //if the index does not exist, this block is executed
        {
            //new stem node is created with the index to be added
            stemNode *new_stem_node = malloc(sizeof(stemNode));
            new_stem_node->index = name[0];
            new_stem_node->first = NULL;
            new_stem_node->next = NULL;
            
            if(*ROOT == NULL)               //this block will be executed when this is the first element being stored
            {
                *ROOT = new_stem_node;
                return *ROOT;
            }
            else                            //this block will be executed when there is atleast one element
            {
                int cmp_res = (name[0] - (*ROOT)->index);
                if(cmp_res < 0)             //this block is executed when the new element is being added in the first position
                {
                    new_stem_node->next = *ROOT;
                    *ROOT = new_stem_node;
                    return *ROOT;
                }
                else                       //this block is executed when the new element is being added at not-first position
                {
                    stem_iter = *ROOT;
                    while(stem_iter->next != NULL && (new_stem_node->index - stem_iter->next->index) > 0)
                        stem_iter = stem_iter->next;

                    if(stem_iter->next == NULL) //if new_stem_node is added as the last node in stem
                    {
                        stem_iter->next = new_stem_node;
                    }
                    else                        //if the new stem_node is being added in between two nodes
                    {
                        new_stem_node->next = stem_iter->next;
                        stem_iter->next = new_stem_node;
                    }
                    return new_stem_node;
                }
            }
        }
}
_Bool queue_is_empty(qNode *TAIL)
{
    if(TAIL == NULL)
        return true;
    return false;
}
void slice_str(const char * str, char * buffer, size_t start, size_t end)
{
    //this program slices a string from strat index to end index
    size_t j = 0;
    for ( size_t i = start; i < end; i++ ) {
        buffer[j++] = str[i];
    }
    buffer[j] = 0;
}
void remove_stem_node(stemNode **ROOT, stemNode *stem_dest)
{
    if(*ROOT == stem_dest)      //if the stem node to be deleted is the root
    {
        *ROOT = stem_dest->next;
        free(stem_dest);
    }
    else        //if the stem node to be deleted is any other stem node
    {
        stemNode *stem_iter = *ROOT;
        while(stem_iter->next != stem_dest)
            stem_iter = stem_iter->next;
        //linking node behind stem_dest to node after stem_dest and freeing stem_node
        stem_iter->next = stem_dest->next;
        free(stem_dest);
    }
}
void enqueue(stemNode **ROOT, qNode **TAIL, char *name)
{
    qNode *new_q_node = (qNode *)malloc(sizeof(qNode));
    
    stemNode *stem_dest = return_stem_dest(ROOT, name);
    leafNode *leaf_iter = stem_dest->first;
    while(strcmp(leaf_iter->name, name) != 0)
        leaf_iter = leaf_iter->next;
    
    new_q_node->leaf_ptr = leaf_iter;
    if(*TAIL == NULL)           //First call is made
    {
        *TAIL = new_q_node;
        new_q_node->next = NULL;
    }
    else                        //nth call is made
    {
        new_q_node->next = *TAIL;
        *TAIL = new_q_node;
    }
    
}
void view_list(stemNode *ROOT, char* queryString)
{
    stemNode *stem_iter = ROOT;
    leafNode *leaf_iter = NULL;
    int ctr;
    int queryStringLen = strlen(queryString);
    char stringSlice[queryStringLen + 1];

    while(stem_iter != NULL)            //iterating through each stem node
    {
        leaf_iter = stem_iter->first;
        
        ctr = 0;                        //this will increment only if something has been printed
        while(leaf_iter != NULL){                       //iterating through each leaf node
            slice_str(leaf_iter->name, stringSlice, 0, queryStringLen);     
            
            //this block is executed if the name begins with input string
            if( queryString[0] == '*' || strcmp(stringSlice, queryString) == 0 )
            {
                printf("%s\t\t%ld\n", leaf_iter->name, leaf_iter->number);
                ctr++;
            }
            leaf_iter = leaf_iter->next;
        }
        stem_iter = stem_iter->next;
        if( ctr != 0)           //when incrementd, means some data has been displayed, and so will print new line
            printf("\n");
    }
    
}
void add_leaf_node(stemNode *stem_dest, char *name, long int phone_num)
{
    //leaf node is always created
    leafNode *leaf_iter = NULL;
    leafNode *new_leaf_node = (leafNode *)malloc(sizeof(leafNode));
    strcpy(new_leaf_node->name, name);
    new_leaf_node->number = phone_num;
    
    if(stem_dest->first == NULL)     //this block is executed if this is the first leaf node being added
    {
        stem_dest->first = new_leaf_node;
    }
    else                             //if it's not the first leaf node being added
    {
        int cmp_res = strcmp(stem_dest->first->name, new_leaf_node->name); 
        if(cmp_res > 0)                 // leaf_node to be added in first position
        {
            new_leaf_node->next = stem_dest->first;
            stem_dest->first = new_leaf_node;
        }
        else                            //Adding leaf node in between other nodes
        {
            leaf_iter = stem_dest->first;
            while(leaf_iter->next != NULL && strcmp(leaf_iter->next->name, new_leaf_node->name) < 0)
                leaf_iter = leaf_iter->next;
            
            //irespective of null or address of next node, sets it to new_leaf_node
            new_leaf_node->next = leaf_iter->next;
            leaf_iter->next = new_leaf_node;
                
        }
    }
}
void delete_leaf_node(stemNode **stem_dest, char *name)
{   
    printf("bleeh\t%c\n", (*stem_dest)->index);
    printf("%s\n", (*stem_dest)->first->name);
    if(strcmp( (*stem_dest)->first->name, name) == 0 )          //if node to be deleted is the first node
    {
        printf("in here\n");
        leafNode *leaf_temp =  (*stem_dest)->first;
        if(leaf_temp->next == NULL)
            (*stem_dest)->first = NULL;
        else
            (*stem_dest)->first = leaf_temp->next;
        free(leaf_temp);
    }
    else
    {
        printf("over here\n");
        leafNode *leaf_iter = (*stem_dest)->first;
        leafNode *leaf_temp =  NULL;
        while(strcmp(leaf_iter->next->name, name) != 0)
            leaf_iter = leaf_iter->next;
        
        //deleting node
        leaf_temp = leaf_iter->next;
        leaf_iter->next = leaf_temp->next;
        free(leaf_temp);
    }
}
void view_queue(qNode *TAIL)
{
    qNode *q_iter = TAIL;
    while(q_iter != NULL)
    {
        printf("%s\t%ld\n", q_iter->leaf_ptr->name, q_iter->leaf_ptr->number);
        q_iter = q_iter->next;
    }
}
void destroy_queue(qNode **TAIL)
{
    qNode *q_iter = *TAIL;
    *TAIL = NULL;
    qNode *q_temp = NULL;
    while(q_iter != NULL)
    {
        q_temp = q_iter;
        q_iter = q_iter->next;
        free(q_temp);
    }
}
