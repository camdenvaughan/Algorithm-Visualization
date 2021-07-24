#pragma once
#include "Scene.h"
#include "algorithms/AlgData.h"

class BinaryScene : Scene
{
public:
	BinaryScene();
	~BinaryScene();

	void Draw() override;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	SceneState PollEvents(sf::Event& event) override;

private:
	std::vector<AlgData> data;
};

