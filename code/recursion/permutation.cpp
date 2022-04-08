// 1 2 3
// 1 -> 
// 2
// 3
#include <cstdio>
#include <vector>
using namespace std;
const int maxN = 10;
int arr[maxN],n;
vector<int> permutation;
bool check[maxN]; // เก็บไว้ว่าเราได้ใส่ arr[i] ไปใน permutation หรือยัง
void search(){
	if(permutation.size() == n){
		// print คำตอบ
		for(int x : permutation){
			printf("%d ",x);
		}
		printf("\n");
	} else {
		// ใช้ตัวซ้ำไม่ได้, ลำดับตัวเลขมีผล
		for(int i=0;i<n;i++){
			if(check[i]) continue;

			// ใส่ arr[i] เข้าไปในคำตอบ
			permutation.push_back(arr[i]);
			check[i] = true;
			search();

			permutation.pop_back();
			check[i] = false;
		}

	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	search();
	return 0;
}