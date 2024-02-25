
int private_cxpathjson_convert_index(int index, int size){
    if(index >=0){
        return index;
    }
    return (size +index);


}

bool private_cxpathjson_path_is_append(cJSON *current_path){
    bool is_append = false;
    if(cJSON_IsString(current_path)){
        is_append = strcmp(current_path->valuestring, CXPATHJSON_APPEND_KEY) == 0;
    }

}