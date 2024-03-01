#ifndef CXPATHJSON_APPEND_KEY
#define CXPATHJSON_APPEND_KEY "$append"
#endif

int private_cxpathjson_validate_path_all(cJSON *path);

int private_cxpathjson_validate_path_read_only(cJSON *path);

void private_cxpathjson_replace_comas(char *result);