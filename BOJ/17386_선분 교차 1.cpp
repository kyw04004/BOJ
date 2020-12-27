#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll ax, bx, cx, dx, ay, by, cy, dy;
	cin >> ax >> ay >> bx >> by;
	cin >> cx >> cy >> dx >> dy;
	ll ccw1 = ax * by + bx * cy + cx * ay;
	ccw1 -= ay * bx + by * cx + cy * ax;
	ll ccw2 = ax * by + bx * dy + dx * ay;
	ccw2 -= ay * bx + by * dx + dy * ax;
	ll ccw3 = cx * dy + dx * ay + ax * cy;
	ccw3 -= cy * dx + dy * ax + ay * cx;
	ll ccw4 = cx * dy + dx * by + bx * cy;
	ccw4 -= cy * dx + dy * bx + by * cx;
	if (ccw1 > 0) ccw1 = 1;
	else if (ccw1 < 0) ccw1 = -1;
	if (ccw2 > 0) ccw2 = 1;
	else if (ccw2 < 0) ccw2 = -1;
	if (ccw3 > 0) ccw3 = 1;
	else if (ccw3 < 0) ccw3 = -1;
	if (ccw4 > 0) ccw4 = 1;
	else if (ccw4 < 0) ccw4 = -1;
	if (ccw1*ccw2 <= 0 && ccw3*ccw4 <= 0) cout << 1;
	else cout << 0;
	return 0;
}