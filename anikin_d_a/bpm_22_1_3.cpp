#include <iostream>
#include <string>


int is_glas(char letter) {
    std::string glas = "aouie";
    int k = 0;

    for (int i = 0; i < glas.size(); i += 1) {
        if (letter == glas[i]){
            k += 1;
        }
    }
    if (k != 0){
        return 1;
    }
    return 0;
}

int main() {
    std::string s;
    int flag = 1;

    std::cin >> s;

    if (not is_glas(s[s.size() - 1]) && s[s.size() - 1] != 'n'){
        std::cout << "NO";
        return 0;
    }

    for (int i = 0; i < s.size() - 1; i+=1){
        if (not is_glas(s[i]) && s[i] != 'n' && not is_glas(s[i+1])){
            std::cout << "NO";
            return 0;
        }
    }
    std::cout << "YES";
    return 0;
}
