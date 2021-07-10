#include <stdio.h>
#include <stdlib.h>

unsigned long string_to_long(char* input);

int main(int argc, char *argv[]){
	char* memory_to_eat=malloc(20);
	if(argc<2){ //if user didnt give argument
		printf("how much memory can i eat ?\n");
		scanf("%s",memory_to_eat);
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
	for(unsigned long  i=0;i<memorysize;i++){
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
	int unit=0; //empty=0, kilo=1, mega=2, giga=3, etc...
	int multiplier=0; //either 1000 or 1024
	while(input[i]!='\x00'){
		switch(input[i]){
		case 'k':
			unit=1;
			break;
		case 'M':
			unit=2;
			break;
		case 'G':
			unit=3;
			break;
		case 'T':
			unit=4;
			break;
		case 'P':
			unit=5;
			break;
		case 'E':
			unit=6;
			break;
		case 'i':
			break;
		default:
			output*=10; //decimalshift to the left
			output+=input[i]-48; //48 is the position of '0' in ASCII, '0' - 48 = 0 | '9' - 48 = 9
		}
		if(unit!=0){
			if(input[i+1]=='i'){ //checking for an 'i' to see if we use 1000 or 1024
				multiplier=1024;
			}
			else{
				multiplier=1000;
			}
			for(unsigned int j=0;j<unit;j++){
				output*=multiplier;
			}
		}
		if(unit){//if it detected an unit, stop the loop
			break;
		}
		i++;
	}
	return output;
}
