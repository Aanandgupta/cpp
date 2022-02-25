#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-6
class line
{
    public:
    int a,b,c;
    line(int a,int b,int c)
    {
        this->a=a;
        this->b=b;
        this->c=c;
    }
};

double calc(double x,double y,double x1,double y1)
{
    return (((x1-x)*(x1-x))+((y1-y)*(y1-y)));
}

double dist(vector <vector<int>>points,line line,double x)
{
    double y=-1*(line.a*x+line.c)/line.b;
    
    double total=0;
    for(int i=0;i<points.size();i++)
    {
        total+=calc(x,y,points[i][0],points[i][1]);
        // cout<<total;
    }
    return total;
}
double findOptimumCost(vector <vector<int>>p , line l)
{
    double low = -1e6;
    double high = 1e6;
 
    // loop until difference between low and high
    // become less than EPS
    while ((high - low) > EPS) {
        // mid1 and mid2 are representative x co-ordiantes
        // of search space
        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;
 
        //
        double dist1 = dist(p, l, mid1);
        double dist2 = dist(p, l, mid2);
 
        // if mid2 point gives more total distance,
        // skip third part
        if (dist1 < dist2)
            high = mid2;
 
        // if mid1 point gives more total distance,
        // skip first part
        else
            low = mid1;
    }
 
    // compute optimum distance cost by sending average
    // of low and high as X
    cout<<low;
    return dist(p,  l, (low + high) / 2);
}

int main()
{
    line l(1, -1, -3);
    vector <vector<int>>points{{ -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }};
    cout << findOptimumCost(points, l);
    return 0;
}


