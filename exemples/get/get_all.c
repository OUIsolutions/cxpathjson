
#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;

    CxpathJson *t = xpath.new_from_file("tests/target/all.json");
    char *name = xpath.get_str(t,"['name']");
    int age =xpath.get_int(t,"['age']");
    bool maried = xpath.get_bool(t,"['maried']");
    double height = xpath.get_double(t,"['height']");

    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("code: %d\n",code);
        printf("message: %s\n",message);
        xpath.free(t);
        return 0;
    }
    printf("name: %s\n",name);
    printf("age: %d\n",age);
    printf("height: %lf\n",height);
    printf("maried: %s\n", maried ? "true": "false");
    xpath.free(t);

}