#include "src/one.c"


int  main(){
    
    int error = 0;
    cJSON *t = cjson_path_load_from_file(&error,"teste.json");

    if(error){
        printf("error code %d\n",error);
    }

    const char *value = cjson_path_get_str(&error,t,"['a','b',-2]");

    cjson_path_free(t);


}