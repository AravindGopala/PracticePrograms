#include <stdio.h>
#include <stdlib.h>
int removeObstacle(int numRows, int numColumns, int** lot)
{
    if(numRows <= 0 && numColumns <= 0)
    {
        return -1;
    }
    int i=0;
    int j=0;
    int steps =0;
    while(i< numRows)
    {
        while(j < numColumns)
        {
            if(lot[i+1][j] == 1 && lot[i][j+1] == 1)
            {
                break;
            }
            if(lot[i+1][j] == 1)
            {
                i++;
                steps++;
            }
            else if (lot[i][j+1] == 1)
            {
                j++;
                steps++;
            }
            if(lot[i][j] > 1)
            {
                return 1;
            }
        }
        i++;
    }
        return -1;
}
int main()
{
    printf("Hello World!\n");
    int input[4] = {8,4,6,12};
    printf("%d", minimumTime(4, input));

    return 0;
}
