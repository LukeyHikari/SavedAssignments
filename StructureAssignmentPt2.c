#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

char rowLetters[6] = {'A','B','C','D','X'};

struct PlaneSeats{
    char row1[5];
    char row2[5];
    char row3[5];
    char row4[5];
    char row5[5];
};

void displaySeats(struct PlaneSeats plane);
bool selectSeat(struct PlaneSeats *plane, char *seat);
bool cancelSeat(struct PlaneSeats *plane);

int main(){
    struct PlaneSeats myPlane;
    bool exit = false, validinput = false;
    char inputtedSeat[6];
    int len;

    //Initialize the Seats
    for (int i = 0; i<4; i++) {
        myPlane.row1[i] = rowLetters[i];
        myPlane.row2[i] = rowLetters[i];
        myPlane.row3[i] = rowLetters[i];
        myPlane.row4[i] = rowLetters[i];
        myPlane.row5[i] = rowLetters[i];
    }
   
    while(!exit){
        printf("Please input the seats on the plane you wish to occupy [e.g. 1A,4b]\nIf you are done selecting, please type DONE\nTo cancel a seat, please type CANCEL\n");
        do{
            displaySeats(myPlane);
            printf("\nSelect seat: ");
            scanf("%s", inputtedSeat);
            len = sizeof(inputtedSeat)/sizeof(inputtedSeat[0]);
            for(int i = 0; i<len; i++) inputtedSeat[i] = toupper(inputtedSeat[i]);
            printf("\n%c\n", myPlane.row1[0]);
            if(isdigit(inputtedSeat[0])){
                printf("\n%c\n\n", myPlane.row1[0]);
                //validinput = selectSeat(&myPlane, inputtedSeat);
            }
            else if(strcmp(inputtedSeat, "CANCEL") == 0){
                printf("\n%c\n", myPlane.row1[0]);
                //validinput = cancelSeat(&myPlane);
            }
            else if(strcmp(inputtedSeat, "DONE") == 0){
                printf("You have finished inputting the seats. Thank you.");
                validinput = true;
                exit = true;
            }
            else{
            printf("Invalid Input. Please Reinput.");
            validinput = false;
            }
        }while(validinput == false);
    }

    printf("\nThe final seating is:\n");
    displaySeats(myPlane);
}

bool selectSeat(struct PlaneSeats *plane, char *seat){
    char rowSelected[2];
    int selectedRow;
    bool validinput = true;
    
    rowSelected[0] = seat[0];
    selectedRow = atoi(rowSelected);
    switch(selectedRow){
        case 1:
            if(seat[1] == 'A' && plane->row1[0] != 'X') plane->row1[0] = rowLetters[4];
            else if(seat[1] == 'B' && plane->row1[1] != 'X') plane->row1[1] = rowLetters[4];
            else if(seat[1] == 'C' && plane->row1[2] != 'X') plane->row1[2] = rowLetters[4];
            else if(seat[1] == 'D' && plane->row1[3] != 'X') plane->row1[3] = rowLetters[4];
            else{
                printf("Invalid Input. Please Reinput.");
                validinput = false;
            }
            break;
        case 2:
            if(seat[1] == 'A' && plane->row2[0] != 'X') plane->row2[0] = rowLetters[4];
            else if(seat[1] == 'B' && plane->row2[1] != 'X') plane->row2[1] = rowLetters[4];
            else if(seat[1] == 'C' && plane->row2[2] != 'X') plane->row2[2] = rowLetters[4];
            else if(seat[1] == 'D' && plane->row2[3] != 'X') plane->row2[3] = rowLetters[4];
            else{
                printf("Invalid Input. Please Reinput.");
                validinput = false;
            }
            break;
        case 3:
            if(seat[1] == 'A' && plane->row3[0] != 'X') plane->row3[0] = rowLetters[4];
            else if(seat[1] == 'B' && plane->row3[1] != 'X') plane->row3[1] = rowLetters[4];
            else if(seat[1] == 'C' && plane->row3[2] != 'X') plane->row3[2] = rowLetters[4];
            else if(seat[1] == 'D' && plane->row3[3] != 'X') plane->row3[3] = rowLetters[4];
            else{
                printf("Invalid Input. Please Reinput.");
                validinput = false;
            }
            break;
        case 4:
            if(seat[1] == 'A' && plane->row4[0] != 'X') plane->row4[0] = rowLetters[4];
            else if(seat[1] == 'B' && plane->row4[1] != 'X') plane->row4[1] = rowLetters[4];
            else if(seat[1] == 'C' && plane->row4[2] != 'X') plane->row4[2] = rowLetters[4];
            else if(seat[1] == 'D' && plane->row4[3] != 'X') plane->row4[3] = rowLetters[4];
            else{
                printf("Invalid Input. Please Reinput.");
                validinput = false;
            }
            break;
        case 5:
            if(seat[1] == 'A' && plane->row5[0] != 'X') plane->row5[0] = rowLetters[4];
            else if(seat[1] == 'B' && plane->row5[1] != 'X') plane->row5[1] = rowLetters[4];
            else if(seat[1] == 'C' && plane->row5[2] != 'X') plane->row5[2] = rowLetters[4];
            else if(seat[1] == 'D' && plane->row5[3] != 'X') plane->row5[3] = rowLetters[4];
            else{
                printf("Invalid Input. Please Reinput.");
                validinput = false;
            }
            break;
        default:
            printf("Invalid Input. Please Reinput.");
            validinput = false;
            break;
    }

    return validinput;
}

bool cancelSeat(struct PlaneSeats *plane){
    bool cancelling = true, validinput = false;
    int len, selectedRow;
    char inputtedSeat[6], rowSelected[2];
    printf("%c", plane->row1[0]);
    // while(cancelling){
    //     printf("Please select the seat you wish to cancel: ");
    //     scanf("%s", inputtedSeat);
    //     len = sizeof(inputtedSeat)/sizeof(inputtedSeat[0]);
    //     for(int i = 0; i<len; i++) inputtedSeat[i] = toupper(inputtedSeat[i]);

    //     if(isdigit(inputtedSeat[0])){
    //         validinput = true;
    //         rowSelected[0] = inputtedSeat[0];
    //         selectedRow = atoi(rowSelected);

    //         switch(selectedRow){
    //             case 1:
    //                 if(inputtedSeat[1] == 'A' && plane->row1[0] == 'X') plane->row1[0] = rowLetters[0];
    //                 else if(inputtedSeat[1] == 'B' && plane->row1[1] == 'X') plane->row1[1] = rowLetters[1];
    //                 else if(inputtedSeat[1] == 'C' && plane->row1[2] == 'X') plane->row1[2] = rowLetters[2];
    //                 else if(inputtedSeat[1] == 'D' && plane->row1[3] == 'X') plane->row1[3] = rowLetters[3];
    //                 else{
    //                     printf("Seat is not Cancellable (Open Seat). Stopping Cancellation.");
    //                     validinput = false;
    //                 }
    //                 break;
    //             case 2:
    //                 if(inputtedSeat[1] == 'A' && plane->row2[0] == 'X') plane->row2[0] = rowLetters[0];
    //                 else if(inputtedSeat[1] == 'B' && plane->row2[1] == 'X') plane->row2[1] = rowLetters[1];
    //                 else if(inputtedSeat[1] == 'C' && plane->row2[2] == 'X') plane->row2[2] = rowLetters[2];
    //                 else if(inputtedSeat[1] == 'D' && plane->row2[3] == 'X') plane->row2[3] = rowLetters[3];
    //                 else{
    //                     printf("Seat is not Cancellable (Open Seat). Stopping Cancellation.");
    //                     validinput = false;
    //                 }
    //                 break;
    //             case 3:
    //                 if(inputtedSeat[1] == 'A' && plane->row3[0] == 'X') plane->row3[0] = rowLetters[0];
    //                 else if(inputtedSeat[1] == 'B' && plane->row3[1] == 'X') plane->row3[1] = rowLetters[1];
    //                 else if(inputtedSeat[1] == 'C' && plane->row3[2] == 'X') plane->row3[2] = rowLetters[2];
    //                 else if(inputtedSeat[1] == 'D' && plane->row3[3] == 'X') plane->row3[3] = rowLetters[3];
    //                 else{
    //                     printf("Seat is not Cancellable (Open Seat). Stopping Cancellation.");
    //                     validinput = false;
    //                 }
    //                 break;
    //             case 4:
    //                 if(inputtedSeat[1] == 'A' && plane->row4[0] == 'X') plane->row4[0] = rowLetters[0];
    //                 else if(inputtedSeat[1] == 'B' && plane->row4[1] == 'X') plane->row4[1] = rowLetters[1];
    //                 else if(inputtedSeat[1] == 'C' && plane->row4[2] == 'X') plane->row4[2] = rowLetters[2];
    //                 else if(inputtedSeat[1] == 'D' && plane->row4[3] == 'X') plane->row4[3] = rowLetters[3];
    //                 else{
    //                     printf("Seat is not Cancellable (Open Seat). Stopping Cancellation.");
    //                     validinput = false;
    //                 }
    //                 break;
    //             case 5:
    //                 if(inputtedSeat[1] == 'A' && plane->row5[0] == 'X') plane->row5[0] = rowLetters[0];
    //                 else if(inputtedSeat[1] == 'B' && plane->row5[1] == 'X') plane->row5[1] = rowLetters[1];
    //                 else if(inputtedSeat[1] == 'C' && plane->row5[2] == 'X') plane->row5[2] = rowLetters[2];
    //                 else if(inputtedSeat[1] == 'D' && plane->row5[3] == 'X') plane->row5[3] = rowLetters[3];
    //                 else{
    //                     printf("Seat is not Cancellable (Open Seat). Stopping Cancellation.");
    //                     validinput = false;
    //                 }
    //                 break;
    //             default:
    //                 printf("Invalid Input. Please Reinput.");
    //                 validinput = false;
    //                 break;
    //         }
    //     }
    //     if(!validinput) cancelling = true;
    //     else cancelling = false;
    // }

    return validinput;
}

void displaySeats(struct PlaneSeats plane){
    //Print the Plane Seats
    printf("1\t");
    for(int i = 0; i<4; i++) printf("%c\t",plane.row1[i]);
    printf("\n2\t");
    for(int i = 0; i<4; i++) printf("%c\t",plane.row2[i]);
    printf("\n3\t");
    for(int i = 0; i<4; i++) printf("%c\t",plane.row3[i]);
    printf("\n4\t");
    for(int i = 0; i<4; i++) printf("%c\t",plane.row4[i]);
    printf("\n5\t");
    for(int i = 0; i<4; i++) printf("%c\t",plane.row5[i]);
}
