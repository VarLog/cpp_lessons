#include <cstring>

#include <iostream>
#include <string>

char* compose_c(const char* name, const char* domain) {
    // Резервируем место для строк, для '@' и '\0'
    char* res = (char*)malloc(strlen(name) + strlen(domain) + 2);
    char* p = strcpy(res, name);
    p += strlen(name);
    *p = '@';
    strcpy(p + 1, domain);
    return res;
}

std::string compose(const std::string& name, const std::string& domain) {
    return name + '@' + domain;
}

int main(int, char**) {
    auto res_cpp = compose("student_cpp", "iate.ru");
    std::cout << res_cpp << std::endl;

    char* res_c = compose_c("student_c", "iate.ru");
    std::cout << res_c << std::endl;
    free(res_c);

    return 0;
}
