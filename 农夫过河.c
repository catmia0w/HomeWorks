#define MaxVertexNum 10
typedef enum{FALSE,TRUE}Boolean;
Boolean visited[MaxVertexNum];
int path[MaxVertexNum];
int locate(MGraph *G,int F,int W,int S,int V)
{
  int i;
  for(i=0;i<G->vertexNum;i++)
    if(G->vertexs[i].farmer==F&&G->vertexs[i].wolf==W&&G->vertexs[i].sheep==S&&G->vertexs[i].vegetable==V)
      return(i);
  return(-1);
}
int is_safe(int F,int W,int S,int V)
{
  if(F!=S&&(W==S||S==V)) return (0);
  else return(1);
}
int is_connected(MGraph *G,int i,int j)
{
  int k=0;
  if(G->vertexs[i].wolf!=G->vertexs[j].wolf)k++;
  if(G->vertexs[i].sheep!=G->vertexs[j].wolf)k++;
  if(G->vertexs[i].vegetable!=G->vertexs[j].vegetable)k++;
  if(G->vertexs[i].farmer!=G->vertexs[j].farmer&&k<=1)
    return(1);
  else return (0);
}
void CreateG(MGraph *G)
{
  int i,j,F,W,S,V;
  i=0;
  for(F=0;F<=1;F++)
    for(W=0;W<=1;W++)
      for(S=0;S<=1;S++)
        for(V=0;V<=1;V++)
          if(is_safe(F,W,S,V))
          {
            G->vertexs[i].farmer=F;
            G->vertexs[i].wolf=W;
            G->vertexs[i].sheep=S;
            G->vertexs[i].vegrtable=V;
            i++;
          }
  G->vertexNum=i;
  for(i=0;i<G->vertexNum;i++)
    for(j=0;j<G->vertexNum;i++)
      if(is_connected(G,i,j))
        G->edges[i][j]=G->edges[j][i]=1;
  else 
    G->edges[i][j]=G->edges[j][i]=0;
  return;
}
void printf_path(MGraph *G,int u,int v)
{
  int k;
  k=u;
  while(K!=v)
  {
    printf("\n(%d,%d,%d,%d)",G->vertexs[k].farmer,G);
  }
}
