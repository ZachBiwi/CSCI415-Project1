/**************************************************************************************
*   Keys.cpp
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415
*
*   �2023
***************************************************************************************/

#include "Keys.h"

using namespace std;

/**
*@brief This is the default constructor
*@param n1 the n value for the key pair
*@param e1 the e value for the public key
*@param d1 the d value for the private key
*/
Keys::Keys(InfInt n1, InfInt e1, InfInt d1) {
    n = n1;
    e = e1;
    d = d1;
}