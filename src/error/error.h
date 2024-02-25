
#define  CJSON_PATH_DOCUMENT_NOT_EXIST_CODE 1
#define  CJSON_PATH_DOCUMENT_NOT_EXIST_MESSAGE "Document not exist"

#define  CJSON_PATH_DOCUMENT_NOT_PARSABLE_CODE 2
#define  CJSON_PATH_DOCUMENT_NOT_PARSABLE_MESSAGE "Document not a valida json"

bool cjson_path_error();
int cjson_path_get_error_code();
const char *cjson_path_get_error_message();