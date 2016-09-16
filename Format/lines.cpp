#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define FBO find_by_order
#define OOK order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

struct coOrdinate{
	double x;
	double y;
};
coOrdinate getPerpendicularBase(double a, double b , double c,double x, double y)
{
	coOrdinate answer;
	double divider = (a*a + b*b);
	answer.x = ( b * (b*x - a*y) - a*c)/divider;
	answer.y = ( a * ( (-b) * x  + a*y )  - b*c) /divider;
	return answer ;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0);
	coOrdinate v1,v2,perpendicular;
	cin >> v1.x >> v1.y;
	int debug;
	while(1)
	{
		
	cin >> v2.x >> v2.y;
	perpendicular = getPerpendicularBase(v1.y,-1*v1.x,0,v2.x,v2.y);
	
	cout << perpendicular.x << "  "  << perpendicular.y << endl;
	//cout << " DEBUG " << endl;
	///cin >> debug;
	}
    return 0;

}
