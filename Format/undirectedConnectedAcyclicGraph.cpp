#include<bits/stdc++.h>
using namespace std;

struct link{
	int x;
	link *next;
};

struct node{
	int x;
	int level;
	int visited;
	int color;
	int nodeNumber;
	link *l;
	node *next;
	
	
	node()
	{
		x=0;
		level=0;
		l=0;
		next=0;
		color=0;
		visited=0;
		nodeNumber=0;
	}
};

void addEdge(node *G,int u,int v)
{
	link *temp=new link;
	temp->x=v;
	temp->next=G[u].l;
	G[u].l=temp;
	temp = new link;
	temp->x=u;
	temp->next=G[v].l;
	G[v].l=temp;
	return;
}

void printGraph(node *G,int V)
{
	int *visited = new int[V];
	node *tempNode;link *tempLink;
	stack<node *> stk;
	visited[0]=1;
	stk.push(&G[0]);
	while(!stk.empty())
	{
		tempNode = stk.top();
		stk.pop();
		tempLink = tempNode->l;
		while(tempLink != 0)
		{
			if(visited[tempLink->x]==0)
			{
				visited[tempLink->x]=1;
				stk.push(&G[tempLink->x]);
			}
			cout << "node " << tempNode->nodeNumber << " is conctd to " << tempLink->x << endl;
			tempLink = tempLink->next;
		}
	}
	return;
}	

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T,N,u,v;
	cin >> N;
	node *G = new node[N];
	for(int i=0;i<N;i++)
		G[i].nodeNumber = i;
	for(int i=0;i<N-1;i++)
	{
		cin >> u >> v;
		addEdge(G,u,v);
	}
	printGraph(G,N);
	return 0;
}
	
