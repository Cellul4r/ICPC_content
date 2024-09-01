struct seg {
    typedef ll T;
    T id=0;
    T f(T a, T b) {return a+b;}

    T t[2 * NN];
    ll n=NN;  // array size

    void modify(ll p, T value) {  // set value at position p
      for (p+=n, t[p] = value; p /= 2;) t[p] = f(t[2*p], t[2*p+1]);
    }

    T query(ll l, ll r) { // fold f on interval [l, r)
      T resl=id, resr=id;
      for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l&1) resl = f(resl, t[l++]);
        if (r&1) resr = f(t[--r], resr);
      }
      return f(resl, resr);
    }
}
