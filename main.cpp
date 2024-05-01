
#include <iostream>
#include <unistd.h>

class Position
{
public:
    Position(int x, int y) : x(x), y(y){};
    int x;
    int y;
};

bool render = true;
Position me(0, 0);

void draw_plataform(int size_x, int size_y)
{
    std::cout << "\033[2J\033[1;1H";

    for (int y = 0; y < size_y; y++)
    {

        for (int x = 0; x < size_x; x++)
        {
            if (x == me.x && y == me.y)
            {
                std::cout << "0";
            }
            else
            {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
}
void observerKeys()
{

    std::cout << "\n moveu-se para: "
              << "(" << me.x << "," << me.y << ")\n";

    std::string tec;
    std::cout << "digite suas coordenadas (x,y) ou 'exit' para sair: \n";
    std::cin >> tec;

    if (tec == "exit")
    {
        render = false;
        return;
    }
    try
    {

        std::string x = tec.substr(1, 1);
        std::string y = tec.substr(3, 3);

        std::cout << tec;

        me.x = std::stoi(x);
        me.y = std::stoi(y);
    }
    catch (const std::exception &e)
    {
        std::cout << "coordenadas inválidas\n digite as cordenadas nesse formato: (x,y).";
    }
}

int main()
{

    int size_x;
    int size_y;
    std::cout << "digite a altura:";
    std::cin >> size_y;
    std::cout << "digite a largura:";
    std::cin >> size_x;

    while (render)
    {
        observerKeys();
        usleep(100000);

        draw_plataform(size_x, size_y);
    }

    return 0;
}
