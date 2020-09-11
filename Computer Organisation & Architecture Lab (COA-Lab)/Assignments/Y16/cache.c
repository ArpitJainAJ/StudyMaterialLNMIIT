#include <stdio.h>
#include <math.h>

void binary(int decimal) {
	int binary[10];
	int i = 0;
	while (decimal > 0) {
		binary[i++] = decimal % 2;
		decimal /= 2;
	}
	for(i; i<10; i++) {
		binary[i] = 0;
	}
	int j = i-1;
	for( j; j >=0; j--) {
		printf("%d", binary[j]);
	}
	printf("\n");
}

void binaryCache(int decimal) {
	int binary[10];
	int i = 0;
	while (decimal > 0) {
		binary[i++] = decimal % 2;
		decimal /= 2;
	}
	int j = i-1;
	for( j; j >=0; j--) {
		printf("%d", binary[j]);
	}
	printf("\n");
}

int main() {

	const int mainMemoryWords = 1024;
	const int mainMemoryWordSize = 16;
	const int cacheWord = 256;
	const int cacheWordsPerBlock = 32;
	int mainMemoryBytesPerWord = mainMemoryWordSize / 8;	

	int cacheBytesPerBlock = cacheWordsPerBlock * mainMemoryWordSize / 8;
	int offsetSize = log(cacheBytesPerBlock)/log(2);
	int setSize = log(mainMemoryWords)/log(2);
	int cacheBlocks = cacheWord / cacheWordsPerBlock;
	int tagSize = setSize  - log(cacheBlocks)/log(2) - log(cacheWordsPerBlock)/log(2);

	int memoryAddress;
	printf("\n");
	printf("Number of blocks in cache: %d\n", cacheBlocks);
	printf("Number of bits required for words is: %.0f\n", log(cacheWordsPerBlock)/log(2));
	printf("Number of bits required for block is: %.0f\n", log(cacheBlocks)/log(2));
	printf("Number of bits required for tag is: %d\n", tagSize);
	
	printf("\n");
	printf("Enter the memory address (k): ");
	scanf("%d", &memoryAddress);
	printf("Equivalent binary value of k is: ");
	binary(memoryAddress);
	printf("Main memory block is: %d\n", memoryAddress / mainMemoryBytesPerWord);
	printf("Cache block is: %d\n", memoryAddress % cacheBlocks);
	printf("Word is given by: ");
	binaryCache(((memoryAddress % cacheBlocks) * 2 - 1) + memoryAddress % 2 - 1);
	printf("Block is given by: ");
	binaryCache((memoryAddress % cacheBlocks));
	printf("\n");

}
