// combination of X_5[7],[9],[10]
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;

// just having fun don't put templates in cpp files :)
template <typename T>
void printVector(vector<T> vec){
    int lineSize = 10;
    int count = 0;

    for(T p: vec){
        cout << p << " ";
        if(++count % lineSize == 0){ 
            cout << endl; 
        }
    }
}

int main(){
    int rollsAmt = 100;
    int roll;

    ofstream outFile("numbers.txt");
    for(int i = 0; i < rollsAmt; i++){
        roll = rand();
        outFile << roll % 100 << endl;
    }
    outFile.close();

    vector<int> numbers;

    ifstream inputFile("numbers.txt");
    int num;
    while(inputFile >> num){
        numbers.push_back(num);
    }
    inputFile.close();

    cout << "numbers before sorting:" << endl;
    printVector(numbers);

    sort(numbers.begin(), numbers.end());

    cout << endl << "numbers after sorting:" << endl;
    printVector(numbers);
}