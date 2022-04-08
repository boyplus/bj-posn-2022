#include <cstdio>
#include <queue>
using namespace std;
const int maxRow = 1000, maxCol = 1000;
char mp[maxRow][maxCol];
bool visited[maxRow][maxCol];
int n,m;
class Grid{
public:
	int r,c,l;
	Grid(int r,int c,int l){
		this->r = r;
		this->c = c;
		this->l = l;
	}
};
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",mp[i]);
	}
	queue<Grid> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mp[i][j] == 'S'){
				q.push(Grid(i,j,0));
				break;
			}
		}
	}
	while(q.empty() == false){
		int r = q.front().r,c = q.front().c, l = q.front().l;
		visited[r][c] = true;
		if(mp[r][c] == 'E'){
			printf("%d\n",l);
			return 0;
		}
		q.pop();
		if((mp[r-1][c] == '.' || mp[r-1][c] == 'E') && visited[r-1][c] == false){
			q.push(Grid(r-1,c,l+1));
		}
		if((mp[r+1][c] == '.' || mp[r+1][c] == 'E') && visited[r+1][c] == false){
			q.push(Grid(r+1,c,l+1));
		}
		if((mp[r][c-1] == '.' || mp[r][c-1] == 'E') && visited[r][c-1] == false){
			q.push(Grid(r,c-1,l+1));
		}
		if((mp[r][c+1] == '.' || mp[r][c+1] == 'E') && visited[r][c+1] == false){
			q.push(Grid(r,c+1,l+1));
		}
	}
	return 0;
}
// row, col, level
/*
5 4
....
.S#E
..#.
..#.
....
*/