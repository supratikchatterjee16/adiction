int mem_init(){//This is a structure check and creation procedure. One run only.
	struct stat buffer;
	if(stat("./words", &buffer) == -1) 				mkdir("./words", 0700);
    if(stat("./words/forward",&buffer)==-1)   		mkdir("./words/forward", 0700);
    if(stat("./words/backward",&buffer)==-1)   	mkdir("./words/backward", 0700);
	if(stat("./words/meta.inf",&buffer)==-1)		create((char*)"./words/meta.inf");
	if(stat("./words/words.txt",&buffer)==-1)		create((char*)"./words/words.txt");
	return 0;
}

int update_values(char* filepath, char* word){
	long *values;
	int pos=0;
	values = file_values_long(filepath);
	pos = index_of(word);
	*(values + pos) = *(values + pos) + 1;
	printf("update_values success\n");
	return file_write_values_long(filepath, values);;
}

int update_forward(char* last, char* word){
	char *filepath;
	filepath = strcat((char*)"./words/forward/", last);
	if(!word_list_has(word)==0){
		printf("word list does not have word %s\n",word);
		create_word(word);
	}
	//printf("Word list check for word.\n");
	if(!word_list_has(last)){
		printf("word list does not have word %s\n",last);
		create_word(last);
	}
	//printf("Word list check for last word.\n");
	return update_values(filepath, word);
}
int update_backward(char* last, char* word){
	char filepath[100]="./words/backward/";
	if(!word_list_has(word)) 	create_word(word);
	if(!word_list_has(last)) 		create_word(last);
	
	return update_values(strcat(filepath, word), last);
}

int adict(char* text){
	WordPointer *wp;
	char *word, *last_word;
	int n=0;
	
	n += mem_init();
	wp = create_wp(text);
	last_word = (char*)malloc(1);
	*last_word='`';
	while((word=fetch_next(wp))){
		printf("word in core : %s\n",word);
		if(strcmp(word,(char*)"")==0) break;
		printf("Starting updates.\n");
		update_forward(last_word, word);
		printf("Forward .\n");
		update_backward(last_word, word);
		printf("Backward .\n");
		last_word = word;
	}
	printf(".\n");
	return n;
}
