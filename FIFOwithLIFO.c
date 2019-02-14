
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

struct Node {
int key;
struct Node* next;};

struct Node* init() {
struct Node* stackTop = malloc(sizeof(struct Node));
stackTop->key = 0;
return stackTop;}

struct Queue {
struct Node* stack1;
struct Node* stack2;
};
 
struct Queue* initQ() {
	struct Queue* q = malloc(sizeof(struct Queue));
	q->stack1=init();
	q->stack2=init();
	return q;
}

 

int isEmpty(struct Node* stackTop) {
if (stackTop->key!=0) return 0;
else return 1;
}

void push(struct Node* stackTop, int key){
	if(isEmpty(stackTop)){
	 stackTop->key=key;
	 stackTop->next=malloc(sizeof(struct Node));
	 stackTop->next->key = 0;}
	
	else{
	
		struct Node* p = stackTop->next; 
		while (p->key != 0 ){
			p = p->next;}
		p->key = key;
		p->next=malloc(sizeof(struct Node));
		p->next->key = 0;}
		
}

int pop(struct Node* stackTop){
	struct Node* p = stackTop->next; 
	int value;
	struct Node* current=stackTop;
		if(isEmpty(current)){
				return -1;}	
		
		else{
			while (p->key != 0) {
			current=current->next;
			p = p->next;}
			value=current->key;
			current->key = 0;
			p->key=0;
			return value;}}
			

void print(struct Node* stackTop){
	if(isEmpty(stackTop)){
	 printf("Stack empty\n");}
	
	else{
		printf("%d ",stackTop->key);
		struct Node* p = stackTop->next; 
		while (p->key != 0 && p->key!=-1){
			printf("%d ",p->key);
			p = p->next;}
			printf("\n");}
			
}

int enque=1;
int counter=0;
int deQueue(struct Queue *q){
	int val=pop(q->stack1);
	
	while(val!=-1){
		
		push(q->stack2,val);
		val=pop(q->stack1);	}
		val=pop(q->stack2);
		free(q->stack1);
		q->stack1=init();
		enque=0;
		return val;
}

void enQueue(struct Queue *q, int key){
	if (enque==1){

	push(q->stack1,key);
		}
	
	else{
		

		int val=pop(q->stack2);

		while(val!=-1){
		
		push(q->stack1,val);
		val=pop(q->stack2);}
		push(q->stack1,key);
		
	
		
		free(q->stack2);
		q->stack2=init();
		
		
		
		val=pop(q->stack1);
	
	while(val!=-1){
		
		push(q->stack2,val);
		val=pop(q->stack1);	}
	
	free(q->stack1);
	q->stack1=init();

	}
		
}






void printQueue(struct Queue *q) {

if (enque==1){
	
	int val=pop(q->stack1);
	
	while(val!=-1){
		
		push(q->stack2,val);
		val=pop(q->stack1);	
		enque=0;}}
		
print(q->stack2);}
		

struct Queue* q= initQ();

enQueue(q,2);
enQueue(q,8);
enQueue(q,11);
enQueue(q,15);
printf("Queue is:\n");
printQueue(q);
int val=deQueue(q);
printf("Deque Value %d\n",val);
val=deQueue(q);
printf("Deque Value %d\n",val);
printf("Queue is:\n");
printQueue(q);
enQueue(q,1);
enQueue(q,5);
printf("Queue is:\n");
printQueue(q);

}
