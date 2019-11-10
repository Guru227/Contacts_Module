// implementations_headers.h
// contains struct definitions

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
