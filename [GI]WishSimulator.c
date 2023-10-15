#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "[GI]ThreeStarList.h"
#include "[GI]FourStarList.h"
#include "[GI]FiveStarList.h"

#define threeStar 0.943

void fourStarRoll(int *fourStarGuaranteed);

int main()
{   
    int drawCount; //define the wishes (only 1 and 10)
    double normalFiveStars = 0.006; //Base chance of getting five stars items.
    double normalFourStars = 0.051;
    int sumCount = 0;
    int baseFive = 1;  //counts of wishes for five stars items.
    int baseFour = 1;  //counts of wishes for four stars items.
    double maxChance = 1.000; //define maxChance.
    double randomNum; //Random number generation.
    int fourStarGuaranteed = 0;
    int fiveStarGuaranteed = 0; // Guaranteed system for 'up' characters
    int bannerChoice;
    int totalUpCount = 0;
    int averageUp;


    srand (time(NULL)); // Get random value

    printf("Choose a banner, 0 for Hutao and 1 for Neuvillette: ");
    scanf("%d", &bannerChoice);
    
    while ((bannerChoice != 0) && (bannerChoice != 1))
    {
        printf("Error Input.\n");
        printf("Please input 0 or 1 here.\n");
        scanf("%d", &bannerChoice);
    }

    //Get user input of wishes first time.
    printf("Wish once or Wish ten times: \n");
    scanf("%d", &drawCount);

    //Check whether the input matches either of choices, otherwise, prompt user to enter again.
    while (drawCount != 1 && drawCount != 10 )
    {
        printf("Error Input.\n");
        printf("Please input your value in either 1 or 10. \n");
        scanf("%d", &drawCount);
    }

    //Simulate the Wishing System
    do
    {   
        int tenCountProgress = 1; // Check 10 elements in a single 10 times wishes. AND RESET
        
        //Guaranteed System for Five star items.
        if (baseFive >= 74)
        {
            normalFiveStars += (baseFive - 74) * 0.06;
            if (normalFiveStars > maxChance)
            {
                normalFiveStars = maxChance;
            }
        } else if (baseFive == 90)
        {
            normalFiveStars = maxChance;
        }
        //Guaranteed System for Four star items.
        if (baseFour == 10)
        {
            normalFourStars = maxChance - 0.006;
        }
        
        //For a single wish.
        if (drawCount == 1)
        {
            randomNum = (double)rand() / RAND_MAX; //Get random value from 0 to 1.
            if (baseFive < 74 && baseFour < 10)   //If not triggered guaranteed system.
            {
                if (randomNum <= drawCount * threeStar) // Less or equal to 0.943 get three stars items.
                {   
                    threeStarRoll();
                } else if (randomNum > drawCount * threeStar && randomNum <= drawCount * (threeStar + normalFourStars)) // Larger than 0.943 and smaller than 0.994
                {
                    fourStarRoll(&fourStarGuaranteed);
                    baseFour = 1;
                } else if (randomNum > drawCount * (threeStar + normalFourStars) && randomNum <= maxChance) // Larger than 0.994 and smaller or equal to 1.000
                {
                    FiveStarUpBanner(bannerChoice, &fiveStarGuaranteed, &totalUpCount);
                    baseFive = 1;
                    baseFour = 1;
                }
                baseFive++;
                baseFour++;
            } else if (baseFour == 10) 
            {
                if(randomNum <= drawCount * (threeStar + normalFourStars))
                {
                    fourStarRoll(&fourStarGuaranteed);
                    baseFour = 1;
                    baseFive++;
                } else
                {
                    FiveStarUpBanner(bannerChoice, &fiveStarGuaranteed, &totalUpCount);
                    baseFive = 1;
                    baseFour = 1; //both of them are reset if five star appeared.
                }
            } else if (baseFive >= 74)
            {
                if (randomNum >= (1 - drawCount * normalFiveStars) && randomNum <= maxChance) // reverse range lol
                {
                    FiveStarUpBanner(bannerChoice, &fiveStarGuaranteed, &totalUpCount);
                    baseFive = 1;
                    baseFour = 1;
                } else if (randomNum <= (1 - drawCount * normalFiveStars) * threeStar )
                {
                    threeStarRoll();
                    baseFive++;
                    baseFour++;
                } else if (randomNum > (1 - drawCount * normalFiveStars) * threeStar && randomNum <= (1 - drawCount * normalFiveStars) * (threeStar + normalFourStars))
                {
                    fourStarRoll(&fourStarGuaranteed);
                    baseFour = 1;
                    baseFive++;
                }
            }
            sumCount++;
            
        } else if (drawCount == 10) // TEN WISHES = 1 wish * 10
        {
            
            // Code here to repeat a single wish for 10 times.
            int newDrawCount = drawCount / 10; // Convert to 1 for calculation purpose.
            while (tenCountProgress <= drawCount) // each elements is calculated independently.
            {
                randomNum = (double)rand() / RAND_MAX; //Get random value from 0 to 1.
                if (baseFive < 74 && baseFour < 10)   //If not triggered guaranteed system.   //Problem marked here as there must be a fourStar
                {
                    randomNum = (double)rand() / RAND_MAX; //Get random value from 0 to 1.
                    if (randomNum <= newDrawCount * threeStar) // Less or equal to 0.943 get three stars items.
                    {
                        threeStarRoll();
                        baseFive++;
                        baseFour++;
                    } else if ((randomNum > newDrawCount * threeStar && randomNum <= newDrawCount * (threeStar + normalFourStars)) || (baseFour == 10)) // Larger than 0.943 and smaller than 0.994
                    {
                        fourStarRoll(&fourStarGuaranteed);
                        baseFour = 1;
                        baseFive++;
                    } else if (randomNum > newDrawCount  * (threeStar + normalFourStars) && randomNum <= maxChance) // Larger than 0.994 and smaller or equal to 1.000
                    {
                        FiveStarUpBanner(bannerChoice, &fiveStarGuaranteed, &totalUpCount);
                        baseFive = 1;
                        baseFour = 1;
                    }
                    
                } else if (baseFour == 10) 
                {
                    randomNum = (double)rand() / RAND_MAX;
                    if(randomNum <= newDrawCount * (threeStar + normalFourStars)) //0.994 for four star
                    {
                        fourStarRoll(&fourStarGuaranteed);
                        baseFour = 1;
                        baseFive++;
                    } else // if not four star, five star
                    {
                        FiveStarUpBanner(bannerChoice, &fiveStarGuaranteed, &totalUpCount);
                        baseFive = 1;
                        baseFour = 1; //both of them are reset if five star appeared.
                    }
                } else if (baseFive >= 74)
                {
                    if (randomNum >= (1 - newDrawCount * normalFiveStars) && randomNum <= maxChance) 
                    {
                        FiveStarUpBanner(bannerChoice, &fiveStarGuaranteed, &totalUpCount);
                        baseFive = 1;
                        baseFour = 1;
                    } else if (randomNum <= (1 - newDrawCount * normalFiveStars) * threeStar )
                    {
                        threeStarRoll();
                        baseFour++;
                        baseFive++;
                    } else if ((randomNum > (1 - newDrawCount * normalFiveStars) * threeStar && randomNum <= (1 - newDrawCount * normalFiveStars) * (threeStar + normalFourStars)) || (baseFour == 10))
                    {
                        fourStarRoll(&fourStarGuaranteed);
                        baseFour = 1;
                        baseFive++;
                    }
                }
                tenCountProgress++;
            }
            sumCount += 10;
            tenCountProgress = 1;
        }
        printf("\033[0m");// change the color back

        

        printf("Number of wishes: %d\n", sumCount);

        printf("Press other values for termination.\n");
        scanf("%d", &drawCount);

    } while (drawCount == 1 || drawCount == 10);

    averageUp = sumCount / totalUpCount;

    printf("You have %d for the 'up' character, in your total %d wishes.\n", totalUpCount, sumCount);
    if (averageUp > 0)
    {
        printf("You got an 'up' character in every \033[1;33m %d \033[0m wishes\n", averageUp);
    } else 
    {
        printf("Sorry, you did not get any 'up' Characters.\n");
    }
    return 0;
}
