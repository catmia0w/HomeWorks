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
  
}
