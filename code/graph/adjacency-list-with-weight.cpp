#include <cstdio>
#include <vector>
using namespace std;
const int maxN = 30000;
vector<pair<int,int>> g[maxN];
int main(){
	int n,m,u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back({v,w});
		if(u == v) continue;
		g[v].push_back({u,w});
	}
	for(int i=0;i<n;i++){
		printf("%d: ",i);
		for(int j=0;j<g[i].size();j++){
			printf("(%d, %d) ",g[i][j].first,g[i][j].second);
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