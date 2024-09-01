// invariant binary search
ll l = -1; //value that always works
ll r = n; //value that never works
while (r-l > 1) {
	ll m = (l+r)/2;

	if (f(m))
	    l = m;
	else
	    r = m;
} // ans is now l
