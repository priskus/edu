#include <iostream>
#include <vector>
#include <ctime>
#include <map>
#include <unistd.h>
#include <fstream>
#include <limits>

struct person
{
    std::string name;
    int health=0;
    int armour=0;
    int damage=0;
};
struct crd
{
    int x=0;
    int y=0;
};

bool play;// make it = 0 to break the game abruptly

void my_int_cin(int& a){
    std::cin >> a;
    while (std::cin.fail() || a<=0){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите значение повторно:";
        std::cin >> a;
    }
}

std::string seekInMapByValue(std::map<std::string,crd> m, crd value)
{
    for (auto it = m.begin(); it != m.end(); ++it)
        if (it->second.x == value.x && it->second.y == value.y)
            return it->first;
    return "";
}

void printField(std::map<std::string,crd>& coords, const person& player, int fieldSize)
{

    for(auto& [key, value] : coords) std::cout << key<<" "<<value.x<<":"<<value.y<<std::endl;
    std::cout << std::endl;

    for(int i = 0; i<fieldSize+2; ++i) {
        for (int j = 0; j < fieldSize+2; ++j) {
            std::string ic="";
            for (auto it = coords.begin(); it != coords.end(); ++it)
            {   ic="";
                if(i==0 || i==fieldSize+1) {ic="--"; break;}
                if(j==0 || j==fieldSize+1) {ic="|"; break;}
                if (it->second.x == j-1 && it->second.y == i-1) {
                    if (it->first == player.name) { ic = "🤠"; break;}
                    else { ic = "💀";  break;}
                } else { ic = "  ";}
            }
            std::cout << ic;
        }
        std::cout << std::endl;
    }
//    getch();
}

void genCommand(std::string &command, int i, int &enemiesQuantity)
{
    if(i==enemiesQuantity)
    {
        while (true) {
            std::cout << "Enter (w/a/s/d) or (save/read) ";
            // direction = getch();
            std::cin >> command;
            if (command != "w" && command != "a" && command != "s" && command != "d" && command != "save" && command != "read") {
                std::cout << "incorrect command!\n";
                continue;
            }
            break;
        }
    }
    else
    {
        std::string ch[] {"w","a","s","d"};
        command = ch[rand()%4];
        // cout <<"press to continue\n";
        // getch();
        //  string s;
        //  cin >> s;
    }

}

void attack(const std::string& victimName, std::map<std::string,crd>& coords, const person& object, std::vector <person>& enemies, bool playerActing, person& player, int& enemiesQuantity)
{
    if(playerActing)
        for(auto subject = enemies.begin(); subject!=enemies.end(); ++subject)
        {
            if(victimName == subject->name)
            {
                subject->armour -= object.damage;
                if(subject->armour < 0)
                {
                    subject->health += subject->armour;
                    subject->armour = 0;
                    if (subject->health <= 0)
                    {
                        coords.erase(subject->name);
                        enemies.erase(subject);
                        --enemiesQuantity;
                        if(!enemiesQuantity) {std::cout <<"Goodness won!\n"; play = false;}

                        sleep(2);
                        break;
                    }

                }

                std::cout << "player is attacking\n";
                sleep(1);
            }
        }
    else if(victimName == player.name)
    {
        player.armour -= object.damage;
        if(player.armour < 0)
        {
            player.health += player.armour;
            if(player.health <= 0)
            {
                std::cout << "player is dead\n";
                sleep(2);
                play = false;
                return;
            }
            player.armour = 0;
        }

        std::cout << "enemy is attacking\n";
        sleep(1);
    }
}

void writeSave(person& player, std::vector <person>& enemies, std::map<std::string,crd>& coords)
{
    std::ofstream out ("./save.bin", std::ios::binary);
    out.write((char*)&player.health, sizeof(player.health));
    out.write((char*)&player.armour, sizeof(player.armour));
    out.write((char*)&player.damage, sizeof(player.damage));

    int enemiesSize = enemies.size();
    out.write((char*)&enemiesSize, sizeof(enemiesSize));
    for(person &p : enemies)
    {
        int len = p.name.length();
        out.write((char*)&len, sizeof(len));
        out.write(p.name.c_str(), len);
        out.write((char*)&p.health, sizeof(p.health));
        out.write((char*)&p.armour, sizeof(p.armour));
        out.write((char*)&p.damage, sizeof(p.damage));
    }

    int coordsSize = coords.size();
    out.write((char*)&coordsSize, sizeof(coordsSize));
    for(auto &[key,value] : coords)
    {
        int len = key.length();
        out.write((char*)&len, sizeof(len));
        out.write(key.c_str(), len);
        out.write((char*)&value.x, sizeof(value.x));
        out.write((char*)&value.y, sizeof(value.y));
    }
    out.close();
}

void readSave(person& player, std::vector <person>& enemies, std::map<std::string,crd>& coords, int& enemiesQuantity)
{
    std::ifstream in ("./save.bin", std::ios::binary);
    in.read((char*)&player.health, sizeof(player.health));
    in.read((char*)&player.armour, sizeof(player.armour));
    in.read((char*)&player.damage, sizeof(player.damage));

    int enemiesSize;
    in.read((char*)&enemiesSize, sizeof(enemiesSize));
    enemies.clear();
    enemiesQuantity = enemiesSize;
    enemies.resize(enemiesSize);
    for(person& p : enemies)
    {
        int len;
        in.read((char*)&len, sizeof(len));
        p.name.resize(len);
        in.read((char*)p.name.c_str(), len);
        in.read((char*)&p.health, sizeof(p.health));
        in.read((char*)&p.armour, sizeof(p.armour));
        in.read((char*)&p.damage, sizeof(p.damage));
    }
    int coordsSize;
    in.read((char*)&coordsSize, sizeof(coordsSize));
    coords.clear();

    for(int i = 0; i < coordsSize; ++i)
    {
        // pair <string, crd>;
        int len;
        in.read((char*)&len, sizeof(len));
        std::string name(len,0);
        in.read((char*)name.c_str(), len);
        int x=0,y=0;
        in.read((char*)&x, sizeof(x));
        in.read((char*)&y, sizeof(y));
        coords.insert(std::pair<std::string, crd> {name, {x,y}});
    }

    in.close();
}

void act(std::map<std::string,crd> &coords, person& object, std::string command, int fieldSize, std::vector <person> &enemies, bool playerActing, person& player, int &enemiesQuantity)
{

    std::string victimName;//name of a attack victim
    if (command == "w")
    {victimName = seekInMapByValue(coords, {coords[object.name].x, coords[object.name].y - 1});
        if (!victimName.empty() )
            attack(victimName, coords, object, enemies, playerActing, player, enemiesQuantity);
        else if (coords[object.name].y > 0)
            coords[object.name].y -= 1;
    }
    else if (command == "s")
    {victimName = seekInMapByValue(coords, {coords[object.name].x, coords[object.name].y + 1});
        if(!victimName.empty())
            attack(victimName, coords, object, enemies, playerActing, player, enemiesQuantity);
        else if(coords[object.name].y < fieldSize - 1)
            coords[object.name].y += 1;
    }
    else if (command == "a")
    {victimName = seekInMapByValue(coords, {coords[object.name].x - 1, coords[object.name].y});
        if(!victimName.empty())
            attack(victimName, coords, object, enemies, playerActing, player, enemiesQuantity);
        else if(coords[object.name].x > 0)
            coords[object.name].x -= 1;
    }
    else if (command == "d")
    {victimName = seekInMapByValue(coords, {coords[object.name].x + 1, coords[object.name].y});
        if(!victimName.empty())
            attack(victimName, coords, object, enemies, playerActing, player, enemiesQuantity);
        else if(coords[object.name].x < fieldSize - 1)
            coords[object.name].x += 1;
    }
    else if (command == "save")
        //if you want to save and read game progress, you should enter the same field sizes
        //and player Name when save and when read
        writeSave(player, enemies, coords);
    else if (command == "read")
        readSave(player, enemies, coords, enemiesQuantity);
}


int main() {
    srand(time(NULL));
    std::vector <person> enemies;
    person enemy;
    person player;
    std::map <std::string,crd> coords; //coordinates of the palyer and enemies
    int fieldSize;
    std::cout <<"Enter field size: ";
    my_int_cin(fieldSize);
    int enemiesQuantity;
    std::cout <<"Enter enemies quantity: ";
    my_int_cin( enemiesQuantity);

    std::cout << "Enter your player name: ";
    std::cin >> player.name;

    do{
        std::cout << "His health level(50-150): ";
        my_int_cin(player.health);
    }while(player.health<50 || player.health>150);

    do{
        std::cout << "His armour level(0-50): ";
        my_int_cin(player.armour);
    }while(player.armour<0 || player.armour>50);

    do{
        std::cout << "His damage level(15-30): ";
        my_int_cin(player.damage);
    }while(player.damage<15 || player.damage>30);

    play = true;

    coords.insert(std::pair<std::string,crd>(player.name, {rand() % fieldSize, rand() % fieldSize}));
    system("clear");
    for(int i = 1; i <=enemiesQuantity; ++i)
    {
        enemy.name = "Enemy" + std::to_string(i);
        enemy.health = rand() % 100 + 50;
        enemy.armour = rand() % 50;
        enemy.damage = rand() % 15 + 15;
        enemies.push_back(enemy);
        crd xy = {rand() % fieldSize, rand() % fieldSize};
        auto it = coords.begin();

        while(it != coords.end()) {
            if (it->second.x == xy.x && it->second.y == xy.y)
            {
                xy = {rand() % fieldSize, rand() % fieldSize};
                it = coords.begin();
            }
            else
                ++it;
        }
        coords.insert(std::pair<std::string,crd>(enemy.name, xy));
    }

    std::string command;

    for( int i = 0; play; )
    {
        for(person p : enemies)
            std::cout << p.name <<"  health:"<< p.health <<"  armour:"<< p.armour <<std::endl;
        std::cout <<player.name <<"  health:"<< player.health <<"  armour:"<< player.armour <<std::endl;

        printField(coords, player, fieldSize);
        // sleep(1);
        genCommand(command, i, enemiesQuantity);

        if(i==enemiesQuantity)
            act(coords, player, command, fieldSize,enemies, true, player, enemiesQuantity);
        else
            act(coords, enemies[i], command, fieldSize, enemies, false, player, enemiesQuantity);
        system("clear");
        ++i;
        if(i>=enemiesQuantity + 1) i=0;
    }
}