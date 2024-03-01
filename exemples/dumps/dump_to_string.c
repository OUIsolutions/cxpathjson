#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    char *content = xpath.dump_to_string(t, false);
    printf("%s", content);
    xpath.free(t);
    free(content);
    

}