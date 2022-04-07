#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 201,INF = (int)1e9;
int dist[maxN][maxN];
int main(){
	int n,m,u,v,w;
	scanf("%d %d",&n,&m);
	//init dist from node u to v to INF except dist from node u to u is 0
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		dist[u][v] = w;
		dist[v][u] = w;
	}
	//dist from i to j can be calculate by i to k + k to j
	//and compare with dist from i to j (choose the minimum) 
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[i][j] == INF){
				printf("INF ");
			} else{
				printf("%3d ",dist[i][j]);	
			}
			
		}
		printf("\n");
	}
	return 0;
}
/*
9 14
0 1 4
0 7 8
1 7 11
1 2 8
2 3 7
3 4 9
4 5 10
6 5 2
7 6 1
7 8 7
2 8 2
2 5 4
3 5 14
8 6 6
*/