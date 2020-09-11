#include <stdio.h>

int checkRAW(char a[], char b[]) {
	int raw = 1, i;
	char result = 0;
	for(i = 4; i < 8; i++) {
		if(a[i+8] != b[i]) {
			raw = 0;	
			break;
		}
	}
 	if(raw) {
		printf("RAW hazard due to register ");
		int j;
		for(j = 12; j < 16; j++) {
			printf("%d",a[j]);
		}
		result = raw;
	}
	for(i = 8; i < 12; i++) {
		if(a[i+4] != b[i]) {
			raw = 0;	
			break;
		}
	}
 	if(raw) {
		printf("RAW hazard due to register ");
		int j;
		for(j = 12; j < 16; j++) {
			printf("%d",a[j]);
		}
		result += raw;		
	}
	return result;
}

void display(char a[]) {
	int i;
	for (i = 0; i < 16; i++) {
		printf("%d", a[i]);
	}
	printf("\n");
}

int main() {
	
	char I1[] = {0,0,0,0, 0,0,0,1, 0,0,1,0, 0,0,1,1};
	char I2[] = {0,0,0,1, 0,0,1,1, 0,1,0,1, 0,1,1,1};
	char I3[] = {0,0,0,0, 0,0,1,0, 0,0,1,1, 1,0,0,0};
	char I4[] = {0,0,1,0, 0,0,1,1, 0,1,1,1, 1,0,0,1};
	char nop[] = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
	char r1,r2,r3,r4,r5;
	int nop1 = 0, nop2 = 0, nop3 = 0;
	printf("\n");
	r1 = checkRAW(I1,I2);
	if(r1) {
		printf(" in instructions I1, I2.\n");
		nop1 += 1;
	}
	r2 = checkRAW(I1,I3);
	if(r2) {
		printf(" in instructions I1, I3.\n");
	}
	r3 = checkRAW(I2,I3);
	if(r3) {
		printf(" in instructions I2, I3.\n");
		nop2 += 1;
	}
	r4 = checkRAW(I2,I4);
	if(r4) {
		printf(" in instructions I2, I4.\n");
	}
	r5 = checkRAW(I3,I4);
	if(r5) {
		printf(" in instructions I3, I4.\n");
		nop3 += 1;
	}
	printf("\nWith NOP: \n");
	display(I1);
	if(nop1) {
		int i;
		for(i = 0; i < nop1; i++) {
			display(nop);
		}
	}
	display(I2);
	if(nop2) {
		int i;
		for(i = 0; i < nop2; i++) {
			display(nop);
		}
	}
	display(I3);
	if(nop3) {
		int i;
		for(i = 0; i < nop3; i++) {
			display(nop);
		}
	}
	display(I4);
	printf("\n");	
}

