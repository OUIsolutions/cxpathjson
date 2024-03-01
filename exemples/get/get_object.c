
#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    CxpathJson *a = xpath.get_object(t, "['m']");
    char *a1 = xpath.get_str(a,"['n']");
    if(!errors.has_errors(t)){
        printf("%s\n",a1);
    }
    xpath.free(t);

}