#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void show_usage(char* name){
printf("Usage : %s [OPTIONS] MEMORY TO WASTE\n\n-m, --malloc	Allocate only, do not write inside the allocated memory\n-h, -?, --help	Show this\n",name,name);
}

struct arguments{
	char* name; //argv[0]
	char* memorysize;
	int malloc_only; //do not write, just malloc
};

struct arguments read_args(int argc, char* argv[]){
	struct arguments ret;
	ret.memorysize=0;
	for(int i=1; i<argc; i++){
		if(!strcmp(argv[i],"--version") || !strcmp(argv[i],"-v")){
			printf("1.3.0\n");
			exit(0);
		} else if(!strcmp(argv[i],"--malloc") || !strcmp(argv[i],"-m")){
			ret.malloc_only=1;
		} else if(!strcmp(argv[i],"--help") || !strcmp(argv[i],"-h") || !strcmp(argv[i],"-?")){
			show_usage(argv[0]);
			exit(0);
		} else if(argv[i][0]=='-'){
			printf("unrecognised argument : %s\n",argv[i]);
		} else {
			ret.memorysize=argv[i];
		}
	}
	if(ret.memorysize==0){
		show_usage(argv[0]);
		exit(1);
	}
	return ret;
}

