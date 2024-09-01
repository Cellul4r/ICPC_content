// Lazy prop segtree, array type is T, lazy op is D
// 3 funcs: comb T, comb D, apply D to T (all assoc)
struct lseg {
	typedef ll T;
	typedef ll D;

	T idT = 0, t[2 * NN];
	D idD = 0, d[NN];
	ll n = NN;

	T f(T a, T b) { return a + b; }
	D g(D a, D b) { return a + b; }
	T h(D a, T b) { return a + b; }

	void apply(ll p, D v) {
		t[p] = h(v, t[p]);
		if(p < n) d[p] = g(v, d[p]);
	}

	void modify(ll p, T v = idT) {
		if(p < n) p += n, t[p] = v;
		while(p /= 2) t[p] = h(d[p], f(t[2 * p], t[2 * p + 1]));
	}

	void modify(ll l, ll r, D v) {
		ll l0 = (l += n), r0 = (r += n);
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) apply(l++, v);
			if(r & 1) apply(--r, v);
		}
		modify(l0), modify(r0-1);
	}

	void push(ll p) {
		for(ll s=26; --s; ) {
			ll i = p >> s;
			apply(2 * i, d[i]);
			apply(2 * i + 1, d[i]);
			d[i] = idD;
		}
	}

	T query(ll l, ll r) {
		l += n, r += n;
		push(l), push(r - 1);
		T resL = idT, resR = idT;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) resL = f(resL, t[l++]);
			if(r & 1) resR = f(t[--r], resR);
		}
		return f(resL, resR);
	}
}
