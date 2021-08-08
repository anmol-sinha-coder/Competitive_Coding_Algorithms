#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Nearest_Obstacle
{
 int row, col;
 long dist, blocks; //Use Chebyshev distance only

 Nearest_Obstacle(): row(INT_MAX-1),col(INT_MAX-1),dist(INT_MAX-1),blocks(0){}
};

int queensAttack(int size, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{   //                    -|-                        /                                      \
    //                              min(r_q-1, c_q-1)+min(n-r_q, n-c_q)     min(n-r_q, c_q-1)+min(n-c_q, r_q-1)
 int initial_attacks = 2*(size-1)     +     (size-1-abs(r_q-c_q))     +     (size-1-abs(size+1-(r_q+c_q)));
 Nearest_Obstacle n, s, e, w, ne, nw, se, sw;

 for(int i=0;i<k;i++)
    if(obstacles[i][1] == c_q)
        if(obstacles[i][0] > r_q)// n
            if(min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])) < n.dist )
                n.row=obstacles[i][0],
                n.col=obstacles[i][1],
                n.dist=min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])),
                n.blocks=size+1-n.row;
            else ;
        else//(obstacles[i][0] < r_q) s
            if( min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])) < s.dist )
                s.row=obstacles[i][0],
                s.col=obstacles[i][1],
                s.dist=min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])),
                s.blocks=s.row;
            else ;
    else if(obstacles[i][0] == r_q)
        if(obstacles[i][1] > c_q)// e
            if( min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])) < e.dist )
                e.row=obstacles[i][0],
                e.col=obstacles[i][1],
                e.dist=min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])),
                e.blocks=size+1-e.col;
            else ;
        else//(obstacles[i][1] < c_q) w
            if( min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])) < w.dist )
                w.row=obstacles[i][0],
                w.col=obstacles[i][1],
                w.dist=min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])),
                w.blocks=w.col;
            else ;
    else if(obstacles[i][0] - obstacles[i][1] == r_q - c_q)
        if(obstacles[i][0] + obstacles[i][1] > r_q + c_q)// ne
            if( min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])) < ne.dist )
                ne.row=obstacles[i][0],
                ne.col=obstacles[i][1],
                ne.dist=min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])),
                ne.blocks=min(abs(size+1-obstacles[i][0]), abs(size+1-obstacles[i][1]));
            else ;
        else//(obstacles[i][0] + obstacles[i][1] < r_q + c_q) sw
            if( min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])) < sw.dist )
                sw.row=obstacles[i][0],
                sw.col=obstacles[i][1],
                sw.dist=min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])),
                sw.blocks=min(abs(obstacles[i][0]), abs(obstacles[i][1]));
            else ;
    else if(obstacles[i][0] + obstacles[i][1] == r_q + c_q)
        if(obstacles[i][0] - obstacles[i][1] > r_q - c_q)// nw
            if( min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])) < nw.dist )
                nw.row=obstacles[i][0],
                nw.col=obstacles[i][1],
                nw.dist=min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])),
                nw.blocks=min(abs(size+1-obstacles[i][0]), abs(obstacles[i][1]));
            else ;
        else//(obstacles[i][0] - obstacles[i][1] > r_q - c_q) se
            if( min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])) < se.dist )
                se.row=obstacles[i][0],
                se.col=obstacles[i][1],
                se.dist=min(abs(r_q-obstacles[i][0]), abs(c_q-obstacles[i][1])),
                se.blocks=min(abs(obstacles[i][0]), abs(size+1-obstacles[i][1]));
            else ;

 cout<<n.blocks<<endl<<
       s.blocks<<endl<<
       e.blocks<<endl<<
       w.blocks<<endl<<
      ne.blocks<<endl<<
      nw.blocks<<endl<<
      se.blocks<<endl<<
      sw.blocks<<endl;
 int final_attacks = initial_attacks-(n.blocks+s.blocks+e.blocks+w.blocks+ne.blocks+nw.blocks+se.blocks+sw.blocks);
 return final_attacks;
}

int main()
{


    return 0;
}
