#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<int> vec, subset;
void search(int k){
	// already complete generate subset
	if(k == vec.size()){
		for(int x:subset){
			printf("%d ",x);
		}
		printf("\n");
	} else {
		// do not include the k-th element in the answer
		// so do the next search
		search(k+1);

		// include k-th element
		subset.push_back(vec[k]);
		search(k+1);

		// after we include k-th element, we need to pop it since we use
		// the global var
		subset.pop_back();
	}
}
int main(){
	int x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		vec.push_back(x);
	}
	search(0);
	return 0;
}