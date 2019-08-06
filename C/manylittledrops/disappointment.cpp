#include <iostream>
#include <iomanip>
using namespace std;
typedef struct{
    float price;
    int quantity;
    char name[20];
    int code;
}item;
class inventory{
    public: void shop();
    void input();
    void display(int i);
    private:item item_set[100];
    int n;
};
void inventory::input(){
    cout<<"Enter the number of items";;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nItem "<<i+1<<endl;
        cout<<"Item Name:"<<endl;
        cin>>item_set[i].name;
        cout<<"Item ID:"<<endl;
        cin>>item_set[i].code;
        cout<<"Item Price:"<<endl;
        cin>>item_set[i].price;
        cout<<"Item Quantity:"<<endl;
        cin>>item_set[i].quantity;
    }
}
void inventory::shop(){
    while(1){
            cout<<"Press 1 to exit, anything else to continue";
        int proc=0;
        cin>>proc;
        if(proc==1)
            return;
    for(int i=0;i<n;i++){
        if(item_set[i].quantity!=0){
                display(i);
        }
    }
     int acode=0,quan=0,ch=0;
            bool isexists=false;

        cout<<endl<<"Enter the item code of the item you want to purchase";
        cin>>acode;
        cout<<endl<<"Enter the number of items you want to purchase";
        cin>>quan;
        for(int j=0;j<n;j++){
            if(item_set[j].code==acode){
                isexists=true;
                ch=j;
            }
        }
        if(isexists)
        {
            if(quan>item_set[ch].quantity){
                cout<<"Invalid Quantity";
                continue;
            }
            else
                item_set[ch].quantity-=quan;
        }
        else{
            cout<<"That item does not exist or maybe out of stock currently";
            continue;
        }

    }
}
void inventory::display(int i){
    cout<<"Item Name:"<<item_set[i].name<<endl;
    cout<<"Item ID:"<<item_set[i].code<<endl;
    cout<<"Item Price:"<<item_set[i].price<<endl;
    cout<<"Item Quantity:"<<item_set[i].quantity<<endl;
}
int main(){
    inventory in;
    in.input();
    in.shop();
    return 0;
}
