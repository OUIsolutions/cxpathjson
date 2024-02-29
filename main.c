#include "src/one.c"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("a.json");

    xpath.set_str(t,"teste","['a','b']");

    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("%d",code);
        printf("%s",message);
        xpath.free(t);
        return 0;
    }

    xpath.dump_to_file(t,"c.json", true);
    xpath.free(t);

}