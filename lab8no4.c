#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int searchNum(int numAr[], int numArSize, int target);
int checkNum(int numAr[], int numArSize);
void sortDescending(int numAr[], int n);

int main() {
    int scores[4];
    int i;
    srand(time(NULL));
    for (i = 0; i < 4; i++) {
        scores[i] = checkNum(scores, i);
    }
    printf("\nscores: ");
    for (i = 0; i < 4; i++){
    	printf("%d ", scores[i]);
	}
    sortDescending(scores, 4);
    printf("\nBest 3 scores: ");
    for (i = 0; i < 3; i++) {
        printf("%d ", scores[i]);
    }
    return 0;
}


int searchNum(int numAr[], int numArSize, int target) {
	int i;
    for ( i = 0; i < numArSize; i++) {
        if (numAr[i] == target) return 1;
    }
    return 0;
}

int checkNum(int numAr[], int numArSize) {
    int rnum = (rand() % 100) + 1;
    while (searchNum(numAr, numArSize, rnum)) {
        rnum = (rand() % 100) + 1;
    }
    return rnum;
}

void sortDescending(int numAr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (numAr[j] < numAr[j + 1]) { 
                temp = numAr[j];
                numAr[j] = numAr[j + 1];
                numAr[j + 1] = temp;
            }
        }
    }
}
