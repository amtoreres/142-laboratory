#include <stdio.h>
#include <stdlib.h>

int primeChecker(int);
void mergeSort(int *arr, int left, int right);
void mergeSubarrays(int *arr, int left, int mid, int right);
int linearSearch(int *arr, int num, int length);
void showSortedArray(int *arr, int length);

int main()
{
    int num, ctr=0, arrSize=5, isSearch, index;
    int *arr = (int *) malloc(arrSize*sizeof(int));

    printf("\n---Enter -1 to stop----\n");

     while(1){  
        //if arrSize is not sufficient to hold the numbers
        if(arrSize <= ctr){
            arrSize++;
            arr = (int *)realloc(arr, arrSize*sizeof(int));
        }

        printf("Enter prime number: ");
        scanf("%d", &num);

        //break if number is negatives
        if(num == -1)
            break;

        //if number is array, add to array
        if(primeChecker(num)==1){
            arr[ctr] = num;
            ctr++;
        }
        else
            printf("%d is not a prime number. ", num);
    }
    
    //if there are no elements in the array
    if(ctr == 0){
        printf("The array is empty. Cannot sort and search.");
        return 0;
    }

    mergeSort(arr, 0, ctr-1);

    printf("\nThe array of prime numbers has been sorted. \nDo you want to search for a prime number? (1-yes | 0-no): ");
    scanf("%d", &num);
    if(num == 1){
        printf("Enter the number to be search: ");
        scanf("%d", &num);
        index = linearSearch(arr, num, ctr);
        if(index != -1){
            printf("The number %d is found at index %d.", num, index);
        }
        else{
            printf("The number %d is not found on the array.", num);
        }
        showSortedArray(arr, ctr);
    }

    printf("\nProgram terminated.\n");

    return 0;
}


//checks if the number is prime
int primeChecker(int num){
    if(num >= 2){
        for(int i=2; i <= num/2; i++){
            if(num%i == 0){
                return -1;
            }
        }
        return 1;
    }
    else{
        return -1;
    }
}


void mergeSort(int *arr, int left, int right){
    if(left < right){
        int mid = (left+right) / 2;
        mergeSort(arr, left, mid);             //divides the left subarray
        mergeSort(arr, mid+1, right);          //divides the right subarray
        mergeSubarrays(arr, left, mid, right);
    }
}

void mergeSubarrays(int *arr, int left, int mid, int right){

    /* i = left subarray index tracker
       j = right subarray index tracker
       k = tempArray index tracker */
    int i=left, j=mid+1, k=left, tempArr[right+1];

    //checks if either the left or right subarray is already transfered to tempArr
    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){       //compares the elements of left and right subarrays
            tempArr[k] = arr[i];   
            i++;                    //move to next element in left subarray
            k++;                    //move to next slot in tempArr
        }
        else{
            tempArr[k] = arr[j];    
            j++;                    //move to next element in right subarray
            k++;                    
        }
    }

    //copies the remaining elements in left subarray to tempArr if right subarray is exhausted
    while(i <= mid){
        tempArr[k] = arr[i];
        i++;
        k++;
    }

    //copies the remaining elements in right subaarray to tempArr if left subaaray is exhausted
    while (j <= right){
        tempArr[k] = arr[j];
        j++;
        k++;
    }

    //copies the elements from tempArr to arr
    for(int idx=left; idx<=right; idx++){
        arr[idx] = tempArr[idx];
    }
}


int linearSearch(int *arr, int num, int length){
    for(int i=0; i<length; i++){
        if(num == arr[i]){
            return i;
        }
    }
    return -1;
}

void showSortedArray(int *arr, int length){
    printf("\nSorted Array: ");
    for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
     printf("\n");
}






