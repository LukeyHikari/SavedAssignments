#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

struct hand getHand();
const char* handEval(struct hand Hand);

struct hand{
    int Pip[5];
    int Suite[5]; 
};

int main(){
    struct hand inpHand;
    
    inpHand = getHand();
    //Print the Hand
    printf("Your inputted hand is:");
    for(int i = 0; i<5; i++){
        //Pips
        switch (inpHand.Pip[i]){
            case 1:
                printf("\nAce | ");
                break;
            case 11:
                printf("\nJack | ");
                break;
            case 12:
                printf("\nQueen | ");
                break;
            case 13:
                printf("\nKing | ");
                break;
            default:
                printf("\n%d | ", inpHand.Pip[i]);
                break;
        }
        //Suites
        switch (inpHand.Suite[i]){
            case 1:
                printf("Flower/Club");
                break;
            case 2:
                printf("Spade");
                break;
            case 3:
                printf("Heart");
                break;
            case 4:
                printf("Diamond");
                break;
        }
    }
    printf("\n\nYour hand is a %s", handEval(inpHand));
}

struct hand getHand(){
    struct hand tempHand;
    char pipInput[10], suiteInput[10];
    int pipValue, suiteValue, len;

    for(int i=0; i<5; i++){
        printf("Please input the pip[Ace,King,Queen,Jack,1-10] of hand %d\n", i+1);
        scanf("%s", pipInput);
        printf("Please input the suite[Diamond,Heart,Spade,Club/Flower] of hand %d\n", i+1);
        scanf("%s", suiteInput);

        //Clear the screen/terminal for Better Input Visibility
        printf("\e[1;1H\e[2J");

        //Lowercase the input for simpler logic
        len = strlen(pipInput);
        for(int i = 0; i < len; i++) pipInput[i] = tolower(pipInput[i]);
        len = strlen(suiteInput);
        for(int i = 0; i < len; i++) suiteInput[i] = tolower(suiteInput[i]);

        //Convert Pips to int
        if(strcmp(pipInput, "ace") == 0) pipValue = 1;
        else if(strcmp(pipInput, "king") == 0) pipValue = 13;
        else if(strcmp(pipInput, "queen") == 0) pipValue = 12;
        else if(strcmp(pipInput, "jack") == 0) pipValue = 11;
        else if(strcmp(pipInput, "10") == 0) pipValue = 10;
        else if(isdigit(pipInput[0])) pipValue = atoi(pipInput);
        else pipValue = 0;

        //Convert Suites to int
        if(strcmp(suiteInput, "diamond") == 0) suiteValue = 4;
        else if(strcmp(suiteInput, "heart") == 0) suiteValue = 3;
        else if(strcmp(suiteInput, "spade") == 0) suiteValue = 2;
        else if(strcmp(suiteInput, "club") == 0 || strcmp(suiteInput, "flower") == 0) suiteValue = 1;
        else suiteValue = 0;

        //Check for Dups/Excess
        if(i > 0){
            for(int k = 0; k<i; k++){
                if(pipValue == tempHand.Pip[k] && suiteValue == tempHand.Suite[k]){
                    pipValue = -1;
                    suiteValue = -1;
                    break;
                }
                else continue;
            }
        }

        //Either Declare that Value or Request Reinput
        if(pipValue == -1 && suiteValue == -1){
            printf("Inputted Card has already been inputted. Please reinput the hand\n");
            i--;    
        }
        else if(pipValue == 0 && suiteValue == 0){
            printf("Inputted Pip or Suite is Invalid. Please reinput the hand\n");
            i--;
        }
        else{
            tempHand.Pip[i] = pipValue;
            tempHand.Suite[i] = suiteValue;
        }
    }

    //Reorganize the hand numerically
    int tempPip,tempSuite;
    for(int i = 0; i<5; ++i){
        for(int k = i+1; k<5; ++k){
            if(tempHand.Pip[i] > tempHand.Pip[k]){
                tempPip = tempHand.Pip[i];
                tempSuite = tempHand.Suite[i];
                tempHand.Pip[i] = tempHand.Pip[k];
                tempHand.Pip[k] = tempPip;
                tempHand.Suite[i] = tempHand.Suite[k];
                tempHand.Suite[k] = tempSuite;
            }
        }
    }

    return tempHand;
}

const char* handEval(struct hand Hand){
    char *evaledHand = malloc(256);
    bool flush, straight, royal, diffPip = false;
    int i, temp, pipCount1 = 1, pipCount2 = 1;

    //Evaluate for Flushes
    temp = Hand.Suite[0];
    for(i=1; i<5; i++){
        if(Hand.Suite[i] != temp){
            flush = false;
            break;
        }
        else flush = true;
    }

    //Evaluate for Straights and Royals
    if(Hand.Pip[0] == 1 && Hand.Pip[1] == 10){
        temp = Hand.Pip[1];
        royal = true;
        i = 2;
    } 
    else{
        temp = Hand.Pip[0];
        royal = false;
        i = 1;
    }

    for(; i<5; i++){
        if(Hand.Pip[i] == temp+1){
            straight = true;
            temp = Hand.Pip[i];
        }
        else{
            straight = false;
            royal = false;
            break;
        }
    }

    //Evaluate for Number of Similar Pip
    if(Hand.Pip[0] == Hand.Pip[1]){
        temp = Hand.Pip[0];
        pipCount1 = 1;
        i = 1;
    }
    else{
        temp = Hand.Pip[1];
        i = 2;
    }
 
    for(; i<5; i++){
        if(Hand.Pip[i] == temp && diffPip == false) pipCount1++;
        else if(Hand.Pip[i] == temp && diffPip == true) pipCount2++;
        else diffPip = true;
        temp = Hand.Pip[i];
    }

    //Get HandType
    if(flush == true && straight == true && royal == true) strcpy(evaledHand,"Royal Flush");  
    else if(flush == true && straight == true && royal == false) strcpy(evaledHand,"Straight Flush");  
    else if(pipCount1 == 4) strcpy(evaledHand,"Four of a Kind");  
    else if(pipCount1 == 3 && pipCount2 == 2) strcpy(evaledHand,"Full House");  
    else if(pipCount2 == 3 && pipCount1 == 2) strcpy(evaledHand,"Full House");  
    else if(flush == true && straight == false && royal == false) strcpy(evaledHand,"Flush");  
    else if(flush == false && straight == true && royal == false) strcpy(evaledHand,"Straight");  
    else if(flush == false && straight == true && royal == true) strcpy(evaledHand,"Straight"); 
    else if(pipCount1 == 3 || pipCount2 == 3) strcpy(evaledHand,"Three of a Kind");  
    else if(pipCount1 == 2 && pipCount2 == 2) strcpy(evaledHand,"Two Pair");  
    else if(pipCount1 == 2 && pipCount2 == 1) strcpy(evaledHand,"Pair");  
    else if(pipCount2 == 2 && pipCount1 == 1) strcpy(evaledHand,"Pair");  
    else strcpy(evaledHand,"High Card");

    return evaledHand;
    free(evaledHand);
}