

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



CxpathJson * newCxpathJson_from_string( const char *data){
    CxpathJson  *self = private_newCxpathJson();
    self->element =  cJSON_Parse(data);
    if(!self->element){
        CxpathJson_raise_errror(
                self,
                CXPATHJSON_STRING_NOT_PARSABLE_CODE,
                NULL,
                PRIVATE_CXPATHJSON_STRING_NOT_PARSABLE_MESSAGE,
                data
                );
    }
    return  self;
}


CxpathJson * newCxpathJson__from_file( const char *path){

    char *content = private_cxpathjson_read_file(path);
    if(!content){
        CxpathJson  *self = private_newCxpathJson();
        CxpathJson_raise_errror(
                self,
                CXPATHJSON_FILE_NOT_FOUND_CODE,
                NULL,
                PRIVATE_CXPATHJSON_FILE_NOT_FOUND_MESSAGE,
                path
                );
        return self;
    }

    return newCxpathJson_from_string(content);
}

void CxpathJson_free(CxpathJson * self){
    CxpathJson_clear_errors(self);
    if(self->element){
        cJSON_Delete(self->element);
    }

    free(self);
}
