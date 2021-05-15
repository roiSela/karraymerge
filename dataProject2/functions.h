#pragma once
#include <iostream> 
#include "Heap.h"
#include "Node.h"
using namespace std;
struct karray
{
    int* karr;
    int numberOfArray; //each karray has a number between 0 to K-1 .
    int size = 0; //this is the size of the array
    int currsize = 0; //this shows us the index we are looking about to know , when he is equal to size , we know isend = true
    bool isEnd = false;
};



//functions:

void KmergeWay(int* arr, int n, int k); //this function sorts arr from low to high numbers
void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int* a, int* b);

