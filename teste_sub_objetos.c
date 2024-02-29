#include "src/one.c"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;



int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *rooot = xpath.new_from_file("a.json");
    CxpathJson *a = xpath.get_object(rooot, "['a']");
    char *a1 = xpath.get_str(a,"['a1']");
    if(!errors.has_errors(rooot)){
        printf("a1:%s\n",a1);
    }


    CxpathJson *b = xpath.get_array(rooot, "['b']");
    char  *b0 =xpath.get_str(b,"[0]");
    if(!errors.has_errors(rooot)){
        printf("b0: %s\n",b0);
    }

    if(errors.has_errors(rooot)){
        char *message =errors.get_error_message(rooot);
        int code = errors.get_error_code(rooot);
        printf("%d",code);
        printf("%s",message);
        xpath.free(rooot);
        return 0;
    }

    xpath.free(rooot);

}