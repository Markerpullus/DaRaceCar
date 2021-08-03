#pragma once

#include "State.h"

class GameState : public State
{
private:
	sf::Sprite car;
	sf::Texture carTexture;

public:
	GameState() = default;
	~GameState() = default;

	virtual void Init() override;

	virtual void Update() override;
};

