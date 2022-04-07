#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxN = 10001;
int level[maxN];
vector<int> vec[maxN];
int main(){
	int n,m,u,v,s,e;
	scanf("%d %d %d %d",&n,&m,&s,&e);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	bool found = false;
	for(int i=0;i<n;i++){
		level[i] = -1;
	}
	level[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == e){
			found = true;
			printf("%d\n",level[u]);
			break;
		} 
		for(int i=0;i<vec[u].size();i++){
			int v = vec[u][i];
			if(level[v] != -1) continue;
			level[v] = level[u]+1;
			q.push(v);
		}
	}
	if(found == false) printf("-1\n");
	return 0;
}
/*
6 4 0 5
0 1
2 1
3 4
3 2
*/