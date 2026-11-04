#include <stdio.h> //contains functions
#include <string.h> //string functions

// Structure to store song details
struct Song  //everything stored inside 'type' song
{
    char singer[50];
    char songName[100];
    float price;
    int year;
};

// Array to store songs
struct Song songs[10];
int count = 0;

// Function to enter song data
void enterData()
{
    printf("Singer: ");
    scanf(" %[^\n]", songs[count].singer);

    printf("Song Name: ");
    scanf(" %[^\n]", songs[count].songName);

    printf("Price: ");
    scanf("%f", &songs[count].price);

    printf("Year: ");
    scanf("%d", &songs[count].year);

    count++;

    printf("Song added successfully!\n");
}

// Function to save songs to file
void saveToFile()
{
    FILE *file;

    file = fopen("songs.txt", "w");

    if(file == NULL)
    {
        printf("File could not be opened.\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        fprintf(file, "%s\n", songs[i].singer);
        fprintf(file, "%s\n", songs[i].songName);
        fprintf(file, "%f\n", songs[i].price);
        fprintf(file, "%d\n", songs[i].year);
    }

    fclose(file);

    printf("Data saved successfully.\n");
}

// Function to read songs from file
void readFromFile()
{
    FILE *file;

    file = fopen("songs.txt", "r");

    if(file == NULL)
    {
        printf("File could not be opened.\n");
        return;
    }

    count = 0;

    while(fscanf(file, " %[^\n]", songs[count].singer) == 1)
    {
        fscanf(file, " %[^\n]", songs[count].songName);
        fscanf(file, "%f", &songs[count].price);
        fscanf(file, "%d", &songs[count].year);

        count++;
    }

    fclose(file);

    printf("Data loaded successfully.\n");
}

// Sort songs by year (newest to oldest)
void sortSongs()
{
    int i, j;
    struct Song temp;

    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(songs[j].year < songs[j + 1].year)
            {
                temp = songs[j];
                songs[j] = songs[j + 1];
                songs[j + 1] = temp;
            }
        }
    }
}

// Print all songs
void printCatalogue()
{
    int i;

    printf("\nSong Catalogue\n");

    for(i = 0; i < count; i++)
    {
        printf("\nSinger: %s\n", songs[i].singer);
        printf("Song Name: %s\n", songs[i].songName);
        printf("Price: %.2f\n", songs[i].price);
        printf("Year: %d\n", songs[i].year);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\nSong Catalogue\n");
        printf("1. Enter Data\n");
        printf("2. Save Data To File\n");
        printf("3. Read Data From File\n");
        printf("4. Print Catalogue\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enterData();
                break;

            case 2:
                saveToFile();
                break;

            case 3:
                readFromFile();
                break;

            case 4:
                sortSongs();
                printCatalogue();
                break;

            case 5:
                printf("Program Closed.\n");
                break;

            default:
                printf("Invalid Choice.\n");
        }

    } while(choice != 5);

    return 0;
}