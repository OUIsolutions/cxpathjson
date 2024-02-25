#include "src/one.c"


int  main(){
    
    int error = 0;
    cJSON *t = cjson_path_load_from_file(&error,"teste.json");
    if(error){
        printf("%d",error);
        return 1;
    }

    const char *a = cjson_path_get_str(&error,t,"[\"a\"]");
    if(error){
        printf("%d",error);
        return 1;
    }

    printf("%s\n",a);

    cjson_path_free(t);


}