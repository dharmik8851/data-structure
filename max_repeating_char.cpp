#include<iostream>
#include<string>
using namespace std;

int main(){
	string s1 = "we are humans in ourlifewearemadebygod";
	int freq[26];
	
	for(int i=0; i<s1.size(); i++){
		freq[s1[i] - 'a'] = 0;
	}
	
	for(int i=0; i<s1.size(); i++){
		freq[s1[i] - 'a']++;
	}
	
	int max=0;
	char c;
	for(int i=0; i<s1.size(); i++){
		if(freq[s1[i] - 'a'] > max){
			max = freq[s1[i] - 'a'];
			c = s1[i];
		}
	}
	
	cout<<endl<<max<<" "<<c;
	return 0;
}