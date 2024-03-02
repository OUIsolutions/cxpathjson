# CXPathJson
CXPathJson is a library to set and get values from a json string using a path string.

# Installation 

## Single File
CXpathJson is made to be as dumb as possible and adopt the idea of single file library.
For installation, simply copy the **CXpathJson.h** into your project and compile with gcc/g++ or clang. 

[Download Link](https://github.com/OUIsolutions/cxpathjson/releases/download/v0.1/CxpathJson.h)

## full Folder 
you also can download the entire **src** project and include with **src/one.c** 

```c

#include "src/one.c"

CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonObject();
    xpath.set_str(t,"hello world","['a']");
    char *content = xpath.dump_to_string(t,true);
    printf("%s",content);
    free(content);
    xpath.free(t);


}
```

# Usage
In all examples, we will use the json files in the `tests/target` directory.

##  Basic hello world
<!--codeof:exemples/extra/hello_world.c -->


## Constructing a path
For loading a function from a json file  you just need to call the function
**xpath.new_from_file**  passing the json path
Example:
<!--codeof:exemples/constructors/construct_json_object_from_file.c -->


- `new_from_string` to read the json string from a string. This function receives 1 parameter: the json string.
Example:
<!--codeof:exemples/constructors/construct_json_object_from_string.c -->

- `newJsonArray` to create an empty json array.
Example:
<!--codeof:exemples/constructors/construct_json_object_array.c -->

- `newJsonObject` to create an empty json object.
Example:
<!--codeof:exemples/constructors/construct_json_object_object.c -->

**Important**: Note that every example already create the errors object. Every example also has a `free` function to free the memory allocated by the json object.

### Get
Every `get` function gets 2 parameters: the json object and the path string. The first
parameter is the json object and the second parameter is the path string. The path string is a list of keys separated by a comma. For example, the path string `"['a', 0, 'b']"` will get the value of the key `b` in the json string `{"a": [ {"b": 1} ]}`.

<!--codeof:exemples/get/get_all.c -->

#### Getting a sub object
<!--codeof:exemples/get/get_object.c -->

#### Getting a sub array
<!--codeof:exemples/get/get_array.c -->

#### Getting size 
- `size` to get the size of an array.
<!--codeof:exemples/get/get_size.c -->

### Iterating over arrays 
You can easly iterate over array by using **get_size** function

<!--codeof:exemples/get/array_iteration.c -->

### getting element array in reverse order
if you pass a negative number (-1) for example, you can get the last element of an array 

<!--codeof:exemples/get/last_one.c -->


### Types 
you also can get type information about the current element 
<!--codeof:exemples/extra/retriving_type.c -->




### Set
Every `set` function gets 3 parameters: the json object, the value to set and the path string.
To set a value in the json object, you can use a range of functions. The functions are:

<!--codeof:exemples/set/set_all.c -->


## Dumps
You can dump the json object to a file using `dump_to_file` or to a string using `dump_to_string`.

- `dump_to_file` to dump the json object to a file. The code below will dump the json object to create a file called `b.json`. This function receives 3 parameters: the json object, the file path and and boolean to indicate if the file should be idented.
<!--codeof:exemples/dumps/dump_to_file.c -->

- `dump_to_string` to dump the json object to a string. This function receives 2 parameters: the json object and a boolean to indicate if the string should be idented.
<!--codeof:exemples/dumps/dump_to_string.c -->


## Error Handling
The library has a built-in error handling system. You can use the `error` object to get the error message if the json string is invalid. The error message will be stored in the `error` object. You can use the `error` object to get the error message as shown below.
<!--codeof:exemples/errors/raise_element_not_exists.c -->

The code above will print the following error message:
```
5-Element not exist
```
where `5` is the code of the error and `Element not exist` is the message of the error.





