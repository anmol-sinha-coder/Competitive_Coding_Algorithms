#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
 list< list<int> > adj;
 int vert,edge;

    public:
 Graph()
 {
  vert=edge=0;
 }

 void add_Vertex(int v)
 {
  list<int> t;
  t.push_back(v);
  adj.push_back(t);
  vert++;
 }

 void display_List()
 {
  list< list<int> >::iterator i;
   for (i = adj.begin(); i != adj.end(); ++i)
   {
    list<int>::iterator j;
    for (j=(*i).begin(); j != (*i).end(); j++)
      cout<<*j<<"-->";
    cout<<endl;
    }
 }

};

int main()
{
    cout<<"\t__________________________GRAPH DATA STRUCTURE____________________________\n\n";
    Graph G;
    G.add_Vertex(1);
    G.add_Vertex(2);
    G.display_List();
    return 0;
}
