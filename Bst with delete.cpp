//Programme for implementation of Binary Search Tree
#include<iostream>
using namespace std;

//Defining the structure of the node in the programme
 struct node
    {
        int data;
        node* left;
        node* right;
        node* parent;
    };

//Class for Binary Search Tree
class BST
{
   public:

    node* root;
    
    //Function for inserting a node
    node* insert(int x, node* temp)
    {
        if(temp == NULL)     //Addition of the node when an empty space is found
        {
            temp = new node;
            temp->data = x;
            temp->left = temp->right = NULL;
            
        }
        else if(x < temp->data)  //If the node belongs to the left subtree
            { temp->left = insert(x, temp->left);
            temp->left->parent = temp;
            }
        else if(x > temp->data)   //If the node belongs to the right subtree
            { temp->right = insert(x, temp->right);
            temp->right->parent = temp;
            }
        return temp;
    }
    
    //Function for searching a node in the Binary Search Tree 
    node* search(int x, node* temp)
    {
      if(temp == NULL)
           return NULL;
      else if(x==temp->data)   //If the value is found it prints it
           return temp;     
      else if(x<temp->data)
           return search(x,temp->left);   //The value is in left subtree
      else if(x>temp->data)
           return search(x,temp->right);  //The value is in right subtree
    }
    
    //Function for checking the parent node
    node* parent(int x, node* temp){
    	if(temp==NULL){
    		return NULL;
    	}
    	else if(x==temp->data){         //If the node is found
    		if(temp->parent==NULL){   //If node has no parent it prints the node itself
    			return temp;
    		}
    		else if(temp->parent!=NULL){  //If the node has parent then it prints the parent
    	                        return temp->parent;
    		}
    	}
    	
            else if(x<temp->data)           //The node is in the left subtree
            return parent(x, temp->left);
            
            else if(x>temp->data)          //The node is in the right subtree
            return parent(x, temp->right);
    	}
    
    //Function for traversing the tree in inorder fashion and displaying the nodes
    void inorder(node* temp)
    {
        if(temp == NULL)
            return;
        inorder(temp->left);      //Goes to the left child first
        cout << temp->data << " ";     //Printing the value of the node
        inorder(temp->right);     //Goes to the right child next
    }
    
    //Function for finding the minimum element
    node* min(node *temp){
    	if(temp==NULL){
    		return NULL;
    	}
    	else if(temp->left==NULL){       //If the node has no left child it is the smallest
    		return temp;
    	}
    	else if(temp->left!=NULL){
    		return min(temp->left);      //If the node has left child then recursively calls the function for left child
    	}
    }  
    
    //Function for deleting a node in Binary Search Tree
    node* deletion(int x, node* temp)
   {
     if(temp == NULL)
           return NULL;
     else if(x<temp->data)         //Finding the node in left subtree
           deletion(x,temp->left);
     else if(x>temp->data)         //Finding the node in right subtree
           deletion(x,temp->right);
   else if(x==temp->data)         
     {       
     	//Case-1: The node has no child
     	if(temp->left== NULL && temp->right == NULL){   
     		if(temp->parent->left==temp){         //If the node is in its parent's left
     			temp->parent->left=NULL;  //Making the parent node to point to null
     		}
     		else if(temp->parent->right==temp){   //If the node is in its parent's right
     			temp->parent->right=NULL;
     		}
     		delete temp;  //Deleting the node
     		}
     		
     	//Case-2: The node has 1 child	
     	else if(temp->left== NULL || temp->right == NULL){ 
     		if(temp->parent->left==temp){        //If the node is at its parent's left
     			if(temp->left!=NULL){     //If the node has left child
     			temp->parent->left=temp->left;  //Replacing the node's place by its child
     			temp->left->parent=temp->parent;
     			}
     			else if(temp->right!=NULL){    //If the node is at its parent's right
     			temp->parent->left=temp->right;   //Replacing the node's place by its child
     			temp->right->parent=temp->parent;
     			}
     		}
     		else if(temp->parent->right==temp){   //If the node is at its parent's right
     			if(temp->left!=NULL){
     				temp->parent->left=temp->left;
     				temp->left->parent=temp->parent;
     			}
     			else if(temp->right!=NULL){
     				temp->parent->right=temp->right;
     				temp->right->parent=temp->parent;
     			}
     		}
     		delete temp;   //Deleting the node
     	}
     	
     	//Case-3: The node has 2 children
     	else if(temp->left!=NULL && temp->right!=NULL){
     		node* temp1=min(temp->right);    //Finding the smallest node in the node's right subtree
     		temp->data=temp1->data;   //Replacing the node's value with this min node's value
     		
     		//If the min node has no child
     		if(temp1->left==NULL && temp1->right==NULL){
     			if(temp1->parent->left==temp1){
     			temp1->parent->left=NULL;
     		}
     		            else if(temp1->parent->right==temp1){
     			temp1->parent->right=NULL;
     		}
     		delete temp1;
     		}
     		
     		//If the min node has 1 right child (It will have no left child as it is the smallest)
     		else if(temp1->right!=NULL){
     				temp1->parent->right=temp1->right;
     				temp1->right->parent=temp1->parent;
     		delete temp1;
     		}
     	}
     		     	} 
     }
   
   
   //The constructor for BST
    BST()
    {
        root = NULL;
    }
    
     void insert(int x)
    {
        root = insert(x, root);
    }
    
 void display()
    {
        inorder(root);
        cout << endl;
    }
    
    node* search(int x)
    {   
       node *temp=search(x,root);
       return temp;
       
    }
    
    node* parent(int x){
    	 node*ti=parent(x,root);
    	 return ti;
    }
    
    void deletion(int x)
   {
      deletion(x,root);
   }

};
  
//Main function for the programme    
int main()
{
    BST t;  //Making BST variable type  
    t.insert(10);
    t.insert(8);
    t.insert(9);
    t.insert(7);
    t.insert(50);
    t.insert(55);
    t.display();
    node * temp =t.search(8);
    cout << temp -> data;
    cout<<endl;
    t.deletion(10);
    t.display();
    node* ti= t.parent(8);
    cout<<ti->data;
    cout<<endl;
}
