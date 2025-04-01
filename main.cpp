#include <iostream>

void NewMemory() {
    while(1) {
        int *a = new int(1);
    }
}

int main() {
    NewMemory();
    return 0;
}
