# include <iostream>
# include <ctime>

void ShowIntro(int Difficulty, int Attempts);
bool PlayGame(int Difficulty, int Attempts);
void ShowPasswordHint(int Sum, int Product);
void ShowWinMessage();
void ShowLoseMessage();

int main()
{
    srand(time(NULL));
    const int MaxDifficulty = 4;
    int CodeInputAttemps = 3;
    int LevelDifficulty = 1;
    while (true)
    {       
        bool bLevelComplete = PlayGame(LevelDifficulty, CodeInputAttemps);
        std::cin.clear();
        std::cin.ignore();
        if (bLevelComplete)
        {
            if (LevelDifficulty == MaxDifficulty)
            {
                ShowWinMessage();
                break;
            }
            ++LevelDifficulty;
        }
        else
        {
            --CodeInputAttemps;
            if (CodeInputAttemps == 0)
            {
                ShowLoseMessage();
                break;
            }

        }
        
    }
    
    return 0;
}

void ShowWinMessage()
{
    system("cls");
    std::cout << "================\n";
    std::cout << "=   SUCCESS   ==\n";
    std::cout << "================\n";
}

void ShowLoseMessage()
{
    system("cls");
    std::cout << "================\n";
    std::cout << "=    FAIL!    ==\n";
    std::cout << "================\n";
}

void ShowIntro(int Difficulty, int Attempts)
{
    system("cls");
    std::cout << "You are a secret agent breaking into a secure server room...\n";
    std::cout << "Secure level: " << Difficulty << "\n";
    std::cout << "Attempts left: "<< Attempts << "\n";
    std::cout << "Enter the correct code to continue...\n";
    std::cout << "_____________________________________________________________";
}

void ShowPasswordHint(int Sum, int Product)
{
    std::cout << std::endl;
    std::cout << " ### There are 3 numbers in the code ### " << std::endl;
    std::cout << " ### The codes add-up  to: " << Sum << std::endl;
    std::cout << " ### The codes product is: " << Product << std::endl;
}

bool PlayGame(int Difficulty, int Attempts)
{
    ShowIntro(Difficulty, Attempts);

    const int CodeA = (rand() % Difficulty + 1) + 1;
    const int CodeB = (rand() % Difficulty + 1) + 1;
    const int CodeC = (rand() % Difficulty + 1) + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    ShowPasswordHint(CodeSum, CodeProduct); 

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if ((GuessSum == CodeSum) && (GuessProduct == CodeProduct))
    {
        std::cout <<"Correct Code! \n";
        return true;
    }   
    std::cout << "Nope...\n";  
    return false;
}