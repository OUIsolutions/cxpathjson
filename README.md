# CXPathJson
CXPathJson is a library to set and get values from a json string using a path string.

# Installation 

## Single File
CXpathJson is made to be as dumb as possible and adopt the idea of single file library.
For installation, simply copy the **CXpathJson.h** into your project and compile with gcc/g++ or clang. 

[Download Link]()

# Usage
In all examples, we will use the json files in the `tests/target` directory.

## example
<!-- tests/get/get_int.c -->

The code above is a simple example of how to get an integer from a json string using a path string. The path string is a string that represents the path to the value in the json string. The path string is a list of keys separated by a comma. For example, the path string `"['a', 'b', 'c']"` will get the value of the key `c` in the json string `{"a": {"b": {"c": 1}}}`.


### Constructing a path
The first step is to construct a path. You can do it by calling the `newCxpathJsonNamespace` as shown below.

<!-- tests/constructors/construct_xpath.c -->

Your next step is to create an error object and a json object. The error object will be used to store the error messages if the json string is invalid. The json object will be used to store the json string. You can read the json string from a file or from a string. In the example below, we read the json string from a file.
You have 4 options to create a json object:
- `new_from_file` to read the json string from a file.
Example:
<!-- tests/constructors/construct_json_object_from_file.c -->

- `new_from_string` to read the json string from a string.
Example:
<!-- tests/constructors/construct_json_object_from_string.c -->

- `newJsonArray` to create an empty json array.
Example:
<!-- tests/constructors/construct_json_object_array.c -->

- `newJsonObject` to create an empty json object.
Example:
<!-- tests/constructors/construct_json_object_object.c -->




