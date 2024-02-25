#include "src/one.c"


int  main(){
    
    
    cJSON *t = cjson_path_load_from_file("teste.json");
    if(cjson_path_error()){
        printf("%s",cjson_path_get_error_message());
        return 1;
    }

    const char *a = cjson_path_get_str(t,"[\"a\"]");
    if(cjson_path_error()){
        printf("%s",cjson_path_get_error_message());
        return 1;
    }

    printf("%s\n",a);

    cjson_path_free(t);


}