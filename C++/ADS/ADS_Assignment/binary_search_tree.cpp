#include <iostream>
#include <vector>
template <class T>
class BinarySearchTree{
    T data;
    BinarySearchTree<T>* first_child;
    BinarySearchTree<T>* next_sibling;
    bool is_left_child;
public:
    BinarySearchTree(T data){
        this->data=data;
        this->first_child=NULL;
        this->next_sibling=NULL;
    }
    T get_data(){ return this->data;}
    void set_data(T data){this->data=data;}
    void modify_data(T data){this->data=data;}
    BinarySearchTree<T>* get_lchild(){
        if((this->first_child)==NULL)
            return NULL;
        if((this->first_child)->is_left_child)
            return this->first_child;
        return (this->first_child)->next_sibling;
    }
    BinarySearchTree<T>* get_rchild(){
        if((this->first_child)==NULL)
            return NULL;
        if(!((this->first_child)->is_left_child))
            return this->first_child;
        return (this->first_child)->next_sibling;
    }
    void set_lchild(BinarySearchTree<T>* newn){
        if(newn!=NULL && this->first_child!=NULL){
            if(((this->first_child)->is_left_child))
                newn->next_sibling=(this->first_child)->next_sibling;
        }
        if(this->first_child==NULL)
            this->first_child=newn;
        else{
            if((this->first_child)->is_left_child){
                if(newn!=NULL)
                    this->first_child=newn;
                else{
                    if(((this->first_child)->next_sibling)!=NULL){
                        this->first_child->data=(this->first_child)->next_sibling->data;
                        this->first_child->is_left_child=false;
                        (this->first_child)->next_sibling=NULL;
                    }
                }
            }
            else
            (this->first_child)->next_sibling=newn;
        }
        if(newn!=NULL)
            newn->is_left_child=true;
    }
    void set_rchild(BinarySearchTree<T>* newn){
        if(newn!=NULL && this->first_child!=NULL){
            if(!((this->first_child)->is_left_child))
                newn->next_sibling=(this->first_child)->next_sibling;
        }
        if(this->first_child==NULL)
            this->first_child=newn;
          else{
            if(!((this->first_child)->is_left_child)){
                if(newn!=NULL)
                    this->first_child=newn;
                else{
                    if(((this->first_child)->next_sibling)!=NULL){
                        this->first_child->data=(this->first_child)->next_sibling->data;
                        this->first_child->is_left_child=true;
                        (this->first_child)->next_sibling=NULL;
                    }
                }
            }
            else
            (this->first_child)->next_sibling=newn;
        }
        if(newn!=NULL)
            newn->is_left_child=false;
    }
};
template <class T>
BinarySearchTree<T>* build_tree_from_list(std::vector<T> ele){
    if(ele.empty())
        return NULL;
    BinarySearchTree<T>* root=NULL;
    for(size_t i=0;i<ele.size();i++)
        root=insert_into_tree(root,ele[i]);
    return root;
}
template <class T>
void print_inorder_traversal(BinarySearchTree<T>* node){
    if(node==NULL)
        return;
    print_inorder_traversal(node->get_lchild());
    std::cout<<node->get_data()<<" ";
    print_inorder_traversal(node->get_rchild());
}
template <class T>
void print_preorder_traversal(BinarySearchTree<T>* node){
    if(node==NULL)
        return;
    std::cout<<node->get_data()<<" ";
    print_inorder_traversal(node->get_lchild());
    print_inorder_traversal(node->get_rchild());
}
template <class T>
void print_postorder_traversal(BinarySearchTree<T>* node){
    if(node==NULL)
        return;
    print_inorder_traversal(node->get_lchild());
    print_inorder_traversal(node->get_rchild());
    std::cout<<node->get_data()<<" ";
}
template <class T>
BinarySearchTree<T>* insert_into_tree(BinarySearchTree<T>* root,int data){
    if(root==NULL)
        return new BinarySearchTree<T>(data);
    BinarySearchTree<T>* parent;
    BinarySearchTree<T>* pos=root;
    while(pos!=NULL){
        parent=pos;
        if(pos->get_data()>data)
            pos=pos->get_lchild();
        else
            pos=pos->get_rchild();
    }
    if(data>parent->get_data())
        parent->set_rchild(new BinarySearchTree<T>(data));
    else
        parent->set_lchild(new BinarySearchTree<T>(data));
    return root;
}
template <class T>
BinarySearchTree<T>* search_key(BinarySearchTree<T>* root,T key){
    if(root==NULL)
        return NULL;
    BinarySearchTree<T>* temp=root;
    while(temp->get_data()!=key){
        temp=(temp->get_data()<key)?(temp->get_rchild()):(temp->get_lchild());
        if(temp==NULL)
            return NULL;
    }
    return temp;
}
template <class T>
BinarySearchTree<T>* delete_key(BinarySearchTree<T>* root,int key){
    if(root==NULL)
        return NULL;
    if(root->get_data()>key){
        root->set_lchild(delete_key(root->get_lchild(),key));
        return root;
    }
    else if(root->get_data()<key){
        root->set_rchild(delete_key(root->get_rchild(),key));
        return root;
    }
    else{ //Node is found!
        if(root->get_lchild()==NULL && root->get_rchild()==NULL)
            return NULL;
        else if(root->get_lchild()==NULL)
            return root->get_rchild();
        else if(root->get_rchild()==NULL)
            return root->get_lchild();
        else{
            BinarySearchTree<T>* successor_parent=root->get_rchild();
            BinarySearchTree<T>* successor=root->get_rchild();
            while(successor->get_lchild()!=NULL){
                successor_parent=successor;
                successor=successor->get_lchild();
            }
            if(successor!=successor_parent)
                successor_parent->set_lchild(successor->get_rchild());
            else
                root->set_rchild(successor->get_rchild());
            root->set_data(successor->get_data());
            //delete successor;
            return root;
        }
    }
}
int main()
{
    std::vector<int> element_list;
    std::cout<<"Enter the elements of the tree, enter -1 to stop: ";
    while(1){
        int temp;
        std::cin>>temp;
        if(temp==-1)
            break;
        element_list.push_back(temp);
    }
    BinarySearchTree<int>* root=build_tree_from_list(element_list);
    int choice;
    while(1){
        std::cout<<"\nSelect the desired option:-\n1.Insert\n2.Delete\n3.Search\n4.Print Inorder\n5.Print Preorder\n6.Print Postorder\n7.Exit";
        std::cin>>choice;
        if(choice==1){
            std::cout<<"Enter the element to be inserted: ";
            int ele;
            std::cin>>ele;
            insert_into_tree(root,ele);
        }
        else if(choice==2){
            int key;
            std::cout<<"Enter the key to be deleted: ";
            std::cin>>key;
            root=delete_key(root,key);
            std::cout<<key<<" is deleted\n";
        }
        else if(choice==3){
            int key;
            std::cout<<"Enter the key to be searched: ";
            std::cin>>key;
            if(search_key(root,key)==NULL)
                std::cout<<"The key is not present in the tree\n";
            else
                std::cout<<"The key is present in the tree\n";
        }
        else if(choice==4){
            std::cout<<"The inorder traversal is: ";
            print_inorder_traversal(root);
        }
        else if(choice==5){
            std::cout<<"The preorder traversal is: ";
            print_preorder_traversal(root);
        }
        else if(choice==6){
            std::cout<<"The postorder traversal is: ";
            print_postorder_traversal(root);
        }
        else if(choice==7)
            return 0;
        else
            std::cout<<"Invalid Choice!\n";
    }
    return 0;
}
