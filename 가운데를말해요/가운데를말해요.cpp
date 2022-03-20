#include <iostream>
#include <queue>

using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;

	cin >> n;

	priority_queue<int> q_max; //작은 수들 중 top에 최대값
	priority_queue<int, vector<int>, greater<>> q_min; //큰 수들 중 top에 최소값
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (q_max.size() == q_min.size()) // size 가 같으면 max에 추가
			q_max.push(a);
		else q_min.push(a);

		if (!q_min.empty() && !q_max.empty() && q_max.top() > q_min.top()) {
			//max의 top값이 min의 top값보다 크면 바꿈
			int max = q_max.top();
			int min = q_min.top();
			q_max.pop();
			q_min.pop();
			q_max.push(min);
			q_min.push(max);
		}
		cout << q_max.top() << "\n";
	}
	return 0;
}