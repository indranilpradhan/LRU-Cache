#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class lru
{
	
	long long int s;
	long long int len =0;
	list<pair<T1, T2> > ls;
public:
	lru(long long int a)
	{
		s =a;		
	}
	
	T2 get(T1 key)
	{
		if(ls.size() == 0)
		{
			throw -1;
		}
			
		else
		{
			for(typename list<pair<T1,T2> >::iterator it = ls.begin();it!=ls.end();it++)
			{
				if((*it).first == key)
				{
					T2 val = (*it).second;
					T1 k = (*it).first;
					ls.erase(it);
					ls.push_back(make_pair(k,val));
					return val;
				}
			}
			throw -1;
		}
	}
	
	void set(T1 key,T2 value)
	{
		int flag = 0;
		for(typename list<pair<T1,T2> >::iterator it = ls.begin(); it!=ls.end(); it++)
		{
			if((*it).first == key)
			{
				flag = 1;
				ls.erase(it);
				ls.push_back(make_pair((*it).first,value));
			}
		}
		if(flag == 0)
		{
			if(ls.size() == s)
			{
				ls.pop_front();
				ls.push_back(make_pair(key,value));
			}
			if(ls.size()<s)
			{
				ls.push_back(make_pair(key,value));
			}
		}
	}
	
	void display()
	{
		for(typename list<pair<T1,T2> >::iterator it = ls.begin(); it!=ls.end(); it++)
		{
			cout<<(*it).first<<" "<<(*it).second<<" ";
		}
	}
};

int main()
{
		int n;
		cin>>n;
		lru<int,int> lr(n);
		int t;
		cin>>t;
		while(t--)
		{
			char q;
			cin>>q;
			if(q=='G')
			{
				try
				{
					int key;
					cin>>key;
					cout<<lr.get(key)<<endl;
				}
				catch(int ex)
				{
					cout<<ex<<endl;
				}
			}
			if(q=='S')
			{
				int key1;
				cin>>key1;
				int value;
				cin>>value;
				lr.set(key1,value);
			}				
		}
	return 0;
}
