

CxpathJson * private_newCxpathJson(){
    CxpathJson  *self = (CxpathJson*) malloc(sizeof (CxpathJson));
    *self = (CxpathJson){0};
    return self;
}


void CxpathJson_free(CxpathJson * self){
    if(self->error_message){
        free(self->error_message);
    }
    if(self->error_path){
        free(self->error_path);
    }
    cJSON_Delete(self->element);
    free(self);
}
