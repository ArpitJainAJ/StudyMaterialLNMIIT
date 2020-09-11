#include <stdio.h>
#include <math.h>

void binary(int decimal, int n) {
	int binary[n];
	int i = 0;
	while (decimal > 0) {
		binary[i++] = decimal % 2;
		decimal /= 2;
	}
	for(i; i<n; i++) {
		binary[i] = 0;
	}
	int j = i-1;
	for( j; j >=0; j--) {
		printf("%d", binary[j]);
	}
	printf(".\n");
}

int main() {

	int sizeMainMemory;
	int sizeModules;
	int memoryAddress;
	
	int numberOfAddressBits;
	int numberOfModules;
	int simpleModule, simpleAddress;
	int interModule, interAddress;

	int moduleAddressBits;
	int i;
	
	printf("\n");
	printf("Enter the size of the main memory: ");
	scanf("%d", &sizeMainMemory);
	printf("Enter the size of the available memory modules: ");
	scanf("%d", &sizeModules);
	printf("Enter the memory address to be accessed: ");
	scanf("%d", &memoryAddress);
	
	printf("\n");
	numberOfAddressBits = log(sizeMainMemory)/log(2);
	printf("Number of address bits is %d.\n", numberOfAddressBits);
	numberOfModules = sizeMainMemory/sizeModules;
	printf("Number of memory modules used is %d.\n", numberOfModules);
	printf("Memory address in binary is ");
	binary(memoryAddress, numberOfAddressBits);
	printf("\n");

	moduleAddressBits = log(numberOfModules)/log(2);
	printf("For simple memory, address is in Module ");
	
	int n = numberOfAddressBits;
	int binary[n];
	i = 0;
	int b = memoryAddress;
	while (b > 0) {
		binary[i++] = b % 2;
		b /= 2;
	}
	for(i; i<n; i++) {
		binary[i] = 0;
	}
	int j = i-1;
	for( j; j >=i-moduleAddressBits; j--) {
		printf("%d", binary[j]);
	}
	printf(" at address ");
	for( j; j >=0; j--) {
		printf("%d", binary[j]);
	}
	printf(".\n");


	printf("For interleaved memory, address is at address ");
	n = numberOfAddressBits;
	binary[n];
	i = 0;
	b = memoryAddress;
	int c = n-moduleAddressBits;
	while (b > 0) {
		binary[i++] = b % 2;
		b /= 2;
	}
	for(i; i<n; i++) {
		binary[i] = 0;
	}
	j = i-1;
	for( j; j >=i-c; j--) {
		printf("%d", binary[j]);
	}
	printf(" in module ");
	for( j; j >=0; j--) {
		printf("%d", binary[j]);
	}
	printf(".\n");
	printf("\n");
}
