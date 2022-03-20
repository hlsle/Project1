#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;

	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>()); // 1로 맞추기 위해서 크기 n+1
	vector<int> priority(n + 1);

	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b); // 먼저 풀어야 할 문제(a)와 다음에 풀어야 할 문제(b) 저장
		priority[b]++; // 나중에 풀어야 할 문제 표시
	}

	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 1; i <= n; i++) {
		if (priority[i] == 0)
			pq.push(i); // 먼저 풀어도 되는 문제들 큐에 저장
	}

	for (int i = 1; i <= n; i++) {
		cout << pq.top() << " "; //가장 먼저 풀어도되는 문제 출력 -> 그다음으로 풀어도 되는 문제 출력
		int p = pq.top();
		pq.pop(); //출력했으니 삭제
		for (auto j : v[p]) {// j는 v[p].second 값이 들어감
			priority[j]--; //나중에 풀어도 되는 문제들 중 먼저 풀어어야 하는 문제 0으로 만들어줌
			if (priority[j] == 0)
				pq.push(j);
		}
	}

	return 0;
}