#include <iostream>
#include <bitset>

enum switches{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16};

int main() {
    setlocale(LC_ALL,"Russian");
    float tempIn = 0, tempOut = 0;
    bool motionOut = false, lightInOn = false;
    char com = 0;
    int lightColor = 5000;
    std::string temp[4]; //tempIn, tempOut, OutMotion, lightInOn
    std::string buf;
    std::cout << "Введите состояние системы через пробел:\n";
    std::cout << "температура снаружи(\u00B0C) температура внутри(\u00B0C) есть ли движение снаружи(yes/no) свет в доме(on/off)\n";
    for(int time = 0; time < 48; ++time)
    {
        std::cout <<time%24<< ": ";
        getline(std::cin, buf);
        for(int j =0; j < 4; ++j)
        {
            if(buf.find(" ")!=std::string::npos) {
                temp[j] = buf.substr(0, buf.find(" "));
                buf.erase(0, buf.find(" ") + 1);
            }
            else
                temp[j] = buf;
        }
        tempOut = stof(temp[0]);
        tempIn = stof(temp[1]);
        motionOut = temp[2]=="yes";
        lightInOn = temp[3]=="on";

        if(tempOut < 0 && (com & WATER_PIPE_HEATING) == 0)
        {
            com |= WATER_PIPE_HEATING;
            std::cout << "Включение отопления трубы\n";
        }
        else if (tempOut > 5 && com & WATER_PIPE_HEATING)
        {
            com ^= WATER_PIPE_HEATING;
            std::cout << "Выключение отопления трубы\n";
        }


        if((16 < time%24 || time%24 < 5))
        {
            if(motionOut && (com & LIGHTS_OUTSIDE) == 0)
            {
                com |= LIGHTS_OUTSIDE;
                std::cout << "Включение садового освещения\n";
            }
            else if(motionOut == 0 && com & LIGHTS_OUTSIDE)
            {
                com ^= LIGHTS_OUTSIDE;
                std::cout << "Выключение садового освещения\n";
            }
        }
        else if(com & LIGHTS_OUTSIDE)
        {
            com ^= LIGHTS_OUTSIDE;
            std::cout << "Выключение садового освещения\n";
        }


        if(tempIn < 22 && (com & HEATERS) == 0)
        {
            com |= HEATERS;
            std::cout << "Включение внутреннего отопления\n";
        }
        else if (tempIn >= 25 && com & HEATERS)
        {
            com ^= HEATERS;
            std::cout << "Выключение внутреннего отопления\n";
        }


        if(tempIn >= 30 && (com & CONDITIONER) == 0)
        {
            com |= CONDITIONER;
            std::cout << "Включение кондиционирования\n";
        }
        else if (tempIn <= 25 && com & CONDITIONER)
        {
            com ^= CONDITIONER;
            std::cout << "Выключение кондиционирования\n";
        }


        if(16<=time%24 && 20>time%24)  lightColor-=575;
        if(time%24==0) lightColor=5000;
        if(lightInOn && (com & LIGHTS_INSIDE) == 0)
        {
            com |= LIGHTS_INSIDE;
            std::cout << "Включение света в помещении "<<lightColor<<" K\n";
        }
        else if(lightInOn==0 && com & LIGHTS_INSIDE)
        {
            com ^= LIGHTS_INSIDE;
            std::cout << "Выключение света в помещении\n";
        }
        else if(lightInOn && com & LIGHTS_INSIDE)
            std::cout << "Включен свет в помещении "<<lightColor<<" K\n";

        std::bitset<8> x(com);
        std::cout <<"DO: "<< x << '\n';
    }
}
