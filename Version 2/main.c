#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "voidFuncs.h"
#include "voidFuncs.c"
#include "checkWin.c"
#include "checkWin.h"
#define SIZE 9


int main()
{
    char grid[SIZE] = {'0', '1', '2', '3', '4', '5', '6', '7', '8' };
    FILE *file;
    char vs;
    printf("Press 1 to play against the computer\nPress 2 to play against another person\nEnter your choice: ");
    scanf("%c", &vs);
    /**if else checks the file it is null or not**/
    if(file==NULL)
    {
        printf("File could not be opened");
    }
    else if(file != NULL)
    {
        /**opened filed to read and add**/
        file=fopen("save.txt","r+");
        /**grid taken from file**/
        fscanf(file,"%s",grid);
        /**if vs equal to 1 playing with computer
        else if vs equal to 2 playing with human**/
        if(vs == '1')
        {
            int counter = 0, done = 0;
            char currentPlayer = 'O';
            /**  drawGrid     Draws the current state of the tic-tac-toe grid    **/
            drawGrid( grid );
            /**  While done is not equal to 0  **/
            while( !done )
            {
                /**  takeTurn     Orders to play  **/
                takeTurn( grid, &currentPlayer );
                /**  drawGrid     Draws the current state of the tic-tac-toe grid    **/
                drawGrid( grid );
                done = checkForWinner( grid, counter, &currentPlayer );
                /** swapPlayer    Chooses the player  **/
                swapPlayer( &currentPlayer );
                counter++;
                /**file opened to write**/
                file=fopen("save.txt","w");
                /**grid printed to file **/
                fprintf(file,"%s",grid);
                /**file closed**/
                fclose(file);
            }
        }
        else if(vs == '2')
        {
            int counter = 0, done = 0;
            char currentPlayer;
            printf("Please choose your mark(O or X)");
            /**getche to take a currentPlayer's mark **/
            currentPlayer=getche();
            /**  drawGrid     Draws the current state of the tic-tac-toe grid    **/
            drawGrid( grid );
            /**  While done is not equal to 0  **/
            while( !done )
            {
                /**  takeTurn     Orders to play  **/
                takeTurnHuman( grid, &currentPlayer );
                /**  drawGrid     Draws the current state of the tic-tac-toe grid    **/
                drawGrid( grid );
                done = checkForWinner( grid, counter, &currentPlayer );
                /** swapPlayer    Chooses the player  **/
                swapPlayer( &currentPlayer );
                counter++;
                /**file opened to write**/
                file=fopen("save.txt","w");
                /** grid printed to file **/
                fprintf(file,"%s",grid);
                /**file closed**/
                fclose(file);
            }
        }
        char grid[SIZE] = {'0', '1', '2', '3', '4', '5', '6', '7', '8' };
        /**file opened to write**/
        file=fopen("save.txt","w");
        /**grid printed to file **/
        fprintf(file,"%s",grid);
        /**file closed**/
        fclose(file);
    }
}
