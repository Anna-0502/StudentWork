#include "h.h"

int Func::nextID = 1;

ostream&operator<<(ostream&out, const Furniture&furniture){
    out<<"ID:"<<furniture.id<<"\nName:"<<furniture.name<<"\nColor:"<<furniture.color<<"\nNumber:"<<furniture.number;
    return out;
}

istream&operator>>(istream&in, Furniture&arr){
    cout<<"Input name: ";
    getline(in>>ws, arr.name);
    cout<<"Input color: ";
    getline(in>>ws, arr.color);
    cout<<"Input number: ";
    in>>arr.number;
    return in;
}

void Func::size(){
    capacity *= 2;
    Furniture*newArr = new Furniture[capacity];
    for (int i=0; i<count; i++)
        newArr[i]=arr[i];
    delete[] arr;
    arr = newArr;
}

Func::Func(string file): filename(file), count(0), capacity(5){
    arr = new Furniture[capacity];
    load();
}

Func::~Func(){
    save();
    delete[] arr;
}

void Func::load(){
    ifstream file(filename, ios::binary);
    if (!file){
        nextID = 1;
        return;
    }

    file.read((char*)&count, sizeof(count));
    if (count>capacity){
        capacity = count + 5;
        Furniture*newArray = new Furniture[capacity];
        for (int i=0; i<count; i++){
            if (i<capacity){
                newArray[i] = arr[i];
            }
        }
        delete[] arr;
        arr = newArray;
    }

    file.read((char*)&nextID, sizeof(nextID));
    for (int i=0; i<count; i++)
        file.read((char*)&arr[i], sizeof(Furniture));
    file.close();
}

void Func::save(){
    ofstream file(filename, ios::binary);
    if (!file.is_open()) return;

    file.write((char*)&count, sizeof(count));
    file.write((char*)&nextID, sizeof(nextID));
    for (int i=0; i<count; i++)
        file.write((char*)&arr[i], sizeof(Furniture));
    file.close();
}

void Func::add(Furniture ar){
    if (count == capacity) size();
    Furniture newAr(ar.getName(), ar.getColor(), ar.getNumber(), nextID++);
    arr[count++] = newAr;
    cout<<"Element is add\n";
}

void Func::display() const{
    if (count == 0){
        cout<<"The warehouse is empty\n";
        return;
    }
    for (int i=0; i<count; i++)
        cout<<arr[i]<<"\n\n";
}

void Func::erase(int id){
    bool found = false;
    for (int i=0; i<count; i++){
        if (arr[i].getId() == id){
            for (int j = i; j<count-1; j++)
                arr[j]=arr[j+1];
            count--;
            cout<<"Element is delete\n";
            nextID--;
            found = true;
            return;
            }
        }
        if (!found)
            cout<<"Element is delete\n";
}

void Func::edit(int id){
    for (int i=0; i<count; i++){
        if (arr[i].getId() == id){
            cout<<"Actual information:\n"<<arr[i]<<"\n";
            Furniture temp;
            cin>>temp;
            Furniture newFurniture(temp.getName(), temp.getColor(), temp.getNumber(), arr[i].getId());
            arr[i] = newFurniture;
            cout<<"Changes are saved\n";
            return;
        }
    }
    cout<<"Element not found\n";
}

void Func::search(int number, string name) const{
    bool found = false;
    for (int i=0; i<count; i++){
        if ((arr[i].getNumber() == number) || (arr[i].getName() == name)){
            cout<<arr[i]<<"\n";
            found = true;
        }
    }
    if (!found) cout<<"Element not found\n";
}

void menu(){
    cout<<"\nMenu:\n";
    cout<<"1. Show all elements\n";
    cout<<"2. Add new element\n";
    cout<<"3. Delete the element\n";
    cout<<"4. Edit the element\n";
    cout<<"5. Find the element by number and name\n";
    cout<<"0. Exit\n";
    cout<<"Choose:\n";
}