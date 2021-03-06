// implementation of queue using array
#define MAX 100
#include<stdio.h>
void Nqueue();
int delStart();
int delEnd();
int queue[MAX];
int rear =0, front =0;
void display();
int main()
{
  int choice, c, token;
  scanf("%d",&c);
  while(c!=0)
  {
          switch(c)
          {
            case 1:    Nqueue(token);
                       break;
            case 2:    token=delStart();
                       break;
            case 3:    token=delEnd();
                       break;
            case 4:    display();
                       printf("\n");
                       break;
          }
          scanf("%d",&c);   
  }
  return 0;
}
void display()
{
     int i;
     for(i=rear;i<front;i++)
           printf("%d->",queue[i]);
}
void Nqueue()
{ 
     int token;
     scanf("%d",&token);
     queue[front]=token;
     front=front+1;
}
int delEnd()
{
     int t;
     if(front==rear)
     {
            printf("Underflow\n");
            return 0;
     }
     front=front-1;
     t=queue[front+1];
     return t;
}
int delStart()
{
     int t;
     rear=rear+1;
     t=queue[rear-1];
     return t;
}