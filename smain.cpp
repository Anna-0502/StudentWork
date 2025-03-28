#include "h.h"

int main(){
    Func f("furniture.dat");
    int choise, id, number;
    string name;

    do{
        menu();
        cin>>choise;
        cin.ignore();

        switch (choise){
            case 1:
                f.display();
                break;
            case 2:{
                Furniture newArr;
                cin>>newArr;
                f.add(newArr);
                break;
            }
            case 3:
                cout<<"ID for delete: ";
                cin>>id;
                f.erase(id);
                break;
            case 4:
                cout<<"ID for edit: ";
                cin>>id;
                f.edit(id);
                break;
            case 5:
                cout<<"Number for search: ";
                cin>>number;
                cout<<"Name for search: ";
                cin.ignore();
                getline(cin, name);
                f.search(number, name);
                break;
            case 0:
                cout<<"Exit\n";
                break;
            default:
                cout<<"Wrong choise\n";
        }
    }
        while (choise != 0);
return 0;
}