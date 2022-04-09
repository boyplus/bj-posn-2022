#include <cstdio>
#include <vector>
using namespace std;
const int maxN = 30000;
vector<int> g[maxN];
bool check[maxN];
bool dfs(int u,int target){
	if(u == target) return true;
	check[u] = true;
	bool isSameComponent = false;
	for(int v : g[u]){
		if(check[v] == false){
			isSameComponent = isSameComponent || dfs(v,target);
		}
	}
	return isSameComponent;
}
int main(){
	// Goal is to determine whether node a, and b are in the same component
	int n,m,u,v,a,b;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	scanf("%d %d",&a,&b);
	bool isSameComponent = dfs(a,b);
	if(isSameComponent){
		printf("Yes\n");
	} else {
		printf("No\n");
	}
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
8 3


9 7
0 8
8 4
0 4
4 3
1 7
2 7
6 5
8 7
*/