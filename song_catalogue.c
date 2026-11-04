#include <stdio.h>  //stdio.h contains functions
#include <string.h> //string functions

struct Song // everything stored inside 'type' song
{
    char singer[50]; //up to 49 characters
    char songName[100]; //up to 99 characters
    float price;
    int year;
};

struct song songs[10]; //creates an array that can hold 10 songs
int count = 0; //track how many songs entered







