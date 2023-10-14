#include <stdio.h>
#include <stdlib.h>
// two choices and guaranteed system need to be changed

void FiveStarNotUp()
{
    int randomNum = rand() % 7;

    if (randomNum == 0)
    {
        printf("\033[1;33m Dehya\n");
    } else if (randomNum == 1)
    {
        printf("\033[1;33m Tighnari\n");
    } else if (randomNum == 2)
    {
        printf("\033[1;33m Keqing\n");
    } else if (randomNum == 3)
    {
        printf("\033[1;33m Mona\n");
    } else if (randomNum == 4)
    {
        printf("\033[1;33m Qiqi\n");
    } else if (randomNum == 5)
    {
        printf("\033[1;33m Diluc\n");
    } else if (randomNum == 6)
    {
        printf("\033[1;33m Jean\n");
    }
}

void FiveStarUpBanner(int whichBanner, int *fiveStarGuaranteed)
{
    if (whichBanner == 0)
    {
        if (*fiveStarGuaranteed == 0)
        {
            FiveStarNotUp();
            *fiveStarGuaranteed = 1;
        } else if (*fiveStarGuaranteed == 1)
        {
            printf("\033[1;33m Hutao\n");
            *fiveStarGuaranteed = 0;
        }
    } else if (whichBanner == 1)
    {
        if (*fiveStarGuaranteed == 0)
        {
            FiveStarNotUp();
            *fiveStarGuaranteed = 1;
        } else if (*fiveStarGuaranteed == 1)
        {
            printf("\033[1;33m Neuvillette\n");
            *fiveStarGuaranteed = 0;
        }
    }
}
