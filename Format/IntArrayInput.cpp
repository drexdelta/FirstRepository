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

bool comparator(int i , int j)
{
    return (i < j);
}
int main()
{
    int N,i ;
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a[100000];
    cin >> N;
    for(i=0;i<N;i++)
    {
        cin>>a[i];
    }
    ///sort(a,a+N,comparator);

    return 0;

}
