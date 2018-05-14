#ifndef commandlineoption_h
#define commandlineoption_h

// #include <stdio.h>
// #include <string.h>

typedef struct commandlineoption{
    char *shortOption;
    char *longOption;
    char *values[32];
    char *usage;
	int totalValue;
    int isMultival;
    int isSwitch;
    int isSeted;
}CommandLineOption;

void OptionInit(CommandLineOption *opt);
CommandLineOption* newOption(char *shopt, char *usage);
extern void OptionMultivalued(CommandLineOption *opt, int truefalse);
extern int  OptionIsMultivalued(CommandLineOption *opt);
extern void OptionSetSwitch(CommandLineOption *opt, int truefalse);
extern int  OptionIsSwitch(CommandLineOption *opt);
extern void OptionAddValue(CommandLineOption *opt, char *value);
extern void OptionSetUsage(CommandLineOption *opt, char *usage);
extern void OptionSetShortOption(CommandLineOption *opt, char *shopt);
extern void OptionSetLongOption(CommandLineOption *opt, char *longopt);
extern void OptionSeted(CommandLineOption *opt, int truefalse);
extern int OptionIsSeted(CommandLineOption *opt);
extern void OptionPrint(CommandLineOption *opt);

#endif
