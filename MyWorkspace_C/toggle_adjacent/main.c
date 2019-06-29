/******************************************************************************

							Online C Compiler.
				Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
typedef struct Boundedarray{
	int num;
	int *arr;
}boundedarray;

static boundedarray one;
boundedarray* cellCompete (int* states, int days)
{
  int i = 0;
  int temp[8];
  while (i < days)
	{
	  for (int j = 0; j < 8; j++)
	{
	  int prev = 0;
	  int next = 0;
	  if (j == 0)
		{
		  prev = 0;
		  next = states[j + 1];
		}
	  else if (j == 7)
		{
		  prev = states[j - 1];
		  next = 0;
		}
	  else
		{
		  prev = states[j - 1];
		  next = states[j + 1];
		}
	  temp[j] = (prev ^ next);
	  printf ("%d", (temp[j]));
	  //printf("j %d", j);
	}
	  printf ("\n");
	  memcpy (states, temp, 8*sizeof(int));
	  printf ("\n");

	  i++;
	}
  one.num = 8;
  one.arr = states;
  return &one;
}

#include<stdbool.h>

int
generalizedGCD (int num, int *arr)
{

  int gcd = 1;
  int new_gcd = 1;
  while (new_gcd < arr[num - 1])
	{
	  bool flag = false;
	  int i = 0;
	  do
	{
	  flag = false;
	  if (arr[i] % gcd == 0)
		{
		  flag = true;
		}
	  i++;
	}while ((flag) && i < (num));

	  if (flag)
	{
	  gcd = new_gcd;
	}
	  new_gcd++;
	}
  return gcd;
}

int
main ()
{
  int i[8] = { 1, 1, 1, 0, 1, 1, 1, 1 };
  int gdc[5] = { 2, 3, 4, 5, 6 };
  printf("gcd is %d\n", generalizedGCD(5, gdc));
 // boundedarray *noundedarray = cellCompete (i, 2);
//  for (int j = 0; j < 8; j++)
//	{
//	  printf ("%d", noundedarray->arr[j]);
//	}
  return 0;
}

