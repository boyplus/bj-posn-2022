#include <cstdio>
#include <vector>
using namespace std;
const int maxN = 30000;
vector<int> g[maxN];
int main(){
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<n;i++){
		printf("%d: ",i);
		for(int j=0;j<g[i].size();j++){
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
5 5
1 0
2 3
4 2
3 4
3 3
*/