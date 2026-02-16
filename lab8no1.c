#include <stdio.h>

int finemax(int num[],int size);
void printarr(int myarr[],int size);
void addone(int number[], int add[], int sizeNum);
void addtwo(int number[], int pos[], int x, int sizeNum, int sizePos);
void addthree(int number[], int pos[][2], int sizePos, int sizeNum);

int main() {
    int number[5] = {20, 50, 100, 199, 9};
    int add[] = {1,1,1,1,1};
    int size = sizeof(number) / sizeof(number[0]);
    int sizeadd = sizeof(add) / sizeof(add[0]);
	int max;
	max = finemax(number,size);
	printarr(number,size);
	printf("max = %d\n",max); 
	
	printf("------- addtone ---------\n");
	addone(number,add,sizeadd);
	printarr(number,size);
	
	printf("------- addtwo ---------\n");
	int x,n,i;
	printf("input x = ");
	scanf("%d",&x);
	printf("input n = ");
	scanf("%d",&n);
	int pos[n];
	printf("input pos = ");
	for(i=0;i<n;i++){
		scanf("%d",&pos[i]);
	}
	addtwo(number,pos,x,size,n);
	printarr(number,size);
	
	printf("------- addthree ---------\n");
    int m; 
    printf("n = ");
    scanf("%d",&m);
    int pos3[m][2]; 
    for(i=0;i<m;i++) {
        printf("input pos and value");
        scanf("%d %d", &pos3[i][0], &pos3[i][1]);
    }
    addthree(number,pos3,m,size);
    printarr(number,size);
}

int finemax(int num[],int size){
	int maximum,i=0;
	maximum = num[i];
	for(i=0;i<size;i++){
		if(num[i] > maximum){
			maximum = num[i];
		}
	}
	num[0] = 555;
	return maximum;
}

void printarr(int myarr[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("number[%d] : %d\n",i,myarr[i]);
	}
	return;
}

void addone(int number[], int add[], int sizeNum){
	int i;
	for(i=0;i<sizeNum;i++){
		number[i] = number[i] + add[i];
	}
	return;
}

void addtwo(int number[], int pos[], int x, int sizeNum, int sizePos){
    int i;
    for (i = 0; i < sizePos; i++){
        int targetIndex = pos[i];
        if (targetIndex >= 0 && targetIndex < sizeNum){
            number[targetIndex] += x;
        }
    }
}

void addthree(int number[], int pos[][2], int sizePos, int sizeNum){
    int i;
    for (i = 0; i < sizePos; i++) {
        int targetIndex = pos[i][0];
        int addValue = pos[i][1];
                if (targetIndex >= 0 && targetIndex < sizeNum){
            number[targetIndex] += addValue;
        }
    }
}
