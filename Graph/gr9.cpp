#include <iostream>
#include <cstring>
using namespace std;

#define INF 9999999


int G[100][100];

int main () {

  int no_edge,n,i,j,sum=0;
  cin>>n;
  int V=n;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      cin>>G[i][j];
    }
  }
  int selected[V];
  memset (selected, false, sizeof (selected));
  no_edge = 0;

  selected[0] = true;

  int x;           
  int y;           

int k=0;
  while (no_edge < V - 1) {

      int min = INF;
      x = 0;
      y = 0;

      for (int i = 0; i < V; i++) {
        if (selected[i]) {
            for (int j = 0; j < V; j++) {
              if (!selected[j] && G[i][j]) {
                  if (min > G[i][j]) {
                      min = G[i][j];
                      x = i;
                      y = j;
                  }
   
              }
          }
        }
      }
    sum+=G[x][y];
      cout <<"Edge "<<++k<<":("<<x+1 << " " << y+1 << ") cost:" << G[x][y];
      cout << endl;
      selected[y] = true;
      no_edge++;
    }
  cout<<"Minimun cost="<<sum;
  return 0;
}