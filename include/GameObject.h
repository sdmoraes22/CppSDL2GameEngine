#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "IObject.h"
#include "Transform.h"

struct Properties
{
public:
	Properties(std::string textureID, int x, int y, int width, int height, SDL_RenderFlip flip = SDL_FLIP_NONE)
	{
		X = x;
		Y = y;
		Flip = flip;
		Width = width;
		Height = height;
		TextureID = textureID;
	}
public:
	std::string TextureID;
	int Width, Height;
	float X, Y;
	SDL_RenderFlip Flip;
	
};
class GameObject: public IObject
{

public:
	GameObject(Properties* props): m_TextureID(props->textureID), 
	m_Width(props->width), m_Height(props->height), m_Flip(props->Flip)
	{
		m_Transform = new Transform(props->X, props->Y);
	}

	virtual void Draw()=0;
	virtual void Update(float dt)=0;
	virtual void Clean()=0;

protected:
	Transform* m_Transform;
	int m_Width, m_Height;
	std::string m_TextureID;
	SDL_RenderFlip m_Flip;
};

#endif