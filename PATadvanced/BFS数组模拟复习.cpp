//��Ҫ�ֶ�ģ��һ������
//����ʱ����visit()
//ע���ڽӱ�Ķ��巽ʽ
void BFS (LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    int p[10000];  //ģ���������
    int x = 0,cnt = 0;
    Visit(S);
    Visited[S] = true;
    p[cnt++] = S;
    while(cnt != x){
        //����
        PtrToAdjvnode t = Graph->G[p[x++]].FirstEdge;  //Ϊɶ��G��p[x++]��---һ��һ�����Ӱ�
        while(t){
                int tt=t->AdjV;
                if(!Visited[tt]){
                p[cnt++]=tt;
                Visit(tt);
                Visited[tt]=true;
            }
            t=t->Next;  //�ڽӱ�
        }
    }
}
