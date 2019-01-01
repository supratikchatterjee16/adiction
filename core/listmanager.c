#ifndef __adict_listmanager
#define __adict_listmanager

char* read_list(){
	if( !exists( (char*)"words/words.txt" ) )
		create( (char*)"words/words.txt" );
	return file_text( (char*)"words/words.txt" );;
}

int word_list_has(char* ch){
	WordPointer *wp;
	char *str;
	int n=0;
	wp = create_wp( read_list() );
	while((str = fetch_next(wp))){
		if(strcmp(str, (char*)"")==0) break;
		if(strcmp(str, ch)==0){return 1;}
	}
	return 0;
}

int word_list_size(char* ch){
	WordPointer *wp;
	char *str;
	int n=0;
	wp = create_wp( read_list() );
	while((str = fetch_next(wp))){
		if(strcmp(str, (char*)""))break;
		n++;
	}
	return n;
}

int word_list_add(char* word){
	file_append_text((char*)"words/words.txt", strcat(word,(char*)" "));
	return 0;
}

int index_of(char* word){
	int pos= 0;
	WordPointer *wp;
	char *str;
	wp = create_wp(read_list());
	while((str = fetch_next(wp))){
		if(strcmp(str, word)==0)break;
		if(strcmp(str, (char*)"")==0){
			pos = -1;
			break;
		}
		pos++;
	}
	return pos;
}

int create_word(char* word){
	char *filepath1, *filepath2;
	printf("Attempting create word %s\n",word);
	filepath1=strcat(strcat((char*)"./words/forward/", word),(char*)".dat");
	if(create(filepath1)){
		printf("Failed to create file %s.\n", filepath1);
		exit(0);
	}
	filepath2=strcat(strcat((char*)"./words/backward/", word),(char*)".dat");
	if(create(filepath2)){
		printf("Failed to create file %s.\n", filepath2);
		exit(0);
	}
	word_list_add(word);
	return 0;
}
#endif
