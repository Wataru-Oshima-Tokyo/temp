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
#include "curses.h"
#include <stdio.h>
#include "point.h"
#include <fstream>
using namespace std;
// using namespace cv;


vector<Point> rbgpoint;
vector<Point> irpoint;

// void rgb_mouse(int event, int x, int y, int flags, void* ustc)
// {
//     Point pt;//mouse position;

//     if (event == CV_EVENT_LBUTTONDOWN)
//     {
//         pt = Point(x, y);
//         number_rgb++;
//         cout <<number_rgb << "; rgb_x = "<< y << "; rgb_y = " << x << endl;
//         rbgpoint.push_back(pt);    // adds a new element at the end of the vector, after its current last element


//         ofstream file("rgb.txt");     //save coordinates to txt file;

//         vector<Point>::iterator it = rbgpoint.begin();
//         for (; it != rbgpoint.end(); ++it)
//         {
//             file << it->y << ' ' << it->x  << ' ' << 1 << endl;
//         }
//         //file<<endl;
//         file.close();


//         if (number_rgb >= 10)//only four points are needed;
//         {
// //            imshow("RGB", frame);
// //            cvDestroyAllWindows();
//             cout << "data of RGB image is enough..." << endl;
//         }
//     }

//     else if (event == CV_EVENT_RBUTTONDOWN)
//     {
//        robot_state = true;
//     }


// }

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

    correction();
    return 0;
}
