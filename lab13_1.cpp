#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double data[], int n, double result[]){
    for(int i=0;i<6;i++){
        result[i] = data[0];   
    }
    result[1] = 0;
    result[3] = 1.0/data[0];
    
    for(int i=1;i<n;i++){
        result[0] += data[i]; // Arithmetic Mean
        result[2] *= data[i]; // Geometric Mean
        result[3] += (1.0/data[i]); // Harmonic Mean
        if(result[4] < data[i]) result[4] = data[i]; // Max
        if(result[5] > data[i]) result[5] = data[i]; // Min
    }
    
    result[0] = result[0]/n; // Arithmetic Mean
    result[2] = pow(result[2],1.0/n); // Geometric Mean
    result[3] = n/result[3]; // Harmonic Mean
    
    for(int i=0;i<n;i++){
        result[1] += pow((data[i]-result[0]),2)/n; // Standard Deviation
    }
    result[1] = sqrt(result[1]); // Standard Deviation
}
