/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on August 30, 2022
 * Purpose: XOR Equivalence
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool p,q;
    
    //Display the Heading
    cout<<"P Q  (P&&Q)||~(P||Q) !(P^Q) "<<
          " (P||Q)&&~(P&&Q) P^Q"<<endl;
    
    //First Row
    p=true;
    q=true;
    cout<<(p?'T':'F')<<" "
        <<(q?'T':'F')<<"         "
        <<((p&&q)||~(p||q)?'T':'F')<<"           "
        <<(!(p^q)?'T':'F')<<"           "
        <<((p||q)&&~(p&&q)?'T':'F')<<"         "
        <<(p^q?'T':'F')<<" "
        <<endl;
    
    //Second Row
    p=true;
    q=false;
    cout<<(p?'T':'F')<<" "
        <<(q?'T':'F')<<"         "
        <<((p&&q)||~(p||q)?'T':'F')<<"           "
        <<(!(p^q)?'T':'F')<<"           "
        <<((p||q)&&~(p&&q)?'T':'F')<<"         "
        <<(p^q?'T':'F')<<" "
        <<endl;
    
    //Third Row
    p=false;
    q=true;
    cout<<(p?'T':'F')<<" "
        <<(q?'T':'F')<<"         "
        <<((p&&q)||~(p||q)?'T':'F')<<"           "
        <<(!(p^q)?'T':'F')<<"           "
        <<((p||q)&&~(p&&q)?'T':'F')<<"         "
        <<(p^q?'T':'F')<<" "
        <<endl;
    
    //Fourth Row
    p=false;
    q=false;
    cout<<(p?'T':'F')<<" "
        <<(q?'T':'F')<<"         "
        <<((p&&q)||~(p||q)?'T':'F')<<"           "
        <<(!(p^q)?'T':'F')<<"           "
        <<((p||q)&&~(p&&q)?'T':'F')<<"         "
        <<(p^q?'T':'F')<<" "
        <<endl;
    
    //Exit
    return 0;
}