#include<stdbool.h>
typedef int elem;
typedef struct Node
{
	elem data;
	struct Node* next;
}node,*pnode;
extern pnode creat();
extern bool add(elem,pnode*);
extern bool add1(elem,pnode*);
extern bool delete(elem,pnode*);
extern bool change(elem,elem,pnode);
extern elem* find(elem,pnode);
extern void show(pnode); 
