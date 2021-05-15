#include "functions.h"

///debug: input_file_1.txt ,output_file_2
void KmergeWay(int* arr, int n, int k)
{
    if (n<k)
    {
        quickSort(arr, 0, n - 1);
        return;
    }
    else
    {
        Heap min(k);//aloacting heap with size K

        karray* arrayOfK;
        arrayOfK = new karray[k]; //allocating k karrays]
        int sizeOfEachKarray;
        sizeOfEachKarray = (n / k);

        int j = 0;

        for (int i = 0; i < (k-1); i++)
        {
            arrayOfK[i].karr = new int[sizeOfEachKarray]; //alloacting int array inside of K array
            arrayOfK[i].numberOfArray = i;
            arrayOfK[i].size = sizeOfEachKarray;

            int temp = j;
            for (int k = 0; k < sizeOfEachKarray; k++)
            {
                arrayOfK[i].karr[k] = arr[k + temp]; //maybe we need k+j-1?
                j++;
            }
        }
        //we need to take care to the last karray, and put all the leftovers to him
        int howMuchToAllocateTheLastKarray = (n-((k-1)* sizeOfEachKarray));
        arrayOfK[k - 1].karr = new int[howMuchToAllocateTheLastKarray];
        arrayOfK[k - 1].size = howMuchToAllocateTheLastKarray;
        arrayOfK[k - 1].numberOfArray = (k - 1);

        for (int i = 0; i <howMuchToAllocateTheLastKarray; i++)
        {
            arrayOfK[k - 1].karr[i] = arr[n - 1 - i];
        }
        
        //now we will recursivly sort those arrays
        for (int i = 0; i < k; i++)
        {
            KmergeWay(arrayOfK[i].karr, arrayOfK[i].size, k);
        }

        //first we will put all the minimal elements of each array inside the min heap
        for (int i = 0; i < k; i++)
        {
            Node temp;
            temp.setChar(i); //here we set the array number
            temp.SetFrequency(arrayOfK[i].karr[0]);
           // (arrayOfK[i].currsize)++;
            min.Insert(temp);
        }

        int i = 0;
        while ((min.getHeapSize())>=1) //while there are elements in the heap
        {
            Node temp;
            temp = min.DeleteMin(); 

            int indextemporery = temp.getChar(); //this is the karray we will handel with
            arr[i] = temp.Frequency();//we fill the array    
            i++;
            arrayOfK[indextemporery].currsize++;
            
            if (arrayOfK[indextemporery].currsize == arrayOfK[indextemporery].size) //if the karray has ended
            {
                arrayOfK[indextemporery].isEnd = true;

            }
            else { //if he didnt ended with this karray, we need to insert the next element in this karray to the heap 

                float f = arrayOfK[indextemporery].karr[arrayOfK[indextemporery].currsize];
                temp.SetFrequency(f); //we update the value of temp to be the value of the next element in the specific karray
                min.Insert(temp);
                
            }
           

        }
        
    }
}




void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
//the good old swap fucntion , revives two pointers from an int type and swaps the value inside those pointers in a swift and clear motion


int partition(int arr[], int left, int right)
{
    int pivot;
    pivot = arr[right];    //we have chosen that pivot will be the most right element

    int i;
    i = (left - 1); //it is a well known method , when we will to the  quickSort(arr, left, pivot - 1); recursive call , i will be -1
    //but whats improtant to understand is that each time we encounter an element smaller than pivot we inc i and then do a swap with an element we know is bigger

    for (int j = left; j <= right - 1; j++)
    {
       
        if (arr[j] <= pivot) //we check if arr[j] is smaller than our pivot , if he is infact smaller,we will swap it with an element we know is bigger
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}


void quickSort(int arr[], int left, int right)
{
    int pivot;

    if (left < right)
    {
       
        pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}
