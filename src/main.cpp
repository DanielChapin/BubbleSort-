#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>

void sortingStep(std::vector<float>& data, unsigned int* index, unsigned int* changes, bool* complete)
{
    if (*complete) return;

    unsigned int c = *index, n = c + 1;

    if (*index >= data.size() - 1)
    {
        *index = 0;
        if (*changes == 0)
        {
            *complete = true;
        }
        *changes = 0;
        return;
    }

    if (data[n] < data[c])
    {
        float temp = data[c];
        data[c] = data[n];
        data[n] = temp;
        *changes = *changes + 1;
        return;
    }

    *index = n;
}

void scramble(std::vector<float>& data)
{
    std::vector<float> temp = data;
    for (int i = 0; i < data.size(); i++)
    {
        int index = rand() % temp.size();
        data[i] = temp[index];
        temp.erase(temp.begin() + index);
    }
}

int main()
{
    sf::VideoMode vm = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode((int) ((float) vm.width / 4 * 3), (int) ((float) vm.height / 4 * 3)), "Bubble Sort", sf::Style::Titlebar);

    std::vector<float> data(50);
    for (unsigned int i = 0; i < data.size(); i++) data[i] = (i + 1) * (1.0f / data.size());
    srand((unsigned int) time(NULL));
    scramble(data);
    unsigned int index = 0, changes = 0;
    bool complete = false;
    bool autoSort = false;
    float stepsPerSec = 10;

    sf::Clock c;

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (e.type == sf::Event::KeyReleased)
            {
                if (e.key.code == sf::Keyboard::P) autoSort = !autoSort;
                if (e.key.code == sf::Keyboard::Escape) window.close();
                if (e.key.code == sf::Keyboard::Space) sortingStep(data, &index, &changes, &complete);
            }
        }

        if (autoSort)
        {
            sortingStep(data, &index, &changes, &complete);
        }

        window.clear();

        sf::Vector2u dim = window.getSize();
        float bw = static_cast<float>(dim.x) / data.size();
        float th = static_cast<float>(dim.y);
        sf::RectangleShape rect;
        for (unsigned int i = 0; i < data.size(); i++)
        {
            float bh = th * data[i];
            rect.setSize(sf::Vector2f(bw, bh));
            rect.setPosition(bw * i, th - bh);

            rect.setFillColor(sf::Color::White);
            if (i == index) rect.setFillColor(sf::Color::Red);
            if (i == index + 1) rect.setFillColor(sf::Color::Blue);
            if (complete) rect.setFillColor(sf::Color::Green);

            window.draw(rect);
        }

        window.display();
    }

    return 0;
}
