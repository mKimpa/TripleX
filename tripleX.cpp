# include <iostream>

void showIntro();

int main()
{
    showIntro();

    return 0;
}

void showIntro()
{
    std::cout << "You are a secret agent breaking into a secure server room..." << std::endl;
    std::cout << "Enter the correct code to continue..." << std::endl;
}