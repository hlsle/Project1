#include <iostream>
#include <queue>

using namespace std;
int main() {
	cin.tie(NULL); 
	ios_base::sync_with_stdio(false); // 입력 버퍼가 줄어 속도가 향상됨 endl 대신 \n 사용할 것
	int n;
	cin >> n;
	priority_queue<int> pq;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.empty() == true)
				cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(a);
	}

	return 0;
}