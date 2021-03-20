#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define random_integer(max) (((unsigned long int)rand())%(max))

//Do not modify this function!!!
void random_array(int M[], int size) {
	for (int i = 0; i < size; i++)
		M[i] = random_integer(size * 2);
}
//Do not modify this function!!!
void check_sorted(int M[], int size) {
	for (int A = 1; A < size; A++) {
		assert(M[A - 1] <= M[A]);
	}
}


void swapp_ele(int* f, int* k) //swapping function
{
	int temp = *f;
	*f = *k;
	*k = temp;
}

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//


//*HEAPING SORT*//

void heapp(int Array[], int Z, int J)
{

	int largest_in_Root = J;
	int Left_Side = 2 * J + 1;
	int Right_Side = 2 * J + 2;

	if (Left_Side < Z && Array[Left_Side] > Array[largest_in_Root])
		largest_in_Root = Left_Side;

	if (Right_Side < Z && Array[Right_Side] > Array[largest_in_Root])
		largest_in_Root = Right_Side;


	// *Swap and continue heapifying*//
	if (largest_in_Root != J) {
		swapp_ele(&Array[J], &Array[largest_in_Root]);//swapping function
		heapp(Array, Z, largest_in_Root);
	}
}

// *Doing The Heap Sort*//

void heap(int Array[], int Length) //heap_sort
{
	// *Building increasing ordered heap*
	for (int i = Length / 2 - 1; i >= 0; i--)
		heapp(Array, Length, i);

	// *Heap sort*//
	for (int i = Length - 1; i >= 0; i--) {
		swapp_ele(&Array[0], &Array[i]);//swapping function

		// *Heapify root element to get highest element at root again*//
		heapp(Array, i, 0);
	}
}



//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//


//*QUICK SORT*//

int parti(int* Array, int start, int end)//partition function
{
	int The_Pivot = Array[end];
	int Partition_Index = start; //setting the partition index
	for (int i = start; i < end; i++)
	{
		if (Array[i] <= The_Pivot)
		{
			swapp_ele(&Array[i], &Array[Partition_Index]);
			Partition_Index++;

		}

	}
	swapp_ele(&Array[Partition_Index], &Array[end]);//swapping function
	return Partition_Index;
}

void quick_sort(int* Array, int start, int end)
{
	if (start < end)
	{
		int parti_Index = parti(Array, start, end); //partition Index
		quick_sort(Array, start, parti_Index - 1);
		quick_sort(Array, parti_Index + 1, end);

	}

}



//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//


//*BINARY SEARCH*//
int binary_search(int Array[], int size, int key) {
	int start = 0, end = size - 1;
	while (start <= end)
	{
		int The_middle = (start + end) / 2;
		if (Array[The_middle] == key)
		{
			return The_middle;
		}
		if (Array[The_middle] > key)
		{
			end = The_middle - 1;
		}
		else
		{
			start = The_middle + 1;
		}
	}

	return -1;
}

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//


//*SEQUENTIAL SEARCH*//
int sequential_search(int Array[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (Array[i] == key)
		{
			return i;
		}
	}

	return -1;
}


//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//

#define ARRAY_SIZE 100000 
#define MAX_TEST_TIMES 1000 

//Do not modify the main function!!!
int main(int argc, char* argv[])
{
	int A[ARRAY_SIZE];
	printf("The size of the array is %d, testing %d times.\n", ARRAY_SIZE, MAX_TEST_TIMES);
	printf("Testing heap_sort  ");
	fflush(NULL);
	for (int p = 0; p < MAX_TEST_TIMES; p++) {
		random_array(A, ARRAY_SIZE);
		heap(A, ARRAY_SIZE);
		check_sorted(A, ARRAY_SIZE);
		if (p % 100 == 0) {
			printf(".");
			fflush(NULL);
		}
	}
	printf(" PASSED. \n");
	printf("Testing quick_sort  "); fflush(NULL);
	for (int p = 0; p < MAX_TEST_TIMES; p++) {
		random_array(A, ARRAY_SIZE);
		quick_sort(A, 0, ARRAY_SIZE - 1);
		check_sorted(A, ARRAY_SIZE);
		if (p % 100 == 0) {
			printf(".");
			fflush(NULL);
		}
	}
	printf(" PASSED. \n");


	random_array(A, ARRAY_SIZE);
	heap(A, ARRAY_SIZE);
	check_sorted(A, ARRAY_SIZE);
	printf("The size of the array is %d, testing %d times.\n", ARRAY_SIZE, MAX_TEST_TIMES * 10);
	printf("Testing sequential search  "); fflush(NULL);
	for (int p = 0; p < MAX_TEST_TIMES * 10; p++) {
		int moh_1 = random_integer(ARRAY_SIZE);
		int moh_2 = sequential_search(A, ARRAY_SIZE, A[moh_1]);
		assert(moh_2 >= 0 && A[moh_2] == A[moh_1]);
		if (p % 100 == 0) {
			printf(".");
			fflush(NULL);
		}
	}
	printf(" PASSED. \n");
	printf("Testing  binary search  "); fflush(NULL);
	for (int p = 0; p < MAX_TEST_TIMES * 10; p++) {

		int moh_1 = random_integer(ARRAY_SIZE);
		int moh_2 = binary_search(A, ARRAY_SIZE, A[moh_1]);
		assert(moh_2 >= 0 && A[moh_2] == A[moh_1]);
		if (p % 100 == 0) {
			printf(".");
			fflush(NULL);
		}
	}
	printf(" PASSED. \n");
}