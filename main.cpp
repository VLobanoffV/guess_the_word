#include <iostream>
#include <chrono>
#include <thread>

class game {
private:
    std::string word;
    std::string mask;
    int attempts;
    char symph;
    int points;

    std::string ReloadMask() {
        
        for (int i = 0; i < this->word.length(); i++) {
            if (this->word[i] == symph) {
                mask[i] = symph;
                this->points++;
                continue;
            }
        }
        this->attempts--;
        return this->mask;
    }

    void InitMask() {
        for (int i = 0; i < word.length(); i++) {
            this->mask += '#';
        }
    }

public:
    game(std::string _word) {

        this->word = _word;
        this->attempts = this->word.length() + 3;
        this->points = 0;
        InitMask();

        while (points != this->word.length()) {

            system("cls");
            std::cout << "-----------------------------------\n          guess the word \n----------------------------------- \n";
            PrintMask();
            std::cout << "\n\n\nEnter a letter or word:\n";
            std::cin >> this->symph;
            this->mask = ReloadMask();

            if (GameOver()) {
                return;
            }
        }


        system("cls");
        system("color FC");
        std::cout << "Congratulations! Word - " << this->word << std::endl;
        int answer;
        std::cout << "\n\nPress (1) to restart or (2) to exit.\n";
        std::cin >> answer;

        switch (answer)
        {
        case 1:
            std::cout << "restarted\n";
            system("cls");
            break;
        case 2:
            system("cls");
            system("exit");
            break;
        default:
            break;
        }


    }

    bool GameOver() {

        if (this->attempts == 0)
        {
            system("cls");
            std::cout << "Game over, u used all attempts \nWord - " << this->word << std::endl;
            return true;

        }
        return false;

    }

    void PrintMask(){
        std::cout << this->mask << "            " << "Attempts: " << this->attempts;
    }
};

int main()
{
    game newG("revolition");
}
