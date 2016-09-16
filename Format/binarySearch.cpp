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
int binarySearch(int *a,int key, int s,int e) /// simple binary search with no repeating values 
{
	if(s==e)
	{
		if(a[s] != key)
			return -1;
		else
			return s; 
	}
	int m = (s+e)/2;
	if(a[m] == key)
		return m;
	else
		if(a[m] > key)
			return binarySearch(a,key,s,m);
		else
			return binarySearch(a,key,m+1,e);
}
//binary search with repleating values , gives first occurence of 'key' in sorted array 
int firstOccurenceBinarySearch(int *a,int key,int s, int e)
{
	if(s==e)
	{
		if(a[s] != key)
			return -1;
		else
			return s;
	}
	int m = (s+e)/2;
	if(a[m] == key)
		return firstOccurenceBinarySearch(a,key,s,m);
	else
		if(a[m] > key)
			return firstOccurenceBinarySearch(a,key,s,m);
		else
			return firstOccurenceBinarySearch(a,key,m+1,e);
}

int lastOccurenceBinarySearch(int *a,int key,int size,int s,int e)
{
	if(s==e)
	{
		if(a[s] != key)
			return -1;
		else
			return s; 
	}
	int m = (s+e)/2;
	/*** point 1  starts **** */
	if(a[m] == key)             
	{
		if(m != size && a[m+1] == key)
			return lastOccurenceBinarySearch(a,key,size,m+1,e);
		else
			return m;
	}
	/** point 1 ends  **/
	else
		if(a[m] > key)
			return lastOccurenceBinarySearch(a,key,size,s,m);
		else
			return lastOccurenceBinarySearch(a,key,size,m+1,e);
}	

int bestFitBinarySearch(int *a , int key,int size , int s , int e) /// x,y are elements of array then x <= key <= y
															/// if the elements is present on array then returns first occurence 
{
	int m = (s+e)/2;
	if(m == 0)
	{
		if(a[m] > key)
			return -1;
		else
			return 0;
	}
	else if(m == size-1)
	{
		if(a[m] > key )
			return size-2;
		else
			return size-1;
	}
	else if(a[m] == key)
		return firstOccurenceBinarySearch(a,key,s,m); /// if we wan the last occurence of the key , then look at point one 
	else if(a[m] < key && a[m+1] > key)
		return m;
	else if(a[m] < key)
	{
		if(a[m+1] < key)
			return bestFitBinarySearch(a,key,size,m+1,e);
		else 
			return m+1;
	}
	else if(a[m] > key)
		return bestFitBinarySearch(a,key,size,s,m);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	int N,i,x;
    int a[100000];
    cin >> N;
    for(i=0;i<N;i++)
    {
        cin>>a[i];
    }
    sort(a,a+N,comparator);
    while(1)
	{
		cin >> x;
		cout << binarySearch(a,x,0,N-1)<<endl;
		cout << " first occurence " << firstOccurenceBinarySearch(a,x,0,N-1) << endl;
		cout << " last occurence " << lastOccurenceBinarySearch(a,x,N,0,N-1) << endl;
		cout << " best fit " << bestFitBinarySearch(a,x,N,0,N-1) << endl;
	}
    return 0;

}
