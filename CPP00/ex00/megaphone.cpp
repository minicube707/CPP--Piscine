#include <iostream>
#include <string>

int main(int argc, char** argv)
{   
    std::string tmp;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i=1; i < argc ; i++)
    {
        tmp = argv[i];
        for (size_t  j = 0; j < tmp.size(); j++)
            std::cout << (char)toupper(tmp[j]) << std::ends;
    }
    return (0);
}