#pragma once

#include "State.h"

class GameState : public State
{
private:

public:
	GameState() = default;
	~GameState() = default;

	virtual void Init() override;

	virtual void Update() override;
};

