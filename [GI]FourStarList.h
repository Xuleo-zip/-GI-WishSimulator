#include <stdio.h>
#include <stdlib.h>

void fourStarWeaponNotUp()
{
    int randomNum = rand() % 18;

    if (randomNum == 0)
    {
        printf("\033[1;35m Rust\n");
    } else if (randomNum == 1)
    {
        printf("\033[1;35m Sacrificial Bow\n");
    } else if (randomNum == 2)
    {
        printf("\033[1;35m The Stringless\n");
    } else if (randomNum == 3)
    {
        printf("\033[1;35m Favonius Warbow\n");
    } else if (randomNum == 4)
    {
        printf("\033[1;35m Eye of Perception\n");
    } else if (randomNum == 5)
    {
        printf("\033[1;35m Sacrificial Fragments\n");
    } else if (randomNum == 6)
    {
        printf("\033[1;35m The Widsith\n");
    } else if (randomNum == 7)
    {
        printf("\033[1;35m Favonius Codex\n");
    } else if (randomNum == 8)
    {
        printf("\033[1;35m Favonius Lance\n");
    } else if (randomNum == 9)
    {
        printf("\033[1;35m Dragon's Bane\n");
    } else if (randomNum == 10)
    {
        printf("\033[1;35m Rainslasher");
    } else if (randomNum == 11)
    {
        printf("\033[1;35m Sacrificial Greatsword\n");
    } else if (randomNum == 12)
    {
        printf("\033[1;35m The Bell\n");
    } else if (randomNum == 13)
    {
        printf("\033[1;35m Favonius Greatsword\n");
    } else if (randomNum == 14)
    {
        printf("\033[1;35m Lion's Roar\n");
    } else if (randomNum == 15)
    {
        printf("\033[1;35m Sacrificial Sword\n");
    } else if (randomNum == 16)
    {
        printf("\033[1;35m The Flute\n");
    } else if (randomNum == 17)
    {
        printf("\033[1;35m Favonius Sword\n");
    }
}

void fourStarCharacterNotUp()
{
    int randomNum = rand() % 30;

    if (randomNum == 0)
    {
        printf("\033[1;35m Freminet\n");
    } else if (randomNum == 1)
    {
        printf("\033[1;35m Lynette\n");
    } else if (randomNum == 2)
    {
        printf("\033[1;35m Kaveh\n");
    } else if (randomNum == 3)
    {
        printf("\033[1;35m Mika\n");
    } else if (randomNum == 4)
    {
        printf("\033[1;35m Yaoyao\n");
    } else if (randomNum == 5)
    {
        printf("\033[1;35m Faruzan\n");
    } else if (randomNum == 6)
    {
        printf("\033[1;35m Layla\n");
    } else if (randomNum == 7)
    {
        printf("\033[1;35m Candace\n");
    } else if (randomNum == 8)
    {
        printf("\033[1;35m Dori\n");
    } else if (randomNum == 9)
    {
        printf("\033[1;35m Collei\n");
    } else if (randomNum == 10)
    {
        printf("\033[1;35m Kuki Shinobu\n");
    } else if (randomNum == 11)
    {
        printf("\033[1;35m Yun Jin\n");
    } else if (randomNum == 12)
    {
        printf("\033[1;35m Kirara\n");
    } else if (randomNum == 13)
    {
        printf("\033[1;35m Shikanoin Heizou\n");
    } else if (randomNum == 14)
    {
        printf("\033[1;35m Kujou Sara\n");
    } else if (randomNum == 15)
    {
        printf("\033[1;35m Gorou\n");
    } else if (randomNum == 16)
    {
        printf("\033[1;35m Sayu\n");
    } else if (randomNum == 17)
    {
        printf("\033[1;35m Thoma\n");
    } else if (randomNum == 18)
    {
        printf("\033[1;35m Yanfei\n");
    } else if (randomNum == 19)
    {
        printf("\033[1;35m Rosaria\n");
    } else if (randomNum == 20)
    {
        printf("\033[1;35m Xinyan\n");
    } else if (randomNum == 21)
    {
        printf("\033[1;35m Sucrose\n");
    } else if (randomNum == 22)
    {
        printf("\033[1;35m Chongyun\n");
    } else if (randomNum == 23)
    {
        printf("\033[1;35m Noelle\n");
    } else if (randomNum == 24)
    {
        printf("\033[1;35m Bennett\n");
    } else if (randomNum == 25)
    {
        printf("\033[1;35m Ningguang\n");
    } else if (randomNum == 26)
    {
        printf("\033[1;35m Beidou\n");
    } else if (randomNum == 27)
    {
        printf("\033[1;35m Xiangling\n");
    } else if (randomNum == 28)
    {
        printf("\033[1;35m Razor\n");
    } else if (randomNum == 29)
    {
        printf("\033[1;35m Barbara\n");
    }
}

void fourStarCharacterUp()
{
    int randomNum = rand() % 3;
    if (randomNum == 0)
    {
        printf("\033[1;35m Diona\n");
    } else if (randomNum == 1)
    {
        printf("\033[1;35m Fischl\n");
    } else if (randomNum == 2)
    {
        printf("\033[1;35m Xingqiu\n");
    }
}

void fourStarRoll(int *fourStarGuaranteed)
{
    //Not Guaranteed
    double randomNum;
    if (*fourStarGuaranteed == 0)
    {
        randomNum = (double)rand() / RAND_MAX;
        if (randomNum <= 0.5) // not obtain 'up' stuff
        {
            randomNum = (double)rand() / RAND_MAX;
            if (randomNum <= 0.5) // half chance to be weapon
            {
                fourStarWeaponNotUp();
                *fourStarGuaranteed = 1;
            } else // half chance to be character
            {
                fourStarCharacterNotUp();
                *fourStarGuaranteed = 1;
            }
        } else // half chance to get 'up' character
        {
            fourStarCharacterUp();
            *fourStarGuaranteed = 0; // reset the guaranteed for 'up'
        }

    } else if (*fourStarGuaranteed == 1) 
    {
        fourStarCharacterUp();
        *fourStarGuaranteed = 0;
    }
}