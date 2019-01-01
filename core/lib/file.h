#ifndef __adict_file
#define __adict_file

#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int max_size;

int exists(char *str){
	struct stat buffer;
	return (stat(str, &buffer) == 0);
}

int create(char *str){
	FILE* file_ptr;
	file_ptr = fopen(str, "w+");
	int n=0;
	if(file_ptr){
		fflush(file_ptr);
		fclose(file_ptr);
	}
	else{
		printf("Failed to create file %s.\n", str);
		n++;
	}
	return n;
}

int file_size(char *ch){
	FILE* fp;
	int size;
	fp = fopen(ch, "r");
	fseek(fp,0,SEEK_END);
	size = ftell(fp);
	fclose(fp);
	return size;
}

char* file_text(char* filename){
	FILE* fp;
	int size;
	char *arr;
	size = file_size(filename);
	fp = fopen(filename, "r");
	arr = (char*)malloc(sizeof(char)*size);
	fread(arr, 1, size, fp);
	fclose(fp);
	return arr;
}

long* file_values_long(char* filename){
	FILE* fp;
	int size;
	long *arr;
	
	size = file_size(filename);
	arr = (long*)malloc(sizeof(long)*size);
	
	fp = fopen(filename, "r");
	fread(arr, sizeof(long), size / sizeof(long), fp);
	fclose(fp);
	return arr;
}

int file_append_text(char *filename, char *word){
	FILE* fp;
	int ctr =0;
	fp = fopen(filename, "a");
	while(*(word+ctr)!=0){
		fputc(*(word+ctr++),fp);
	}
	fclose(fp);
	return 0;
}

int file_write_values_long(char* filename, long* values){
	FILE* fp;
	int size;
	
	size = file_size(filename);
	
	fp = fopen(filename, "w");
	fwrite(values, sizeof(long), size / sizeof(long), fp);
	fclose(fp);
	return 0;
}
#endif
