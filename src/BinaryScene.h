#pragma once
#include "Scene.h"
#include "algorithms/AlgData.h"
#include "algorithms/BinarySearch.h"

class BinaryScene : Scene
{
public:
	BinaryScene();
	~BinaryScene();
	void OnUpdate(float deltaTime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	SceneState PollEvents(sf::Event& event, sf::Vector2i mousePos) override;

private:
	bool isSearching = false;

	std::vector<AlgData> m_Data;

	BinarySearch m_Search;
	SearchBounds m_SearchBounds;
};

