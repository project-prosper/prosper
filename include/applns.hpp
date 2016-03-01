#include <bits/stdc++.h>
using namespace std;

/*class ladder
{
    int s; // no of steps
    public:
    ladder(int);
    int get_s();
    int fib(int);
    void generate(int, int);
    void display(int[], int);
};*/

void ladder(int n, string soFar);

class person
{
    public:   
    int height,weight;
    

    
    static void list(person [], int);
    static bool cmp(person p1,person p2);
    void create(int );
};

class Triomino {

private:
    int k; //log2(side)
    pair<int, int> missing;
    vector<vector<int> > board;

public:
    Triomino(int lg2n, int x, int y); //  of board lg2(side) = lg2n = k; x & y coordinates of missing (row, column)
    void disp();
    void tile(int x_start, int x_end, int y_start, int y_end, pair<int, int> miss);
};


int Hanoi (int, char, char, char, int);
