#include <iostream>
using namespace std;
template <class T, int size>
class QUEUE
{
    T arr[size];
    int front,rear;
    public: QUEUE():rear(-1),front(-1){}
    void insertion(T ele);
    void deletion();
    template <class U, int s>
    friend void display(QUEUE<U,s> q);
    template <class U, int s>
    friend int linear_search(QUEUE<U,s> q, int ele);
};
template <class T,int size>
void QUEUE<T,size>::insertion(T ele)
{
    if((rear+1)%size==front)
    {   cout<<"\nQueue is Full";
        return;
    }
    rear=(rear+1)%size;
    if(front==-1)
        front=0;
    arr[rear]=ele;
    cout<<"\nElement "<<ele<<" was inserted into the queue";
    return;
}
template <class T, int size>
void QUEUE<T, size>::deletion()
{
    if(front==-1)
    {
        cout<<"\nQUEUE is empty";
        return;        
    }
    cout<<"\n"<<arr[front]<<" was deleted.";
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%size;
    return;
}
template <class T, int size>
void display(QUEUE<T,size> q){
    if(q.front==-1){
        cout<<"\nQUEUE is empty";
        return;
    }
    for(int i=q.front;;i=(i+1)%size)
    {    cout<<"\n"<<q.arr[i];
        if (i == q.rear)
            break;
    }
}
template <class T, int size>
int linear_search(QUEUE<T,size> q,int ele){
    if(q.front==-1)
        return -1;
    for (int i = q.front;; i = (i + 1) % size){
        if(q.arr[i]==ele)
            return i+1;
        if(i==q.rear)
            break;
    }
    return -1;
}
int main(){
    QUEUE<int,5> q;
    int ch;
    cout<<"\nSelect the desired option:-";
    while(1){
        cout<<"\n1.Insertion\n2.Deletion\n3.Search\n4.Display\n5.Exit"; 
        cin>>ch;
        switch(ch){
            case 1:cout<<"\nEnter the element to be inserted into the queue";
                   cin>>ch;
                   q.insertion(ch);
            break;
            case 2:q.deletion();
            break;
            case 3:cout<<"\nEnter the search element";
                  cin>>ch;
                  ch=linear_search(q,ch);
                  if(ch==-1)
                    cout<<"\nElement not found";
                  else
                    cout<<"\nElement found at position "<<ch;
            break;
            case 4:display(q);
            break;
            case 5:return 0;
            break;
            default:cout<<"\nInvalid Input";
        }
    }
}