//============================================================================
// Name        : Ass1_21440.cpp
// Author      : 21140
// Version     :
// Copyright   : Assignment1
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stack>
using namespace std;

class TNode
{
public:
	int data;
	TNode* llink;
	TNode* rlink;

public:
	TNode()
	{
		data=0;
		llink=NULL;
		rlink=NULL;
	}

	TNode(int d)
	{
		data=d;
		llink=NULL;
		rlink=NULL;
	}
};

class BinaryTree
{
	TNode* root;
	public:
	BinaryTree()
	{
		root=NULL;
	}

	TNode*& getroot()
	{
		return root;
	}
	void create();
	TNode* maketree();
	void inorder(TNode* p);
	void preorder(TNode* p);
	void postorder(TNode* p);
	void nonRecursive_inorder();
	void nonRecursive_preorder();
	void nonRecursive_postorder();

	TNode* swap(TNode* p);
	int height(TNode*);
	void operator=(BinaryTree);
	TNode* copy(TNode*);

	int count_leaves(TNode* );
	int count_internal_nodes(TNode*);
	
	void makeempty();

	TNode* eraseNode(TNode* p);

};

void BinaryTree::nonRecursive_postorder()
{
	TNode* temp=new TNode(-1);
	stack<TNode*>s;
	TNode* t=root;
	while(1)
	{
		while(t!=0)
		{
			s.push(t);
			if(t->rlink!=0)
			{
				s.push(t->rlink);
				s.push(temp);
			}
			t=t->llink;
		}

		if(s.empty())
		{
			return;
		}

		t=s.top();
		s.pop();

		while(t!=temp && !s.empty())
		{
			cout<<t->data<<" ";
			t=s.top();
			s.pop();
		}

		if(!s.empty())
		{
			t=s.top();
			s.pop();
		}
		else{
			cout<<t->data<<" ";
			break;
		}
	}
}
void BinaryTree::nonRecursive_preorder()
{
	TNode* t=root;
	stack<TNode*>s;
	while(t!=0)
	{
		cout<<t->data<<" ";
		s.push(t);
		t=t->llink;
	}

	while(!s.empty())
	{
		t=s.top();
		s.pop();
		t=t->rlink;
		while(t!=0)
		{
			cout<<t->data<<" ";
			s.push(t);
			t=t->llink;
		}
	}
}
void BinaryTree::nonRecursive_inorder()
{
	stack<TNode*>s;
	TNode* t=root;
	while(t!=0)
	{
		s.push(t);
		t=t->llink;
	}


	while(!s.empty())
	{
		t=s.top();
		s.pop();
		cout<<t->data<<" ";

		t=t->rlink;
		while(t!=0)
		{
			s.push(t);
			t=t->llink;
		}
	}
}
void BinaryTree::makeempty()
{
	root=eraseNode(root);
}

TNode* BinaryTree::eraseNode(TNode* p)
{
	if(p==NULL)
	{
		return NULL;
	}
	if(p->llink==0 && p->rlink==0)
	{
		delete p;
		return NULL;
	}

	p->llink=eraseNode(p->llink);
	p->rlink=eraseNode(p->rlink);

	return NULL;

}
int BinaryTree::count_internal_nodes(TNode* p)
{
	if(p==NULL)
	{
		return 0;
	}
	else{
		int res1=count_internal_nodes(p->llink);
		int res2=count_internal_nodes(p->rlink);
		if(p->llink!=0 || p->rlink!=0)
		{
			return 1+res1+res2;
		}
		return 0;
	}

}

int BinaryTree::count_leaves(TNode* p)
{
	if(p==NULL)
		{
			return 0;
		}

	if(p->llink==0 && p->rlink==NULL)
	{
		return 1;
	}

	int res1;
	res1=count_leaves(p->llink);

	int res2=count_leaves(p->rlink);

	return res1+res2;

}


void BinaryTree::operator =(BinaryTree s)
{
	if(s.root==0)
	{
		return;
	}

	root=s.copy(s.root);
}

TNode* BinaryTree::copy(TNode* p)
{
	if(p==NULL)
	{
		return NULL;
	}

	TNode* n=new TNode(p->data);
	n->llink=copy(p->llink);
	n->rlink=copy(p->rlink);

	return n;
}

int BinaryTree::height(TNode* p)
{
	if(p==0)
	{
		return 0;
	}

	int res1;
	res1=height(p->llink);
	res1=res1+1;

	int res2;
	res2=height(p->rlink);
	res2=res2+1;

	if(res1>res2)
	{
		return res1;
	}
	else
	{
		return res2;
	}

}
TNode* BinaryTree::swap(TNode* p)
{
	TNode* t;
	if(p!=NULL)
	{
		t=p->llink;

		p->llink=swap(p->rlink);
		p->rlink=swap(t);
	}
	return p;


}
void BinaryTree::inorder(TNode* p)
{

	if(p==NULL)
	{
		return;
	}

	inorder(p->llink);
	cout<<"\ndata:"<<p->data;
	inorder(p->rlink);
}


void BinaryTree::preorder(TNode* p)
{

	if(p==NULL)
	{
		return;
	}

	cout<<"\ndata:"<<p->data;
	preorder(p->llink);
	preorder(p->rlink);
}


void BinaryTree::postorder(TNode* p)
{

	if(p==NULL)
	{
		return;
	}

	postorder(p->llink);
	postorder(p->rlink);
	cout<<"\ndata:"<<p->data;
}
void BinaryTree::create()
{
	root=maketree();
}
TNode* BinaryTree::maketree()
{
	TNode* p;
	int x;
	cout<<"\nEnter data:";
	cin>>x;

	p=new TNode(x);
	char ch;
	cout<<"\nEnter y to insert left node of "<<x<<" : ";
	cin>>ch;
	if(ch=='y'){
		p->llink=maketree();
	}


	cout<<"\nEnter y to insert right node of "<<x<<" : ";
	cin>>ch;
	if(ch=='y'){
		p->rlink=maketree();
	}
	return p;

}
int main() {

	BinaryTree b;
	b.create();
	// cout<<"\nInorder:";
	// b.inorder(b.getroot());

	// cout<<"\nnon recursive:";
	// b.nonRecursive_inorder();


// 	cout<<"\npreorder:";
// 	b.preorder(b.getroot());

// 	cout<<"\nnon recursive:";
// 	b.nonRecursive_preorder();
// //
	cout<<"\npostorder:";
	b.postorder(b.getroot());

	cout<<"\nnon recursive:";
	b.nonRecursive_postorder();

//	b.getroot()=b.swap(b.getroot());
//	b.inorder(b.getroot());

	//cout<<"\nheight:"<<b.height(b.getroot())-1;

//	BinaryTree b2;
//	b2=b;
//
//	cout<<"\n\ncopy:";
//	b2.inorder(b2.getroot());


//	cout<<"\nleaves:"<<b.count_leaves(b.getroot());

	cout<<"\ninternal nodes:"<<b.count_internal_nodes(b.getroot());

	// b.makeempty();
	// cout<<"\n\n";
	// cout<<"\nInorder:";
	// b.inorder(b.getroot());

	return 0;
}
