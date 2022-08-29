#include <bits/stdc++.h>
using namespace std;
#define Max 51
int n,m;
int a[Max][Max];
int lenghrow[Max];
int lenghcol[Max];
int S[Max][Max];

void input() {
	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
}

void Solve() {
	for(int i = 1; i <= n; i++) {
		lenghrow[i] = m;
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 0) {
				lenghrow[i] = j - 1;
				break;
			}
		}
		//cout << "lenghrow[" << i << "] = " << lenghrow[i] << endl;
	}
	
	for(int j = 1; j <= m; j++) {
		lenghcol[j] = n;
		for(int i = 1; i <= n; i++){
			if(a[i][j] == 0) {
				lenghcol[j] = i - 1;
				break;
			}
		}
		//cout << "lenghcol[" << j << "] = " << lenghcol[j] << endl;
	}
	int ans = 1;
	for(int i = 1; i <= lenghcol[1]; i++) {
		int arc = 1e9;
		for(int j = 1; j <= i ; j++){
			arc = min(arc,lenghrow[j]);
		}
		//cout << "arc = " << arc << endl;
		ans = max(arc * i, ans);
		//cout << "ans = " << ans << endl;
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	input();
	Solve();
	return 0;
}