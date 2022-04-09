#include <cstdio>
#include <vector>
using namespace std;
const int maxN = 30000;
vector<int> g[maxN];
bool check[maxN];
int group[maxN];
void dfs(int u,int groupNumber){
	check[u] = true;
	group[u] = groupNumber;
	for(int v:g[u]){
		if(check[v] == false){
			dfs(v,groupNumber);
		}
	}
}
int main(){
	// Goal is to determine whether node a, and b are in the same component or not for q queries
	int n,m,u,v,a,b;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<n;i++){
		if(check[i] == false){
			dfs(i,i);
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&a,&b);
		if(group[a] == group[b]){
			printf("Yes\n");
		} else {
			printf("No\n");
		}

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
2
8 3
8 7

*/