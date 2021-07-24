#include "Renderer.h"

Renderer::Renderer()
{
	
}
Renderer* Renderer::GetInstance()
{
	static Renderer* instance;
	return instance;
}

Renderer::~Renderer()
{

}
