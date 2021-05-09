#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

struct LL_Node
{
 unsigned long int bit_address;
 LL_Node *next;
}*head;

void Insert_End(int addr)
{
 LL_Node *nn=new LL_Node;
 nn->bit_address=addr;
 if(head==NULL)
 {
  head=nn;
  nn->next=NULL;
  return;
 }
 LL_Node *temp = head;
 for(;temp->next!=NULL;temp=temp->next);
 temp->next=nn;
 temp=nn;
 nn->next=NULL;
}

void Delete_Begin()
{
 while(head)
 {
  if(head->next==NULL)
  {
   head=NULL;
   return;
  }
  LL_Node* temp=head;
  head=head->next;
  delete temp;
 }
}

int main()
{
 cout<<"\t\t__________________________FREE SPACE ALLOCATION__________________________"<<endl<<endl;
 ifstream obj("Free_Space_Bits.txt",ios::in);
 char A[1000]=""; int l=0,count=0,op=0;
 while(!obj.eof())
  if((int)(A[l++]=obj.get())-48)    //Here, 0 is free block, 1 is used block
   count++;
 A[l-1]='\0';
 bitset<1000> bv=0;
 if(count <= (l=strlen(A))/2)
 { //using bit_vector, when FREE-SPACE blocks are more than ALLOCATED blocks
  for(int index=0;index<l;index++)
   bv[index]=(int)A[l-1-index]-48;
  cout<<bv<<endl;
  cout<<"Preferred Method is Bit-Vector Management"<<endl<<endl;
  op=1;
 }
 else
 { //using linked_list, when FREE-SPACE blocks are less than ALLOCATED blocks
  for(int index=0;index<l;index++)
   if(!((int)(A[index])-48))
    Insert_End(index);
  LL_Node *show=head;
  for(;show->next!=NULL;show=show->next)
   cout<<show->bit_address<<"==>";
  cout<<show->bit_address<<endl;
  cout<<"Preferred Method is Linked-List Management"<<endl<<endl;
  op=2;
 }

do
{
  char ch;
  cout<<" Want to convert to ";
  if(op==1)
  {
  cout<<"Linked_List ?(Y/N):";cin>>ch;
  if(ch=='N' || ch=='n')
    return 0;
  op=2;
  Delete_Begin();
  for(int index=l-1;index>=0;index--)
   if(!((int)(bv[index])))
    Insert_End(l-1-index);
  LL_Node *show=head;
  for(;show->next!=NULL;show=show->next)
   cout<<show->bit_address<<"==>";
  cout<<show->bit_address<<endl;
  cout<<"______________________________________________________________________________"<<endl;
  }
  else
  {
  cout<<"Bit_Vector ?(Y/N):"; cin>>ch;
  if(ch=='N' || ch=='n')
    return 0;
  op=1;
  bv=0;

  for(int i=0;i<l;i++)
   bv[i]=1;                      //bv=~bv
  LL_Node *trans=head;
  for(;trans->next!=NULL;trans=trans->next)
   bv[l-1-trans->bit_address]=0;
  bv[l-1-trans->bit_address]=0;
  cout<<bv<<endl;
  cout<<"______________________________________________________________________________"<<endl;
  }
}while(1);

 obj.close();
 cout<<endl;
 return 0;
}
