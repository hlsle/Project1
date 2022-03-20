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
	vector<vector<int>> v(n + 1, vector<int>()); // 1�� ���߱� ���ؼ� ũ�� n+1
	vector<int> priority(n + 1);

	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b); // ���� Ǯ��� �� ����(a)�� ������ Ǯ��� �� ����(b) ����
		priority[b]++; // ���߿� Ǯ��� �� ���� ǥ��
	}

	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 1; i <= n; i++) {
		if (priority[i] == 0)
			pq.push(i); // ���� Ǯ� �Ǵ� ������ ť�� ����
	}

	for (int i = 1; i <= n; i++) {
		cout << pq.top() << " "; //���� ���� Ǯ��Ǵ� ���� ��� -> �״������� Ǯ� �Ǵ� ���� ���
		int p = pq.top();
		pq.pop(); //��������� ����
		for (auto j : v[p]) {// j�� v[p].second ���� ��
			priority[j]--; //���߿� Ǯ� �Ǵ� ������ �� ���� Ǯ���� �ϴ� ���� 0���� �������
			if (priority[j] == 0)
				pq.push(j);
		}
	}

	return 0;
}