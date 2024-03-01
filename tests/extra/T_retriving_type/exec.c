
#include "../../../CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/str.json");


    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("%d",code);
        printf("%s",message);
        xpath.free(t);
        return 0;
    }
    printf("exist :%d\n" , xpath.types.exist(t,"['a','b']"));
    printf("type code:%d\n" , xpath.types.type(t,"['a','b']"));
    printf("type str:%s\n" , xpath.types.type_str(t,"['a','b']"));

    xpath.free(t);

}