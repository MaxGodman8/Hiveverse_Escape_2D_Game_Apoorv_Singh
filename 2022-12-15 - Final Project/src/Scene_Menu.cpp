
#include "Scene_Menu.h"
#include "Scene_Zelda.h"
#include "Common.h"
#include "Assets.h"
#include "GameEngine.h"
#include "Components.h"
#include "Action.h"
#include "LevelEditor.h"
#include "Overworld.h"
#include "OptionsScreen.h"

Scene_Menu::Scene_Menu(GameEngine * gameEngine)
    : Scene(gameEngine)
{
    init();
}

void Scene_Menu::init()
{
    registerAction(sf::Keyboard::W,     "UP");
    registerAction(sf::Keyboard::S,     "DOWN");
    registerAction(sf::Keyboard::D,     "ZELDA");
    registerAction(sf::Keyboard::Space, "EDITOR");
    registerAction(sf::Keyboard::Escape, "QUIT");
    
    m_title = "Hive Escape";
    m_menuStrings.push_back("Play");
    m_menuStrings.push_back("Options");
    m_menuStrings.push_back("Level Editor");

    m_levelPaths.push_back("overworld.txt");
   // m_levelPaths.push_back("level1.txt");
    
    m_levelPaths.push_back("leveleditor.txt");
                                            
    m_menuText.setFont(m_game->assets().getFont("Megaman"));
    m_menuText.setCharacterSize(64);

    m_game->playSound("MusicTitle");
}
                                            
void Scene_Menu::update()
{
    m_entityManager.update();
}
                                            
void Scene_Menu::sDoAction(const Action& action)
{
    if (action.type() == "START")
    {
        if (action.name() == "UP")
        {
            if (m_selectedMenuIndex > 0) { m_selectedMenuIndex--; }
            else { m_selectedMenuIndex = m_menuStrings.size() - 1; }
        }
        else if (action.name() == "DOWN")
        {
            m_selectedMenuIndex = (m_selectedMenuIndex + 1) % m_menuStrings.size();
        }
        else if (action.name() == "ZELDA")
        {
            if (m_selectedMenuIndex == 0) {

                //then overworld scene..
                m_game->changeScene("ZELDA", std::make_shared<Overworld>(m_game, m_levelPaths[0]));
            }

            if (m_selectedMenuIndex == 2) {

                //then overworld scene..
                m_game->changeScene("ZELDA", std::make_shared<LevelEditor>(m_game, m_levelPaths[1]));
            }

            if (m_selectedMenuIndex == 1) {

                //then overworld scene..
                m_game->changeScene("MENU", std::make_shared<OptionsScreen>(m_game));
            }

            
            m_game->assets().getSound("MusicTitle");
        }
        
        else if (action.name() == "QUIT")
        {
            onEnd();
        }
    }
}

void Scene_Menu::sRender()
{
    // clear the window to a blue
    m_game->window().setView(m_game->window().getDefaultView());
    m_game->window().clear(sf::Color(203, 195, 227));

    // draw the game title in the top-left of the screen
    m_menuText.setCharacterSize(48);
    m_menuText.setString(m_title);
    m_menuText.setFillColor(sf::Color(100, 100, 100));
    m_menuText.setPosition(sf::Vector2f(10, 10));
    m_game->window().draw(m_menuText);
    
    // draw all of the menu options
    for (size_t i = 0; i < m_menuStrings.size(); i++)
    {
        m_menuText.setString(m_menuStrings[i]);
        m_menuText.setFillColor(i == m_selectedMenuIndex ? sf::Color::Black : sf::Color(100, 100, 100));
        m_menuText.setPosition(sf::Vector2f(400, 200 + i * 100));
        m_game->window().draw(m_menuText);
    }

    // draw the controls in the bottom-left
    m_menuText.setCharacterSize(20);
    m_menuText.setFillColor(sf::Color(100, 100, 100));
    m_menuText.setString("up: w     down: s    play: d      back: esc");
    m_menuText.setPosition(sf::Vector2f(10, 690));
    m_game->window().draw(m_menuText);
}

void Scene_Menu::onEnd()
{
    m_hasEnded = true;
    m_game->quit();
}
                                            
