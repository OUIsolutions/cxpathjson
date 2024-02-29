#include "src/one.c"

CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;
int  main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("a.json");

    int b = xpath.get_int(t,"['a','b']");
    if(errors.has_errors(t)){
        char *message = errors.get_error_message(t);
        printf("error:%s\n",message);
        char *path = errors.get_error_path(t);
        if(path){
            printf("path:%s\n",path);
        }
    }
    if(errors.is_ok(t)){
        printf("%d\n",b);
    }


    CxpathJson_free(t);
}