

char *cxpathjson_dump_to_string(cJSON *element, bool ident){
    if(ident){
        return cJSON_Print(element);
    }
    return cJSON_PrintUnformatted(element);
}

int cxpathjson_dump_to_file(const char *filename, cJSON *element, bool ident){
    char *result = cxpathjson_dump_to_string(element, ident);
    if(!result){
        return  CXPATHJSON_PRINT_PROBLEM;
    }

    return private_cxpathjson_write_file(filename, result);

}


