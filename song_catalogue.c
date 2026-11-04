#include <stdio.h>  //stdio.h contains functions
#include <string.h> //string functions

struct Song // everything stored inside 'type' song
{
    char singer[50]; //up to 49 characters
    char songName[100]; //up to 99 characters
    float price;
    int year;
};

struct Song songs[10]; //creates an array that can hold 10 songs
int count = 0; //track how many songs entered

void enterdata()
{
    printf("Singer:");
    scanf(" %[^\n]s", songs[count].singer); //reads string with spaces
    printf("Song Name:");
    scanf(" %[^\n]s", songs[count].songName);
    printf("Price:");
    scanf("%f", &songs[count].price);
    printf("Year:");
    scanf("%d", &songs[count].year);  
    
    count++; //increment count after each song entered

}

switch(choice)
{
    case 1:
        enterdata();
        break;
    case 2:
        saveToFile();
        break;
    case 3:
        readFromFile();
        break;
    case 4:
        printCatalogue();
        break;
    case 5:
        printf("Exiting program.\n");
        break;
    default:
        printf("Invalid choice. Please try again.\n");
}
int main(void)
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







