#pragma once

#include "Common.h"
#include "Scene.h"
#include <map>
#include <memory>
#include <deque>

#include "EntityManager.h"

class OptionsScreen : public Scene
{

protected:

	std::vector<std::string>    m_menuStrings;
	sf::Text                    m_menuText;
	size_t                      m_selectedMenuIndex = 0;
	std::vector<std::string>    m_levelPaths;

	void init();
	void update();
	void onEnd();
	void sDoAction(const Action& action);

public:

	OptionsScreen(GameEngine* gameEngine = nullptr);
	void sRender();

};

