#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <cmath>


using namespace std;

typedef long long ll;

vector<ll> tree;
vector<ll> arr;






void init(int node, int start, int end)
{
    if(start==end)
    {
        tree[node] = arr[start];
        
    }else
    {
        int mid = (start+end)/2;
        init(2*node, start, mid);
        init(2*node+1, mid+1, end);
        tree[node] = tree[2*node]+tree[2*node+1];
    }
}


ll sum(int node, int start, int end, int left, int right)
{
    if(left>end || start>right) return 0;
    
    if(start>=left && right>=end) return tree[node];
    
    
     int mid = (start+end)/2;
     return sum(2*node, start, mid, left, right) + sum(2*node+1, mid+1, end, left, right);
}

ll sum2(int node, int start, int end, int left, ll value)
{
    if(start==end)
        return start;
    
    int mid = (start+end)/2;
    ll val = tree[2*node]-left;
    
    if(value>val)
       return sum2(2*node+1, mid+1, end, 0, value-val); 
    else
       return sum2(2*node, start, mid, left, value);
        
}

void update(int node ,int start, int end, int idx, ll value)
{
    if(idx>end || idx<start) return;
    tree[node]+=value;
    if(start!=end)
    {
        int mid = (start+end)/2;
        update(2*node, start, mid, idx, value);
        update(2*node+1, mid+1, end, idx, value);
      
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    
    arr.resize(n+1);
    for(int i=1;i<=n;i++)
        arr[i]=1;
    
    int h = 1<<static_cast<int>(ceil(log2(n)+1));
    tree.resize(h);
    init(1, 1, n);
    
    
    int cur = 1;
    int next  = k;
    cout<<"<";
    for(int i=0;i<n;i++)
    {
        int left = sum(1, 1, n, 1, cur-1);
        int right = sum(1, 1, n, cur, n);
        
        if(cur==1)
        {
            if(tree[1]<next)
            {
                next%=tree[1];
                if(next==0) next = tree[1];
                --i;
                continue;
            }
        }
        
        if(right<next)
        {
            next-=right;
            --i;
            cur=1;
            continue;
        }
        
        int sol = sum2(1, 1, n, left, max(next, 1));
        update(1, 1, n, sol, -1);
        if(i==n-1)
            cout<<sol<<">";
        else
            cout<<sol<<", ";
        
        cur = sol;
        next = k;
        
    }
    
    
   
    
    
    return 0;
    
}

/*
메모리 시간  

#include<stdio.h>
#define Max 100001
int N, K;

int segTree[Max * 4];
int SHIFT=1;

void makeSHIFT() {
	while (SHIFT < N)
		SHIFT <<= 1;
	SHIFT -= 1; //익숙해지자
}

void update(int dataIdx, int diff) {
	int nodeIdx = dataIdx + SHIFT;
	while (nodeIdx) {
		segTree[nodeIdx] += diff;
		nodeIdx >>= 1;
	}
}

int query(int nth) {
	int nodeIdx = 1;
	int nodeMax = (SHIFT + N)/2;
	if (segTree[nodeIdx] < nth) return -1;
	while (nodeIdx <= nodeMax) { //종료조건 : node가 leaf면 종료한다.
		int childLeft = nodeIdx <<1;
		int childRight = childLeft + 1;

		if (segTree[childLeft] < nth) {
			nth -= segTree[childLeft];
			nodeIdx = childRight;
		}
		else {
			nodeIdx = childLeft;
		}
	}
	return nodeIdx - SHIFT;
}


int main() {
	scanf("%d %d", &N, &K);
	makeSHIFT();
	for (int i = 1; i <= N; i++)
		update(i, 1);
	int jump = K;
	int n = N;
	printf("<");
	while (n) {
		if (jump > n) {
			jump %= n;
			if (jump == 0)jump = n;
		}

		int res = 0;
		res = query(jump);
		printf("%d", res);
		update(res, -1);

		jump += (K - 1);
		n--;
		if (n == 0)break;
		printf(", ");
	}
	printf(">");
	return 0;
}




























*/


