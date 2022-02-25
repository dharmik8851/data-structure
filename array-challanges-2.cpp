#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter size of your array -> "; cin>>n;
	int a[n],currSum[n+1];
	currSum[0] = 0;
	
	//taking n inputs from user
	//finding cumulative sum and storing it into currSum array
	for(int i=0; i<n; i++){
		cin>>a[i];
		currSum[i+1]=a[i]+currSum[i];
	}
	
	//find subarray index i and j where sum of elemets between i and j is equal to s.
	int s;
	cout<<endl<<"Enter sum of subarray you want to find -> "; cin>>s;
	int i=0,j=0,sum=0;
	while(j<n && sum+a[j] <= s){
		sum += a[j];
		j++;
	}
	if(sum == s){
		cout<<"sum found at index -> "<<i+1<<" "<<j;
	}else{
	while(j<n){
		sum += a[j];
		while(sum > s){
			sum -= a[i];
			i++;
		}
		if(sum == s){
			cout<<"sum found at index -> "<<i+1<<" "<<j+1;
			break;
		}
		j++;
	}
	}
	
	//find smallest positive number missing from array;
	const int N = 1e6+2;
	bool check[N];
	for(int i=0; i<N; i++){
		check[i] = false;
	}
	for(int i=0; i<n; i++){
		if(a[i] >= 0){
			check[a[i]] = true;
		}
	}
	int ans = -1;
	for(int i=1; i<N; i++){
		if(check[i] == false){
			ans = i; break;
		}
	}
	cout<<endl<<endl<<"find smallest positive number missing from array";
	cout<<endl<<"your answer is -> "<<ans;
	
	//print all possible subarrays find maximum subarray sum
	int maxSum = INT_MIN;
	int TC = 0;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int sum = 0;
			for(int k=i; k<=j; k++){
				sum += a[k];
				TC++;
			}
			maxSum = max(maxSum,sum);
		}
	}
	cout<<endl<<"\nmaximum subarray sum is -> "<<maxSum;
	cout<<endl<<"time complexity is -> "<<TC<<" times second inner loop executes";
	
	//optimization in 'print all possible subarrays find maximum subarray sum'
	int maxSum2,sum2,TC2;
	cout<<endl<<"cumulative sum of array -> ";
	for(int i=0; i<=n; i++){
		cout<<currSum[i]<<" ";
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<i; j++){
			sum2 = currSum[i]-currSum[j];
			maxSum2=max(maxSum2,sum2);
			TC2++;
		}
	}
	cout<<endl<<"\nmaximum subarray sum is -> "<<maxSum2;
	cout<<endl<<"time complexity is -> "<<TC2<<" times second inner loop executes";
	
	//kadane algorithm for upper question
	int currentSum=0,maxSum3=INT_MIN,TC3=0;
	for(int i=0; i<n; i++){
		currentSum+=a[i];
		if(currentSum<0){
			currentSum=0;
		}
		maxSum3=max(currentSum,maxSum3);
		TC3++;
	}
	cout<<endl<<"\nmaximum subarray sum is -> "<<maxSum3;
	cout<<endl<<"time complexity is -> "<<TC3<<" times second inner loop executes";
	
	return 0;
}