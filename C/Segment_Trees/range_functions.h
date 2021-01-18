#ifndef RANGE_FUNC_INCLUDED
#define RANGE_FUNC_INCLUDED
struct segement_tree{
  int n;
  int* low_ranges,high_ranges; // pointer to dynamically assign size
};
struct slow_updater{
  int n;
  int* arr;
};
void range_update_increment_segtree(int a,int b,int delta,segement_tree* st);
int range_query_segtree(int a,int b,segement_tree* st);
void range_update_increment_slow(int a,int b,int delta,slow_updater* su);
int range_query_slow(int a,int b,slow_updater* su);
#endif
