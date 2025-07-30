#include <bits/stdc++.h>
using namespace std;

// class stack{
	// public:
		// int *arr;
		// int size;
		// int top;
// 		
		// stack(int size){
			// this->size=size;
			// arr=new int[size];
			// top=-1;
		// }
// 		
		// void print(){
			// for(int i=top;i>=0;i--){
				// cout<<arr[i]<<endl;
			// }
		// }
// 		
		// void push(int data){
			// top++;
			// arr[top]=data;
		// }
// 		
		// void pop(){
			// top--;
		// }
// };
 

int stackLen(stack<int>st){
	int cnt=0;
	while(!st.empty()){
		cnt++;
		st.pop();
	}
	return cnt;
}

void midEleInStack(stack<int>st),int &pos,int &ans{
	int len=stackLen(st);
	int mid=len/2;
	int temp=st.top();
	st.pop()
	mid
}

int main(){
	int n;cin>>n;
	stack<int>st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	midEleInStack(st);
}


