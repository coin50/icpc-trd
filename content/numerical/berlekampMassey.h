/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: Wikipedia
 * Description: Recovers any $n$-order linear recurrence relation from the first
 * $2n$ terms of the recurrence.
 * Useful for guessing linear recurrences after brute-forcing the first terms.
 * Should work on any field, but numerical stability for floats is not guaranteed.
 * Output will have size $\le n$.
 * Usage: berlekampMassey({0, 1, 1, 3, 5, 11}) // {1, 2}
 * Time: O(N^2)
 * Status: bruteforce-tested mod 5 for n <= 5 and all s
 */

//type p0w first

vector<ll> berlekampMassey(vector<ll> s) {
	int n = s.size(), L = 0, m = 0;
	vector<ll> C(n), B(n), T;
	C[0] = B[0] = 1;

	ll b = 1;
	for( int i = 0; i < n; i++ ) { ++m;
		ll d = s[i]%MOD;
        for( int j = 1; j <= L; j++ ) d = (d + C[j] * s[i - j])%MOD;
		if (!d) continue;
		T = C; ll coef = d*p0w(b, MOD-2)%MOD;
        for( int j = m; j < n; j++ ) C[j] = (C[j] - coef * B[j - m])%MOD;
		if (2*L > i) continue;
		L = i + 1 - L; B = T; b = d; m = 0;
	}

	C.resize(L+1); C.erase(C.begin());
	for (ll& x : C) x = (MOD - x)%MOD;
	return C;
}