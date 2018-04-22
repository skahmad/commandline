#ifndef commandlineoption_h
#define commandlineoption_h

// #include <stdio.h>
// #include <string.h>

typedef struct commandlineoption{
    char *shortOption;
    char *longOption;
    char *values[32];
    char *usage;
    int isMultival;
    int isSwitch;
}CommandLineOption;

void OptionInit(CommandLineOption *opt);
CommandLineOption* newOption(char *shopt, char *usage);
void OptionAddValue(CommandLineOption *opt, char *value);
void OptionSetUsage(CommandLineOption *opt, char *usage);
void OptionSetShortOption(CommandLineOption *opt, char *shopt);
void OptionSetLongOption(CommandLineOption *opt, char *longopt);


#endif
