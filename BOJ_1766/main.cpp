#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, m;
vvi edges;
vi degs;

vi ans;
void solve() {
	auto q = priority_queue<int, vi, greater<int>>{};
	for (auto i = 1; i <= n; ++i) {
		if (0 == degs[i]) {
			q.push(i);
		}
	}

	for (auto i = 0; i < n; ++i) {
		if (q.empty()) {
			return;
		}

		auto f = q.top();
		q.pop();

		ans.push_back(f);

		for (const auto& x : edges[f]) {
			--degs[x];
			if (0 == degs[x]) {
				q.push(x);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m;
	edges = vvi(n + 1, vi{});
	degs = vi(n + 1, 0);
	while (0 < (m--)) {
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b);
		++degs[b];
	}

	for (auto i = 1; i <= n; ++i) {
		if (1 < edges[i].size()) {
			sort(edges[i].begin(), edges[i].end());
		}
	}

	ans = vi{};
	ans.reserve(n);
	solve();

	for (const auto& x : ans) {
		cout << x << ' ';
	}

	return 0;
}