#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <util.h>
#include<commandlineoption.h>


void OptionInit(CommandLineOption *opt) {
	if(opt != NULL) {
		opt->shortOption = NULL;
		opt->longOption =  NULL;
		opt->usage = NULL;
		opt->isMultival = false;
		opt->isSwitch = false;
		opt->totalValue = 0;
		opt->isSeted = false;
	}
}
CommandLineOption* newOption(char *shopt, char *usage) {
	CommandLineOption *opt;
	opt = (CommandLineOption*)malloc(sizeof(CommandLineOption));
	OptionInit(opt);
	opt->shortOption = newString(shopt);
	opt->usage = newString(usage);
	return opt;
}
void OptionMultivalued(CommandLineOption *opt, int truefalse) {
	if(opt == null) {
		printf("(null) in OptionMultivalued\n");
		return;
	}
	if(truefalse)
		opt->isMultival = true;
	else
		opt->isMultival = false;
}
int OptionIsMultivalued(CommandLineOption *opt) {
	if(opt == null) {
		printf("(null) in OptionIsMultivalued\n");
		return false;
	}
	return opt->isMultival;
}
void OptionSetSwitch(CommandLineOption *opt, int truefalse) {
	if(opt == null) {
		printf("(null) in OptionSwitch\n");
		return;
	}
	if(truefalse)
		opt->isSwitch = true;
	else
		opt->isSwitch = false;
}
int  OptionIsSwitch(CommandLineOption *opt) {
	if(opt == null) {
		printf("(null) in OptionIsSwitch\n");
		return false;
	}
	return opt->isSwitch;
}

void OptionAddValue(CommandLineOption *opt, char *value){
	if(opt == NULL) {
		printf("(null) in OptionAddValue\n");
		return ;
	}
	if(strlen(value)>0)
		opt->values[opt->totalValue++] = newString(value);
}
void OptionSetUsage(CommandLineOption *opt, char *usage) {
	if(opt == NULL) {
		printf("(null) in OptionSetUsage\n");
		return ;
	}
	if(opt->usage != NULL)
		free(opt->usage);
	opt->usage = newString(usage);
}
void OptionSetShortOption(CommandLineOption *opt, char *shopt) {
	if(opt == NULL) {
		printf("(null) in OptionSetShortOption\n");
		return ;
	}
	if(opt->shortOption != NULL)
		free(opt->shortOption);
	opt->shortOption = newString(shopt);
}
void OptionSetLongOption(CommandLineOption *opt, char *longopt) {
	if(opt == NULL) {
		printf("(null) in OptionSetLongOption\n");
		return ;
	}
	if(opt->longOption != NULL)
		free(opt->longOption);
	opt->longOption = newString(longopt);
}
void OptionSeted(CommandLineOption *opt, int truefalse) {
	if(opt == null) {
		printf("(null) in OptionSeted\n");
		return;
	}
	opt->isSeted =(truefalse>0?true:false);
}
int OptionIsSeted(CommandLineOption *opt) {
	if(opt != null)
		return opt->isSeted;
	return false;
}
void OptionPrint(CommandLineOption *opt) {
	if(opt == NULL) {
		printf("(null) in OptionPrint\n");
		return;
	}
	printf("Short Name : %s\n",opt->shortOption);
	// printf("Long Option : %s\n",opt->longOption);
	printf("Usage : %s\n",opt->usage);
	if(opt->totalValue>0) {
		printf("Total Values : %d\n",opt->totalValue);
		int i=0;
		for(i = 0; i<opt->totalValue; i++ ) {
			printf("\t%s\n",opt->values[i]);
		}

	}
}
