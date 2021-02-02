#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
ll V, E, schk[500005], scc[500005], S, cnt;
ll start, P, cost[500005], scccost[500005], chk[500005];
ll dp[500005];
vector<vector<ll>> v, ans, sccv;
vector<pair<ll, ll>> input;
vector<ll> res;
stack<ll> st;
ll dfs(ll now) {
	st.push(now);
	schk[now] = S++;
	ll parent = schk[now];
	for (ll i = 0; i < v[now].size(); i++) {
		ll next = v[now][i];
		if (schk[next] == -1) parent = min(parent, dfs(next));
		else if (scc[next] == -1) parent = min(parent, schk[next]);
	}
	if (parent == schk[now]) {
		vector<ll> temp;
		while (1) {
			ll here = st.top();
			scccost[cnt] += cost[here];
			st.pop();
			scc[here] = cnt;
			temp.push_back(here);
			if (here == now) break;
		}
		ans.push_back(temp);
		cnt++;
	}
	return parent;
}
void go(ll now) {
	for (ll i = 0; i < sccv[now].size(); i++) {
		ll next = sccv[now][i];
		if (dp[next] < dp[now] + scccost[next]) {
			dp[next] = max(dp[next], dp[now] + scccost[next]);
			go(next);
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(schk, -1, sizeof(schk));
	memset(scc, -1, sizeof(scc));
	cin >> V >> E;
	v.resize(V + 1);
	for (int i = 0; i < E; i++) {
		ll a, b; cin >> a >> b;
		v[a].push_back(b);
		input.push_back({ a,b }); // �Է°� ����
	}
	for (ll i = 1; i <= V; i++) cin >> cost[i];
	cin >> start >> P;
	for (ll i = 0; i < P; i++) {
		ll a;
		cin >> a;
		res.push_back(a); // ������� ����
	}
	for (ll i = 1; i <= V; i++)
		if (schk[i] == -1) dfs(i); // scc ã��
	sccv.resize(cnt + 1); // scc �׷��� ����
	for (ll i = 0; i < input.size(); i++) { // scc �׷��� �����
		ll s = input[i].first;
		ll e = input[i].second;
		if (scc[s] == scc[e]) continue;
		sccv[scc[s]].push_back(scc[e]);
	}
	dp[scc[start]] = scccost[scc[start]]; // ���� scc �� ����
	go(scc[start]); // ����
	memset(chk, 0, sizeof(chk));
	for (ll i = 0; i < res.size(); i++) // ��������� ���� scc üũ!
		chk[scc[res[i]]] = 1;
	ll output = 0; // ��°�
	for (ll i = 0; i < cnt; i++) {
		if (!chk[i]) continue; // ����Ʈ�� ���� scc ����
		output = max(output, dp[i]); // �ִ밪
	}
	cout << output;
	return 0;
}