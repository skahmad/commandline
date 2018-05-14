#include<stdio.h>
#include<commandlineparser.h>
#include<commandlineoption.h>

int main(int argc, char *argv[]) {
	// printf("Hello Worl.");
	CommandLineOption *fileopt = newOption("-f","-fFileName1 FileName2 or -f FilName1 ...");
	CommandLineOption *diropt = newOption("-d","-dDirectoryName or -d DirectoryName");
	CommandLineOption *usropt = newOption("-u","-uUserName or -u UserName");
	OptionMultivalued(fileopt, 1);
	OptionMultivalued(diropt, 1);
	OptionSetSwitch(usropt, 1);
	CommandLineParser *parser = newParser(argc, argv);
	ParserAddOption(parser, fileopt);
	ParserAddOption(parser, diropt);
	ParserAddOption(parser, usropt);

	ParserParse(parser);

	if(ParserHasError(parser))
		ParserPrintError(parser);
	else {
		if(OptionIsSeted(fileopt))
			OptionPrint(fileopt);

		if(OptionIsSeted(diropt))
			OptionPrint(diropt);

		if(OptionIsSeted(usropt))
			OptionPrint(usropt);
	}
	ParserPrint(parser);
	return 1;
}
