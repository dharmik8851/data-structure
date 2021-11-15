#include<iostream>
using namespace std;

//return fibonacci no at nth position
int fib(int n){
	int first;
	if(n == 0 || n == 1){
		return n;
	}
	else {
		return fib(n-1)+fib(n-2);	
	}
}

//check if array is sorted or not
bool checkSorted(int arr[], int n){
	if(n == 2){
		return arr[0]<arr[1];
	}
	return arr[0]<arr[1]&&checkSorted(arr+1,n-1);
}

//print numbers in increasing order
void incr(int n){
	if(n==1){
		cout<<"1 ";
		return;
	}
	incr(n-1);
	cout<<n<<" ";
}

//print numbers in increasing order
void dec(int n){
	if(n==1){
		cout<<"1 ";
		return;
	}
	cout<<n<<" ";
	dec(n-1);
}

//find first occerence of element 
int firstocc(int arr[], int n, int i, int key){
	if(arr[0] == key) return i;
	else if(n == 1)	return -1;
	return firstocc(arr+1, n-1, i+1, key);
}

//find last occerence of element 
int lastocc(int arr[], int n, int key){
	if(arr[n-1] == key) return n-1;
	else if(n == 1) return -1;
	return lastocc(arr,n-1,key);
}

//reverse a given string 
void revString(string str){
	if(str.length() == 0) return;
	revString(str.substr(1));
	cout<<str[0];
}

//replace pi with 3.14 in a given string
void replacePi(string s){
	if(s.length() == 0) return;
	if(s[0] == 'p' && s[1] == 'i'){
		cout<<"3.14";
		replacePi(s.substr(2));
	}else{
		cout<<s[0];
		replacePi(s.substr(1));
	}
}

//tower of honoi
void toh(int n,char src,char des,char helper){
	if(n == 0) return;
	
	//transfer n-1 rings from src to helper
	toh(n-1,src,helper,des);
	cout<<endl<<src<<" to "<<des;
	//transfer n-1 rings from helper to des
	toh(n-1,helper,des,src);
}

//remove all duplicate chars 
string removeDup(string s){
	if(s.length() == 0) return "";
	char ch = s[0];
	string str = removeDup(s.substr(1));
	if(ch == str[0]) return str;
	else return ch+str;
}

//move all 'x' to end
string moveallX(string s){
	if(s.length() == 0) return "";
	string ans = moveallX(s.substr(1));
	if(s[0] == 'x') return ans+s[0];
	else return s[0]+ans;
}

//print all substring
void subseq(string s, string ans){
	if(s.length() == 0) {
		cout<<endl<<ans; return;
	}
	char ch = s[0];
	subseq(s.substr(1), ans);
	subseq(s.substr(1), ans+" "+ch);
}

//print all substrings with ascii 
void subseqA(string s, string ans){
	if(s.length() == 0){
		cout<<endl<<ans;
		return;
	}
	char ch = s[0];
	int code = ch;
	subseqA(s.substr(1),ans);
	subseqA(s.substr(1),ans+ch);
	subseqA(s.substr(1),ans+to_string(code));
}

//print all possible words from phone digits
string arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string s, string ans){
	if(s.length() == 0){
		cout<<endl<<ans;
		return;
	}
	char ch = s[0];
	string code = arr[ch-'0'];
	string ros = s.substr(1);
	
	for(int i=0; i<code.length(); i++){
		keypad(ros,ans+code[i]);
	}
}
int main(){
	int n = 10;
	cout<<fib(n);
	
	int arr[n] = {8,5,9,8,7,6,2,6,7,5};
	cout<<endl<<checkSorted(arr,n);
	
	cout<<endl;
	dec(n);
	cout<<endl;
	incr(n);
	
	cout<<endl<<endl<<firstocc(arr,n,0,6);
	cout<<endl<<lastocc(arr,n,6);
	
	cout<<endl<<endl<<"binod -> "; revString("binod");
	
	cout<<endl<<endl;
	replacePi("patelpipppidharmikpi");
	
	//tower of henoi
	cout<<endl<<endl<<"tower of henoi";
	toh(3,'A','C','B');
	
	//remove duplicates in string chars
	cout<<endl<<endl;
	cout<<"aabbbcccddddd  -> "<<removeDup("aabbbcccddddd");
	
	//move all 'x' to end
	cout<<endl<<endl;
	cout<<"dhaxrmxixkx ->"<<moveallX("dhaxrmxixkx");
	
	//print all sub strings 
	cout<<endl<<endl<<"all substrings of 'ABC' -> "; subseq("ABC","empty");
	
	//print all sub strings with ascii 
	cout<<endl<<endl<<"all substrings of 'AB' with ascii -> "; subseqA("AB","empty ");
	
	//print all possible words from phone digits
	cout<<endl<<endl<<"all possible words from phone digits 2 and 3";
	keypad("23","");
	
	return 0;      

}