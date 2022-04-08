#include <cstdio>
#include <vector>
using namespace std;
const int maxN = 30000;
vector<int> g[maxN];
bool check[maxN];
void dfs(int u){
	check[u] = true;
	for(int v : g[u]){
		if(check[v] == false){
			dfs(v);
		}
	}
}
int main(){
	// Goal is to count the number of connected component in graph
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int count = 0;
	for(int i=0;i<n;i++){
		if(check[i] == false){
			count++;
			dfs(i);
		}
	}
	printf("%d\n",count);
	return 0;
}

/*
9 7
0 8
8 4
0 4
4 3
1 7
2 7
6 5
*/