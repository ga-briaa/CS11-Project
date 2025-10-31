#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include "parser.h" // Must include! Library for user input

#define clear() printf("\033[H\033[J") // Clears screen
#define MAX_INPUT 100 // Maximum value of player input

char input[MAX_INPUT]; // Player input for actions & movement
bool nextScreen; // Determines if player can go to the next screen

// Displays Main Menu
void menu();
// Starts the game tutorial
void gameIntro();
// Starts the game story
void gameStory();

// Shows 1st ending (non solum.)
void ending1();
// Shows 2nd ending (Good Ending)
void ending2();
// Shows 3rd ending (Good Ending?)
void ending3();

void scare();
int main() {
    menu();
    return 0;
}

void menu() {
    // Displays the title
    clear();
    printf("      _ _\n");
    printf(" __ _| | |\n");
    printf("/ _` | | |\n");
    printf("\\__,_|_|_|\n");
    printf("\t      _\n");
    printf("\t __ _| |___ _ _  ___\n");
    printf("\t/ _` | / _ \\ ' \\/ -_)  _\n");
    printf("\t\\__,_|_\\___/_||_\\__\\  (#)\n");
    
    // Takes user input to go to the next screen
    char response;
    bool isValidResponse = false;
    while (!isValidResponse) {
        // Displays interface
        printf("\n\nChoose an option:");
        printf("\n1 - Start Game");
        printf("\n2 - Exit");
        printf("\n\n>> ");

        scanf(" %c", &response);
        switch(response) {
            case '1':
                // Starts game
                isValidResponse = true;
                gameIntro();
                break;
            case '2':
                // Exits game
                isValidResponse = true;
                exit(0);
                break;
            default:
                // Shows error message
                printf("Invalid input.\n");
        }
    }
}

void gameIntro() {
    // Displays game description and some useful commands
    clear();
    printf("Welcome to all alone.\n");
    printf("\nall alone. is a short horror text-based game, where the story progresses depending on your actions.");
    printf(" You wake up in your new apartment the day after you moved in. However, something is amiss...\n");

    printf("\nSome useful commands:\n"
        "'Look' - Describes the current location or specific object\n"
        "'Go back' or 'Back' - Goes to the previous location or screen\n"
        "'Info' - Lists useful commands\n"
        "'Menu' - Goes to main menu\n");

    printf("\nNote:\nProgress will not be saved once you exit to the main menu.\n"
        "The program only takes simple commands i.e. Look box, Take note.\n");

    // Takes user input to go to the next screen
    char response;
    while(response != 'Y') {
        printf("\nPress Y to start game");
        printf("\n>> ");

        scanf(" %c", &response);
        response = toupper(response);
    }

    // Game introduction
    clear();
    printf("Whatever you do");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);

    printf("\n\nDon't open the door.\n");
    sleep(1);
    printf("Please.");
    sleep(1);

    // Starts the game story
    gameStory();
}

void gameStory() {
    nextScreen = false;

    // Screen 1 - Bedroom
    clear();
    printf("Beep. Beep. Beep.\n");
    sleep(1);
    printf("What a strange dream.\n");
    sleep(1);
    printf("\nYou wake up in your bedroom."
        " It's a little dusty and empty (aside from the piles of boxes), but you'll somehow manage."
        " An open box sits beside your bed."
        " It's probably a good idea to check and clean at least a single box.");

    // Get player input until it goes to the next screen
    while(!nextScreen) {
        // Takes player input
        printf("\n\n>> ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "_\n")] = 0; // Removes newline from input
        screen1(input); // Calls parser for Screen 1 (Bedroom)
    }

    nextScreen = false;

    // Screen 2 - The Box
    clear();
    printf("You pick up the box.");
    sleep(1);
    printf("\n\nOn the side is a label written with a marker \"Important!!\""
        "\nThe box contains some important documents, some chargers and wires, and my journals."
        " At the bottom of the box is a small folded note."
        " There seems to be something written on it.");
    sleep(3);
    printf("\n\nHuh.");
    sleep(1);
    printf(" You don't remember putting this here.");
    sleep(1);
    printf("\nCleaning all this stuff is kinda tiring...");

    // Get player input until it goes to the next screen
    while(!nextScreen) {
        //Takes player input
        printf("\n\n>> ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "_\n")] = 0; // Removes newline from input
        screen2(input); // Calls parser for Screen 2 (The Box)
    }

    nextScreen = false;

    // Screen 3 - The Note
    clear();
    printf("You read the note.");
    sleep(1);
    printf("\n\"it's in your files\"");
    sleep(1);
    printf("\nWhat does that mean?"
        " My files?");
    sleep(1);
    printf("\n\nWhat does it say?");

    // Creates and writes the note
    FILE *note;
    note = fopen("mysterious_note.txt", "w");

    if(note != NULL) {
        fprintf(note, "it's too late to turn back now.\n\n");
        fprintf(note, "remember this:\n\n");
        fprintf(note, "\tnon\n\n\t\tsolum");
    } else {
        // Error message
        printf("\nYou can't see it.");
        printf("\nBut you have a strange feeling it says \"non solum\"");
    }
    fclose(note);

    // Get player input until it goes to the next screen
    while(!nextScreen) {
        //Takes player input
        printf("\n\n>> ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "_\n")] = 0; // Removes newline from input
        screen3(input); // Calls parser for Screen 3 (The Note)
    }

    nextScreen = false;

    // Screen 4 - The Rock
    clear();
    printf("In your apartment, nothing much has changed.");
    sleep(1);
    printf("\nExcept for the window broken open by what seems like a rock taped with a piece of paper.");
    sleep(1);
    printf("\n\nHow did this even happen? Who would do such a thing?");
    
    // Get player input until it goes to the next screen
    while(!nextScreen) {
        //Takes player input
        printf("\n\n>> ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "_\n")] = 0; // Removes newline from input
        screen4(input); // Calls parser for Screen 4 (The Rock)
    }

    nextScreen = false;

    // Screen 5 - The Paper
    clear();
    printf("You take the paper.");
    sleep(1);
    printf("\nIt has something written on it."
        " You read its contents.");
        sleep(1);
    printf("\n\nSomething about my file?"
        "\nBash? Really? Is this a joke?");
    sleep(1);
    printf("\n\nWhat does it say?");

    // Creates and writes paper
    FILE *paper;
    paper = fopen("atBASH.txt", "w");
        
    if(paper != NULL) {
        fprintf(paper, "i can see you\n\n");
        fprintf(paper, "remember:\n");

        for(int i = 0; i < 35; i++) {
            fprintf(paper, "\nnon solum. ");
            fprintf(paper, "non solum. ");
        }

        fprintf(paper, "\n\nwlm'g lkvm rg.");
        fprintf(paper, "\nivnvnyvi gsrh: xolhvw wlli");
        fprintf(paper, "\nwlm'g ovg rg r");
    } else {
        // Error message
        printf("\nYou can't see the file.");
        printf("\nYou need to find it.");
    }
    fclose(paper);

    // Get player input until it goes to the next screen
    while(!nextScreen) {
        //Takes player input
        printf("\n\n>> ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "_\n")] = 0; // Removes newline from input
        screen5(input); // Calls parser for Screen 5 (The Paper)
    }

    nextScreen = false;
}

void ending1() {
    // Screen for 1st ending
    clear();
    printf("The front door is now wide open.");
    sleep(1);
    printf("\nYou expect someone to be there,");
    sleep(1);
    printf(" but nobody is there.");
    sleep(1);
    printf("\nYou look outside the hallways and");
    sleep(1);
    printf("\n\tyou see");
    sleep(1);
    printf(" \tno one.");
    sleep(1);
    printf("\n\nAt the doorstep is a piece of paper. You take it.");
    sleep(1);
    printf("\nThis has got to be some sick prank.");
    sleep(1);
    printf("\n\n\"read it. from the same way.\"");
    printf("\nAnother file?");
    sleep(1);
    printf("\n\nWhat does it say?");

    // Creates and writes the final paper
    FILE *final;
    final = fopen("non_solum.txt", "w");

    if(final != NULL) {
        fprintf(final, "behind you");
    } else {
        printf("behind you");
    }
    fclose(final);

    printf("\n\n>> ");
    getchar();

    scare();
    clear();
    printf("Ending 1/3");
    printf("\nnon solum.");
    printf("\n\nPress ENTER to go to main menu.");
    getchar();
    menu();
}

void ending2() {
    // Screen for 2nd ending
    clear();
    printf("Whoever's doing this is sick.");
    sleep(1);
    printf("\n\nYou decided to lock yourself in your bedroom."
        " Is someone actually out there?");
    sleep(1);
    printf("\n\nNot taking any chances, you call the cops to your address.");
    printf("\nThankfully, they arrived pretty quickly and escorted you to somewhere safe.");
    sleep(1);
    printf("\n\nYou swear that you heard thumping noises before the police arrived.");
    sleep(2);
    printf("\n\nEnding 2/3");
    printf("\nGood Ending");

    printf("\n\nPress ENTER to go to main menu.");
    getchar();
    menu();
}

void ending3() {
    // Screen for 3rd ending
    clear();
    printf("You are standing in your bedroom.");
    sleep(1);
    printf("\nMaybe it is still too early to clean things up...");
    sleep(1);
    printf("\n\nYou went on with your day and eventually forgot about the note."
        "\nWhen you finally remembered, the note was nowhere to be found.");
    sleep(1);
    printf("\n\nYou wonder who put it there and where did it go?");
    sleep(2);
    printf("\n\nEnding 3/3");
    printf("\nGood Ending?");

    printf("\n\nPress ENTER to go to main menu.");
    getchar();
    menu();
}

void scare() {
    clear();
    for(int i = 0; i < 25; i++) {
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    }
    sleep(1);
    
    clear();
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣛⠟⢒⠀⠂⠀⠐⠋⡰⢗⠳⠖⢷⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣷⣉⢶⣲⣐⡀⠀⣀⣨⣷⣳⡀⠈⢈⢨⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣹⠟⣟⠁⢿⢦⢊⠊⡗⠘⡑⠙⠊⠀⠈⠘⣿⣟⢿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠉⡢⠁⠀⠈⠉⠀⠁⠘⠈⠉⠀⠀⠀⠀⠀⠀⠀⠕⠆⡫⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣅⡒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠢⠊⠛⢟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⡿⣲⣾⡕⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢶⡶⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢶⡭⠅⠋⠊⠍⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣌⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢱⣠⡐⣂⣦⣼⡿⣿⣆⣆⠀⠀⠀⠀⠀⢀⣠⣴⣶⣶⣦⣤⠀⠀⠘⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾⣿⣿⣿⣿⡿⣎⠿⣿⣿⣷⡀⠀⠀⣾⣿⣻⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣺⣿⣿⣿⣿⣿⣿⣿⣙⣷⣼⣿⣿⠧⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢿⣿⣿⣿⣿⣿⡿⣿⣿⡿⠋⠋⠁⠀⠀⠻⣿⡿⣿⣿⣿⡿⢿⣿⣟⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⣬⣿⣷⣿⣽⣥⣼⡿⠛⠁⠀⠀⠀⠀⠀⠀⠘⠳⣬⣽⣭⣾⠿⠛⣡⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣏⠁⠁⠈⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⢯⢛⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣯⡀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠠⣬⣢⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⣧⡼⠀⠈⠀⠀⠀⠸⠆⠀⠀⠠⠀⠀⠀⠀⠀⠀⠀⣰⣾⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣿⣽⣦⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨⡟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣤⣤⣄⣤⣤⣤⣶⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⣛⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⡻⢞⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    sleep(1);
}