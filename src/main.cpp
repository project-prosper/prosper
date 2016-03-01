#include <iostream>
#include <ctime>

#include "applns.hpp"
#include "sim.hpp"

using namespace std;

void main_menu();
void misc_menu();
void arr_menu();

int main() {
    main_menu();
}

void main_menu() {
    short int ch=1;
    srand(time(NULL));
    //system("clear");
    while(true) {
        system("clear");
        cout << "\t----PROSPER-main-menu-----";
        cout << "\nMain menu\n";
        cout << "Enter Choice.\n";
        cout << "1. Perform array ops\n";
        cout << "2. Perform miscellaneous ops\n";
        cout << "3. Exit\n";
        cin >> ch;
        if (ch == 1)
            arr_menu();
        else if (ch == 2)
             misc_menu();
        else if (ch == 3) 
            return;
        else if (ch != 1 || ch != 2 || ch != 3) 
            cout << "Try again.\n";
        
    }
}

void arr_menu() {
    cout << "\nPROSPER - Array ops menu\n";
    int sz;
    cout << "Enter array size.\n";
    cin >> sz;
    Sorter obj(sz);
    cout << "\nEnter the elts now: \n";
    for(int i = 0; i<sz;i++) {
        cin >> obj[i];
    }

    short ch;
    while(true) {
        system("clear");
        cout << "Enter choice\n";
        cout << "----Quick Sort and variants----\n";
        cout << "1. Quick Sort\n";
        cout << "2. Quick Sort (Pivot-middle)\n";
        cout << "3. Quick Sort (Pivot-first)\n";
        cout << "4. Quick Sort (Pivot-random)\n";
        cout << "----Insertion Sort and variants----\n";
        cout << "5. Insertion sort (Iterative)\n";
        cout << "6. Insertion sort (Recursive)\n";
        cout << "7. Insertion sort (Binary)\n";
        cout << "8. Count inversions.\n";
        cout << "----Hybrid Search & Sort----\n";
        cout << "9. Quick-Insertion Sort\n";
        cout << "10. Merge-Insertion Sort\n";
        cout << "11. Linear search (Variant)\n";
        cout << "------Simulations-----\n";
        cout << "12. Plot insertion sort and variants\n";
        cout << "13. Plot quick sort and variants\n";
        cout << "14. Plot hybrid sort\n";
        cout << "15. Plot linear search and variant\n";
        cout << "-----------------------\n";
        cout << "16. Display\n";
        cout << "17. Modify array\n";
        cout << "18. Exit.\n";

        cin >> ch;

        switch(ch) {

            case 1:
                    obj.quick_sort(0, sz-1);
                    cout << "Sorted successfully\n";
                    break;
            case 2:
                    obj.quick_sort_pivot_middle(0, sz-1);
                    cout<< "Sorted successfully\n" ;
                    break;
            case 3:
                    obj.quick_sort_pivot_first(0, sz-1);
                    cout<< "Sorted successfully\n" ;
                    break;
            case 4:
                    obj.quick_sort_pivot_random(0,sz-1);
                    cout << "Sorted successfully\n";
                    break;
            case 5:
                    obj.insertion_sort_iterative(0,sz-1);
                    cout << "Sorted successfully\n";
                    break;
            case 6:    
                    obj.insertion_sort_recursive(0,sz-1);
                    cout << "Sorted successfully\n";
                    break;
            case 7:
                    obj.insertion_sort_binary(0,sz-1);
                    cout << "Sorted successfully\n";
                    break;
            case 8:
                    cout << "# of inversions: " << obj.countInversions(0,sz-1) << endl;
                    break;
            case 9:
                    obj.quick_insertion_sort(0,sz-1);
                    cout << "Sorted successfully\n";
                    break;
            case 10:
                    obj.merge_insertion_sort(0,sz-1);
                    cout << "Sorted successfully\n";
                    break;
            case 11:
                    cout << "enter the key element :";
                    int k;
                    cin >> k ;  
                    if(obj.linear_search(k,0,sz-1))
                        cout << "\nElement found";
                    else
                        cout << "\n Element not found";
                    break;
                    
            case 12:
                    plot_insertion_sort();
                    break;
            case 13:
                    plot_quick_sort();
                    break;
            case 14:
                    plot_hybrid_sort();
                    break;
            case 15:
                    plot_variant_linear();
                    break;
            case 16:
                    obj.disp();
                    break;
            case 17:
                    cout << "Enter array size (new): ";
                    cin >> sz;
                    obj.resize(sz);
                    cout << "Enter the elements now: ";
                    for(int i = 0; i<sz;i++) {
                        cin >> obj[i];
                    }
                    cout << "Array updated successfully";
                    break;
            case 18:
                    return;
        }
        cout << "\nDo you wish to continue?(Enter 1) ";
        int cho;
        cin >> cho;
        if(cho != 1) 
            return;
    }

}

void misc_menu(){
    short int ch=1;
    system("clear");
    while(true) {
        system("clear");
        cout << "\nMisc. menu\n";
        cout << "Enter Choice.\n";
        cout << "1. Tower of Hanoi\n";
        cout << "2. L-shaped Triomino\n";
        cout << "3. Ladder_Climb\n";
        cout << "4. Circus\n";
        cout << "5. Exit\n";
        cin >> ch;
        switch(ch) {
                    case 1: {
                            int discs;  
                            cout << "Enter the number of discs: " << endl;
                            cin >> discs;
                            int mvs = Hanoi(discs, 'S', 'M', 'D', 0);
                            cout << "# of moves: " << mvs << endl;
                            break;
                        }
                    
                    case 2:
                            {int k;
                            cout<<"Enter k where 2^k is number of sides in the triominoes: ";
                            cin >> k;
                            cout << "Enter the coordinates of missing tile: ";
                            int x_co,y_co;
                            cin >>x_co>> y_co;
                            Triomino tr(k,x_co,y_co);
                            tr.disp();
                            tr.tile(0, pow(2,k)-1,0, pow(2,k)-1, make_pair(x_co, y_co));
                            break;}
                    
                    case 3:
                            {int x;
                            cout<<"Enter the no.of steps:";
                            cin>>x;
                            //l.fib(l.get_s()+1);
                            //l.generate(l.get_s(),0);
                            cout << endl;
                            ladder(x,"");
                            cout << endl ;
                           break;}
                    
                    case 4:
                           
                           {int n;                           
                           cout<<"Enter no.of persons:";
                           cin>>n;
                           person x;
                           x.create(n);
                                       
                           break;}
                    
                    case 5:return; 
                    
                    default:cout << "Try again.\n";
        }
        cout << "\nDo you wish to continue?(Enter 1) ";
        int cho;
        cin >> cho;
        if(cho != 1) 
            return;
     }
 }