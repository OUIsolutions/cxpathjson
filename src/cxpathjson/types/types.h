#define CXPATHJSON_NOT_FOUND (-1)

#define CXPATHJSON_NULL 1

#define CXPATHJSON_STRING 2
#define CXPATHJSON_BOOL 3
#define CXPATHJSON_NUMBER 4
#define CXPATHJSON_OBJECT 5
#define CXPATHJSON_ARRAY 6

#define CXPATHJSON_INVALID_TEXT "Invalid"
#define CXPATHJSON_NULL_TEXT "Null"

#define CXPATHJSON_STRING_TEXT  "String"
#define CXPATHJSON_BOOL_TEXT "Boolean"
#define CXPATHJSON_NUMBER_TEXT "Number"
#define CXPATHJSON_OBJECT_TEXT "Object"
#define CXPATHJSON_ARRAY_TEXT "Array"


int cxpathjson_type(CxpathJson * self, const char *format, ...);

const char * CxpathJson_type_str(CxpathJson * self, const char *format, ...);
