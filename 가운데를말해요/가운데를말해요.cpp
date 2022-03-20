#include <iostream>
#include <queue>

using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;

	cin >> n;

	priority_queue<int> q_max; //���� ���� �� top�� �ִ밪
	priority_queue<int, vector<int>, greater<>> q_min; //ū ���� �� top�� �ּҰ�
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (q_max.size() == q_min.size()) // size �� ������ max�� �߰�
			q_max.push(a);
		else q_min.push(a);

		if (!q_min.empty() && !q_max.empty() && q_max.top() > q_min.top()) {
			//max�� top���� min�� top������ ũ�� �ٲ�
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