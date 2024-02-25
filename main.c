#include "src/one.c"


int  main(){
    
    int error = 0;
    cJSON *t = cjson_path_load_from_file(&error,"teste.json");
    const char *r = cjson_path_get_str(&error,t,"['a','b']");
    printf("error %d\n",error);
    if(!error){
        printf("%s\n",r);

    }
    cjson_path_free(t);


}