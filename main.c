#include "src/one.c"

CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;
int  main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("a.json");


  //  xpath.set_str(t,"aaaaaaaaa","['a','c']");
    xpath.set_str(t,"aaaaaaaaa","['a','d']");

    if(xpath.errors.has_errors(t)){
        printf("%s",xpath.errors.get_error_message(t));
    }

    xpath.dump_to_file(t,"result.json",true);


    CxpathJson_free(t);
}