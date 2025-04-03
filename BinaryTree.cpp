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

Node* createTree(){
	int data;
	cin>>data;
	
	if(data==-1) return NULL;
	
	Node* root=new Node(data);
	
	root->left=createTree();
	if (root->left) 
        cout << "Left child of " << root->data << " is " << root->left->data << endl;
		
	root->right=createTree();
	if (root->right) 
        cout << "Right child of " << root->data << " is " << root->right->data << endl;

	return root;
}

void preOrder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<endl;
	preOrder(root->left);
	preOrder(root->right);
}

void BFS(Node* root){
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		Node* front = q.front();
		q.pop();
		cout<<front->data<<endl;
		
		if(front->left!=NULL){
			q.push(front->left);
		}
		if(front->right!=NULL){
			q.push(front->right);
		}
	}
}

void heightByBFS(Node* root){
	queue<Node*>q;
	q.push(root);
	int cnt=0;
	
	while(!q.empty()){
				
		for(int i=0;i<q.size();i++){
			Node* front = q.front();
			q.pop();
			
			if(front->left!=NULL){
				q.push(front->left);
			}
			if(front->right!=NULL){
				q.push(front->right);
			}
		}		
		cnt++;
	}
	cout<<"height:"<<cnt<<endl;
}

int height(Node* root){
	if(root==NULL){
		return 0;
	}
	int lefth = height(root->left);
	int righth = height(root->right);
	return max(lefth,righth)+1;
}


int diameterOfBT(Node* root){
	if(root==NULL){
		return 0;
	}
	int lefth = diameterOfBT(root->left);
	int righth = diameterOfBT(root->right);
	int both = height(root->left) + height(root->right);
	return max(lefth,max(righth,both));
}

bool isheightBalanced(Node* root,int &height){
	if(root==NULL){
		height=0;
		return true;
	}
	
	int l=0,r=0;
	bool lf = isheightBalanced(root->left,l);
	bool rh = isheightBalanced(root->right,r);
	height=max(l,r)+1;
	
	if(abs(l-r)>1){
		return false;
	}
	return lf && rh;
}

bool htBalance(Node* root){
	int height=0;
	return isheightBalanced(root,height);
}

void BFSLevelWise(Node* root){
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while(q.size()>1){
		Node* front = q.front();
		q.pop();
		if(front==NULL){
			cout<<endl;
			q.push(NULL);
		}
		else{
			cout<<front->data<<" ";	
			if(front->left!=NULL){
				q.push(front->left);
			}
			if(front->right!=NULL){
				q.push(front->right);
			}
		}
		
	}
	cout<<endl;
}

Node* LCA(Node* root,int p,int q){
	if(root==NULL) return NULL;
	if(root->data==p || root->data==q){
		return root;
	}
	
	Node* lefts = LCA(root->left,p,q);
	Node* rights = LCA(root->right,p,q);
	
	if(lefts && rights) return root;
	return (lefts!=NULL)? lefts:rights;
}

bool pathsum(Node* root,int target){
	if(!root) return false;
	if(root->left==NULL && root->right==NULL){
		//return target==root->data;
		if(target==root->data) return true;
		else return false;
	}
	
	return pathsum(root->left,target- root->data ) ||
		pathsum(root->right,target- root->data);
}

searchInInorder(int in[],int size,int target){
	for(int i=0;i<size;i++){
		if(in[i]==target){
			return i;
		}
	}
	return -1;
}

Node* constructTreefromInPre(int pre[],int in[],int &preindex,int instart,int inend,int size){
	if(preindex>=size || instart>inend){
		return NULL;
	}
	int ele=pre[preindex];
	preindex++;
	Node* root=new Node(ele);
	
	int pos = searchInInorder(in,size,ele);
	root->left=constructTreefromInPre(pre,in,preindex,instart,pos-1,size);
	root->right=constructTreefromInPre(pre,in,preindex,pos+1,inend,size);
	return root;
}

//VIEWS IN A TREE
void printLeftView(Node* root,int level,vector<int>&leftview){
	if(!root) return;
	if(level==leftview.size()){
		leftview.push_back(root->data);
	}
	printLeftView(root->left,level+1,leftview);
	printLeftView(root->right,level+1,leftview);
}

void printRightView(Node* root,int level,vector<int>&rightview){
	if(!root) return;
	if(level==rightview.size()){
		rightview.push_back(root->data);
	}
	printRightView(root->right,level+1,rightview);
	printRightView(root->left,level+1,rightview);	
}

void printTopView(Node* root){
	map<int,int>mapi;
	queue<pair<Node*,int>>q;
	q.push({root,0});
	
	while(!q.empty()){
		pair<Node*,int>temp=q.front();
		q.pop();
		Node* fnt=temp.first;
		int t=temp.second;
		
		if(mapi.find(t)==mapi.end()){
			mapi[t]=fnt->data;
		}
		if(fnt->left!=NULL){
			q.push({fnt->left,t-1});
		}
		if(fnt->right!=NULL){
			q.push({fnt->right,t+1});
		}
	}
	for(auto i:mapi){
		cout<<i.second<<" ";
	}
}

void printBottomView(Node* root){
	map<int,int>mapi;
	queue<pair<Node*,int>>q;
	q.push({root,0});
	
	while(!q.empty()){
		pair<Node*,int>temp=q.front();
		q.pop();
		Node* fnt=temp.first;
		int t=temp.second;
				
		mapi[t]=fnt->data;	
		if(fnt->left!=NULL){
			q.push({fnt->left,t-1});
		}
		if(fnt->right!=NULL){
			q.push({fnt->right,t+1});
		}
	}
	for(auto i:mapi){
		cout<<i.second<<" ";
	}
}

//BOUNDARY TRAVERSAL
void printLeftBndry(Node* root){
	if(!root) return;
	if(root->left==NULL && root->right==NULL){
		return;
	}
	cout<<root->data;
	if(root->left!=NULL){
		printLeftBndry(root->left);
	}
	else{
		printLeftBndry(root->right);
	}
}

void printRightBndry(Node* root){
	if(!root) return;
	if(root->left==NULL && root->right==NULL){
		return;
	}
	cout<<root->data;
	if(root->right!=NULL){
		printRightBndry(root->right);
	}
	else{
		printRightBndry(root->left);
	}
}

void printLeafBndry(Node* root){
	if(!root) return;
	if(root->left==NULL && root->right==NULL){
		cout<<root->data;
	}
	printLeafBndry(root->left);
	printLeafBndry(root->right);
}

void Boundary(Node* root){
	if(!root) return;
	cout<<root->data;
	printLeftBndry(root->left);
	printLeafBndry(root->left);
	printLeafBndry(root->right);
	printRightBndry(root->right);
}


int main(){
	Node* root=createTree();
	//preOrder(root);
	//BFS(root);
	//heightByBFS(root);
	//int h=height(root);
	//int h=diameterOfBT(root);
	//bool h = htBalance(root);
	 //BFSLevelWise(root);
	// Node* h = LCA(root,6,2);
	// cout<<"LCA:"<<h->data<<endl;
	//bool s=pathsum(root,10);
	//cout<<s<<endl;
	
	// int preorder[] = {2,8,10,6,4,12};
    // int inorder[] = {10,8,6,2,4,12};
    // int size=6;     
    // int preindex = 0;
    // Node* root1 = constructTreefromInPre(preorder,inorder,preindex,0,size-1,size);
	//BFSLevelWise(root);
	// vector<int>rightview;
	// printRightView(root,0,rightview);
	// for(auto i:rightview){
		// cout<<i<<" ";
	// }
	//printTopView(root);
	//printBottomView(root);
	Boundary(root);
	cout<<"root:"<<root->data<<endl;	
	
}