#ifndef __adict_string
#define __adict_string
#include<stdio.h>
#include<stdlib.h>

int strlen(char *str){
	int j=0;
	while(*(str+j++)!='\0');
	return j-1;
}

int strcmp(char *str1, char *str2){
	int flag = 0, ctr =0;
	while(flag==0){
		if(*(str1+ctr)==0){
			if(*(str2+ctr)==0)return 0;
			else return *(str2+ctr);
		}
		if(*(str2+ctr)==0){
			if(*(str1+ctr)==0)return 0;
			else return *(str1+ctr);
		}
		flag = *(str1+ctr) - *(str2+ctr);
		ctr++;
	}
	return flag;
}


int printstr(char *ch){
	while(*ch++!='\0')printf("%d ",*ch);
	printf("\n");
	return 0;
}

char* strcat(char *str1, char* str2){
	int size=0,i=0,j=0;
	char *str;
	size+=strlen(str1)+strlen(str2);
	str = (char*)malloc(sizeof(char)*size);
	while(*(str1+i)!='\0'){
		*(str+i) = *(str1+i);
		i+=1;
	}
	while(*(str2+j)!='\0'){
		*(str+i+j)= *(str2+j);
		j+=1;
	}
	printf("strcat : %s\n",str);
	return str;
}

char* strrev(char *str){
	int i, length = strlen(str);
	char *arr;
	arr = (char*)malloc(length*sizeof(char));
	i = 0;
	while(--length>-1)*(arr+i++) = *(str+length);
	*(arr+i)='\0';
	return arr;
}

int findIndexOf(char* word, char* text){
	int index, size, i;
	size = strlen(word);
	index = 0;
	while(*(text+index)!=0){
		for(i = 0; i<size&&*(text+index+i)!=0;i++){
			printf("%c %d %c %d\n",*(text+index+i),*(text+index+i),*(word+i),*(word+i));
			if(*(text+index+i)!=*(word+i))break;
		}
		if(i==size)return index;
		index++;
	}
	return -1;
}
#endif
