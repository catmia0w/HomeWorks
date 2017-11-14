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
