#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
	Item elem;
	struct QueueNode *next;
}QueueNode;

typedef QueueNode TcelQ;
typedef QueueNode *ACelQ;

typedef struct Queue{
	QueueNode *front;
	QueueNode *rear;
	long size;
}Queue;

typedef Queue TCoada;
typedef Queue *AQ;


Queue* createQueue(void){
	Queue *q=(Queue*)malloc(sizeof(Queue));
	q->rear=q->front=NULL;
	q->size=0;
	return q;
} 

int isQueueEmpty(Queue *q){
	return(q==NULL||q->rear==NULL&&q->front==NULL);
}

void enqueue(Queue *q, Item elem){
	QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
	node->elem=elem;
	node->next=NULL;
	if(isQueueEmpty(q)){
		q->rear=q->front=node;
	}else{
		q->rear->next=node;
		q->rear=node;
	}
	q->size++;
}

Item front(Queue* q){
	return q->front->elem;
}

void dequeue(Queue* q){
	if(isQueueEmpty(q))return;
	QueueNode* aux=q->front;
	q->front=q->front->next;
	free(aux);
	if(q->front==NULL)
		q->rear=NULL;
	q->size--;
	return;
}

void destroyQueue(Queue *q){
	while(!isQueueEmpty(q)){
		dequeue(q);
	}
	free(q);
}

#endif
