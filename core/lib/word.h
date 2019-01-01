#ifndef __adict_words
#define __adict_words
typedef struct{
	char *start,*last, *current;
} WordPointer;

WordPointer* create_wp(char *ch){
	WordPointer *wp;
	wp = (WordPointer*)malloc(sizeof(WordPointer));
	wp->start = ch;
	wp->last = ch;
	wp->current = ch;
	return wp;
}

int rewind_wp(WordPointer *wp){
	wp->last = wp->start;
	wp->current = wp->start;
	return 0;
}

char*clean(char* word){
	char* ch=word;
	while(*ch!='\0'){
		if(((*ch>=48) && (*ch<=57))|| 
		  ((*ch>=65) && (*ch<=90))|| 
		  ((*ch>=97) && (*ch<=122)));
		else *ch = '\0';
		ch++;
	}
	return word;
}

char *fetch_next(WordPointer *wp){
	char *word;
	int size;
	int flag = 1;
	int i=0;
	while(flag){
		if(*wp->current == 32|| *wp->current==0 ||*wp->current==10)
			flag = 0;
		wp->current++;
	}
	size = wp->current-wp->last;
	if(size > 0){
		word = (char*)malloc(sizeof(char)*size);
		flag= 1;
		while(flag){
			if(*wp->last == 32|| *wp->last==0 ||*wp->last==10 )
				flag = 0;
			*(word+i++)=*(wp->last++);
		}
		*(word+size-1) = '\0';
	}
	else return NULL;
	wp->last = wp->current;
	return clean(word);
}
#endif
