#include "src/one.c"


int  main(){
    
    int error = 0;
    cJSON *t = cjson_path_load_from_file(&error,"teste.json");
    error  = cjson_path_set_str(t,"aaaaaaa","['a','b','c']");
    
        
    printf("result: %d\n",error);

    cjson_path_dump_to_file("a.json",t,true);

    cjson_path_free(t);


}