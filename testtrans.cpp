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
//use executables? 
//create executable taking as an input a midifile

int main() {
    //std::string filename;

        // Creating an object of CSVWriter
        CSVReader reader("text1.csv");
        
        // Get the data from CSV File
        std::tuple<std::set<std::string>,std::vector<std::string>> other = reader.getData();
        std::set<std::string> pitches = std::get<0>(other);
        std::vector<std::string> notes = std::get<1>(other);
        std::map<std::string, int> trans = bijection(pitches);
        std::vector<int> translated = translation(notes, trans);
        
        for (std::vector<int>::iterator it = translated.begin() ; it != translated.end(); ++it){
            std::cout << *it << "   ";
        }
        
        /*for (std::vector<std::string>::iterator it = notes.begin() ; it != notes.end(); ++it){
         std::cout << *it << "   ";
         }
         */
        /*for (std::set<std::string>::iterator it = pitches.begin() ; it != pitches.end(); ++it){
         std::cout << *it << "   " << trans[*it] <<std::endl;
         }*/
        
        
    
        // Creating an object of CSVWriter
        CSVWriter writer("text1.txt");
        
        // outputting the csv file named, "translated.csv"
        writer.writeData();
    
    
    int count;
    int total;
    
    count = 0;
    total = 0;

    ifstream original("text1.csv");
    ifstream trans("translated.csv");
    
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

