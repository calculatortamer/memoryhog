#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	if(argc<2){
		printf("cant hog 0 memory, give me more\n");
		return 1;
	}
	unsigned long memorysize=atol(argv[1]);
	printf("allocating %lu bytes of memory\n",memorysize);
	char* memoryallocated=malloc(memorysize); //allocating memory
	if(memoryallocated==NULL){
		printf("malloc failed !!\n");
	}
	else{
		printf("malloc success\n");
	}
	printf("writing to memory");
	for(unsigned long  i=0;i<memorysize;i++){
		memoryallocated[i]=(char)rand();
	}
	printf("writing done");
	gets(); //wait until user is satisfied
	return 0;
}
