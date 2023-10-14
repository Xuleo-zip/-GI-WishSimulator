#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void threeStarRoll()
{
    int randomNum = rand() % 13; //Total 13 items available, use rand() % (total + 1) to get a large number of random value in a short time.

    if(randomNum == 0)
    {
        printf("\033[1;34m Slingshot\n");
    } else if (randomNum == 1)
    {
        printf("\033[1;34m Sharpshooter's Oath\n");
    } else if (randomNum == 2)
    {
        printf("\033[1;34m Raven Bow\n");
    } else if (randomNum == 3)
    {
        printf("\033[1;34m Jade Orb\n");
    } else if (randomNum == 4)
    {
        printf("\033[1;34m Thrilling Tales of Dragon Slayers\n");
    } else if (randomNum == 5)
    {
        printf("\033[1;34m Magic Guide\n");
    } else if (randomNum == 6)
    {
        printf("\033[1;34m Black Tassel\n");
    } else if (randomNum == 7)
    {
        printf("\033[1;34m Debate Club\n");
    } else if (randomNum == 8)
    {
        printf("\033[1;34m Bloodtainted Greatsword\n");
    } else if (randomNum == 9)
    {
        printf("\033[1;34m Ferrous Shadow\n");
    } else if (randomNum == 10)
    {
        printf("\033[1;34m Skyrider Sword\n");
    } else if (randomNum == 11)
    {
        printf("\033[1;34m Harbinger of Dawn\n");
    } else if (randomNum == 12)
    {
        printf("\033[1;34m Cool Steel\n");
    }
}