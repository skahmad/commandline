#include<util.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char* newString(char* str) {
	int length = strlen(str) + 1;
	char* tstr = (char*)malloc(sizeof(char)*length);
	strcpy(tstr,str);
	return tstr;
}
char *newEmptyString(int length) {
	char *t = (char*)malloc(sizeof(char)*(length+1));
	return t;
}
int   StringStartWith(char *str, char *word) {
	if(str == null || word == null)
		return false;

	int sl = strlen(str);
	int wl = strlen(word);
	int l = (sl>wl?wl:sl);
	int flag = true;

	int i;
	for(i=0; i<l; i++) {
		if(str[i] == word[i])
			continue;
		else {
			flag = false;
			break;
		}
	}
	return flag;
}
