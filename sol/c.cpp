#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int char_to_int(char c) {
	return (int) c - (int) 'a';
}

int check_equal(int counts[26], int bcounts[26]) {
	for (int i = 0; i < 26; i++) {
		if (counts[i] != bcounts[i]) {
			return false;
		}
	}
	return true;
}

bool check(int counts[26], int len, string b) {
	// check if substring represented by count is in b
	int bcounts[26] = {0};
	for (int i = 0; i < len; i++) {
		int c = char_to_int(b[i]);
		bcounts[c]++;
	}
	if (check_equal(counts, bcounts)) {
		return true;
	}
	for (int j = len; j < b.size(); j++) {
		int newc = char_to_int(b[j]);
		bcounts[newc]++;
		int oldc = char_to_int(b[j - len]);
		bcounts[oldc]--;
		if (check_equal(counts, bcounts)) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	string trash;
	getline(cin, trash);
	for (int i = 0; i < n; i++) {
		string a, b;
		getline(cin, a);
		getline(cin, b);
		int counts[26] = {0};
		
		int start = 0;
		int end = 0;
		int bestlen = 0;
		int beststart = 0;
		int bestend = 0;
		printf("%i\n", check(counts, end - start, b));
		while (true) {
			if (check(counts, end - start, b)) {
				end++;
				counts[char_to_int(a[end - 1])]++;
				if (end - start > bestlen) {
					bestlen = end - start;
					beststart = start;
					bestend = end;
				}
				if (end >= a.size()) {
					break;
				}
			} else {
				start++;
				if (start > a.size()) {
					break;
				}
				counts[char_to_int(a[start - 1])]--;
			}
		}

		if (bestlen == 0) {
			printf("NONE\n");
		} else {
			cout << a.substr(beststart, bestend) << "\n";
		}
		/*
		for (char c : a) {
			counts[char_to_int(c)]++;
		}
		
		int cs[26] = {0};
		int start = 0;
		int end = 0;
		int bestlen = -1;
		int beststart = 0;
		int bestend = 0;
		while (end < b.size() && start < b.size()) {
			char c = b[end];
			int ci = char_to_int(c);
			cs[char_to_int(c)]++;
			if (cs[ci] > counts[ci]) {
				while (cs[ci] > counts[ci]) {
					char cstart = b[start];
					int cix = char_to_int(cstart);
					cs[cstart]--;
					start++;
				}
			}
			if (end - start > bestlen) {
				bestlen = end - start;
				beststart = start;
				bestend = end;
			}
			end++;
		}
		if (bestlen == -1) {
			printf("NONE\n");
		} else {
			printf(a.substr(
		}*/
	}
	
	
}
