#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
struct LinkNode
{
    int val;
    LinkNode* next;
    LinkNode(){}
    LinkNode(int a)
    {
        val=a;
        next=NULL;
    }
};

void create_LinkList(LinkNode* &head, int val)
{
   LinkNode* temp=new LinkNode(val);
   if(head==NULL)
   {
    head=temp;
    return;
   }
   LinkNode* ptr=head;
   while(ptr->next!=NULL)
   {
    ptr=ptr->next;

   }
   ptr->next=temp;

}

int main()
{

     IOS;
     
    int r,c;
    cin>>r>>c;
    map<int,vector<vector<int>>> mp;
    vector<LinkNode*> v(r);
    for(int i=0;i<r;i++)
    {
        LinkNode*head=NULL;
        for(int j=0;j<c;j++)
        {
            int b;
            cin>>b;
            create_LinkList(head,b);
        }
        v[i]=head;
    }
  
  for(int i=0;i<r;i++)
  {
    LinkNode* head=v[i];

    LinkNode* ptr=v[i];
    LinkNode* prev;
    int start=0;
    int count=1;
    int ct=0;
    while(ptr!=NULL)
    {
        ct++;
        prev=ptr;
        ptr=ptr->next;
        if(ptr==NULL)break;
        if(prev->val==ptr->val)count++;
        else
        {
            if(prev->val==1)
            {
                mp[1].push_back({i,start,start+count-1});
            }
            else
            {
                mp[0].push_back({i,start,start+count-1});
            }
                start=ct;
                count=1;
            
        }
    }
    if(prev->val==1)
    {
        mp[1].push_back({i,start,start+count-1});
    }
    else
    {
        mp[0].push_back({i,start,start+count-1});
    }
  }

for(auto z:mp)
{
    cout<<z.first<<"-> ";
    for(auto y:z.second)
    {    
            cout<<"[ ";
        for(auto w:y)
            {cout<<w<<" ";}
            cout<<"]";
    }
    cout<<endl;
}


}


/*
Input
12 3
1 1 1
0 0 0
1 1 1
0 0 0
1 1 1
0 0 0
1 1 1
0 0 0
1 1 1
0 0 0
1 1 1
0 0 0

Output (stdout)
0-> [ 1 0 2 ][ 3 0 2 ][ 5 0 2 ][ 7 0 2 ][ 9 0 2 ][ 11 0 2 ]
1-> [ 0 0 2 ][ 2 0 2 ][ 4 0 2 ][ 6 0 2 ][ 8 0 2 ][ 10 0 2 ]
*/