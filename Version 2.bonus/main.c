#include <stdio.h>
#include <stdlib.h>
#define SIZE 9
#include "checkWin.h"
#include "checkWin.c"
#include "voidFuncs.h"
#include "voidFuncs.c"

int main()
{
    char grid[SIZE] = {'0', '1', '2', '3', '4', '5', '6', '7', '8' };
    FILE *file;
    char currentPlayer ;
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
        printf("Please choose your mark(O or X)");
        /**getche to take a currentPlayer's mark **/
        currentPlayer=getche();
        int counter = 0, done = 0;
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
            /** grid printed to file **/
            fprintf(file,"%s",grid);
            /**file closed**/
            fclose(file);
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

