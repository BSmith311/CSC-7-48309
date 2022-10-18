/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on October 17, 2021
 * Purpose:  Calculate/compare the Arithmetic Mean and the Geometric Mean
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cstdlib>    //Random function location
#include <ctime>      //Time Library
#include <cmath>      //Math Library
#include <iomanip>    //Format Library
using namespace std;  //STD Name-space where Library is compiled

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
float logAM(int [],int);
float logGM(int [],int);

//Functions you are to write and use to show the Theorem
float logAM(int [],int);//Log of the Arithmetic Mean
float logGM(int [],int);//Log of the Geometric Mean

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    const int SIZE=1000;
    int array[SIZE];
    int perLine=40;
    
    //Initialize variables here
    for(int i=10;i<=SIZE;i*=10){
        fillAry(array,i);
    
        //Display the results
        prntAry(array,i,perLine);
    
        //Map inputs to outputs here, i.e. the process
        cout<<fixed<<setprecision(6)<<showpoint<<endl;
        cout<<i<<" elements [10,99]"<<endl;
        cout<<"Log(Average) = "<<exp(logAM(array,i))<<" >= ";
        cout<<"Average Logsum() = "<<exp(logGM(array,i))<<endl;
    }

    return 0;
}

float logAM(int a[],int n){
    //Calculate Log Arithmetic Mean
    float sum=0;
    float N=n;
    for (int i=0; i<n; i++){
        sum+=(a[i]/N);
    }
    return log(sum);
}

float logGM(int a[],int n){
    //Calculate log Geometric Mean
    float sum=0;
    float N=n;
    for (int i=0; i<n; i++){
        sum+=log(a[i]);
    }
    sum*=(1/N);
    return (sum);
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    cout<<"Print array size = "<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//[10,99]
    }
}