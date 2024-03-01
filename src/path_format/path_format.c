int private_cxpathjson_validate_path_all(cJSON *path){

    const int NOT_PATH = 1 ;
    const int NOT_ARRAY = 1;
    const int WRONG_TYPE = 1;
    if(!path){
        return NOT_PATH;
    }

    if(!cJSON_IsArray(path)){
        return NOT_ARRAY;
    }

    int path_size = cJSON_GetArraySize(path);
    for(int i = 0;i <path_size;i++){
        cJSON *current = cJSON_GetArrayItem(path,i);
        if(cJSON_IsString(current)){
            continue;
        }

        if(cJSON_IsNumber(current)){
            continue;
        }
        return  WRONG_TYPE;
    }
    return  CXPATHJSON_OK_CODE;



}

int private_cxpathjson_validate_path_read_only(cJSON *path){
    int first_test =  private_cxpathjson_validate_path_all(path);
    if(first_test){
        return first_test;
    }
    const int APPEND_NOT_VALID_IN_READ_ONY = 1;

    int path_size = cJSON_GetArraySize(path);
    for(int i = 0;i <path_size;i++){
        cJSON *current = cJSON_GetArrayItem(path,i);
        if(!cJSON_IsString(current)){
            continue;
        }
        if(strcmp(current->valuestring,CXPATHJSON_APPEND_KEY) ==0){
            return APPEND_NOT_VALID_IN_READ_ONY;
        }
    }
    return CXPATHJSON_OK_CODE;
}


void private_cxpathjson_replace_comas(char *result){
    long size = strlen(result);
    for(int i =1; i < size; i++){
        char current_char = result[i];
        char last_char = result[i-1];

        if(current_char == '\'' && last_char !='\\'){
            result[i] = '"';
        }
    }
}
