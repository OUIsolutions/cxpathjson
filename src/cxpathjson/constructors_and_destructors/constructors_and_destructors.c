

CxpathJson * private_newCxpathJson(){
    CxpathJson  *self = (CxpathJson*) malloc(sizeof (CxpathJson));
    *self = (CxpathJson){0};
    return self;
}


CxpathJson * newCxpathJson_from_cJSON(cJSON *element){
    CxpathJson  *self = private_newCxpathJson();
    self->element = element;
    return  self;
}



CxpathJson * newCxpathJson_from_string(int *error_code, const char *data){

    cJSON  *result = cJSON_Parse(data);
    if(!result){
        *error_code = CXPATHJSON_DOCUMENT_NOT_PARSABLE_CODE;
    }
    return  result;
}


CxpathJson * newCxpathJson__from_file(int *error_code, const char *path){
    char *content = private_cxpathjson_read_file(path);
    if(!content){
        *error_code  = CXPATHJSON_DOCUMENT_NOT_EXIST_CODE;
        return NULL;
    }

    cJSON *result = cxpathjson_load_from_string(error_code, content);
    free(content);
    return result;
}
void CxpathJson_free(CxpathJson * self){
    if(self->error_message){
        free(self->error_message);
    }

    if(self->error_path){
        free(self->error_path);
    }

    if(self->element){
        cJSON_Delete(self->element);
    }

    free(self);
}
