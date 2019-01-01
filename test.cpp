//This will not in any circumstances be made to understand encoded language unless it doesn't get to a point
//Where it gets to the point where it understands most of the things in normal speech.
//English has been chosen initially, to make sure that nothing causes a problem in between.
//Let us take an example to remember what we need to do
//read a book
//please read a book
//so an entry, read, we have a lexicographically arranged structure after it that has all the words that 
//show the structure of a table
//This table will be then made use of to find everything that is there to be found, and written to.
//Aim is to maintain a tally for all words used.
//The database of words shall grow by a lot
//A new word entered makes a new column
//Hence a new row, and column need to be allocated to it.


//Note : test the entirety of the code till a simple adict(string) call automates the entirety of the program.
#include"core/core.h"

int main(int argc, char* argv[]){
	printf("START\n");
	printf("%d\n",adict((char*)"Where there is a will there is a way."));//This line must work.
//	mem_init();
//	word_list_add((char*)"hello");
//	word_list_add((char*)"world");
//	if(word_list_has((char*)"hello"))printf("test 1\n");
//	else printf("failed 1\n");
//	if(word_list_has((char*)"crapper"))printf("failed 2\n");
//	else printf("test 2\n");
//	printf("%d\n", findIndexOf((char*)"holly", (char*)"then there were none"));
	printf("END\n");
	return 0;
}
