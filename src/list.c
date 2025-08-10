#include <stdlib.h>
#include <string.h>
#include "list.h"
<<<<<<< HEAD
#include "utils.h"
#include "option_list.h"

list *make_list()
{
    list* l = (list*)xmalloc(sizeof(list));
    l->size = 0;
    l->front = 0;
    l->back = 0;
    return l;
=======

list *make_list()
{
	list *l = malloc(sizeof(list));
	l->size = 0;
	l->front = 0;
	l->back = 0;
	return l;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
}

/*
void transfer_node(list *s, list *d, node *n)
{
    node *prev, *next;
    prev = n->prev;
    next = n->next;
    if(prev) prev->next = next;
    if(next) next->prev = prev;
    --s->size;
    if(s->front == n) s->front = next;
    if(s->back == n) s->back = prev;
}
*/

void *list_pop(list *l){
    if(!l->back) return 0;
    node *b = l->back;
    void *val = b->val;
    l->back = b->prev;
    if(l->back) l->back->next = 0;
    free(b);
    --l->size;
<<<<<<< HEAD

=======
    
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    return val;
}

void list_insert(list *l, void *val)
{
<<<<<<< HEAD
    node* newnode = (node*)xmalloc(sizeof(node));
    newnode->val = val;
    newnode->next = 0;

    if(!l->back){
        l->front = newnode;
        newnode->prev = 0;
    }else{
        l->back->next = newnode;
        newnode->prev = l->back;
    }
    l->back = newnode;
    ++l->size;
=======
	node *new = malloc(sizeof(node));
	new->val = val;
	new->next = 0;

	if(!l->back){
		l->front = new;
		new->prev = 0;
	}else{
		l->back->next = new;
		new->prev = l->back;
	}
	l->back = new;
	++l->size;
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
}

void free_node(node *n)
{
<<<<<<< HEAD
    node *next;
    while(n) {
        next = n->next;
        free(n);
        n = next;
    }
}

void free_list_val(list *l)
{
    node *n = l->front;
    node *next;
    while (n) {
        next = n->next;
        free(n->val);
        n = next;
    }
=======
	node *next;
	while(n) {
		next = n->next;
		free(n);
		n = next;
	}
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
}

void free_list(list *l)
{
<<<<<<< HEAD
    free_node(l->front);
    free(l);
=======
	free_node(l->front);
	free(l);
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
}

void free_list_contents(list *l)
{
<<<<<<< HEAD
    node *n = l->front;
    while(n){
        free(n->val);
        n = n->next;
    }
}

void free_list_contents_kvp(list *l)
{
    node *n = l->front;
    while (n) {
        kvp* p = (kvp*)n->val;
        free(p->key);
        free(n->val);
        n = n->next;
    }
=======
	node *n = l->front;
	while(n){
		free(n->val);
		n = n->next;
	}
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
}

void **list_to_array(list *l)
{
<<<<<<< HEAD
    void** a = (void**)xcalloc(l->size, sizeof(void*));
=======
    void **a = calloc(l->size, sizeof(void*));
>>>>>>> 869fe66efab52ea31b56f577025fb52b0064622c
    int count = 0;
    node *n = l->front;
    while(n){
        a[count++] = n->val;
        n = n->next;
    }
    return a;
}
