int private_cjson_path_validate_path(cJSON *path){

    if(!path){
        return 1;
    }

    if(!cJSON_IsArray(path)){
        return 1;
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
        return  1;
    }
    return  0;



}

void private_cjson_path_replace_comas( char *result){
    long size = strlen(result);
    for(int i =1; i < size; i++){
        char current_char = result[i];
        char last_char = result[i-1];

        if(current_char == '\'' && last_char !='\\'){
            result[i] = '"';
        }
    }
}
