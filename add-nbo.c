#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t read_file(char* fileName) {
	FILE* fp = fopen(fileName, "rb");

	uint32_t number;
	fread(&number, sizeof(uint32_t), sizeof(number), fp);
	number = ntohl(number);
	fclose(fp);
	return number;
}

int main(int argc, char* argv[]) {

	if (argc != 3) {
		printf("syntax : add-nbo <file1> <file2>\n");
		printf("sample : add-nbo a.bin c.bin\n");
		exit(EXIT_FAILURE);
	}

	uint32_t num1 = read_file(argv[1]);
	uint32_t num2 = read_file(argv[2]);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1 + num2, num1 + num2);

	return 0;
}
