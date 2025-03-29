#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	// ret, intc, intc, intc, intc
	unsigned char function_skip[] = {0xc3, 0xcc, 0xcc, 0xcc, 0xcc};
	unsigned char function_ref[] = {0x48, 0x89, 0x5c, 0x24, 0x10, 0x57, 0x48, 0x83, 0xec, 0x50};
	unsigned char function_start[10];
	
	FILE* dll_file = fopen("flowchartx64.dll", "r+");
	fseek(dll_file, 0x70140, SEEK_SET);	
	if (!fread(function_start, 10, 1, dll_file)){
		printf("Failed to read from flowchartx64.dll\n");
		return 1;
	}
	if (memcmp(function_ref, function_start, 10)){
		printf("Failed to find start of broken function\n");
		return 1;
	}
	fseek(dll_file, 0x70140, SEEK_SET);
	if (!fwrite(function_skip, 5, 1, dll_file)){
		printf("Failed to write to flowchartx64.dll\n");
		return 1;
	}
	fclose(dll_file);
	printf("Patched flowchartx64.dll\n");
	return 0;
}
