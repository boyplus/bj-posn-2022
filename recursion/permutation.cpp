#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<int> vec, permutation;
bool chosen[100];
void search(){
	// already complete generate 
	if(permutation.size() == n){
		for(int x : permutation){
			printf("%d ",x);
		}
		printf("\n");
	} else {
		for(int i=0;i<n;i++){
			if(chosen[i]) continue;
			chosen[i] = true;
			permutation.push_back(vec[i]);
			search();
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}
int main(){
	int x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		vec.push_back(x);
	}
	search();
	return 0;
}