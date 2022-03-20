#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int main() {

	int n;

	cin >> n;
	priority_queue<int, vector<int>, greater<>> pq;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	int sum = 0, result = 0, i = 1;
	while(pq.empty()==0) {
		sum += pq.top();
		pq.pop();
		if (i % 2 == 0) {
			pq.push(sum);
			result += sum;
			sum = 0;
		}
		i++;
	}
	if (n == 1)
		result = 0;
	cout << result;
	return 0;
}