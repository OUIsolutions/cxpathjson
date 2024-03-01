
#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/completed.json");

    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("%d",code);
        printf("%s",message);
        xpath.free(t);
        return 0;
    }

    xpath.set_default_str(t, "Mateus","['name']");
    xpath.set_default_double(t,27,"['age']");
    xpath.set_default_bool(t,true,"['married']");

    char *result = xpath.dump_to_string(t, false);
    printf("%s",result);
    xpath.free(t);
    free(result);



}