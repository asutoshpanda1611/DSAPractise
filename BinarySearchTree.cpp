#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int value){
			data=value;
			left=NULL;
			right=NULL;
		}
};

Node* createBST(Node* root,int data){
	if(!root){
		return new Node(data);
	}		
	else if(data<root->data){		
		if(!root->left){
			cout<<"Left child of"<<root->data<<"is"<<data<<endl;
		}		
		root->left=createBST(root->left,data);
	} 
	else{	
		if(!root->right){
			cout<<"Right child of"<<root->data<<"is"<<data<<endl;
		}	
		root->right=createBST(root->right,data);	
	}       
	return root;
}

void inorder(Node* root,vector<int>&v){
	if(!root) return;
	inorder(root->left,v);
	//cout<<root->data<<" ";
	v.push_back(root->data);
	inorder(root->right,v);
}

void minvalue(Node* root){
	if(!root) return;
	Node* temp=root;
	while(temp->left){
		temp=temp->left;
	}
	cout<<temp->data;
}

Node* maxvalue(Node* root){
	if(!root) return NULL;
	Node* temp=root;
	while(temp->right){
		temp=temp->right;
	}
	return temp;
}

bool searchBST(Node* root,int target){
	if(!root) return false;
	
	bool l=false,r=false;
	if(root->data==target) return true;	
	if(target>root->data){
		r=searchBST(root->right,target);
	}
	else{
		l=searchBST(root->left,target);
	}
	return l||r;	
}

Node* deleteNode(Node* root,int target){
	if(!root) return  NULL; 
	if(root->data==target){
		//4 cases
		if(!root->left && !root->right){
			//deleting leaf nodes
			delete root;
			return NULL;
		}
		else if(root->left && !root->right){
			Node* temp=root->left;
			delete root;
			return temp;
		}
		else if(!root->left && root->right){
			Node* temp=root->right;
			delete root;
			return temp;
		}
		else{
			//node with 2 childs
			Node* maxi=maxvalue(root->left);
			root->data=maxi->data;
			root->left=deleteNode(root->left,maxi->data);
			return root;			
		}
	}   
	else if(root->data>target){
		root->left=deleteNode(root->left,target);
	}
	else{
		root->right=deleteNode(root->right,target);
	}
	return root;                                                             
}

Node* BSTfromInorder(int in[],int s, int e){
	if(s>e) return NULL;
	int mid=(s+e)/2;
	int ele=in[mid];
	
	Node* root=new Node(ele);
	root->left=BSTfromInorder(in,s,mid-1);
	root->right=BSTfromInorder(in,mid+1,e);
	return root;
}

bool isValidBST(Node* root,long mini=LONG_MIN, long maxi=LONG_MAX){
	if(!root) return true;
	if(root->data <= mini || root->data >= maxi){
		return false;
	}
	return isValidBST(root->left,mini,root->data) &&
	       isValidBST(root->right,root->data,maxi);
}

Node* LCAinBST(Node* root,int p,int q){
	if(!root) return NULL;
	if(p< root->data  && q< root->data){
		return LCAinBST(root->left,p,q);
	}
	if(p> root->data && q> root->data){
		return LCAinBST(root->right,p,q);
	}
	return root;
}

int KthSmallestEle(Node* root,int k,vector<int>v){
	return v[--k];
}

bool TwoSumIV(Node* root,vector<int>v,int k){
	int s=0;
	int e=v.size()-1;
	int mid=(s+e)/2;
	
	while(s<e){
		int sum=v[s]+v[e];
		if(sum==k) return true;
		else if(sum>k) e--;
		else if(sum<k) s++;
	}
	return false;
}

//SORTED BST INTO DLL
Node* sortedBSTtoDLL(vector<int>&v){
	if(v.empty())return NULL;
	
	Node* head=new Node(v[0]);
	Node* prev=head;
	
	for(int i=1;i<v.size();i++){
		Node* curr=new Node(v[i]);
		prev->right=curr;
		curr->left=prev;
		prev=curr;
	}
	return head;
}

void printDLL(Node* head){
	while(head){
		cout<<head->data<<"<->";
		head=head->right;
	}
	cout<<"NULL"<<endl;
	
}

//SORTED DLL INTO BST

//iterate DLL and push into a vector then use 
//BSTfromInorder func to create BST

int main(){
	Node* root=NULL;
	while(1){
		int data;
		cin>>data;
		if(data==-1) break;
		root=createBST(root,data);
	}
	
	vector<int>v;
	//minvalue(root);
	//bool x=searchBST(root,56);
	//cout<<x;
	//root=deleteNode(root,50);
	// int in[]={10,20,30,40,50,60,70};
	// int size=7;
	// int s=0;
	// root=BSTfromInorder(in,s,size-1);
	// bool x=isValidBST(root,LONG_MIN,LONG_MAX);
	// cout<<x<<endl;
	//root=LCAinBST(root,70,300);
	//cout<<root->data<<endl;
	inorder(root,v);
	// int sm=KthSmallestEle(root,4,v);
	// cout<<sm<<endl;
	// bool x=TwoSumIV(root,v,400);
	// cout<<x<<endl;
	root=sortedBSTtoDLL(v);
	printDLL(root);
	//for(int i:v) cout<<i<<" ";
}

//use Input: 100 50 200 30 70 120 300 -1
