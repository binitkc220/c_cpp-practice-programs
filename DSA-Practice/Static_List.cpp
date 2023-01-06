#include<iostream>
using namespace std;
template<class T>
class List
{
    T *list;
    int size, current_pos;
    public:
        List(){
            size = 5;
            list = new T[size];
            current_pos = 0;
        }
        List(int size){
            this->size = size;
            list = new T[size];
            current_pos = 0;
        }
        void insertAtPos(int pos, T data){
            if(current_pos==size-1 || pos>current_pos){
                cout << "Invalid Position to insert element !" << endl;
                return;
            }
            if(current_pos==0 && pos==0){
                list[0] = data;
                current_pos++;
            }
            else{
                for(int i=current_pos;i>=pos;i--)
                    list[i+1] = list[i];
                list[pos] = data;
                current_pos++;
            }
        }
        T deleteAtPos(int pos){
            T x=-1;
            if(current_pos==size-1 || pos>current_pos){
                cout << "Invalid Position to delete element !" << endl;
            }
            else{
                x = list[pos];
                for(int i=pos;i<current_pos;i++)
                    list[i] = list[i+1];
                current_pos--;
            }
            return x;
        }
        void display()
        {
            for(int i=0;i<current_pos;i++)
                cout << list[i] << "\t";
            cout << endl;
        }
};
int main()
{
    List<int> l1;
    l1.insertAtPos(0,1);
    l1.insertAtPos(1,2);
    l1.insertAtPos(2,3);
    l1.display();
    cout << "Deleted element at position 2 = " << l1.deleteAtPos(2) << endl;
    l1.display();
    l1.insertAtPos(2,5);
    l1.display();
    return 0;
}