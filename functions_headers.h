// functions_headers.h
// contains all the function protoypes of abstracctions of one layer below

typedef struct leaf_node
{
    struct leaf_node *next;
    char name[30];
    long int number;
}leafNode;
typedef struct stem_node
{
    struct stem_node *next;
    struct leaf_node *first;
    char index;
}stemNode;

//queue
typedef struct queue_node
{
    struct leaf_node *leaf_ptr;
    struct queue_node *next;
}qNode;


//assisting functions(implementations.c)
_Bool leaf_node_exists(stemNode *ROOT, char *name);
stemNode* return_stem_dest(stemNode **ROOT, char *name); //If stemNode present-returns dest, else-creates stemNode and returns
_Bool queue_is_empty(qNode *TAIL);
void slice_str(const char * str, char * buffer, size_t start, size_t end);
void remove_stem_node(stemNode **ROOT, stemNode *stem_dest);

//implementations.c
void enqueue(stemNode **ROOT, qNode **TAIL, char *name);
void view_list(stemNode *ROOT, char *queryString);
void add_leaf_node(stemNode *stem_dest, char *name, long int phone_num);
void delete_leaf_node(stemNode **stem_dest, char *name);
void view_queue(qNode *TAIL);
void destroy_queue(qNode **TAIL);
