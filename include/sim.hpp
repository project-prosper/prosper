#include "Sorter.hpp"
double sort_avg_time(void (Sorter::*sortPtr) (int first, int last), int n);
double sort_time(void (Sorter::*sortPtr) (int first, int last), int n);

double search_avg_time(bool (Sorter::*searchPtr) (int item, int first, int last), int n);
double search_time(bool (Sorter::*searchPtr) (int item, int first, int last), int n);

double count_avg_time(int n);
double count_time(int n);


void plot_insertion_sort(void);
void plot_quick_sort(void);
void plot_hybrid_sort(void);
void plot_variant_linear(void);