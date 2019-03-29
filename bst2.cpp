//include library
#include <iostream>
using namespace std;


class node 
{	//type
	public:

	int data;
	
	node* parent;
	//pointer pointing to the left node
	node* left;
	//pointer pointing to the right node
	node* right;

	//constructor
	node(int val)
	{
		parent=NULL;
		left=NULL;
		right=NULL;
		data=val;
	}
};

class Bst2
{
	//type
	public:

	node* root;

	//constuctor
	Bst2()
	{root = NULL;}	
	

	//insert
	void insert(int value)
	{
		inserthelp(root,value);
	}

	//inserthelper
	void inserthelp(node* current,int value)
	{
		//if root is NULL, create a new node and ,make it root
		if(root==NULL)
		{root= new node(value);}
	
		//else move to the left if the value is less than the data stores where current is pointing
		else if(value<current->data)
		{
			if(current->left==NULL)
			{	
				current->left=new node(value);
				current->left->parent=current;
			}
		
			else	
			{inserthelp(current->left,value);}
		}
		//same as left
		else if(value>current->data)
		{
			if(current->right==NULL)
			{
				current->right=new node(value);
				current->right->parent=current;
			}
		
			else	
			{inserthelp(current->right,value);}
		}

		else
		{return;}
}

	//display
	void display(){
				displayhelper(root);
	}


	//display helper
	void displayhelper(node *temp)
	{
			if(temp==NULL)
				{return;}
			

			//print left
			displayhelper(temp->left);
			
			//printing self
			cout<<temp->data<<" , ";
			
			//print right
			displayhelper(temp->right);
									

			
	}
	

	//search
	node* search(int val)
	{
		node* ptr=root;	
		while(ptr!=NULL)
		{
			if(ptr->data==val)
			return ptr;
		
			else if(ptr->data > val)
			ptr=ptr->left;
		
			else
			ptr=ptr->right;
	 	}
		return ptr;
	
	}

	//find min
	node* find_min(node* current)
	{
		while(current->left!=NULL)
		current=current->left;
	
		return current;
	}


	void replace(node* current, node* rep)
	{
		node* par=current->parent;
		if(current!=root)
		{
			if(current==par->left)
			{par->left=rep;}
			else if(current==par->right)
			{par->right=rep;}
			rep->parent=current->parent;
		}
		else if(current==root)
		{
			root=rep;
			rep->left=current->left;
			rep->left->parent=rep;
		
			if(rep->parent!=current)		
			{
				if(rep->right)
				replace(rep,rep->right);
		
				else
				{rep->parent->left=NULL;}
		 		
				rep->right=current->right;
				rep->right->parent=rep;
			}
			rep->parent=NULL;
		
		}
	}

	//delete
	void del(int val)
	{
		node* current=search(val);
		node* ptr;
		ptr=find_min(current->right);
		replace(current,ptr);
		delete current;
	}
};

int main()
{
	Bst2 b;
	b.insert(4);b.insert(3);b.insert(2);b.insert(1);b.insert(6);b.insert(7);b.insert(5);b.insert(9);
	b.display();
	
	cout<<endl;
	cout<<"Minimum value = "<<b.find_min(b.root)->data<<endl;
	b.del(4);
	b.display();
	cout<<endl;
	b.del(7);
	b.display();
	cout<<endl;
	return 0;
}
