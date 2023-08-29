#include <iostream>
#include <string>

//substitute string part before with part after
void substitute_str(std::string& iostring, const std::string& before, const std::string& after){
    size_t pos = 0;  //Starting position to search for before

    //calls searches for substring before in iostring
    //the position where before is in iostring is set to pos
    //std::npos is non-position, gets returned when find() doesn't find a match.
    while((pos = iostring.find(before, pos)) != std::string::npos){
        iostring.replace(pos, before.length(), after); //replaces before with after
        pos += after.length(); //updates position, ensures that the loop doesn't replace the newly inserted value
    }
}


int main(){

    std::string str = "Hej på dej";
    substitute_str(str, "ej", "ig");
    std::cout << str << std::endl;


    str = "hejjj";
    substitute_str(str, "ej", "eje");
    std::cout << str << std::endl;

    return 0;

}