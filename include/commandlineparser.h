#ifndef commandlineparser_h
#define commandlineparser_h
#include "commandlineoption.h"


typedef struct commandlineparser {
	char *values[128];
	int errorFlag;
	int totalOption;
	int totalValues;
	CommandLineOption *optionList[16];

}CommandLineParser;

#endif
