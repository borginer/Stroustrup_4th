#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct personData{
    string name;
    int age;
};

ostream& operator<<(ostream& os, const personData& pd){
    return os << "Name: " << pd.name << " | Age: " << pd.age; 
}

istream& operator>>(istream& is, personData& pd){
    char c;
    string name;
    char deli = ',';
    if(is >> c && c == '(' && getline(is, name, deli)){
        int age;
        if(is >> age && is >> c && c == ')'){
            pd = {name, age};
            return is;
        }
    }
    pd = {"None", 0};
    return is;
}

class phoneBook{
    vector<personData> book;

    public:
    phoneBook(): book() {}  

    void addPerson(personData pd){
        book.push_back(pd);
    }

    void printBook(){
        for(personData pd: book){
            cout << pd << endl;
        }
    }
};

int main(){
    phoneBook book1;
    personData pd;
    cout << "Enter person data in the following format: (name,age)" << endl;
    cin >> pd;
    book1.addPerson(pd);
    book1.printBook();
}