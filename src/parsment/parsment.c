
cJSON * cxpathjson_load_from_string(int *error_code, const char *data){
    cJSON  *result = cJSON_Parse(data);
    if(!result){
        *error_code = CJSON_PATH_DOCUMENT_NOT_PARSABLE_CODE;
    }
    return  result;
}

cJSON * cxpathjson_load_from_file(int *error_code, const char *path){
    char *content = private_cxpathjson_read_file(path);
    if(!content){
        *error_code  = CJSON_PATH_DOCUMENT_NOT_EXIST_CODE;
        return NULL;
    }

    cJSON *result = cxpathjson_load_from_string(error_code, content);
    free(content);
    return result;
}
char *cxpathjson_dump_to_string(cJSON *element, bool ident){
    if(ident){
        return cJSON_Print(element);
    }
    return cJSON_PrintUnformatted(element);
}

int cxpathjson_dump_to_file(const char *filename, cJSON *element, bool ident){
    char *result = cxpathjson_dump_to_string(element, ident);
    if(!result){
        return  CJSON_PATH_PRINT_PROBLEM;
    }

    return private_cxpathjson_write_file(filename, result);

}



void cxpathjson_free(cJSON *data){
    cJSON_Delete(data);
}