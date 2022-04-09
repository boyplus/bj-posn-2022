#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 30000;
const int INF = (int)1e9; // 1o^9
vector<int> g[maxN];
int level[maxN];
bool check[maxN];
int main(){
	// Goal is to find shortest distance from node u to every nodes in graph
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<n;i++){
		level[i] = INF;
	}
	int source;
	scanf("%d",&source);
	queue<int> q;
	q.push(source);
	level[source] = 0;
	while(q.empty() == false){
		int u = q.front();
		q.pop();
		check[u] = true;
		for(int v:g[u]){
			if(check[v] == false){
				level[v] = level[u]+1;
				q.push(v);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(level[i] == INF){
			printf("- ");
		} else{
			printf("%d ",level[i]);	
		}
	}
	printf("\n");
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
8
*/