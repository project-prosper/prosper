#include "applns.hpp"
#include <iostream>
#include <vector>
#define SIZE 100
#include <algorithm>
using namespace std;



//-----------------CIRCUS-------------------------------------

int d[SIZE];  // array is used store the longest chain

bool person::cmp(person p1, person p2){  // sort by height , if same height then weight is considered
    if (p1.height == p2.height)
        return p1.weight <= p2.weight;
    else
        return p1.height <= p2.height;
}

void person::list(person p[], int n){ // function that builts the longest chain
   
   int k=1; 
   d[0]=p[0].weight;
    
    for(int i = 1; i < n; ++i){      // goes through the entire sorted(by height) set
        
        if (p[i].weight >= d[k - 1])    // the element will be added at he last
            d[k++] = p[i].weight;
        
        else{                  // other element is added in the best position
                int j;
                for (j = k - 1; j >= 0 && d[j] > p[i].weight; --j);
                d[j + 1] = p[i].weight;
        }
    }
    /*
    for(int i=0; i<k; i++){
        for(int j=i+1; j<k; j++){
            if(d[j]>d[i])               // max element's position will give the length of the longest tower
                max=j; 
        }
    }*/
    cout<<"Maximum possible length of tower:"<<k; // k starts from 0 so one is added    
}


void person::create(int n) {

     person p[n];
     for(int i=0;i<n;i++){
                          
        cout<<"Enter Height and Weight of Person "<<i+1<<":";
        cin>>p[i].height>>p[i].weight;
   }                               
                               sort(p,p+n,person::cmp);
                               person::list(p, n);              
}



//----------------LADDER CLIMB--------------------------------------

/*ladder::ladder(int x) {
    s = x;
}*/
/*
int ladder::fib(int n){                 //no.of possible ways to reach stair n=n+1 th term of fibonacci series.
   
   if (n <= 1)
      return n;
   
   return fib(n-1) + fib(n-2);
}

int ladder::get_s() {
    return s;
}*/
/*void ladder::generate(int n,int i){         //generate all possible combinations of climbing the ladder.
                        
  
  static int arr[SIZE];

  if (n == 0){
    
    display(arr, i);
    
    cout<<endl;
  
  }
  
  else if(n > 0){

    int k;

    for(k = 1; k <=2; k++){
      
      arr[i]= k;
      generate(n-k, i+1);
    }
  }
}*/

void ladder(int n, string soFar) { // n = numSteps remaining; soFar = history of steps taken so far

    if(n < 0) {
        return;
    }

    else if(n == 0) {

        cout << soFar << endl;
    }

    else {

        ladder(n-1, (soFar + "1"));
        ladder(n-2, (soFar + "2"));
    }
} 
/*
void ladder::display(int arr[], int n){
    for (int x=0;x<n;x++) {
        cout << arr[x] << " ";
    }
    cout << endl;
}*/

//--------------------------TOWER OF HANOI--------------------------------------


//............IDEA..................//
///logic for example of 3 pegs
//move disc 1 A to c ACB
//move disc 2 A to b ABC
//move disc 1 C to b CBA
//move disc 3 A to c ACB
//move disc 1 B to a BAC
//move disc 2 B to c BCA
//move disc 1 A to c ACB




int Hanoi(int disc, char src, char middle, char destination, int moves){

  if(disc == 1) {

    cout << "Move disc " << disc<< " from " << src << " to " << destination <<  endl;
    moves++;

  }
  else {  
   
    moves = Hanoi(disc-1, src,middle,destination, moves);
   
    cout << "Move disc " << disc<< " from " << src << " to " << destination << endl;
    moves++;

    moves = Hanoi(disc-1,destination,src,middle, moves);
  }

  return moves;
}
/*test for tower of hanoi

int main(){

  int discs;
  
  cout << "Enter the number of discs: " << endl;
  
  cin >> discs;
  
  Hanoi(discs, 's', 'm', 'd');
  

return 0;
} */


//-------------------L-shaped TRIOMINO----------------------------------


Triomino::Triomino(int lg2n, int x, int y) {

    k = lg2n;

    missing.first = x;
    missing.second = y;

    board.resize(pow(2, k));

    for(int i = 0; i < pow(2, k); i++) {
        board[i].resize(pow(2, k));
    }

    board[x][y] = 1;
}

void Triomino::disp() {

    for(int x = 0; x < pow(2, k); x++) {

        cout << "|";

        for(int y = 0; y < pow(2, k); y++) {

            char symbol;

            if( x == missing.first && y == missing.second) {
                symbol = 'M';
            }

            else if(board[x][y] == 1) {
                symbol = 'X';
            }

            else {
                symbol = 'O';
            }
            cout << " " << symbol << " ";
        }

        cout << "|" << endl;
    }

    cout << endl;
}

void Triomino::tile(int x_start, int x_end, int y_start, int y_end, pair<int, int> miss) {

    if((x_end - x_start) != (y_end - y_start)) {
        cout << "Error: Mismatched size";
        return;
    }

    else if(x_end < x_start) {
        cout << "Error: Negative size";
        return;
    }

    else if(x_end == x_start) {
        cout << "Base Case: (" << x_start << ", " << y_start << ")" << endl;
        return;
    }

    int x_mid = (x_start + x_end)/2, y_mid = (y_start + y_end)/2;

    //Xdivide

    if(miss.first <= (x_mid)) { // 1st or 2nd Quad

        if(miss.second <= (y_mid)) { //1st Quad

            board[x_mid][y_mid+1] = 1; //Q2
            board[x_mid+1][y_mid] = 1; //Q3
            board[x_mid+1][y_mid+1] = 1; //Q4

            cout << endl;
            disp();

            //Update Quad 1
            tile(x_start, x_mid, y_start, y_mid, miss);

            //Update Quad 2
            tile(x_start, x_mid, y_mid+1, y_end, make_pair(x_mid, y_mid+1));

            //Update Quad 3
            tile(x_mid+1, x_end, y_start, y_mid, make_pair(x_mid+1, y_mid));

            //Update Quad 4
            tile(x_mid+1, x_end, y_mid+1, y_end, make_pair(x_mid+1, y_mid+1));

        }

        else { //2nd Quad


            board[x_mid][y_mid] = 1; //Q1
            board[x_mid+1][y_mid] = 1; //Q3
            board[x_mid+1][y_mid+1] = 1; //Q4

            cout << endl;
            disp();

            //Update Quad 1
            tile(x_start, x_mid, y_start, y_mid, make_pair(x_mid, y_mid));

            //Update Quad 2
            tile(x_start, x_mid, y_mid+1, y_end, miss);

            //Update Quad 3
            tile(x_mid+1, x_end, y_start, y_mid, make_pair(x_mid+1, y_mid));

            //Update Quad 4
            tile(x_mid+1, x_end, y_mid+1, y_end, make_pair(x_mid+1, y_mid+1));

        }

    }

    else {  // 3rd or 4th Quad

        if(miss.second <= (y_mid)) { //3rd Quad


            board[x_mid][y_mid] = 1; //Q1
            board[x_mid][y_mid+1] = 1; //Q2
            board[x_mid+1][y_mid+1] = 1; //Q4

            cout << endl;
            disp();

            //Update Quad 1
            tile(x_start, x_mid, y_start, y_mid, make_pair(x_mid, y_mid));

            //Update Quad 2
            tile(x_start, x_mid, y_mid+1, y_end, make_pair(x_mid, y_mid+1));

            //Update Quad 3
            tile(x_mid+1, x_end, y_start, y_mid, miss);

            //Update Quad 4
            tile(x_mid+1, x_end, y_mid+1, y_end, make_pair(x_mid+1, y_mid+1));

        }

        else { //4th Quad

            board[x_mid][y_mid] = 1; //Q1
            board[x_mid][y_mid+1] = 1; //Q2
            board[x_mid+1][y_mid] = 1; //Q3

            cout << endl;
            disp();

            //Update Quad 1
            tile(x_start, x_mid, y_start, y_mid, make_pair(x_mid, y_mid));

            //Update Quad 2
            tile(x_start, x_mid, y_mid+1, y_end, make_pair(x_mid, y_mid+1));

            //Update Quad 3
            tile(x_mid+1, x_end, y_start, y_mid, make_pair(x_mid+1, y_mid));

            //Update Quad 4
            tile(x_mid+1, x_end, y_mid+1, y_end, miss);
        }
    }

}
