#include <iostream>
#include <string>

#include "lecture9alogin.h"
#include "secret.h"

int main() {
    Login me{"Twilight", "everypony"};
    Secret message{"Fluttershy is after Pinkie", me};
    std::cout << message.GetText("everypony") << std::endl;
    std::cout << message.GetText("everybody") << std::endl;
}