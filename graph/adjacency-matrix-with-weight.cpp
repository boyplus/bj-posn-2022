#include <cstdio>
using namespace std;
const int maxN = 1000;
// If graph is unweight, can declare g as the array of boolean
int g[maxN][maxN];
int main(){
	int n,m,u,v,w;
	scanf("%d %d",&n,&m);
	// Set -1 to indicate that there is no edge between u and v
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			g[i][j] = -1;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		g[u][v] = w;
		g[v][u] = w;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
5 5
1 0 0
2 3 3
4 2 5
3 4 8
3 3 3
*/