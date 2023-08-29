#include <iostream>
#include <cstring>

char* substitute_cstr(const char* input, const char before, const char* after){
    //count number of before in input
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] == before) {
            count++;
        }
    }

    //calculate length of new string
    int new_length = strlen(input) + count * (strlen(after) - 1) + 1;

    //allocate memory for the new string
    char* result = new char[new_length];
    int j = 0;

    //construct the new string
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] == before){
            strcpy(result + j, after);
            j += strlen(after);
        } else {
            result[j] = input[i];
            j++;
        }
    }

    result[j] = '\0';
    return result;
}

int main () {
    char* result = substitute_cstr("Hej på dej", 'e', "ig");
    std::cout << result << std::endl;
    delete[] result;
    return 0;
}