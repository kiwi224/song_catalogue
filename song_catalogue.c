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

int main()
{
    int choice;  //menu choice

    do
    {
        printf("\nSong catalogue\n");
        printf("1.Enter Data\n");
        printf("2.save to File\n");
        printf("3.Read from File\n");
        printf("4.Print catalogue\n");
        printf("5.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        } while(choice !=5);

        return 0;
        
}




    return 0;
}






