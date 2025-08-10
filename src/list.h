#ifndef LIST_H
#define LIST_H
<<<<<<< HEAD

typedef struct node{
    void *val;
    struct node *next;
    struct node *prev;
} node;

typedef struct list{
    int size;
    node *front;
    node *back;
} list;

#ifdef __cplusplus
extern "C" {
#endif
=======
#include "darknet.h"

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
list *make_list();
int list_find(list *l, void *val);

void list_insert(list *, void *);

<<<<<<< HEAD
void **list_to_array(list *l);

void free_list_val(list *l);
void free_list(list *l);
void free_list_contents(list *l);
void free_list_contents_kvp(list *l);

#ifdef __cplusplus
}
#endif
=======

void free_list_contents(list *l);

>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
#endif
