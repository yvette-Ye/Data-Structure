//
//  main.c
//  Floyd
//
//  Created by 叶欣宇 on 2019/6/27.
//  版权所有，盗版必究！（说起来蛮搞笑的，因为前一天的java实践报告被copy了17份，以后所有的代码都提醒自己写一个这样的声明）
//
#include <stdio.h>
#define MaxSize 10
#define INFINITY 6666
int t1,t2,t3;
typedef struct{
    int edge[MaxSize][MaxSize];
    int vertexNum,edgeNum;
}MGraph;

void CreatGraph(MGraph *G,int n,int m){
    G->vertexNum = n;
    G->edgeNum = m;
    for(int i=1;i<=G->vertexNum;i++)
        for(int j=1;j<=G->vertexNum;j++)
            if(i==j) G->edge[i][j]=0;
            else G->edge[i][j]=INFINITY;
}

void Floyd(MGraph *G,int n,int m){
    for(int k=1;k<=G->vertexNum;k++)
        for(int i=1;i<=G->vertexNum;i++)
            for(int j=1;j<=G->vertexNum;j++)
                if(G->edge[i][j]>G->edge[i][k]+G->edge[k][j] )
                    G->edge[i][j]=G->edge[i][k]+G->edge[k][j];
}

void min(MGraph *G,int n,int m){
    int min = 6666;
    int ii = 0,jj = 0;
    for(int i=1;i<=G->vertexNum;i++){
        for(int j=1;j<=G->vertexNum;j++){
            if(min>G->edge[i][j]&&G->edge[i][j]!=0){
                ii=i;
                jj=j;
                min=G->edge[i][j];
            }
        }
    }
    printf("%d村庄到%d村庄距离最短，为：%d\n",ii,jj,min);
}

int main(){
    MGraph G;
    int n,m;
    printf("请输入村庄的个数，以及道路条数：");
    scanf("%d %d",&n,&m);
    CreatGraph(&G,n,m);
    
    printf("输入两个村庄之间道路的距离:\n");
    for(int i=1;i<=G.edgeNum;i++){
        scanf("%d %d %d",&t1,&t2,&t3);
        G.edge[t1][t2]=t3;
    }
    printf("村庄间道路的距离:\n");
    for(int i=1;i<=G.vertexNum;i++){
        for(int j=1;j<=G.vertexNum;j++){
            printf("%8d",G.edge[i][j]);
        }
        printf("\n");
    }
    
    Floyd(&G,n,m);
    
    printf("村庄间道路最短的距离:\n");
    for(int i=1;i<=G.vertexNum;i++){
        for(int j=1;j<=G.vertexNum;j++){
            printf("%5d",G.edge[i][j]);
        }
        printf("\n");
    }
    min(&G, n, m);
    return 0;
}
