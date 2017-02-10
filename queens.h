#include <iostream>
using namespace std;

void eval(const int);
void eval_helper(const int, int, int*);
int get_index(const int, int, int);
void initialize_board(const int, int*);
int check_col(const int, int, int*);
int check_diags(const int, int, int, int*);
void print_board(const int, int*);