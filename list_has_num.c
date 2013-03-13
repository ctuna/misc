#include <stdio.h>
#include <stdbool.h>

bool arrayHasNum(int numWanted, int array[], int arrayLength){
	int minIndex = 0;
	int midIndex;
	int midOffset;
	int sizeOfInterval= arrayLength;
	int maxIndex = sizeOfInterval-1;
	int pivot;
	
	while (sizeOfInterval>=1){
		midOffset=(sizeOfInterval-1)/2;
		midIndex = minIndex + midOffset;
		pivot = array[midIndex];
		if (pivot==numWanted){
			return true;
			}
		else if (pivot>= numWanted){
			maxIndex = midIndex - 1;
		}
		else {
			minIndex = midIndex + 1;
		}
		sizeOfInterval = maxIndex - minIndex + 1;
	}
	return false;
}

int main(int argc, char** argv){
	int numWanted = atoi(argv[1]);
	int minIndex = 2;
	int midIndex;
	int midOffset;
	int maxIndex = argc - 1;
	int sizeOfInterval = argc - 2;
	int pivot;
	int myArray[sizeOfInterval];
	int i = minIndex;
	int j = 0;
	while (i<=maxIndex){
		*(myArray + j) = atoi(argv[i]);
		i++;
		j++;
	}
	if (arrayHasNum(numWanted, myArray, sizeOfInterval)){
		printf("true\n");
	}
	else printf("false\n");
	return 0;
}




