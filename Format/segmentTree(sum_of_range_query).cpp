#include<bits/stdc++.h>

using namespace std;

int *ST,L,R,*arr,N;

int generateSegmentTreeHelper(int s, int e,int index)
{
	//cout << " s " << s << " e " << e << " index " << index <<  endl;
	if(s == e)
	{
		//cout << " came here " << endl;
		ST[index] = arr[s];
	}
	else
	{
		int m = s + (e-s)/2;
		ST[index] = generateSegmentTreeHelper(s,m,index*2+1) + 
					generateSegmentTreeHelper(m+1,e,index*2+2);
	}
	return ST[index];
}

void generateSegmentTree()
{
	for(int i = 0 ; i < N;i++)
		cout << arr[i] << " " ;
	cout << " this is given array " << endl;
	int h = (int)(ceil(log2(N))); /// h = height  of the segment tree,
									 /// not including the last layer(leaf node layer)
	cout << " height "  << h << endl;
	int stSize = pow(2,h+1)-1;
	cout << " st size " << stSize << endl;
	ST = new int[stSize];
	generateSegmentTreeHelper(0,N-1,0);
}

int getSum(int s , int e , int index)
{
	if(L<=s && R>=e)
		return ST[index];
	if(L>e || R<s)
	{
		//cout << " s " << s << " e " << e << " index " << index << endl;
		//cout << " returning value " << 0 <<endl;
		return 0;
	}
	if(s==e)
	{
		//cout << " s " << s << " e " << e << " index " << index << endl;
		//cout << " returning value " << ST[index]<<endl;
		return ST[index];
	}
	int m = s + (e-s)/2;
	int answer =getSum(s,m,index*2+1) + getSum(m+1,e,index*2+2);
	//cout << " s " << s << " e " << e << " index " << index << endl;
	//cout << " returning value " << ST[index]<<endl;
	return answer;
}	


int update(int s, int e, int index)
{
	
	if(L>e || R<s)
	{
		//cout << " s " << s << " e " << e << " index " << index << endl;
		//cout << " returning value " << 0<<endl;
		return 0 ;
	}
	if(s==e)
	{
		//cout << " s " << s << " e " << e << " index " << index << endl;
		//cout << " returning value " << ST[index]<<endl;
		return (ST[index] = ST[index]*2)/2;
	}
	int m=s+(e-s)/2;
	int incr1,incr2;
	incr1 = update(s,m,index*2+1);
	incr2 = update(m+1,e,index*2+2);
	ST[index] = ST[index]+incr1+incr2;
	return incr1+incr2;
}
	
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	arr = new int[N];
	for(int i = 0 ; i < N ;i++)
		cin >> arr[i];
	cout << " input taken " << endl;
	generateSegmentTree();
	cout << "generation done " << endl;
	int stSize = pow(2,(ceil(log2(N)))+1)-1;
	cout << endl;
	for(int i = 0 ; i < stSize ; i++)
		cout << i << " :: " <<  ST[i] << endl;
	cout << endl;
	int type ;
	while(1)
	{
		cin>> type >> L >> R;
		L--;R--;
		if(type == 1)
			cout << " output is  : " << getSum(0,N-1,0)<<endl;
		else if(type == 0)
		{
			update(0,N-1,0);
			for(int i = 0 ; i < stSize ; i++)
				cout << i << " :: " <<  ST[i] << endl;
		}
	}
	return 0;
}
