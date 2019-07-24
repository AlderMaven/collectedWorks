//Created by Brandon Barnes

#include <iostream>
#include <algorithm>


using namespace std;

class Node;


class Node{
	int data;
    Node* right;
    Node* left;
    
public:
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
	
	Node* getLeft(){
		return this->left;
	}
	Node* getRight(){
		return this->right;
	}
	int getData(){
		return this->data;
	}
	void setLeft(Node* newLeft){
		this->left=newLeft;
	}
	void setRight(Node* newRight){
		this->right=newRight;
	}
	void setData(int newData){
		this->data=newData;
	}
	
};


int treeHeight(Node* root){
	if(root == NULL){
		return 0;
	}
	else{
		return 1 + max(treeHeight(root->getLeft()), treeHeight(root->getRight()));
	}
	
}


int main(){
	Node root = Node(5);
	
	
	Node* temp = new Node(4);
	root.setLeft(temp);
	
	
	temp = new Node(10);
	root.setRight(temp);
	
	
	temp = new Node(6);
	root.getLeft()->setRight(temp);
	
	
	cout << treeHeight(&root) << endl;
	
	
	
	return 0;
}