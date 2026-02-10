#include <stdio.h>
int checkscore(char std[]);
int studentcorrect(char stu[][100]);
int student;

int main() {
    int i,j;
    char s[100][100];
	char ans[8][10] = {
        {'A','B','A','C','C','D','E','E','A','D'},
        {'D','B','A','B','C','A','E','E','A','D'},
        {'E','D','D','A','C','B','E','E','A','D'},
        {'C','B','A','E','D','C','E','E','A','D'},
        {'A','B','D','C','C','D','E','E','A','D'},
        {'B','B','E','C','C','D','E','E','A','D'},
        {'B','B','A','C','C','D','E','E','A','D'},
        {'E','B','E','C','C','D','E','E','A','D'}};
    char keys[10] = {'D','B','D','C','C','D','A','E','A','D'};
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 10; j++) {
            s[i][j] = ans[i][j];
        }
        student = i;
        printf("std %d => %d\n", (i+1), checkscore(s));
    }
    studentcorrect(s);
}

int checkscore(char std[]) {
    char keys[10] = {'D','B','D','C','C','D','A','E','A','D'};
    int i, score = 0;

    for(i = 0; i < 10; i++) {
        if(std[student * 100 + i] == keys[i]){
        	score++;
		} 
    }
    return score;
}

int studentcorrect(char stu[][100]){
	char keys[10] = {'D','B','D','C','C','D','A','E','A','D'};
	int i,score=0;
	for(i=0;i<8;i++){
    	if(stu[i][0] == keys[0]){
    		score++;
		}
	}
	printf("studentcorrect 1 = %d",score);
}
