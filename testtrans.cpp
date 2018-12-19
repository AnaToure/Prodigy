//
//  testtrans.cpp
//  
//
//  Created by Anaëlle Touré on 09/12/2018.
//

#include <iostream>
#include "testtrans.hpp"
#include "midicsv.c"
#include "translate.cpp"
#include "translateback-2.cpp"
#include <ifstream>
#include <ofstream>

//to quantify the lost
//use executables
//create executable taking as an input a midifile

int main() {
    std::string filename;
    int count;
    int total;
    
    count = 0;
    total = 0;
    
    t0 = midicsv(filename); //csv  ( ./midicsv filename >> test.csv in the terminal )
    
    CSVReader main() >> t1("t0.csv"); //txt
    CSVWriter main() >> t2("t1.txt"); //csv
    
    ifstream original("t0");
    ifstream trans("t2");
    
    string line1;
    string line2;
    
    while (std::getline(original, line1, ',')) {
         while (std::getline(trans, line2, ',')) {
        
             if line1[5] != line2[5] and line1[6]!= 0 { //to get rid of the pb of note off
            
                 count += 1;
             }
             total += 1;
    
         }}}
    std:: cout >> count >> " similar notes out of" >> total;
    return 0;
    
}

