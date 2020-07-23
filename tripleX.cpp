# include <iostream>

void showIntro();
void showPasswordHint(int Sum, int Product);

int main()
{
    showIntro();

    const int CodeA = 4;
    const int CodeB = 5;
    const int CodeC = 6;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    showPasswordHint(CodeSum, CodeProduct); 

    return 0;
}

void showIntro()
{
    std::cout << "You are a secret agent breaking into a secure server room..." << std::endl;
    std::cout << "Enter the correct code to continue..." << std::endl;
}

void showPasswordHint(int Sum, int Product)
{
    std::cout << std::endl;
    std::cout << " ··· There are 3 numbers inthe code ··· " << std::endl;
    std::cout << " ··· The codes add-up  to: " << Sum << std::endl;
    std::cout << " ··· The codes product is: " << Product << std::endl;
}