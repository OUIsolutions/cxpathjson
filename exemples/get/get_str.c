
#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    char  *content = xpath.get_str(t,"['c', 1, 'e']");
    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("%d",code);
        printf("%s",message);
        xpath.free(t);
        return 0;
    }

    printf("%s",content);
    xpath.free(t);

}