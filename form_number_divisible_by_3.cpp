#include<iostream>
#include<vector>
using namespace std;

void formNumberDivBy3(vector<int> v, int k){
	pair<int, int> ans;
	bool found=false; int sum=0;

	for(int i=0; i<k; i++) sum+=v[i];

	if(sum%3 == 0){
		found=true;
		ans = make_pair(0,k-1);
	}

	for(int i=k; i<v.size(); i++){
		if(found) break;

		sum = sum+v[i]-v[i-k];
		if(sum%3==0){
			found=true;
			ans=make_pair(i-k+1, i);
		}
	}

	if(!found) ans=make_pair(-1,0);

	if(ans.first==-1) cout<<"No such subarray exist";
	else {
		for(int i=ans.first; i<=ans.second; i++){
			cout<<v[i]<<" ";
		}
	}
}

int main(){
	vector<int> arr = {84,23,45,12,56,82};
	int k=3;

	formNumberDivBy3(arr,k);

	return 0;
}