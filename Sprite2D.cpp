#include "pch.h"

#include "Sprite2D.h"



Sprite2D::Sprite2D() : m_pos(0, 0)
{}

Sprite2D::~Sprite2D()
{}

void Sprite2D::create(ID3D11Device1* device, ID3D11DeviceContext1* context)
{
	m_spriteBatch = std::make_unique<DirectX::SpriteBatch>(context);
	DirectX::CreateWICTextureFromFile(device, L"slime.png", NULL, m_texture.ReleaseAndGetAddressOf());
}

void Sprite2D::draw()
{
	m_spriteBatch->Begin();
	m_spriteBatch->Draw(m_texture.Get(), m_pos);
	m_spriteBatch->End();
}

void Sprite2D::reset()
{
	m_texture.Reset();
	m_spriteBatch.reset();
}

void Sprite2D::update()
{
	m_pos.x += 5.0f;
	m_pos.y += 5.0f;
}
