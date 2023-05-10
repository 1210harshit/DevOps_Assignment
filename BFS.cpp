#include<stdio.h>
#include<stdlib.h>
#define size 40

struct queue
{
	int items[size];
	int front;
	int rear;	
  };
struct queue* createQueue();

void enqueue(struct queue* q,int);
int dequeue(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node
{
	int vertex;
	struct node* next;
	
};
struct node* createNode(int v);
struct Graph
 {
 	int numVertices;
 	int* visited;
 	struct node** adjLists;
 };
 
 struct Graph* createGraph(int);
 
 void addEdge(struct Graph*,int,int);
 void printGraph(struct Graph*);
 void bfs(struct Graph* graph, int startVertex);
 
 int main()
 {
 	struct Graph* graph=createGraph(4);
 	addEdge(graph,0,1);
 	addEdge(graph,0,2);
 	addEdge(graph,1,2);
 	addEdge(graph,1,4);
 	addEdge(graph,1,3);
 	addEdge(graph,2,4);
 	addEdge(graph,3,4);
 	
 	printGraph(graph);
 	bfs(graph,0);
 	
 	return 0;
 }
 
 void bfs(struct Graph* graph, int startVertex)
 	{
 		struct queue* q = createQueue();
		 graph->visited[startVertex]=1;
		 enqueue(q,startVertex);
		 
		 while(!isEmpty(q))
		 	{
		 		printQueue(q);
		 		int currentVertex=dequeue(q);
		 		printf("Visited %d\n",currentVertex);
		 		
		 		struct node* temp=graph->adjLists[currentVertex];
		 		while(temp)
		 			{
		 				int adjVertex=temp->vertex;
		 				if(graph->visited[adjVertex]==0)
		 				 {
		 				 	graph->visited[adjVertex]=1;
		 				 	enqueue(q,adjVertex);
						  }
						 temp=temp->next; 
					 }
			  } 
	 }
 struct node* createNode(int v)
 {
 	struct node* newNode=(node*)malloc(sizeof(struct node));
	newNode->vertex=v;
	newNode->next=NULL;
	return newNode;
 }
 
 struct Graph* createGraph(int vertices)
 {
 	struct Graph* graph=(Graph*)malloc(sizeof(struct Graph));
 	graph->numVertices=vertices;
 	
	 graph->adjLists=(node**)malloc(vertices * sizeof(struct node*));
 	 graph->visited=(int*)malloc(vertices * sizeof(int));
 	
 	int i;
 	for(i=0;i<vertices;i++)
 		{
 			graph->adjLists[i]=NULL;
 			graph->visited[i]=0;
		 }
		 
		 return graph;
 }
 
 void addEdge(struct Graph* graph, int src, int dest)
 	{
 		struct node* newNode=createNode(dest);
 		newNode->next=graph->adjLists[src];
 		graph->adjLists[src]=newNode;
 		
 		newNode=createNode(src);
 		newNode->next=graph->adjLists[dest];
 		graph->adjLists[dest]=newNode;
 			
	 }
	 
	 void printGraph(struct Graph* graph)
	 	{
	 		int v;
	 		for(v=0;v<graph->numVertices;v++)
	 		{
	 			struct node* temp=graph->adjLists[v];
	 			printf("\n Adjacency List of vertex %d\n",v);
	 			while(temp)
	 				{
	 					printf("%d -> ",temp->vertex);
	 					temp=temp->next;
	 					
					 }
					 printf("\n");
			 }
		 }
		 
 struct queue* createQueue()
 	{
 		struct queue* q=(queue*)malloc(sizeof(struct queue));
 		q->front=-1;
 		q->rear=-1;
 		return q;
			  }		 
 
 int isEmpty(struct queue* q)
 	{
 		if(q->rear==1)
 			return 1;
 		else
		    return 0;	
	 }

void enqueue(struct queue* q,int value)
	{
		if(q->rear==size-1)
		   printf("\nQueue is full");
		else
		   {
		   	 if(q->front==-1)
		   	   {
		   	   	q->front=0;
		   	   	q->rear++;
		   	   	q->items[q->rear=value];
				  }
			  }   
		 }
 int dequeue(struct queue* q)
 	{
 		int item;
 		if(isEmpty(q))
 			{
 				printf("Queue is Empty");
 				item=-1;
			 }
		else
			{
				item=q->items[q->front];
				q->front++;
				if(q->front > q->rear)
                  {
                  	printf("Resetting Queue");
                
				  }
				  
			}
				 return item;	 
	}
	
	void printQueue(struct queue *q)
		{
			int i=q->front;
			if(isEmpty(q))
			 	printf("Queue is empty");
			else
			    {
			    	printf("\n Queue contains \n");
			    	for(i=q->front;i<q->rear+1;i++)
			    	 {
			    	 	printf("%d ",q->items[i]);
					 }
				} 	
		}
	
				   		 	 
 
