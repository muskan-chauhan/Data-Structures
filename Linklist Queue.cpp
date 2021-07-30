#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

struct node
{
  char name[30];
  int age;
  node *next;
}*save, *ptr;

class queue1
{
  node *front, *rear;
  public:
  queue1()
  {
    front=rear=NULL;
  }
  node* create_node();
  int isempty();
  void deletion();
  void traverse();
};

int queue1::isempty()
{
  if(rear==NULL)
    return 1;
  else
    return 0;
}

node* queue1::create_node()
{
  node *ptr;
  ptr=new node;
  cout<<"Enter name and age..."<<endl;
  gets(ptr->name);
  cin>>ptr->age;
  ptr->next=NULL;
  return ptr;
}

void queue1::insert(node *nptr)
{
  if(rear=NULL)
    front=rear=nptr;
  else
  {
    rear->next=nptr;
    rear=nptr;
  }
}

void queue1::deletion()
{
  if(isempty())
    cout<<"Underflow"<<endl;
  else
  {
    save=front;
    cout<<"Elementdeleted is..."<<endl;
    puts(save->name);
    cout<<endl<<save->age<<endl;
    front=save->next;
    delete save;
  }
}

void queue1::traverse()
{
  ptr=front;
  while(ptr!=NULL)
  {
    cout<<"The queue is..."<<endl;
    puts(ptr->name);
    cout<<ptr->age<<endl;
    ptr=ptr->next;
  }
}

void main()
{
  queue1 obj;
  cout<<"Enter the options to perform the following..."<<endl;
  cout<<"1: Insert Element"<<endl;
  cout<<"2: Delete Element"<<endl;
  cout<<"3: Traverse"<<endl;
  cout<<"4: Exit"<<endl;
  cout<<"================================"<<endl;
  char ans;
  int opt;
  cout<<"Want to perform any operation on queue? (y/n)"<<endl;
  cin>>ans;
  while(ans=='y'||ans=='Y')
  {
    cout<<"Enter your option..."<<endl<<endl;
    cin>>opt;
    switch(opt)
    {
      case 1: 
        node *ptr;
        ptr=obj.create_node();
        obj.insert(ptr);
        break;
      case 2:
        obj.deletion();
        break;
      case 3: 
        obj.traverse();
        break;
      default:
        exit(0);
        break;
    }
    cout<<"Do you want to perform another operation? (y/n)"<<endl;
    cin>>ans;
    cout<<endl;
  }
  getch();
}
