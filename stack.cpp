#include<bits/stdc++.h>
using namespace std;

class stack1{
	int *arr;
	int size;
	int top;

	public:	
		stack1(int size){
			arr=new int[size];
			this->size=size;
			this->top=-1;
		}	
		void push(int data){
			top++;
			arr[top]=data;
		}	
		void pop(){
			top--;
		}	
		bool isempty(){
			if(top==-1) return true;
			else return false;
		}
		int getTop(){
			if(top==-1) return -1;
			else return arr[top];
		}
		int getsize(){
			return top+1;
		}			
};

int midElementinStack(stack<int>st){
	int size=st.size();
	int pos=0;
	if(!size) return -1;
	else{		
		if(size&1){
			pos=size/2 +1;
		}
		else{
			pos=size/2;
		}
	}
	for(int i=0;i<pos-1;i++){
		st.pop();
	}
	return st.top();
}

void insertAtBottom(stack<int>&st,int data){
	if(st.empty()){
		st.push(data);
		return;
	}
	int temp=st.top();
	st.pop();
	insertAtBottom(st,data);
	st.push(temp);	
}
void insertSorted(stack<int>&st,int temp){
	if(st.empty()||st.top()<temp){
		st.push(temp);
		return;
	}
	int ele=st.top();
	st.pop();
	insertSorted(st,temp);
	st.push(ele);
}
void sortstack(stack<int>&st){
	if(st.empty()) return;
	int temp=st.top();
	st.pop();
	sortstack(st);
	insertSorted(st,temp);
}
bool validString(string s){
	stack<char>st;
	for(int i=0;i<s.length();i++){
		stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') { 
                st.push(c); 
            } 
            else { 
                if (st.empty() || 
                    (c == ')' && st.top() != '(') || 
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false; 
                }
                st.pop(); 
            }
        }
        if(st.empty()) return true;
        else return false;
}
bool redundantBrackets(string s){
	stack<char>st;
	for(auto c:s){
		if(c==')'){
			int opcount=0;
			while(!st.empty() && st.top()!='('){
				char t=st.top();
				st.pop();
				if(t=='+'||t=='-'||t=='*'||t=='/'){
                    opcount++;
                }
			}
			if(!st.empty()) st.pop();
			if(opcount==0) return true;
		}
		else{
			st.push(c);
		}
	}
	return false;
}
void nextSmallerEle(vector<int>&v){
	int n=v.size();
    vector<int>res(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
    	while(!st.empty() && st.top()>=v[i]){
    		st.pop();
    	}
    	res[i]=st.empty()?-1:st.top();
    	st.push(v[i]);
    }
    for(auto i:res)cout<<i<<endl;
}
int main(){
	// stack1 s(3);
	// s.push(6);
	// s.push(4);
	// s.push(7);
	// int t=s.getTop();
	// cout<<t;
	
	stack<int>s;
	s.push(7);
	s.push(4);
	s.push(8);
	s.push(2);
	//int mid=midElementinStack(s);
	//cout<<mid;
	//insertAtBottom(s,10);	
	//sortstack(s);
	//string si="((a*b)+(c))";
	//int c=redundantBrackets(si);
	//int c=validString(si);
	//cout<<c;
	// while(!s.empty()){
		// cout<<s.top()<<endl;
		// s.pop();
	// }
	
	vector<int>v({7,4,6,9,2});
	nextSmallerEle(v);
	
}




