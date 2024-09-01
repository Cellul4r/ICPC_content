//geometry header
typedef complex<ld> Point;
#define x() real()
#define y() imag()
#define cross(a, b) ((conj(a)*(b)).y())
#define dot(a, b) ((conj(a)*(b)).x())
struct Line {
  Point P;
  Point D;

  // Direct constructor
  Line (Point a, Point b, bool q) : P(a), D(b){}

  // Two points
  Line (Point a, Point b) : P(a), D(b-a){}

  // Point and angle
  Line (Point a, ld theta) : P(a), D(polar(1.l, theta)){}
};
//convex hull
vector<Point> P;
vector<Point> HU, HD;

sort(P.begin(), P.end(), [](Point &a, Point &b) {return a.x()==b.x() ? a.y()<b.y() : a.x()<b.x();});
#define do_hull(H) for (auto p:P) {while (H.size() >= 2 && cross(H.back()-H[H.size()-2], p-H[H.size()-2]) <= 0) H.pop_back();H.push_back(p);}
do_hull(HD);
reverse(P.begin(), P.end());
do_hull(HU);
