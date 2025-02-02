#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

void showNewWindow(const std::string& str)
{
    sf::RenderWindow window(sf::VideoMode({400,200}),"");
    tgui::Gui gui{window};

    auto label = tgui::Label::create("Иди нахуй, " + str);
    label->setPosition({"50%","50%"});
    label->setOrigin({0.5f, 0.5f});
    label->getRenderer()->setTextSize(20);
    gui.add(label);

    while(window.isOpen()){
        while (auto eventO = window.pollEvent()) {
            sf::Event event = *eventO;

            if (event.is<sf::Event::Closed>())
                window.close();

            gui.handleEvent(event);
        }
        window.clear();
        gui.draw();
        window.display();
    }

    return;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({800,600}), "title");
    tgui::Gui gui{window};

    auto editBox = tgui::EditBox::create();
    editBox->setSize({"50%","10%"});
    editBox->setPosition({"25%","30%"});
    editBox->setDefaultText("введи имя");
    gui.add(editBox);
    
    auto button = tgui::Button::create("тыкни");
    button->setSize({"30%","10%"});
    button->setPosition({"35%","50%"});
    gui.add(button);

    button->onPress([&](){
        std::string name = editBox->getText().toStdString();
        if (!name.empty())
            showNewWindow(name);
    });

    while(window.isOpen()){
        while (auto eventO = window.pollEvent()) {
            sf::Event event = *eventO;

            if (event.is<sf::Event::Closed>())
                window.close();

            gui.handleEvent(event);
        }
        window.clear();
        gui.draw();
        window.display();
    }

    return 1;
}