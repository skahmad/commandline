#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<commandlineparser.h>
#include<util.h>

void ParserInit(CommandLineParser* par) {
	if(par == NULL) {
		printf("(null) in ParserInit\n");
		return ;
	}
	par->errorFlag = false;
	par->worningFlag = false;
	par->totalWornings = 0;
	par->totalOptions = 0;
	par->totalValues = 0;
	par->argc = 0;
	par->totalErrors = 0;
}
CommandLineParser* newParser(int argc, char *argv[]) {
	CommandLineParser* parser = (CommandLineParser*)malloc(sizeof(CommandLineParser));
	ParserInit(parser);
	parser->argc = argc;

	int l;
	for(l=0; l<argc; l++) {
		parser->args[l] = newString(argv[l]);
	}

	return parser;
}
void ParserAddValue(CommandLineParser* par, char *value) {
	if(par == NULL) {
		printf("(null) in ParserAddValue\n");
		return ;
	}
	if(strlen(value)>0)
		par->values[par->totalValues++] = newString(value);
}
void ParserAddOption(CommandLineParser* par, CommandLineOption *opt) {
	if(par == NULL) {
		printf("(null) in ParserAddOption\n");
		return;
	}
	par->options[par->totalOptions] = opt;
	par->totalOptions++;
}
int  ParserHasError(CommandLineParser* par) {
	return par->errorFlag;
}
void ParserAddError(CommandLineParser *par, char *opt, char *message) {
	if(par == null) {
		printf("(null) in ParserAddError\n");
		return ;
	}
	int l = strlen(opt) + strlen(message) + 2;
	par->errors[par->totalErrors] = newEmptyString(l);
	strcpy(par->errors[par->totalErrors],"Option '");
	strcat(par->errors[par->totalErrors],opt);
	strcat(par->errors[par->totalErrors],"' ");
	strcat(par->errors[par->totalErrors],message);
	par->totalErrors++;
	par->errorFlag = true;
}
void ParserAddWorning(CommandLineParser *par, char *opt, char *message) {
	if(par == null) {
		return;
	}
	int length = strlen(opt) + strlen(message) + 2;
	par->wornings[par->totalWornings] = newEmptyString(length);
	strcpy(par->wornings[par->totalWornings],"Option '");
	strcat(par->wornings[par->totalWornings],opt);
	strcat(par->wornings[par->totalWornings],"' ");
	strcat(par->wornings[par->totalWornings],message);
	par->totalWornings++;
	par->worningFlag = true;
}
void ParserPrintError(CommandLineParser *par) {
	if(par == null) {
		printf("(null) in ParserPrintError\n");
		return;
	}
	int l =0;
	for(l =0; l<par->totalErrors; l++) {
		printf("*** %s\n",par->errors[l]);
	}
}
int ParserContainOption(CommandLineParser *par, char *opt) {
	int index = -1;
	if(par == null) {
		printf("(null) in ParserContainOption\n");
	}
	if(opt == null)
		return index;

	int l;
	for(l=0; l<par->totalOptions; l++) {
		if(strcmp(par->options[l]->shortOption,opt) == 0) {
			index = l;
			break;
		}
	}
	return index;
}
CommandLineOption *ParserGetOption(CommandLineParser *par, int index) {
	if(par == null)
		return null;
	if(index>=par->totalOptions || index<0)
		return null;
	return par->options[index];
}

int ParserParse(CommandLineParser* par) {
	if(par == null)
		return false;

	int start = 0;
	int end = par->argc;

	char carg[128];
	char cval[128];
	char copt[16];
	memset(carg,'\0',128);
	memset(cval,'\0',1);
	memset(copt,'\0',16);
	CommandLineOption *coption = null;

	for(start =0; start<end; start++) {
		memset(carg,'\0',1);
		memset(cval,'\0',1);
		strcpy(carg,par->args[start]);
		if(StringStartWith(carg,"-")) {
			strncpy(copt,carg,2);
			coption = ParserGetOption(par, ParserContainOption(par, copt));
			if(coption == null)
				ParserAddError(par, copt, "Not found!");
			else
				OptionSeted(coption, true);
		}else {
			strcpy(cval,carg);
		}
		if(coption != null) {
			if((coption->totalValue ==0 && !OptionIsSwitch(coption)) || OptionIsMultivalued(coption))
				OptionAddValue(coption, cval);
			else
				ParserAddValue(par, cval);
		}
	}
	// ParserPrint(par);
	return true;
}

void ParserPrint(CommandLineParser *par) {
	if(par == NULL) {
		printf("(null) in ParserPrint\n");
		return;
	}
	int l;
	if(par->totalValues>0)
		printf("Total Values : %d\n",par->totalValues);
	for(l=0; l<par->totalValues; l++)
		printf("\t%s\n",par->values[l]);

	printf("Total Option : %d\n",par->totalOptions);
	if(par->totalOptions) {
		for(l=0; l<par->totalOptions; l++)
			printf("\t%d. %s : %s\n",l+1,par->options[l]->shortOption,par->options[l]->usage);
	}
	printf("Errors : ");
	if(par->errorFlag)
		printf("Found\n");
	else
		printf("Not Found\n");
	if(par->argc>0) {
		printf("Total Agrs : %d\n",par->argc);
		printf("Args : ");
	}
	for(l =0; l<par->argc; l++)
		printf("%s ",par->args[l]);
	printf("\n");
}
