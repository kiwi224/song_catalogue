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

void printCatalogue()
{
    printf("\nSong Catalogue:\n");
    for(int i = 0; i < count; i++)
    {
        printf("Singer: %s\n", songs[i].singer);
        printf("Song Name: %s\n", songs[i].songName);
        printf("Price: %.2f\n", songs[i].price);
        printf("Year: %d\n", songs[i].year);
        printf("---------------------\n");
    }
}

void saveToFile()
{
    FILE *file = fopen("songs.txt", "w");
    if(file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        fprintf(file, "%s\n%s\n%.2f\n%d\n", songs[i].singer, songs[i].songName, songs[i].price, songs[i].year);
    }

    fclose(file);
    printf("Data saved to file successfully.\n");
}

void sortSongs()
{
    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if(strcmp(songs[j].singer, songs[j + 1].singer) > 0)
            {
                struct Song temp = songs[j];
                songs[j] = songs[j + 1];
                songs[j + 1] = temp;
            }
        }
    }
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

        } while(choice !=5);

        return 0;
        
}







