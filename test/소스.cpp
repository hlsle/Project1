#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<vector<int>> v(5, vector<int>());

	v[2].push_back(100);
	v[4].push_back(200);

	for (auto i : v[4])
		cout << i;
	return 0;
}