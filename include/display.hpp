#include<iostream>
#include<vector>
// #include <chrono>
// #include <thread>
#include <unistd.h>



class display
{
    
    std::vector<std::vector<int>> mat;
    
    std::vector<char> gradient = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};


    public:

    int Heigh;
    int Length;

    display(int x, int y);

    void print();
    void clear();
    void add(int x, int y);

};