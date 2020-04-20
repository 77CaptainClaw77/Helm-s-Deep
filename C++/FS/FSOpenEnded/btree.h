#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include <utility>
#include <vector>
class Btree{
    vector<pair<int,int> vec;
    Btree* parent;
    vector<Btree*> children;
    int branch_factor;
    public:Btree(){
            parent=NULL;
            branch_factor=-1;
        }
        int search_key(int k,Btree* root){
        if(root==NULL)
            return NULL:
        int ind=0;
        while(k<root->vec[ind].first)
            ind++;
        if(k==(root->vec[ind]).first)
            return (root->vec[ind]).second;
        return search_key(k,root->children[ind]);
    }
    void insert_item(pair<key_type,val_type> item){

    }
    void delete_item(key_type key){

    }
};

#endif // BTREE_H_INCLUDED
