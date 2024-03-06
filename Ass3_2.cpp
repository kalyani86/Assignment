#include<iostream>
using namespace std;

struct Node

{

	int data;

	struct Node* left;

	struct Node* right;

	int lbit;

	int rbit;

};

class TBT

{



	class Queue

	{

	public:

		Node* Arr[30];

		int front;

		int rear;

		Queue()

		{

			front=-1;

			rear=-1;

		}

		public:

		void push(Node* no)

		{

			if(front==-1 && rear==-1)

			{

				front=0;

				rear=0;

				Arr[rear]=no;

			}

			else

			{

				rear++;

				Arr[rear]=no;

			}

		}

		Node* pop()

		{

			Node* temp;

			if(front==rear)

			{

				temp=Arr[front];

				front=-1;

				rear=-1;

			}

			else

			{

				temp=Arr[front];

				front++;

			}

			return temp;

		}

		bool empty()

		{

			if(front==-1 && rear==-1)

			{

				return true;

			}

			else

			{

				return false;

			}

		}

	};

public:

	Node* head;

	TBT()

	{

		head=new Node();

		head->data=0;

		head->rbit=1;

		head->lbit=0;

		head->left=head;

		head->right=head;

	}

		Queue Q;

		void create()

		{

			int data=0;

			Q.push(head);

			while(Q.empty()==false)

			{

				Node* temp=Q.pop();

				cout<<"enter left data for"<<temp->data<<endl;

				cin>>data;

				if(data!=0)

				{

					Node* X=new Node();

					X->data=data;

					Linsert(temp,X);

					Q.push(X);

				}

				if(temp!=head)

				{

					cout<<"Enter the right data for"<<temp->data<<endl;

					cin>>data;

					if(data!=0)

					{

						Node* X=new Node();

						X->data=data;

						Rinsert(temp,X);

						Q.push(X);

					}

				}

			}

		}

		void Rinsert(Node* S,Node* T)

		{

			T->right=S->right;

			T->rbit=S->rbit;

			T->left=S;

			T->lbit=0;

			S->right=T;

			S->rbit=1;

		}

		void Linsert(Node* S,Node* T)

		{

			T->left=S->left;

			T->lbit=S->lbit;

			T->right=S;

			T->rbit=0;

			S->left=T;

			S->lbit=1;

		}

        void Preorder(Node* head)

		{

            cout<<"The left node of head is:"<<head->left->data<<endl;

			int flag=1;

			Node* p=head->left;

			while(p!=head)

			{

				while(flag!=0)

				{

					cout<<p->data<<" ";

					if(p->lbit==1)

					{

						p=p->left;

					}

					else

					{

						break;

					}

				}

				flag=p->rbit;

				p=p->right;

			}

		}

        Node* insucc(Node* X)

		{

			Node* S=X->right;

			if(X->rbit == 1)

			{

				while(S->lbit==1)

				{

					S=S->left;

				}

			}

			return S;

		}

		void Inorder(Node* T)

		{

			while(1)

			{

				T=insucc(T);

				if(T==head)

				{

					return;

				}

				cout<<T->data<<" ";

			}



		}

        void DeleteTBT(Node* parent,Node* child)

        {

            Node* child_succ;

            if(child->lbit == 1 && child->rbit == 1)

            {

                parent=child;

                child_succ=child->right;

                while(child_succ->lbit !=0)

                {

                    parent=child_succ;

                    child_succ=child_succ->left;

                }

                child->data=child_succ->data;

                child=child_succ;

            }

            if(child->lbit == 0 && child->rbit==0)

            {

                if(parent->right == child)

                {

                    parent->right=child->right;

                    parent->rbit=child->rbit;

                }

                else

                {

                    parent->left=child->left;

                    parent->lbit=child->lbit;

                }

                delete(child);

                return;

            }

            if(child->lbit == 1 && child->rbit == 0)

            {

                if(parent->left == child)

                {

                    parent->left=child->left;

                    parent=parent->left;

                }

                else

                {

                    parent->right=child->left;

                    parent=parent->right;

                }

                while(parent->rbit == 1)

                {

                    parent=parent->right;

                }

                parent->right=child->right;

                delete(child);

            }

            if(child->lbit == 0 && child->rbit == 1)

            {

                if(parent->left==child)

                {

                    parent->left=child->right;

                    parent=parent->left;

                }

                else

                {

                    parent->right=child->right;

                    parent=parent->right;

                    while(parent->lbit == 1)

                    {

                        parent=parent->left;

                    }

                    parent->left=child->left;

                    delete(child);

                    return;

                }

            }

        }

		void Treefunctions(int ch){

			if(ch==1)

			{

				create();

			}

            else if(ch==2)

            {

                Preorder(head);

            }

            else if(ch==3)

            {

                Inorder(head);

            }

			else if(ch == 4)

			{

				int value=0;

				cout<<"Enter the value to delete"<<endl;

				cin>>value;

				Node* parent = nullptr;

				Node* child = head->left;

				while (child != head) {

				    if (value < child->data) {

				        if (child->lbit == 0) {

				            break;

				        }

				        parent = child;

				        child = child->left;

				    } else if (value > child->data) {

				        if (child->rbit == 0) {

				            break;

				        }

				        parent = child;

				        child = child->right;

				    } else {

				        DeleteTBT(parent, child);

				        break;

				    }

				}

			}

		}

};

int main() {

	TBT tobj;

	int ch=0;

	cout<<"1.Create 2.Preorder 3.Inorder 4.DeleteTBT 5.Exit";

    cout<<"Enter your choice"<<endl;

    cin>>ch;

	while(ch<=4)



	{

		tobj.Treefunctions(ch);

		cout<<"1.Create 2.Preorder 3.Inorder 4.DeleteTBT 5.Exit";

		cout<<"Enter your choice"<<endl;

		cin>>ch;

	}

	return 0;

}