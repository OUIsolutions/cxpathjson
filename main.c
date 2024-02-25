#include "src/one.c"


int  main(){
    
    int error = 0;
    cJSON *t = cjson_path_load_from_file(&error,"teste.json");
    if(error){
        printf("error code:%d",error);
        return 1;
    }

    const char *a = cjson_path_get_str(&error,t,R"(["a","b"])");
    if(error){
        printf("error code:%d",error);
        return 1;
    }

    printf("%s\n",a);

    cjson_path_free(t);


}