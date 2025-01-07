#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    char s[] = "[1,2,4,5,6]";
    
    char *ptr = strtok(s, "[,]");
    
    while (ptr != nullptr) {
        printf("%s\n", ptr);
        ptr = strtok(nullptr, "[,]");
    }
}