#include "lecture9alogin.h"



bool operator==(Login const& a, Login const& b) {
    return a.username == b.username && a.password == b.password;
}