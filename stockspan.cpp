#include "bits/stdc++.h"
#include <stack>
#include <vector>
using namespace std;

/*
Stock Span Problem
The span of the stock's price today is defined as
the maximum number of consecutive days (starting 
from today and going backwards) for which the price 
of the stocks was less than or equal to today's price.
Find the span of the stocks for all the days.
*/

vector<int> stockspan(vector<int> prices){
	vector<int> ans;
	stack<pair<int,int>> s;
	for(auto price : prices){
		int days = 1;
		while(!s.empty() and s.top().second <= price){
			days += s.top().first;
			s.pop();
		}
		s.push({days,price});
		ans.push_back(days);
	}
	return ans;
}

int main(){
	vector<int> arr = {100,80,60,70,60,75,85};
	vector<int> res = stockspan(arr);
	
	for(auto i : res)
		cout<<i<<" ";
	
	return 0;
}