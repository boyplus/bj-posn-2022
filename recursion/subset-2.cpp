#include <cstdio>
#include <vector>
using namespace std;
int n, r;
vector<int> vec, subset;
void search(int k){
	// already complete generate subset
	if(k == vec.size()){
		if(subset.size() == r){
			for(int x:subset){
				printf("%d ",x);
			}
			printf("\n");	
		}

	} else {
		search(k+1);
		subset.push_back(vec[k]);
		search(k+1);
		subset.pop_back();
	}
}
int main(){
	int x;
	scanf("%d %d",&n,&r);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		vec.push_back(x);
	}
	search(0);
	return 0;
}