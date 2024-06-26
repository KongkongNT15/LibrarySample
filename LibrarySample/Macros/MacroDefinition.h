#define TAG_MACRO "?macro"
#define CALL_BY_ANSI_OR_UNICODE "ANSIとUNICODEの呼び分け"

#define MacroHelper(x) #x
#define Macro(x) MacroHelper(x)

#define PutMacro(x, message) puts(#x); puts(MacroHelper(x)); puts(message)
