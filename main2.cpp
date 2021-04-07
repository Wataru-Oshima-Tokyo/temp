//
//  main.cpp
//  BinaryTreeSearch
//
//  Created by Wataru Oshima on 2020/05/03.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//
#include "BinaryTreeSearhHeader.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <chrono>
#include <thread>
#include <cassert>
#include <vector>
#include <curses.h>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <point.h>
#include <fstream>
using namespace std;
vector<Point> rbgpoint;
vector<Point> irpoint;

void correction(){
    while (true)
    {
        printf("Are you satisfied with your inputs? (y/n)>>");
        std::string temp;
        string text;
        int count = 0;
        string filename;
        string fileType;
        int tempnum =-1;
        cin >> temp;
        if( temp == "y")
         break;
        else {
            filename = "rgb.txt";
            printf("\nWhich input is not good for you RGB or IR? If RGB, type 1. If Ir, type 2. >>");
            cin >> fileType;
            if(fileType == "2")
                filename = "ir.txt";
            ifstream myfile(filename);
            std::vector<string> row;
            while(getline (myfile, text )) {
                row.push_back(text);
                cout << count+1 << ". ";
                cout << text <<endl;
                count++;
            }
            count = 0;

            while(true) {
                printf("Which number are you not satisfied with? >>");
                myfile.close();
                cin >> temp;
                try{
                    tempnum = stoi(temp);
                    if(tempnum>row.size()){
                        printf("Your input exceeds the number of rows in the file. Please try it again");
                        continue;
                    }
                    break;
                }catch(exception e) {
                    printf("Your input is not valid. Please try it again");
                    continue;
                }
            }
            printf("What number you want to input?>>");
            cin >> temp;
            fstream tempfile(filename);
            for (int i=0; i<row.size(); i++) {
                if(i == tempnum-1) 
                    tempfile<<(temp +"\n");
                else
                    tempfile<<(row[i]+"\n");
            }
            tempfile.clear();
            tempfile.seekg(0);
            printf("Now you have the list below\n");
            while(getline (tempfile, text)){
                cout << count+1 << ". ";
                cout << text << endl;
                count++;
            };
            tempfile.close();            
        }   
    }

    // ifstream myfile("rgb.txt");
    // std::string temp;
    // string text;
    // while(getline (myfile, text )) {
    //             cout << text << endl;
    //     }
    // myfile.close();
}

int main(int argc, const char * argv[]) {
   
// std::vector<int> *v = new std::vector<int>();

// v->push_back(0);
// v->push_back(12);
// v->push_back(45);

string a;
int temp;
// while(1){
//     std::cout << "\nIf you want to modify the value in the vector, please put the index of the vector >>";
//     cin >> a;
//     if(a == "q")
//         break;
//         try{
//             int i = std::stoi(a);
//             std::cout << "\nWhat integer you want to put? if you >>";
//             std::cin >> temp;
//             (*v)[i] = temp;
//             std::cout << "\nNow you have these values in the vector: ";
//             for (int j : *v) {
//                 std::cout<<j << " ";
//             }
//         }
//         catch(std::invalid_argument const&e)
//         {
//             std::cout<<"Bad input: std::invalid_argument thrown ";
//         }

//     }
    correction();
    
return 0;
}
