/**************************************************************************************
*   Keys.h
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415   
*
*   ©2023
***************************************************************************************/

#ifndef KEYS_H
#define KEYS_H

#include <iostream>
#include <utility>
#include <tuple>
#include <math.h>
#include <string>

using namespace std;

class Keys {
private:
    int n, e, d;
public:

    Keys(int, int, int);
   // Keys(string, string);

    inline pair<int,int> getPublic() { return make_pair(e, n); };
    inline pair<int,int> getPrivate() { return make_pair(d, n); };
    void saveToDisk(string dest);

};

#endif