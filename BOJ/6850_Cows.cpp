#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
int n, sum;
vector <int> s;
struct Dot {
	int x;
	int y;
}dot[10005];
int ccw(Dot a, Dot b, Dot c) {
	int x = a.x*b.y + b.x*c.y + c.x*a.y;
	x -= a.y*b.x + b.y*c.x + c.y*a.x;
	return x;
}
bool compare(Dot a, Dot b) {
	int com = ccw(dot[0],a,b);
	if (com != 0) return com > 0 ? true : false;
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> dot[0].x >> dot[0].y;
	for (int i = 1; i < n; i++) {
		cin >> dot[i].x >> dot[i].y;
		if (dot[0].y > dot[i].y) swap(dot[0], dot[i]);
		else if (dot[0].y == dot[i].y && dot[0].x > dot[i].x) swap(dot[0], dot[i]);
	}
	sort(dot+1, dot+n, compare);
	s.push_back(0); s.push_back(1);
	int idx = 2;
	while (idx < n) {
		while (s.size() >= 2 && ccw(dot[s[s.size()-2]], dot[s[s.size() - 1]], dot[idx]) <= 0)
			s.pop_back();
		s.push_back(idx++);
	}
	for (int i = 1; i < s.size()-1; i++) {
		int area = ccw(dot[s[0]], dot[s[i]], dot[s[i + 1]]);
		sum += area;
	}
	cout << abs(sum)/100;
	return 0;
}