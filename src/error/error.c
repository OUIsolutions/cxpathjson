
bool cjson_path_error(){
    return  (bool)private_cjson_path_error_code;
}
int cjson_path_get_error_code(){
    return private_cjson_path_error_code;
}
const char *cjson_path_get_error_message(){
    return private_cjson_path_error_message;
}