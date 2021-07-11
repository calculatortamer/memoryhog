#include <stdio.h>
#include <stdlib.h>

unsigned long string_to_long(char* input);

int main(int argc, char *argv[]){
	char* memory_to_eat=malloc(40); /*you wont need more than 40 characters anyway, you hacker*/
	if(argc<2){ /*if user didnt give argument*/
		printf("how much memory can i eat ?\n");
		scanf("%s",memory_to_eat);
	}
	else{
		memory_to_eat=argv[1];
	}
	
	unsigned long memorysize = string_to_long(memory_to_eat); /*converting string to long*/
	printf("allocating %lu bytes of memory\n",memorysize);
	char* memoryallocated = malloc(memorysize); /*allocating memory*/
	
	
	if(memoryallocated == NULL){ /*if malloc returned null, it means you are too greedy/system has not that much RAM*/
		printf("malloc failed !!\n");
	}
	else{
		printf("malloc success\n");
	}
	
	
	printf("writing to memory\n");
	unsigned long i=0;
	for(;i<memorysize;i++){
		memoryallocated[i] = (char)rand(); /*putting random characters in memory incase ram is compressed or unused*/
	}
	printf("writing done\n");
	
	while(1);
	
	printf("freeing memory");
	free(memoryallocated);
	return 0;
}


unsigned long string_to_long(char* input){
	unsigned long output=0;
	unsigned int i=0;
	int unit=0; /*empty=0, kilo=1, mega=2, giga=3, etc...*/
	int multiplier=0; /*either 1000 or 1024*/
	int decimal=0; /*0=string contains no decimal point/comma, anything else=number of digits after the point/comma*/
	while(input[i]!='\x00'){
		switch(input[i]){
		case 'k':
		case 'K':
			unit=1;
			break;
		case 'M':
		case 'm':
			unit=2;
			break;
		case 'G':
		case 'g':
			unit=3;
			break;
		case 'T':
		case 't':
			unit=4;
			break;
		case 'P':
		case 'p':
			unit=5;
			break;
		case 'E':
		case 'e':
			unit=6;
			break;
		case 'i':
		case 'I':
			break;
		case ',':
		case '.':
			if(!decimal){
				decimal=1;
			}
			else{
				printf("extra decimal character detected, ignoring...\n");
			}
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if(decimal){ /*if decimal isnt zero*/
				decimal++;
			}
			output*=10; /*decimalshift to the left*/
			output+=input[i]-48; /*48 is the position of '0' in ASCII, '0' - 48 = 0 | '9' - 48 = 9*/
			break;
		default:
			printf("unknown character : %c\n",input[i]);
		}
		if(unit){
			if(input[i+1]=='i'){ /*checking for an 'i' to see if we use 1000 or 1024*/
				multiplier=1024;
			}
			else{
				multiplier=1000;
			}
			unsigned int j=0;
			for(;j<unit;j++){
				output*=multiplier;
			}
			break;
		}
		i++;
	}
	if(!unit && decimal){ /*if user is curious enough to ask me to allocate bits*/
		printf("note : i dont allocate bits\n");
	}
	unsigned int j=1;
	for(;j<decimal;j++){
		output/=10;
	}
	return output;
}
