#ifndef commandlineparser_h
#define commandlineparser_h
#include "commandlineoption.h"


typedef struct commandlineparser {
	char *values[128];
	int  totalValues;
	char *errors[128];
	int  totalErrors;
	char *wornings[128];
	int totalWornings;
	int  errorFlag;
	int worningFlag;
	char *args[128];
	int  argc;
	CommandLineOption *options[128];
	int totalOptions;

}CommandLineParser;

void ParserInit(CommandLineParser* par);
CommandLineParser* newParser(int argc, char *argv[]);
CommandLineOption *ParserGetOption(CommandLineParser *par, int index);

void ParserAddValue(CommandLineParser* par, char *value);
void ParserAddOption(CommandLineParser* par, CommandLineOption *opt);
int  ParserHasError(CommandLineParser* par);
void ParserAddError(CommandLineParser *par, char *opt, char *message);
void ParserAddWorning(CommandLineParser *par, char *opt, char *message);
void ParserPrintError(CommandLineParser *par);
int  ParserContainOption(CommandLineParser *par, char *opt);
int  ParserParse(CommandLineParser* par);
void ParserPrint(CommandLineParser *par);

#endif
