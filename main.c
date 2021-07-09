#include <stdio.h>
#include <stdlib.h>

unsigned long string_to_long(char* input);

int main(int argc, char *argv[]){
	char* memory_to_eat=malloc(20);
	if(argc<2){ //if user didnt give argument
		printf("how much memory can i eat ?\n");
		fgets(memory_to_eat,20,stdin); //20 is the maximum letters required to fit a long value in a string
	}
	else{
		memory_to_eat=argv[1];
	}
	
	unsigned long memorysize = string_to_long(memory_to_eat); //converting string to long
	printf("allocating %lu bytes of memory\n",memorysize);
	char* memoryallocated = malloc(memorysize); //allocating memory
	
	
	if(memoryallocated == NULL){ //if malloc returned null, it means you are too greedy/system has not that much RAM
		printf("malloc failed !!\n");
	}
	else{
		printf("malloc success\n");
	}
	
	
	printf("writing to memory\n");
	for(unsigned long  i = 0 ; i<memorysize ;i++){
		memoryallocated[i] = (char)rand(); //putting random characters in memory incase ram is compressed or unused
	}
	printf("writing done\n");
	
	getchar(); //wait until user is satisfied
	free(memoryallocated);
	return 0;
}


unsigned long string_to_long(char* input){
	unsigned long output=0;
	unsigned int i=0;
	while(input[i+1]!='\x00'){
		output*=10; //decimalshift to the left
		output+=input[i]-48; //48 is the position of '0' in ASCII, '0' - 48 = 0 | '9' - 48 = 9
		i++;
	}
	return output;
}
