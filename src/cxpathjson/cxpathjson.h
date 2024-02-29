

typedef struct {

    cJSON * element;
    bool raise_runtime_errors;
    char *error_message;
    cJSON *path_list;
     char *error_path_str;
    int error_code;

}CxpathJson;

