#include <stdio.h>
#include <stdlib.h>
/** checkForWinner  Checks the winner in every move **/
int checkForWinner( char a[], int cnt, char* playerPtr  )
{
    int i, gameOver = 0;
    /**That for loop checks every straight line for winner**/
    for( i = 0; i < 3; i++ )
    {
        /**These if structures check the similarity of straight lines **/
        if( a[3*i] == a[3*i + 1] && a[3*i + 1] == a[3*i + 2])
        {
            printf( "We have a winner! It is %c.\n\n", *playerPtr );
            gameOver = 1;
        }
        if( a[i] == a[i + 3] && a[i + 3] == a[i + 6])
        {
            printf( "Game over, man! %c dominates.\n\n", *playerPtr );
            gameOver = 1;
        }
    }
    /**These if structures check the similarity of diagonal lines or draw **/
    if( a[0] == a[4] && a[4] == a[8])
    {
        printf( "%c wins on a diagonal move!\n\n", *playerPtr );
        gameOver = 1;
    }
    if( a[2] == a[4] && a[4] == a[6])
    {
        printf( "That's it. %c has won!\n\n", *playerPtr );
        gameOver = 1;

    }
    if( cnt == 8  && gameOver ==  0 )
    {
        printf( "Awww. There is no winner!\n\n" );
        gameOver = 1;
    }
    return gameOver;
}
