#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header_1.h"
#include "header_1.c"
#include "board_header.h"
#include "board_header.c"


char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };




int main()
{
    FILE *file;

    int player = 1, i, choice;


    char mark;
    /**do while loop make allows to make move repeatly until i equals -1**/
    do
    {
        /**if the created file is null**/
        if(file == NULL)
        {
            printf("File could not be opened");
        }
        /**if the created file is not null**/
        else if(file!= NULL)
        {
            file=fopen("save.txt","r+");
            fscanf(file,"%s",square);
            board(square);
            player = (player % 2) ? 1 : 2;

            printf("Player %d, enter a number:  ", player);
            scanf("%d", &choice);

            mark = (player == 1) ? 'X' : 'O';
            /**if else structure equalize entered value to mark **/
            if (choice == 1 && square[1] == '1')
                square[1] = mark;

            else if (choice == 2 && square[2] == '2')
                square[2] = mark;

            else if (choice == 3 && square[3] == '3')
                square[3] = mark;

            else if (choice == 4 && square[4] == '4')
                square[4] = mark;

            else if (choice == 5 && square[5] == '5')
                square[5] = mark;

            else if (choice == 6 && square[6] == '6')
                square[6] = mark;

            else if (choice == 7 && square[7] == '7')
                square[7] = mark;

            else if (choice == 8 && square[8] == '8')
                square[8] = mark;

            else if (choice == 9 && square[9] == '9')
                square[9] = mark;
            /**elsew**/
            else
            {
                printf("Invalid move ");

                player--;
                getch();
            }
            i = checkwin(square);

            player++;
            file=fopen("save.txt","w");
            fprintf(file,"%s",square);
            fclose(file);
        }
    }
    while (i ==  - 1);

    board(square);
    /**That if else structure allows to print who has won or draw**/
    if (i == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");

    char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    file=fopen("save.txt","w");
    fprintf(file,"%s",square);
    fclose(file);

    getch();

    return 0;
}









/*******************************************************************
END OF PROJECT
 ********************************************************************/
