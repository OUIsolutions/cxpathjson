
#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    bool content = xpath.get_bool(t,"['f', 'g']");
    
    xpath.set_bool(t,true ,"['f', 'g']");

    xpath.dump_to_file(t,"tests/target/b.json", true);

    CxpathJson *t2 = xpath.new_from_file("tests/target/b.json");
    bool content2 = xpath.get_bool(t2,"['f', 'g']");

    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("%d",code);
        printf("%s",message);
        xpath.free(t);
        return 0;
    }

    if (content2 != content)
    {
        printf("diff");
    }else {
        printf("identical");
    }
    xpath.free(t);
    xpath.free(t2);

}