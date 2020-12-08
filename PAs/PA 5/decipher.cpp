#include "bigint.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout<<"\033[1;41m----Missing an argument----\033[0m"<<endl;
	    cout << "Usage: ./decipher <file>"<<endl;
	    cout << "Examples:" << endl;
	    cout << "\t./decipher secret/message1.txt \033[1;90m//to decipher message 1\033[0m" << endl;
	    cout << "\t./decipher secret/message2.txt \033[1;90m//to decipher message 2\033[0m"<<endl;
		return -1;
	}

	/************* You complete *************/

    if(argc < 2){
        cout << "Please provide file name." << endl;
        return -1;
    }

    ifstream ifile(argv[1]);

    if (ifile.fail()){
        cout << "File provided does not exist. Please try again." << endl;
        ifile.clear();
        return -2;
    }

    int base;
    string e;
    string m;
    
    ifile >> base >> e >> m;
    if (ifile.fail()){
        cout << "Incorrect file formatting." << endl;
        ifile.clear();
        return -2;
    }
    
    try{
        if(base < 2 || base > 36){
            throw InvalidBaseException();
        }
    }catch(exception& E){
        cout << E.what() << endl;
        return -1;
    }
    
    
    const BigInt exp(e, base);
    const BigInt mod(m, base);
    
    
    //cout << base << " " << e << " " << m << endl;
    
    string num;
    vector<int> msg;
    while(ifile >> num){
        const BigInt number(num, base);
        BigInt temp;
        try{
            temp = modPow(number, exp, mod);
            int value = temp.to_int();
            msg.push_back(value);
        }catch(exception& E){
            cout << E.what() << endl;
            return -1;
        }
    }
   
    
    for(unsigned int i = 0; i < msg.size(); i++){
        cout << (char)msg[i];
        //cout << msg[i] << " ";
    }
    cout << endl;

	return 0;
}
