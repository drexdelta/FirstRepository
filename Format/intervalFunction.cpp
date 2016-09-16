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

struct intervalNode
{
	int l;
	int r;
	intervalNode()
	{
		l=r=-1;
	}
};

intervalNode *getInterval(int l1,int r1,int l2,int r2) /// here l1 <= r1 && l2 <= r2 
{
	intervalNode *tempIntervalNode = new intervalNode;
	if(l2 >= l1 && l2 <= r1)
	{
		if(r2 < r1)
		{
			tempIntervalNode->l = l2;
			tempIntervalNode->r = r2;
		}
		else
		{
			tempIntervalNode->l = l2;
			tempIntervalNode->r = r1;
		}
		return tempIntervalNode;
	}
	else if(l1 >= l2 && l1 <= r2)
	{
		if(r1 < r2)
		{
			tempIntervalNode->l = l1;
			tempIntervalNode->r = r1;
		}
		else
		{
			tempIntervalNode->l = l1;
			tempIntervalNode->r = r2;
		}
		return tempIntervalNode;
	}
	else
		return tempIntervalNode;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T,l1,l2,r1,r2;
    intervalNode *tempIntervalNode;
    cin >> T;
    while(T--)
    {
        cin >> l1>>r1>>l2>>r2;
        tempIntervalNode = getInterval(l1,r1,l2,r2);
        if(tempIntervalNode->l == -1)
			cout <<" no overlapping interval" << endl;
		else
			cout <<" start " << tempIntervalNode->l << " end :: " << tempIntervalNode->r<< endl;
    }
    int N;
    cin >>N;



    return 0;
}
