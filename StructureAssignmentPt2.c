#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

char rowLetters[6] = {'A','B','C','D','X'};

struct planeSeat{
    char row1[5];
    char row2[5];
    char row3[5];
    char row4[5];
    char row5[5];
};

void DisplaySeats(struct planeSeat plane);

int main(){
    struct planeSeat myPlane;
    bool exit = false, validinput = false, cancelling = false;
    char inpSeat[6], rowSelected[2];
    int selectedRow, len;

    //Initialize the Seats
    for(int i = 0; i<4; i++) myPlane.row1[i] = rowLetters[i];
    for(int i = 0; i<4; i++) myPlane.row2[i] = rowLetters[i];
    for(int i = 0; i<4; i++) myPlane.row3[i] = rowLetters[i];
    for(int i = 0; i<4; i++) myPlane.row4[i] = rowLetters[i];
    for(int i = 0; i<4; i++) myPlane.row5[i] = rowLetters[i];

   
    while(!exit){
        printf("Please input the seats on the plane you wish to occupy [e.g. 1A,4b]\nIf you are done selecting, please type DONE\nTo cancel a seat, please type CANCEL\n");
        do{
            DisplaySeats(myPlane);
            printf("\nSelect seat: ");
            scanf("%s", inpSeat);
            len = sizeof(inpSeat)/sizeof(inpSeat[0]);
            for(int i = 0; i<len; i++) inpSeat[i] = toupper(inpSeat[i]);
            if(isdigit(inpSeat[0])){
                rowSelected[0] = inpSeat[0];
                selectedRow = atoi(rowSelected);
                validinput = true;
                switch(selectedRow){
                    case 1:
                        if(inpSeat[1] == 'A' && myPlane.row1[0] != 'X') myPlane.row1[0] = rowLetters[4];
                        else if(inpSeat[1] == 'B' && myPlane.row1[1] != 'X') myPlane.row1[1] = rowLetters[4];
                        else if(inpSeat[1] == 'C' && myPlane.row1[2] != 'X') myPlane.row1[2] = rowLetters[4];
                        else if(inpSeat[1] == 'D' && myPlane.row1[3] != 'X') myPlane.row1[3] = rowLetters[4];
                        else{
                            printf("Invalid Input. Please Reinput.");
                            validinput = false;
                        }
                        break;
                    case 2:
                        if(inpSeat[1] == 'A' && myPlane.row2[0] != 'X') myPlane.row2[0] = rowLetters[4];
                        else if(inpSeat[1] == 'B' && myPlane.row2[1] != 'X') myPlane.row2[1] = rowLetters[4];
                        else if(inpSeat[1] == 'C' && myPlane.row2[2] != 'X') myPlane.row2[2] = rowLetters[4];
                        else if(inpSeat[1] == 'D' && myPlane.row2[3] != 'X') myPlane.row2[3] = rowLetters[4];
                        else{
                            printf("Invalid Input. Please Reinput.");
                            validinput = false;
                        }
                        break;
                    case 3:
                        if(inpSeat[1] == 'A' && myPlane.row3[0] != 'X') myPlane.row3[0] = rowLetters[4];
                        else if(inpSeat[1] == 'B' && myPlane.row3[1] != 'X') myPlane.row3[1] = rowLetters[4];
                        else if(inpSeat[1] == 'C' && myPlane.row3[2] != 'X') myPlane.row3[2] = rowLetters[4];
                        else if(inpSeat[1] == 'D' && myPlane.row3[3] != 'X') myPlane.row3[3] = rowLetters[4];
                        else{
                            printf("Invalid Input. Please Reinput.");
                            validinput = false;
                        }
                        break;
                    case 4:
                        if(inpSeat[1] == 'A' && myPlane.row4[0] != 'X') myPlane.row4[0] = rowLetters[4];
                        else if(inpSeat[1] == 'B' && myPlane.row4[1] != 'X') myPlane.row4[1] = rowLetters[4];
                        else if(inpSeat[1] == 'C' && myPlane.row4[2] != 'X') myPlane.row4[2] = rowLetters[4];
                        else if(inpSeat[1] == 'D' && myPlane.row4[3] != 'X') myPlane.row4[3] = rowLetters[4];
                        else{
                            printf("Invalid Input. Please Reinput.");
                            validinput = false;
                        }
                        break;
                    case 5:
                        if(inpSeat[1] == 'A' && myPlane.row5[0] != 'X') myPlane.row5[0] = rowLetters[4];
                        else if(inpSeat[1] == 'B' && myPlane.row5[1] != 'X') myPlane.row5[1] = rowLetters[4];
                        else if(inpSeat[1] == 'C' && myPlane.row5[2] != 'X') myPlane.row5[2] = rowLetters[4];
                        else if(inpSeat[1] == 'D' && myPlane.row5[3] != 'X') myPlane.row5[3] = rowLetters[4];
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
            }
            else if(strcmp(inpSeat, "CANCEL") == 0){
                cancelling = true;
                validinput = false;
                while(cancelling){
                    printf("Please select the seat you wish to cancel: ");
                    scanf("%s", inpSeat);
                    len = sizeof(inpSeat)/sizeof(inpSeat[0]);
                    for(int i = 0; i<len; i++) inpSeat[i] = toupper(inpSeat[i]);
                    if(isdigit(inpSeat[0])){
                        validinput = true;
                        rowSelected[0] = inpSeat[0];
                        selectedRow = atoi(rowSelected);
                        switch(selectedRow){
                            case 1:
                                if(inpSeat[1] == 'A' && myPlane.row1[0] == 'X') myPlane.row1[0] = rowLetters[0];
                                else if(inpSeat[1] == 'B' && myPlane.row1[1] == 'X') myPlane.row1[1] = rowLetters[1];
                                else if(inpSeat[1] == 'C' && myPlane.row1[2] == 'X') myPlane.row1[2] = rowLetters[2];
                                else if(inpSeat[1] == 'D' && myPlane.row1[3] == 'X') myPlane.row1[3] = rowLetters[3];
                                else{
                                    printf("Seat is not Cancellable (Open Seat). Stopping Cancellation.");
                                    validinput = false;
                                }
                                break;
                            case 2:
                                if(inpSeat[1] == 'A' && myPlane.row2[0] == 'X') myPlane.row1[0] = rowLetters[0];
                                else if(inpSeat[1] == 'B' && myPlane.row2[1] == 'X') myPlane.row1[1] = rowLetters[1];
                                else if(inpSeat[1] == 'C' && myPlane.row2[2] == 'X') myPlane.row1[2] = rowLetters[2];
                                else if(inpSeat[1] == 'D' && myPlane.row2[3] == 'X') myPlane.row1[3] = rowLetters[3];
                                else{
                                    printf("Seat is not Cancellable (Open Seat). Stopping Cancellation.");
                                    validinput = false;
                                }
                                break;
                            case 3:
                                if(inpSeat[1] == 'A' && myPlane.row3[0] == 'X') myPlane.row1[0] = rowLetters[0];
                                else if(inpSeat[1] == 'B' && myPlane.row3[1] == 'X') myPlane.row1[1] = rowLetters[1];
                                else if(inpSeat[1] == 'C' && myPlane.row3[2] == 'X') myPlane.row1[2] = rowLetters[2];
                                else if(inpSeat[1] == 'D' && myPlane.row3[3] == 'X') myPlane.row1[3] = rowLetters[3];
                                else{
                                    printf("Seat is not Cancellable (Open Seat). Stopping Cancellation.");
                                    validinput = false;
                                }
                                break;
                            case 4:
                                if(inpSeat[1] == 'A' && myPlane.row4[0] == 'X') myPlane.row1[0] = rowLetters[0];
                                else if(inpSeat[1] == 'B' && myPlane.row4[1] == 'X') myPlane.row1[1] = rowLetters[1];
                                else if(inpSeat[1] == 'C' && myPlane.row4[2] == 'X') myPlane.row1[2] = rowLetters[2];
                                else if(inpSeat[1] == 'D' && myPlane.row4[3] == 'X') myPlane.row1[3] = rowLetters[3];
                                else{
                                    printf("Seat is not Cancellable (Open Seat). Stopping Cancellation.");
                                    validinput = false;
                                }
                                break;
                            case 5:
                                if(inpSeat[1] == 'A' && myPlane.row5[0] == 'X') myPlane.row1[0] = rowLetters[0];
                                else if(inpSeat[1] == 'B' && myPlane.row5[1] == 'X') myPlane.row1[1] = rowLetters[1];
                                else if(inpSeat[1] == 'C' && myPlane.row5[2] == 'X') myPlane.row1[2] = rowLetters[2];
                                else if(inpSeat[1] == 'D' && myPlane.row5[3] == 'X') myPlane.row1[3] = rowLetters[3];
                                else{
                                    printf("Seat is not Cancellable (Open Seat). Stopping Cancellation.");
                                    validinput = false;
                                }
                                break;
                            default:
                                printf("Invalid Input. Please Reinput.");
                                validinput = false;
                                break;
                        }
                    }
                    if(!validinput) cancelling = true;
                    else cancelling = false;
                }
            }
            else if(strcmp(inpSeat, "DONE") == 0){
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
}

void DisplaySeats(struct planeSeat plane){
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
