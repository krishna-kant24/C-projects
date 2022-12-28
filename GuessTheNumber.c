/* This is a simple game in which player guesses a random number.
In this game, player is asked to input a number.
If the input number is greater than the random number, player is asked for a lower number to input.
If the input number is lesser than the random number, player is asked for a higher number to input.
If the player guesses the random number, score is shown. Score is the number of guesses it took the player
to reach the correct number. The least number of guesses is the high score.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void game();
void highscore(int);
int replay();

int main(){
    while(1){
        system("cls");  //clear screen
        game();

        if(!replay()){  //replay is not 1(true)
            break;
        }
    }
    return 0;
}

void game(){
    int random_num, input_num, score;
    score = 0;
    srand(time(0));
    random_num = rand() % 100 + 1;
    puts("Enter a number between 1 and 100:");
    while(1){
        scanf("%d", &input_num);

        if(input_num < random_num){
            puts("Higher Number Please");
            score++;
        }
        else if(input_num > random_num){
            puts("Lower Number Please");
            score++;
        }
        else{
            score++;
            break;
        }
    }
    puts("\nYou guessed the correct number! YAY!");
    printf("Your score: %d guesses\n", score);
    highscore(score);
}

void highscore(int score){
    FILE *fpt;
    int h_score, fw = 0;

    fpt = fopen("high_score.bin", "rb");
    if(fpt != NULL){
        fscanf(fpt, "%d", &h_score);
        if(score < h_score){
            fw = 1;
        }
        else{
            printf("High Score: %d guesses\n", h_score);
        }
        fclose(fpt);
    }
    else{
        fw = 1;
    }
    if(fw == 1){
        fpt = fopen("high_score.bin", "wb");
        fprintf(fpt, "%d", score);
        printf("New High Score: %d guesses\n", score);
        fclose(fpt);
    }
}

int replay(){
    char s_input[5];
    do{
        printf("\nPlease Enter \"quit\" to quit the game or Enter \"play\" to play the game again: ");
        scanf("%4s", &s_input);
        if(strcmp(s_input, "quit") == 0){
            return 0;
        }
    }while(strcmp(s_input, "play") != 0);
    return 1;
}