#include "src/one.c"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;



int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("a.json");
    CxpathJson *a = xpath.get_object(t,"['a']");
    char *a1 = xpath.get_str(a,"['a1']");
    if(!errors.has_errors(t)){
        printf("a1:%s\n",a1);
    }


    CxpathJson *b = xpath.get_array(t,"['b']");
    char  *b0 =xpath.get_str(b,"[0]");
    if(!errors.has_errors(t)){
        printf("b0: %s\n",b0);
    }

    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("%d",code);
        printf("%s",message);
        xpath.free(t);
        return 0;
    }

    xpath.free(t);

}