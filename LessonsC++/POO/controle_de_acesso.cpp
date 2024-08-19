#include <iostream> 
using namespace std; 

class Data{

    int day; 
    int month; 
    int year; 

    public: 

    void setDate(int dia, int mes, int ano){
        day = dia; 
        month = mes; 
        year = ano; 
    }

    void print(){
        cout << day << '/' << month << '/' << year; 
    }

    void copyFrom(const Data d){
        day = d.day; 
        month = d.month; 
        year = d.year; 
    }

}; 


int main(){

    Data data1; 
    data1.setDate(23,11,2023); 

    Data data2; 
    data2.copyFrom(data1); 
    data2.print();

    cout << "\n"; 

    return 0; 
}
