#include "src/one.c"


int  main(){
    
    
    cjson_path * t = cjson_path_load_from_file("teste.json");
    cjson_path *r  = cjson_path_get_cJSON(t, "[%d][aaa]", 1);
    cjson_path_free(t);


}