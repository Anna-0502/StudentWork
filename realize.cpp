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

string Furniture::toString() const {
    stringstream ss;
    ss << id << "," << name << "," << color << "," << number;
    return ss.str();
}

void Furniture::fromString(const string& str) {
    stringstream ss(str);
    string temp;

    getline(ss, temp, ',');
    id = stoi(temp);

    getline(ss, name, ',');
    getline(ss, color, ',');

    getline(ss, temp, ',');
    number = stoi(temp);
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
    ifstream file(filename);
    if (!file.is_open()){
        count=0;
        nextID = 1;
        ofstream newFile(filename);
                if (!newFile.is_open()){
                    cerr<<"Error creating file:"<<filename<<endl;
                    return;
                }
            newFile.close();
            return;
            }
            string line;
            if (getline(file, line)) {
                try {
                    count = stoi(line);
                }
                catch (const std::invalid_argument& ia) {
                    cerr << "Invalid count." << endl;
                    count = 0;
                }
            }
            else {
                count = 0;
            }    
            if (getline(file, line)) {
                try {
                    nextID = stoi(line);
                }
                catch (const std::invalid_argument& ia) {
                    cerr << "Invalid nextID." << endl;
                    nextID = 1;
                }
            }
            else {
                nextID = 1;
            }    
            if (count > capacity) {
                capacity = count + 5;
                Furniture* newArray = new Furniture[capacity];
                delete[] arr;
                arr = newArray;
            }
            for (int i = 0; i < count; i++) {
                if (getline(file, line)) {
                    arr[i].fromString(line);
                }
                else {
                    cerr << "Error reading." << endl;
                    count = i;
                    break;
                }
            }
            file.close();
        }

void Func::save(){
    ofstream file(filename);
    if (!file.is_open()){
        cerr<<"Error opening:"<<filename<<endl;
                return;
            }
            file << count << endl;
            file << nextID << endl;

            for (int i = 0; i < count; i++) {
                file << arr[i].toString() << endl;
            }
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