// 1 2 3
// 
// 1
// 2
// 3
// 1 2
// ...
#include <cstdio>
#include <vector>
using namespace std;
const int maxN = 20;
int n;
int arr[maxN];
vector<int> subset;
// การบ้าน: ลองใช้ array ในการเก็บคำตอบแทน vector
// ลองทำดูเลยก็ได้นะครับบ
// การบ้าน2: ถ้าไม่ใช้ recursive แล้ว เราสามารถ gen subset ด้วยวิธีอื่นยังไงได้บ้าง
void search(int k){
	// 2 กรณี -> 

	// 1. ไม่ใส่ arr[k]
	// 2. ใส่ arr[k] เข้าไปในคำตอบ (subset)
	
	// base case -> ถ้าพิจารณาครบทุตัวแล้ว -> ทำการ print subset
	if(k == n){
		// print คำตอบ
		for(int x : subset){
			printf("%d ",x);
		}
		printf("\n");
	} else {
		// 1 ไม่ใส่ arr[k]
		search(k+1);

		// 2 ใส่ arr[k] เข้าไปในคำตอบ
		subset.push_back(arr[k]);
		search(k+1);
		subset.pop_back();
	}

}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	search(0);
	return 0;
}