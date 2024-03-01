
#include "../../../CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/array.json");
    CxpathJson *a = xpath.get_array(t, "['a']['b']");
    char  *a1 =xpath.get_str(a,"[0]");

    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("%d",code);
        printf("%s",message);
        xpath.free(t);
        return 0;
    }
    printf("%s\n",a1);
    xpath.free(t);

}