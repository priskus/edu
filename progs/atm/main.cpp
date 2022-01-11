#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

int main() {
    srand(time(NULL));
    setlocale(LC_ALL,"ru");
    std::ifstream file("atm.bin", std::ios::binary);
    int count=0, bill, maxCount=100, currentSum=0;
    std::vector<std::pair<int,int>> noms {{100,0},{500,0},{1000,0},{2000,0},{5000,0}};

    char mode;
    if(file.is_open())
    {
        while (!file.eof()) {
            bill = 0;
            file >> bill;
            if (bill != 0) {
                ++count;
                currentSum += bill;
            }
            for (auto &x : noms)
                if (bill == x.first)
                    ++x.second;
        }
        file.close();
        std::cout << "now in atm " <<count <<" bill(s) of "<< currentSum <<"$"<< std::endl;
        for (auto &x : noms) std::cout << x.first << " " << x.second << std::endl;
    }

    std::cout << "Enter +, to fill atm\n";
    std::cout << "Enter -, to get money\n";
    std::cout << "The smallest bills, atm can keep are of 100$ nominal\n";
    std::cin >> mode;
    if(mode == '+')
    {
        std::ofstream file("atm.bin", std::ios::app | std::ios::binary);
        int buf=0;
        while(count < maxCount)
        {
            buf = noms[(rand() % 5)].first;
            file<<buf<<std::endl;
            ++count;
        }
        file.close();
        std::cout << "atm fed up";
        return 0;
    }
    if(mode == '-')
    {
        std::cout << "Enter amount to get: ";
        int askSum;
        std::ofstream file("atm.bin", std::ios::binary);
        std::vector<std::pair<int,int>> pay = {{100,0},{500,0},{1000,0},{2000,0},{5000,0}};

        std::cin >> askSum;
        for(int i = noms.size()-1;i>=0;--i)
        {
            if(askSum <= currentSum)
            {

                pay[i].second = (askSum / noms[i].first) < noms[i].second ? (askSum / noms[i].first) : noms[i].second;
                askSum -= pay[i].first*pay[i].second;
                currentSum -= pay[i].first*pay[i].second;
                noms[i].second -= pay[i].second;

            }
            else {
                std::cout << "There is no currently such amount in the atm";
                return 0;}
        }
        std::cout << "for pay"<<std::endl;
        for(auto &x : pay)
            if(x.second)
                std::cout << x.first <<" "<<x.second<<std::endl;
        std::cout << std::endl;
        std::cout << "rest in atm "<<currentSum<<"$"<<std::endl;
        for(auto &x : noms) std::cout << x.first <<" "<<x.second<<std::endl;

        for(auto &x : noms)
            for(int i = 0; i < x.second; ++i)
                file << x.first << std::endl;
        file.close();
    }


}