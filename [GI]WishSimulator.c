#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define targetFiveStar 0.5 // Get the 'UP' items
#define threeStar 0.943


int main()
{   
    int drawCount; //define the wishes (only 1 and 10)
    double normalFiveStars = 0.006; //Base chance of getting five stars items.
    double normalFourStars = 0.051;
    int sumCount = 0;
    int baseFive = 1;  //Isolated counts of wishes for five stars items.
    int baseFour = 1;  //Isolated counts of wishes for four stars items.
    double maxChance = 1.000; //define maxChance.
    double randomNum; //Random number generation.
    //int countTen; // Ten wishes.


    srand (time(NULL)); // Get random value

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
            if (baseFive < 74 && baseFour != 10)   //If not triggered guaranteed system.
            {
                if (randomNum <= drawCount * threeStar) // Less or equal to 0.943 get three stars items.
                {
                    printf("\033[1;34m You get a Three Star Item.\n");
                } else if (randomNum > drawCount * threeStar && randomNum <= drawCount * (threeStar + normalFourStars)) // Larger than 0.943 and smaller than 0.994
                {
                    printf("\033[1;35m You get a Four Star Item.\n");
                    baseFour = 1;
                } else if (randomNum > drawCount * (threeStar + normalFourStars) && randomNum <= maxChance) // Larger than 0.994 and smaller or equal to 1.000
                {
                    printf("\033[1;33m You get a Five Star Item.\n");
                    baseFive = 1;
                    baseFour = 1;
                }
                baseFive++;
                baseFour++;
            } else if (baseFour == 10) 
            {
                if(randomNum <= drawCount * (threeStar + normalFourStars))
                {
                    printf("\033[1;35m You get a Four Star Item.\n");
                    baseFour = 1;
                    baseFive++;
                } else
                {
                    printf("\033[1;33m You get a Five Star Item.\n");
                    baseFive = 1;
                    baseFour = 1; //both of them are reset if five star appeared.
                }
            } else if (baseFive >= 74)
            {
                if (randomNum >= (1 - drawCount * normalFiveStars) && randomNum <= maxChance) // Get the range for five star first.
                {
                    printf("\033[1;33m You get a Five Star Item.\n");
                    baseFive = 1;
                    baseFour = 1;
                } else if (randomNum <= (1 - drawCount * normalFiveStars) * threeStar ) //Similar method applied to four star
                {
                    printf("\033[1;34m You get a Three Star Item.\n");
                    baseFive++;
                } else if (randomNum > (1 - drawCount * normalFiveStars) * threeStar && randomNum <= (1 - drawCount * normalFiveStars) * (threeStar + normalFourStars)) //Similar method applied to three star
                {
                    printf("\033[1;35m You get a Four Star Item.\n");
                    baseFour = 1;
                    baseFive++;
                }
            }
            sumCount++;
            
        } else if (drawCount == 10) // TEN WISHES = 1 wish * 10
        {
            int newDrawCount = drawCount / 10;
            while (tenCountProgress <= drawCount) // each elements is still calculated independently.
            {
                randomNum = (double)rand() / RAND_MAX; //Get random value from 0 to 1.
                if (baseFive < 74 && baseFour != 10)   
                {
                    if (randomNum <= newDrawCount * threeStar) 
                    {
                        printf("\033[1;34m You get a Three Star Item.\n");
                    } else if (randomNum > newDrawCount * threeStar && randomNum <= newDrawCount * (threeStar + normalFourStars)) 
                    {
                    printf("\033[1;35m You get a Four Star Item.\n");
                    baseFour = 1;
                    } else if (randomNum > newDrawCount  * (threeStar + normalFourStars) && randomNum <= maxChance) 
                    {
                        printf("\033[1;33m You get a Five Star Item.\n");
                        baseFive = 1;
                        baseFour = 1;
                    }
                    baseFive++;
                    baseFour++;
                } else if (baseFour == 10) 
                {
                    if(randomNum <= newDrawCount * (threeStar + normalFourStars))
                    {
                        printf("\033[1;35m You get a Four Star Item.\n");
                        baseFour = 1;
                        baseFive++;
                    } else
                    {
                        printf("\033[1;33m You get a Five Star Item.\n");
                        baseFive = 1;
                        baseFour = 1; 
                    }
                } else if (baseFive >= 74)
                {
                    if (randomNum >= (1 - newDrawCount * normalFiveStars) && randomNum <= maxChance) 
                    {
                        printf("\033[1;33m You get a Five Star Item.\n");
                        baseFive = 1;
                        baseFour = 1;
                    } else if (randomNum <= (1 - newDrawCount * normalFiveStars) * threeStar )
                    {
                        printf("\033[1;34m You get a Three Star Item.\n");
                        baseFive++;
                    } else if (randomNum > (1 - newDrawCount * normalFiveStars) * threeStar && randomNum <= (1 - newDrawCount * normalFiveStars) * (threeStar + normalFourStars))
                    {
                        printf("\033[1;35m You get a Four Star Item.\n");
                        baseFour = 1;
                        baseFive++;
                    }
                }
                tenCountProgress++;
            }
            sumCount += 10;
        }

        

        printf("Number of wishes: %d\n", sumCount);

        printf("Press other values for termination.\n");
        scanf("%d", &drawCount);

    } while (drawCount == 1 || drawCount == 10);

    return 0;
}