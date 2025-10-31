
// This is a required file!

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

void menu();
void ending1();
void ending2();
void ending3();
extern bool nextScreen;

// Parser for bedroom (Screen 1)
bool screen1(char *input) {
    // Turns player input into lowercase
    for(int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // List of valid player input
    if(strcmp(input, "check box") == 0 || strcmp(input, "look box") == 0) {         // Checks the box
        printf("You check the contents of the box.");
        printf("\n\nPress ENTER to continue.");
        getchar();

        nextScreen = true;
    } else if(strcmp(input, "open box") == 0) {                                     // Opens the box
        printf("The box is already opened.");
    } else if(strcmp(input, "look around") == 0 || strcmp(input, "look") == 0) {    // Look around
        printf("Your new bedroom. A little old, but it's the best that you found.");
    } else if(strcmp(input, "info") == 0) {                                         // Shows useful commands
        printf("\nSome useful commands:\n"
            "'Look' - Describes the current location or specific object\n"
            "'Go back' or 'Back' - Goes to the previous location or screen\n"
            "'Info' - Lists useful commands\n"
            "'Menu' - Goes to main menu\n");

        printf("\nNote:\nProgress will not be saved once you exit to the main menu.\n"
            "The program only takes simple commands i.e. Look box, Take note.");
    } else if(strcmp(input, "menu") == 0) {                                         // Goes back to main menu
        nextScreen = true;
        menu();
    } else {                                                                        // Invalid input.
        printf("You think you should get the open box cleared up before you start your day.");
    }
    return nextScreen;
}

// Parser for the box (Screen 2)
bool screen2(char *input) {
    // Turns player input into lowercase
    for(int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // List of valid player input
    if(strcmp(input, "read note") == 0 || strcmp(input, "look note") == 0 || strcmp(input, "look") == 0) {  // End 1 & 2 Read the note
        printf("You pick up the note.");
        printf("\n\nPress ENTER to continue.");
        getchar();

        nextScreen = true;
    } else if(strcmp(input, "go back") == 0 || strcmp(input, "back") == 0) {                                // End 3 - Don't read the note
        printf("You decide not to clean the box.");
        printf("\n\nPress ENTER to continue.");
        getchar();

        nextScreen = true;
        ending3();
    } else if(strcmp(input, "info") == 0) {                                                                 // Shows useful commands
        printf("\nSome useful commands:\n"
            "'Look' - Describes the current location or specific object\n"
            "'Go back' or 'Back' - Goes to the previous location or screen\n"
            "'Info' - Lists useful commands\n"
            "'Menu' - Goes to main menu\n");

        printf("\nNote:\nProgress will not be saved once you exit to the main menu.\n"
            "The program only takes simple commands i.e. Look box, Take note.");
    } else if(strcmp(input, "menu") == 0) {                                                                 // Goes back to main menu
        nextScreen = true;
        menu();
    } else {                                                                                                // Invalid input
        printf("Should I read the note?");
    }
    return nextScreen;
}

bool screen3(char *input) {
    // Turns player input into lowercase
    for(int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    if(strcmp(input, "non solum") == 0) {                                   // Non solum.
        printf("Non solum? What does that mean?");
        sleep(1);
        printf("\n\nA loud crash can be heard outside."
            " You can clearly hear the howl of the wind through the window."
            " Was there an open window somewhere?");
        sleep(2);
        printf("\n\nYou decide to go check out what happened.");

        printf("\n\nPress ENTER to continue.");
        getchar();
        
        nextScreen = true;
    } else if(strcmp(input, "info") == 0) {                                 // Shows useful commands
        printf("\nSome useful commands:\n"
            "'Look' - Describes the current location or specific object\n"
            "'Go back' or 'Back' - Goes to the previous location or screen\n"
            "'Info' - Lists useful commands\n"
            "'Menu' - Goes to main menu\n");

        printf("\nNote:\nProgress will not be saved once you exit to the main menu.\n"
            "The program only takes simple commands i.e. Look box, Take note.");
    } else if(strcmp(input, "menu") == 0) {                                 // Goes back to main menu
        nextScreen = true;
        menu();
    } else {                                                                // Invalid input
        printf("what does it say?");
    }
    return nextScreen;
}

bool screen4(char *input) {
    // Turns player input into lowercase
    for(int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    if(strcmp(input, "look paper") == 0 || strcmp(input, "take paper") == 0) {                          // Read the piece of paper
        printf("You picked up the piece of paper.");
        printf("\n\nPress ENTER to continue.");
        getchar();

        nextScreen = true;
    } else if(strcmp(input, "look rock") == 0) {                                                        // Look at rock
        printf("A small rock with a piece of paper taped on it. Who threw this onto your window?");
    } else if(strcmp(input, "look") == 0 || strcmp(input, "look around") == 0) {                        // Look around your apartment
        printf("Your fifth floor apartment."
            " The cheapest one you could find in the area."
            " You guess you were pretty lucky since this apartment is 5 minutes away from everything.");
    } else if(strcmp(input, "look window") == 0 || strcmp(input, "look outside") == 0) {                // Look outside your window
        printf("You wonder how someone threw a rock all the way up to the fifth floor."
            " From the fire exit? Well, your room is beside it.");
    } else if(strcmp(input, "info") == 0) {                                                             // Shows useful commands
        printf("\nSome useful commands:\n"
            "'Look' - Describes the current location or specific object\n"
            "'Go back' or 'Back' - Goes to the previous location or screen\n"
            "'Info' - Lists useful commands\n"
            "'Menu' - Goes to main menu\n");

        printf("\nNote:\nProgress will not be saved once you exit to the main menu.\n"
            "The program only takes simple commands i.e. Look box, Take note.");
    } else if(strcmp(input, "menu") == 0) {                                                             // Goes back to main menu
        nextScreen = true;
        menu();
    } else {                                                                                            // Invalid input
        printf("What should I do?");
    }
    return nextScreen;
}

bool screen5(char *input) {
    // Turns player input into lowercase
    for(int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    if(strcmp(input, "non solum") == 0 || strcmp(input, "non solum.") == 0) {       // End 1 - Non solum.
        printf("The front door creaked slowly.");
        printf("\n\nPress ENTER to continue.");
        getchar();

        nextScreen = true;
        ending1();
    } else if(strcmp(input, "closed door") == 0) {                                  // End 2 - Closed door
        printf("You immediately lock the front door.");
        printf("\n\nPress ENTER to continue.");
        getchar();

        nextScreen = true;
        ending2();
    } else if(strcmp(input, "info") == 0) {                                         // Shows useful commands
        printf("\nSome useful commands:\n"
            "'Look' - Describes the current location or specific object\n"
            "'Go back' or 'Back' - Goes to the previous location or screen\n"
            "'Info' - Lists useful commands\n"
            "'Menu' - Goes to main menu\n");

        printf("\nNote:\nProgress will not be saved once you exit to the main menu.\n"
            "The program only takes simple commands i.e. Look box, Take note.");
    } else if(strcmp(input, "menu") == 0) {                                         // Goes back to main menu
        nextScreen = true;
        menu();
    } else {                                                                        // Invalid input
        printf("what does it say");
    }
    return nextScreen;
}