#include "src/one.c"


int  main(){
    
    int error = 0;
    cJSON *t = cjson_path_load_from_file(&error,"teste.json");
    int size = cjson_path_size(&error,t, "['a','b']");
    if(error){
        printf("error code %d\n",error);
    }
    printf("%d",size);

    cjson_path_free(t);


}