#pragma once

#include <CommonStates.h>
#include <SpriteBatch.h>
#include <SpriteFont.h>

class DebugFont
{
public:
	DebugFont();
	~DebugFont();
public:
	void create(ID3D11Device1* device,ID3D11DeviceContext1* context);
	void draw();
	void reset();
	void update();
private:
	std::unique_ptr<DirectX::CommonStates>	m_state;
	std::unique_ptr<DirectX::SpriteBatch>	m_spriteBatch;
	std::unique_ptr<DirectX::SpriteFont>	m_spriteFont;

	float value;
};

