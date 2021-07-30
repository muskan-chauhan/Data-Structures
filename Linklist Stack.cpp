#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

struct node 
{
  char name[30];
  int age;
  node *next
}*save, *ptr;

class stack1
{
  node *start;
  public:
  stack1()
  {
    start=NULL;
  }
  node* create_node();
  int isempty();
  void push(node*);
  void pop();
  void traverse();
};

int stack1::isempty()
{
  if(start==NULL)
    return 1;
  else
    retuen 0;
}

node* stack1::create_node()
{
  node *ptr;
  ptr=new node;
  cout<<"Enter name and age..."<<endl;
  gets(ptr->name);
  cin>>ptr->age;
  ptr->next=NULL;
  return ptr;
}

void stack1::push(node *nptr)
{
  if(start==NULL)
  {
    start=nptr;
  }
  else
  {
    save=start;
    start=nptr;
    nptr->next=save;
  }
}

void stack1::pop()
{
  if(isempty())
    cout<<"underflow"<<endl;
  else
  {
    save=start;
    cout<<"Element deleted is..."<<endl;
    puts(save->name);
    cout<<endl<<save->age<<endl;
    start=save->next;
    delete save;
  }
}

void stack1::traverse()
{
  ptr=start;
  while(ptr!=NULL)
  {
    cout<<"The stack is..."<<endl;
    cout<<"-->";
    cout<<"Name: ";
    puts(ptr->name);
    cout<<"Age: "<<ptr->age<<endl;
  }
}

void main()
{
  clrscr();
  stack1 obj;
  cout<<"Enter the options to perform the following..."<<endl;
  cout<<"1: Insert Element"<<endl;
  cout<<"2: Delete Element"<<endl;
  cout<<"3: Traverse "<<endl;
  cout<<"4: Exit"<<endl;
  cout<<"========================="<<endl;
  har ans;
  int opt;
  cout<<"Want to perform any operation on stack: (y/n)";
  cin>>ans;
  
  while(ans=='y'||ans=='Y')
  {
    cout<<"Enter an option... "<<endl<<endl;
    cin>>opt;
    switch(opt)
    {
      case 1:
        node *ptr;
        ptr=obj.create_node();
        obj.push(ptr);
        break;
      case 2:
        obj.pop();
        break;
      case 3:
        obj.traverse();
        break;
      default:
        exit(0);
        break;
    }
    cout<<"Do yuo want to perform another operation: (y/n)";
    cin>>ans;
    cout<<"================================";
    cout<<endl;
  }
  getch();
}
  
    
  
