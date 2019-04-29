#include "pch.h"
#include "DebugFont.h"
#include <SimpleMath.h>

using namespace DirectX;

using Microsoft::WRL::ComPtr;

DebugFont::DebugFont() :value(0.f)
{}

DebugFont::~DebugFont()
{}

void DebugFont::create(ID3D11Device1 * device, ID3D11DeviceContext1 * context)
{
	m_state = std::make_unique<CommonStates>(device);
	m_spriteBatch = std::make_unique<SpriteBatch>(context);
	m_spriteFont = std::make_unique<SpriteFont>(device, L"SegoeUI_18.spritefont");
}

void DebugFont::draw()
{
	m_spriteBatch->Begin(SpriteSortMode_Deferred, m_state->NonPremultiplied());

	wchar_t text[256];
	swprintf(text, L"value = %f", value);

	m_spriteFont->DrawString(m_spriteBatch.get(), text, SimpleMath::Vector2(0, 100));
	m_spriteBatch->End();
}

void DebugFont::reset()
{
	m_state.reset();
	m_spriteBatch.reset();
	m_spriteFont.reset();
}

void DebugFont::update()
{
	
}