#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

void mergesort(int* v1,int* v2, int l1, int* result)
{
 int i=0;
 int j=0;

    while(j< l1 && i < l1)
        {
         if(v1[i]>v2[j])
            {
             result[count]=v2[j];
             count++;
             j++;
            }
         else{
             result[count]=v1[i];
             count++;
             i++;
            }
        }
    while(i < l1)
    {
            result[count]=v1[i];
            count++;
            i++;
    }
   while(j < l1)
    {
            result[count]=v2[j];
            count++;
            j++;
    }
}

int* split(int unsortedArray[], int l2,int* sortedArray,int level)
{
  int median= l2/2;
  int lefthalf[median];
  int righthalf[median];

  for(int i=0;i<median;i++)
  {
     lefthalf[i] =unsortedArray[i];
  }
  for(int i=median;i<l2;i++)
  {
      righthalf[i-median] =unsortedArray[i] ;
  }

  if(median > level)
  {
      split(lefthalf,sizeof(lefthalf)/sizeof(int),sortedArray, level);
      split(righthalf,sizeof(righthalf)/sizeof(int),sortedArray, level);

  }
  else{
      mergesort(lefthalf, righthalf, sizeof(lefthalf)/sizeof(int),sortedArray);
      return sortedArray;
      }
  }

int main()
{
  vector<int> v1{6,5,3,1,8,7,2,4};
//  std::cout<<v1[1]<<std::endl;
  int UnsortedArray[] = {8,7,6,5,3,1,2,4};
  int length = sizeof(UnsortedArray)/sizeof(int);
  int SortedArray[length/2];
  cout<<"size of Array"<<length<<endl;
  count=0;
  split(UnsortedArray, length, SortedArray,1);
  count=0;
  split(SortedArray,length,SortedArray,2);
  count=0;
  split(SortedArray,length,SortedArray,5);

  cout<<"Started Here"<<endl;
  for (int i=0;i<(8);i++)
  {
  cout<<SortedArray[i]<<endl;
  }
cout<<"Ended Here"<<endl;
}
