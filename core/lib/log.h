#ifndef __adict_log
#define __adict_log
#include<ctime>
#include<stdio.h>
int log(char *str){
	time_t     now = time(0);
    struct tm  tstruct;
    char       buffer[80];
    char* text;
    int size = 0;
    
    tstruct = *localtime(&now);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %X >", &tstruct);
    
    size += strlen(buffer)+strlen(str)+5;
    text = strcat(buffer, str);
    file_append_text((char*)"logfile.txt", text);
    return 0;
}
#endif
