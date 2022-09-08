
std::vector<std::string> EmployeeManager::generateLogin()
{
    std::vector<std::string> vectOfLogins;
    auto genLogin = [&](Employee& e)
    {
        std::string login;
        for (int i = 0; i < 2; ++i)
        {
            login += e.getSurname().at(i);
        }
        for (int i = 0; i < 2; ++i)
        {
            login += e.getName().at(i);
        }

        auto result = std::find(vectOfLogins.begin(), vectOfLogins.end(), e.getLogin());
        int i = 4;
        while (result == std::end(vectOfLogins));
        {
            for (i; i < i + 2; ++i)
            {
                login += e.getName().at(i);
            }
            auto result = std::find(vectOfLogins.begin(), vectOfLogins.end(), e.getLogin());
            i = i + 2;
        }

        vectOfLogins.push_back(login);
        //e.getLogin().push_back(login);
    };
    std::for_each(_employees.begin(), _employees.end(), genLogin);

    return vectOfLogins;
}





//std::string EmployeeManager::generateLogin()
//{
//    auto genLogin = [&](Employee& e)
//    {
//        std::string login;
//        for (int i = 0; i < 2; ++i)
//        {
//            login += e.getSurname().at(i);
//        }
//        for (int i = 0; i < 2; ++i)
//        {
//            login += e.getName().at(i);
//        }
//
//        e.getLogin().push_back(login);
//
//        for (int i = 0; i < _employees.size(); ++i)
//        {
//            if (
//        }
//    };
//    std::for_each(_employees.begin(), _employees.end(), genLogin);
//
//    for (int i = 0; i < _employees.size(); ++i)
//    {
//        std::string login;
//            for (int j = 0; j < 2; ++j)
//            {
//                login += _employees.at(i).getSurname().at(j);
//            }
//        for (int k = 0; k < 2; ++k)
//        {
//            login += _employees.at(i).getSurname().at(k);
//        }
//
//        _employees.at(i).getLogin().push_back(login);
//    }
//
//    return std::string();
//}
//
//std::string EmployeeManager::generatePasswords()
//{
//    return std::string();
//}

//
//void randomPasswordGeneration(int N)
//{
//    // Initialize counter
//    int i = 0;
//
//    int randomizer = 0;
//
//    // Seed the random-number generator
//    // with current time so that the
//    // numbers will be different every time
//    srand((unsigned int)(time(NULL)));
//
//    // Array of numbers
//    char numbers[] = "0123456789";
//
//    // Array of small alphabets
//    char letter[] = "abcdefghijklmnoqprstuvwyzx";
//
//    // Array of capital alphabets
//    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
//
//    // Array of all the special symbols
//    char symbols[] = "!@#$^&*?";
//
//    // Stores the random password
//    char password[N];
//
//    // To select the randomizer
//    // inside the loop
//    randomizer = rand() % 4;
//
//    // Iterate over the range [0, N]
//    for (i = 0; i < N; i++) {
//
//        if (randomizer == 1) {
//            password[i] = numbers[rand() % 10];
//            randomizer = rand() % 4;
//            printf("%c", password[i]);
//        }
//        else if (randomizer == 2) {
//            password[i] = symbols[rand() % 8];
//            randomizer = rand() % 4;
//            printf("%c", password[i]);
//        }
//        else if (randomizer == 3) {
//            password[i] = LETTER[rand() % 26];
//            randomizer = rand() % 4;
//            printf("%c", password[i]);
//        }
//        else {
//            password[i] = letter[rand() % 26];
//            randomizer = rand() % 4;
//            printf("%c", password[i]);
//        }
//    }
//}
//
//// Driver Code
//int main()
//{
//    // Length of the password to
//    // be generated
//    int N = 10;
//
//    // Function Call
//    randomPasswordGeneration(N);
//
//    return 0;
//}