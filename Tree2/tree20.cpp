#include<stdio.h>
#define LIMIT 100005
#define MOD 1000000007
#define left(i) (2*i+1)
#define right(i) (2*i+2)

typedef struct {
 int inrolled;
 int laststudent;
 int secondlaststudent;
 int courseno;
 long long int z;
}courseinfo;

courseinfo heap[LIMIT];
int Y[LIMIT];
int X[LIMIT];
int C, P, N;

int printheap(int N){
 int i;
 for(i = 0; i < N; i++){
  printf("[%d | %d | %lld | %d | %d]\t\t", heap[i].courseno, heap[i].inrolled, heap[i].z, heap[i].laststudent, heap[i].secondlaststudent);
 }
 printf("\n\n");
 return 0;
}

int swap(courseinfo *a, courseinfo *b){
 courseinfo temp;
 temp = *a;
 *a = *b;
 *b = temp;
 return 0;
}

int minheapify(int i, int heapsize){
 int smallest = i;
 if(left(i) < heapsize && heap[left(i)].z <= heap[smallest].z){
  if(heap[left(i)].z != heap[smallest].z)
   smallest = left(i);
  else if(heap[left(i)].courseno < heap[smallest].courseno)
   smallest = left(i);
 }
 if(right(i) < heapsize && heap[right(i)].z <= heap[smallest].z){
  if(heap[right(i)].z != heap[smallest].z)
   smallest = right(i);
  else if(heap[right(i)].courseno < heap[smallest].courseno)
   smallest = right(i);
 }
 
 if(i != smallest){  
   swap(&heap[i], &heap[smallest]);
   minheapify(smallest, heapsize);
 }
 return 0;
}

int buildheap(int C){
 int i = C/2 -1;
 for(; i >= 0; i--)
  minheapify(i, C);
 minheapify(0, C);
 return 0;
}

int main(){
 scanf("%d%d%d", &C, &P, &N);
 int i;
 for(i = 1; i <= N; i++){
  scanf("%d", &Y[i]);
  heap[i-1].inrolled = 1;
  heap[i-1].courseno = i;
  heap[i-1].laststudent = Y[i];
  heap[i-1].secondlaststudent = 0;
  heap[i-1].z = 1*Y[i];
 }
 for(; i <= C; i++){
  heap[i-1].inrolled = 0;
  heap[i-1].courseno = i;
  heap[i-1].laststudent = 0;
  heap[i-1].secondlaststudent = 0;
  heap[i-1].z = 0;
 }
 //printheap(C);
 buildheap(C);
 //printheap(C);
 for(i  = 1; i <= P; i++){
  scanf("%d", &X[i]);
 }
   //printf("%d", );
 for(i = 1; i <= P; i++){
   if(i == 1){
   	printf("%d",heap[0].courseno);
   }else{
  printf(" %d", heap[0].courseno);
   }

  heap[0].inrolled++;
  heap[0].secondlaststudent = heap[0].laststudent;
  heap[0].laststudent = X[i];
  heap[0].z = (heap[0].inrolled * (heap[0].laststudent + heap[0].secondlaststudent))%MOD;
  minheapify(0, C);
    }
  return 0;
}