//
// Created by Ravis Rank Willix on 10/29/26.
//
#include <iostream>
using namespace std;
char row1[3]{};
char row2[3]{};
char row3[3]{};
int inputRow;
int inputColumn;
char input[2]{'X','O'};

int main() {
    int i=0;


    while ( i<9) {
        cout<<"Enter column: ";
        cin>>inputColumn;
        cout<<"Enter row: ";
        cin>>inputRow;
        int n=i%2;
        switch (inputRow) {
            case 1:

                row1[inputColumn-1]=input[n];
                break;
            case 2:

                row2[inputColumn-1]=input[n];
                break;
            case 3:

                row3[inputColumn-1]=input[n];
                break;
                defualt: cout<<"Error";
        }i++;
    }
    for (int j=0; j<3;j++){
    cout<<row1[j];
};cout<<endl;
    for (int j=0; j<3;j++){
        cout<<row2[j];
    };cout<<endl;

    for (int j=0; j<3;j++){
        cout<<row3[j];
    };
return 0;
}