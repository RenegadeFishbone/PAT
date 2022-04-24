//需要手动模拟一个队列
//访问时调用visit()
//注意邻接表的定义方式
void BFS (LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    int p[10000];  //模拟队列数组
    int x = 0,cnt = 0;
    Visit(S);
    Visited[S] = true;
    p[cnt++] = S;
    while(cnt != x){
        //出队
        PtrToAdjvnode t = Graph->G[p[x++]].FirstEdge;  //为啥是G【p[x++]】---一个一个出队啊
        while(t){
                int tt=t->AdjV;
                if(!Visited[tt]){
                p[cnt++]=tt;
                Visit(tt);
                Visited[tt]=true;
            }
            t=t->Next;  //邻接表
        }
    }
}
