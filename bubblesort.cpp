#include <iostream>
using namespace std;

void printarray(float** array, int n){
    cout << "belegung des Array: \n";
    for (int i = 0; i < n; i++)
        cout << "Wert " << i << ": " << *array[i] << "\n";
    
    cout << endl;
    
}

void sort(float* f_ptr[], int n){

    float* temp;

    for(int i=0; i < n; i++){
        for(int j = 0; j < n - i; j++)
            if (*f_ptr[j] < *f_ptr[j + 1]){
                temp = f_ptr[j];
                f_ptr[j] = f_ptr[j + 1];
                f_ptr[j + 1] = temp;
            }
    }

}

int main(){

    int n = 4;          //Anzahl array Elemente, wird in getarray befuellt
    float* f_ptr[n]; 

    f_ptr[0] = new float(1.414213562); //sqrt(2)
    f_ptr[1] = new float(1.732050808); //sqrt(3)
    f_ptr[2] = new float(2.718281828); //e
    f_ptr[3] = new float(3.141592653); //pi

    printarray(f_ptr,n);

    sort(f_ptr,n);

    printarray(f_ptr,n);



    return 0;
}