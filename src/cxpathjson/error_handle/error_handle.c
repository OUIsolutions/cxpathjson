
void CxpathJson_raise_errror(CxpathJson * self, int error_code, cJSON *path, const char *format, ...){
    if(self->error_code){
        return;
    }
    self->error_code = error_code;
    if(path){
        self->error_path_str = cJSON_PrintUnformatted(path);
        self->path_list = cJSON_Duplicate(path, true);
    }

    va_list args;
    va_start(args, format);
    self->error_message = (char*)malloc(2000 * sizeof (char));
    vsnprintf(self->error_message, 2000 * sizeof (char), format, args);
    va_end(args);

}

bool CxpathJson_get_error_code(CxpathJson * self){
    if(!self){
        return CXPATHJSON_NOT_FOUND;
    }
    return self->error_code;
}

char *  CxpathJson_get_error_message(CxpathJson * self){
    if(!self->error_code){
        return NULL;
    }

    if(self->full_error_message){
        return self->full_error_message;
    }

    if(!self->error_path_str){
        return self->error_message;
    }

    if(!self->error_message){
        return NULL;
    }


    self->full_error_message = (char *) malloc(

            strlen(self->error_path_str) +
            strlen(self->error_message) +
            strlen(PRIVATE_CPATHJSON_ON_PATH_FORMAT) + 2
    );
    sprintf(self->full_error_message,
            PRIVATE_CPATHJSON_ON_PATH_FORMAT,
            self->error_message,
            self->error_path_str
    );

    return self->full_error_message;

}


void CxpathJson_clear_errors(CxpathJson * self){

    if(self->error_message){
        free(self->error_message);
    }

    if(self->path_list){
        cJSON_Delete(self->path_list);
    }

    if(self->error_path_str){
        free(self->error_path_str);
    }

    if(self->full_error_message){
        free(self->full_error_message);
    }

    self->error_code = CXPATHJSON_OK_CODE;
}
