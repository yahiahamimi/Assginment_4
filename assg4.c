/******************************************************************************
 *
 * File Name: assg4.c
 *
 * Description: File contains all functions based on the assignment 4 in Standard Diploma
 * each Task has its own Functionality and description individually
 * and the user which functionality he wants to use
 *
 * Author: Yahia Hamimi
 ******************************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "assg4.h"

/**
 * @name print_Array
 * @details Prints the elements of the array.
 *
 * @param arr The array to be printed.
 * @param size The size of the array.
 */
void print_Array(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
/**
 * @name scan_Array
 * @details Prints the elements of the array.
 *
 * @param arr The array to be printed.
 * @param size The size of the array.
 */
void scan_Array(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\n");
}
/**
 * @name task1
 * @details This function takes an array of integers and its size as input
 * and returns the sum of all the elements in the array (accessing via pointers).
 *
 * @param a The array of integers to be summed.
 * @param numbers_size The size of the array.
 *
 * @return The sum of the elements in the array.
 */
int task1(int a[], int numbers_size)
{
	int i, sum = 0;
	int *ptr = a;

	for (i = 0; i < numbers_size; i++)
	{
		sum += *(ptr + i); // using pointers arthmetic
	}
	/*another way using ptr/array index
	for (i = 0; i < numbers_size; i++)
			sum += ptr[i]-------------->sum+=*(ptr+i);
	*/
	return sum;
}

/**
 * @name task2
 *
 * @param str The string to get its length.
 *
 * @details This function takes a string as input and returns its length (manipulating via pointers).
 *
 * @return The length of the string.
 */
int task2(char str[])
{
	int counter = 0;
	char *ptr = str;
	while (*ptr != '\0')
	{
		counter++;
		ptr++;
	}
	return counter - 1;
}

/**
 * @name task3
 * @details This function takes an array of integers and its size as input and
 * returns a pointer to the last element in the array (manipulating via pointers).
 *
 * @param a The array of integers.
 * @param numbers_size The size of the array.
 *
 * @return A pointer to the last element in the array.
 */
int *task3(int a[], int numbers_size)
{
	int *ptr = a + numbers_size - 1; // equivalent to ptr=&a[numbers_size-1]
	return ptr;
}

/**
 * @name task4
 *
 * @param ptr The array of integers to get its smallest element.
 * @param size The size of the array.
 *
 * @details This function takes an array of integers and its size as input and
 * returns the smallest element in the array (manipulating via pointers).
 *
 * @return The smallest element in the array.
 */
int task4(int *ptr, int size)
{
	int i = 0;
	// assume that the minimum number is the first element
	int min = ptr[0];

	// start compare from the second array element
	for (i = 1; i < size; i++)
	{
		if (ptr[i] < min)
			min = ptr[i];
	}
	return min;
}

/**
 * @name task5
 *
 * @param ptr1 The array of integers to copy from.
 * @param ptr2 The array of integers to copy to.
 * @param size The size of the arrays.
 *
 * @details This function takes two arrays of integers and their size as input and
 * copies the elements from the first array into the second array (manipulating via pointers).
 *
 */
void task5(int *ptr1, int *ptr2, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		*ptr2 = *ptr1;
		// another syntax is ptr2[i]=ptr1[i]; and we don't need the increament line
		ptr1++;
		ptr2++;
	}
}

/**
 * @name task7
 *
 * @param ptr1 The pointer to the first number to swap.
 * @param ptr2 The pointer to the second number to swap.
 *
 * @details This function takes two pointers to integers as input and swaps the two numbers
 * using the XOR operator (manipulating via pointers).
 *
 */
void task7(int *ptr1, int *ptr2) // this the way to swap two numbers using xor(aka bitwise operators)
{
	*ptr1 = *ptr1 ^ *ptr2;
	*ptr2 = *ptr1 ^ *ptr2;
	*ptr1 = *ptr1 ^ *ptr2;
}
/**
 * @name task8
 *
 * @param arr1 The array of integers to swap with arr2.
 * @param arr2 The array of integers to swap with arr1.
 * @param size The size of the arrays.
 *
 * @details This function takes two arrays of integers and their size as input and
 * swaps each element in array1 with the corresponding element in array2 (manipulating via pointers).
 *
 */
void task8(int *arr1, int *arr2, int size)
{
	int i = 0, temp;
	// Swap each element in array1 with the corresponding element in array2
	for (i = 0; i < size; i++)
	{
		// Swap between the two arrays elements
		temp = *arr1;
		*arr1 = *arr2;
		*arr2 = temp;
		// increment pointers to get the next array element
		arr1++;
		arr2++;
	}
}
char edit_str[4];
/**
 * @name task9
 *
 * @param str The string to be edited.
 *
 * @details This function takes a string as input and returns a pointer to a new string
 * which is the last two characters of the input string concatenated with a space between them.
 *
 * @return A pointer to a new string containing the last two characters of the input string
 * concatenated with a space between them.
 *
 */
char *task9(char str[])
{
	int size = 0;
	char *ptr = str;
	while (*ptr != '\0')
	{

		ptr++;
		size++;
	}
	/*after this loop ptr will be shifted by string size + 1 cause getchar() aka the pointer will be pointing to empety place
	after the null terminator thus we need to decrease the pointer first to be pointing to the null terminator*/
	--ptr;

	/* get the last character in the string word */
	edit_str[0] = *(--ptr); // we need to do pre increment then access
	edit_str[1] = ' ';
	/* get the second last character in the string word */
	edit_str[2] = *(--ptr);

	/* Add the null terminator */
	edit_str[3] = '\0';

	return edit_str;
}

/**
 * @name task10
 *
 * @param ptr_1 The first pointer to integer to be swapped.
 * @param ptr_2 The second pointer to integer to be swapped.
 *
 * @details This function takes two pointers to integers as input and swaps the two pointers.
 *
 */
void task10(int **ptr_1, int **ptr_2)
{
	int *temp = *ptr_1;
	*ptr_1 = *ptr_2;
	*ptr_2 = temp;
}

/**
 * @name task11
 *
 * @param num_1 The first integer to be swapped.
 * @param num_2 The second integer to be swapped.
 *
 * @details This function takes two pointers to integers as input ( 16-bits & 32-bits ) and swaps the two numbers
 * by swapping the 2-bytes of each number.
 *
 */
void task11(int *num_1, int *num_2)
{
	// point to the first integer using pointer to short to access 2-bytes
	short *ptr1 = (short *)num_1;

	// point to the second integer using pointer to short to access 2-bytes
	short *ptr2 = (short *)num_2;

	// make the first 2-bytes in num2 equals to the second two bytes of num1
	ptr2[0] = ptr1[1];

	// make the second 2-bytes in num2 equals to the first two bytes of num1
	ptr2[1] = ptr1[0];
}

/**
 * @name task12
 *
 * @param arr The array of integers to be searched.
 * @param arr_size The size of the array.
 *
 * @details This function takes an array of integers and its size as input and returns the first element
 * whose value occurs an odd number of times in the array (accessing via pointers).
 *
 * @return The first element whose value occurs an odd number of times in the array.
 */
int task12(int *arr, int arr_size)
{
	int i, j;
	int count = 0;
	int index = 0;
	for (i = 0; i < arr_size; i++)
	{
		for (j = 1; j < arr_size; j++)
		{
			/* Count the number of times that this element value exist in the array */
			if (arr[i] == arr[j])
			{
				index = i;
				count++;
			}
		}
		/* check if the count is odd number then we found number */
		if (count % 2 != 0)
		{
			break;
		}
		/* reset the count value before check for the next array element */
		count = 0;
	}
	return arr[index];
}

/* another way
 *int task12(int *a,int size){
	int consecutive_occurr = 1,i;
	int even_odd;

	for(i=0;i<size;i++){
		if(a[i]==a[i+1])
			consecutive_occurr++;
		else{
			even_odd=(consecutive_occurr%2);
			if(even_odd!=0)
				break;
			consecutive_occurr=1;
		}
}
	return a[i];
}
*/

int main(void)
{
	/* Set stdin and stdout to unbuffered mode to solve the problems with scanf and printf */
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int task;
	printf("Enter the specific task to operate:\n");
	scanf("%d", &task);
	/* switch case for each task */
	switch (task)
	{
	case 1:
	{
		int arr1[SIZE];
		printf("Enter the numbers to be summed:\n");
		scan_Array(arr1, SIZE); // my function to scan an array through loops instead of writing it each time
		printf("the summation of the array you have enterd is:%d\n", task1(arr1, SIZE));
		break;
	}
	case 2:
	{
		char str[SIZE_str];
		printf("Please enter ther required string:");
		getchar();
		fgets(str, sizeof(str), stdin);
		printf("the length of the given string is:%d", task2(str));
		break;
	}
	case 3:
	{
		int arr1[SIZE];
		printf("Enter the required array:\n");
		scan_Array(arr1, SIZE);
		int i;
		int *ptr = task3(arr1, SIZE);
		for (i = SIZE - 1; i >= 0; i--)
		{
			printf("\nElement%d is:%d", i, *ptr);
			ptr--;
		}
		break;
	}
	case 4:
	{
		int arr[SIZE];
		printf("Enter the required array:\n");
		scan_Array(arr, SIZE);
		printf("tne minimum element in the array is:%d", task4(arr, SIZE));
		break;
	}
	case 5:
	{
		int arr1[SIZE], arr2[SIZE];
		printf("Enter the required array:\n");
		scan_Array(arr1, SIZE);
		task5(arr1, arr2, SIZE);
		printf("the new copied array will be:\n");
		print_Array(arr2, SIZE);
		break;
	}

	case 6:
	{
		int arr[SIZE] = {10, 100, 200, -1, 1000, 500, 20, 60, -50, 26};
		int i, *ptr[SIZE];
		int MAX = 0;

		for (i = 0; i < SIZE; i++)
		{
			// assign the address of each array element to a pointer element
			ptr[i] = &arr[i];
		}

		for (i = 0; i < SIZE; i++)
		{
			// print all the array elements using array of pointers
			printf("Value of arr[%d] = %d\n", i, *ptr[i]);
		}

		MAX = *ptr[0]; // assume that the maximum number is the first array element

		for (i = 1; i < SIZE; i++)
		{
			if (MAX < *ptr[i])
			{
				MAX = *ptr[i];
			}
		}
		printf("Maximum Number = %d\n", MAX);
		break;
	}

	case 7:
	{
		int num1, num2;
		void (*ptr_func)(int *, int *); // pointer to function decleration
		ptr_func = task7;
		printf("enter the first number:\n");
		scanf("%d", &num1);
		printf("Enter the second number:\n");
		scanf("%d", &num2);
		(*ptr_func)(&num1, &num2); // calling a function using pointer to function way
		printf("num1=%d , num2=%d\n", num1, num2);
		break;
	}
	case 8:
	{
		int arr1[SIZE];
		printf("Enter the first array:\n");
		scan_Array(arr1, SIZE);
		int arr2[SIZE];
		printf("Enter the second array:\n");
		scan_Array(arr2, SIZE);
		task8(arr1, arr2, SIZE);
		printf("after swapping the first array would be:\n");
		print_Array(arr1, SIZE);
		printf("after swapping the Second array would be:\n");
		print_Array(arr2, SIZE);
		break;
	}
	case 9:
	{
		printf("Please enter ther required string:");
		char str[SIZE_str];
		getchar();
		fgets(str, sizeof(str), stdin);
		printf("%s", task9(str));
		break;
	}
	case 10:
	{
		int num1 = 5, num2 = 10;
		int *ptr1 = &num1;
		int *ptr2 = &num2;
		printf("before using swap function the addressies are ptr1:%p , ptr2:%p\n", ptr1, ptr2);
		printf("*prt1 = %d\n", *ptr1);
		printf("*prt2 = %d\n", *ptr2);
		task10(&ptr1, &ptr2); // send the addressies of ptr1,ptr2 to the function and recieve it in apointer to pointer
		printf("after using swap function the addressies are ptr1:%p , ptr2:%p", ptr1, ptr2);
		printf("*prt1 = %d\n", *ptr1);
		printf("*prt2 = %d\n", *ptr2);
		break;
	}
	case 11:
	{
		int num1 = 0xFFFFAAAA;
		int num2 = 0;
		task11(&num1, &num2);
		printf("The value after swapping %x", num2);
		break;
	}
	case 12:
	{
		int arr[SIZE];
		printf("Enter the required array:\n");
		scan_Array(arr, SIZE);
		printf("the number that has odd reprepetitions is:%d", task12(arr, SIZE));
		break;
	}

	default:
		printf("You have entered an invalid task number\n");
	}
}
