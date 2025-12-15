#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
std::string generateCode(){
    std::string code ="";
    std::srand(std::time(0));
    for (int i=0; i<4; i++){
        int digit = std::rand()%10;
        code += std::to_string(digit);
    }
    return code;
}
std::pair<int, int> checkGuess(const std::string& secret, const std::string&guess){
    int bulls = 0;
    int cows = 0;
    std::string secretCopy = secret;

    for (int i = 0; i<4; i++){
        if (guess[i] == secret[i]){
            bulls++;
        } else {
            for (int j=0; j<4; j++){
                if ((guess[i] == secretCopy[j]) && (guess[j] != secret[j])){
                    cows++;
                    secretCopy[j]= 'X';
                    break;
                }
            }
        }
    }
    return std::make_pair (bulls, cows);
}
int main()
{
    std::string secret = generateCode();
    std::string guess;
    int bulls =0;

    while (bulls !=4){
            std::cout << "Enter number:";
            std::cin >> guess;

            std::pair<int,int> result = checkGuess(secret, guess);
            bulls = result.first;
            int cows = result.second;

            std::cout << "Bulls: " << bulls << ", Cows: " << cows << std::endl;

    }
    std::cout << "You win the answer is:" << secret <<std::endl;
    return 0;
}
