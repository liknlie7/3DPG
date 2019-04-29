#pragma once


#include <SpriteBatch.h>
#include <SimpleMath.h>
#include "WICTextureLoader.h"



class Sprite2D
{
public:
	Sprite2D();
	~Sprite2D();

public:
	void create(ID3D11Device1* device ,ID3D11DeviceContext1* context);
	void reset();
	void draw();
	void update();

private:
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	m_texture;
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
	DirectX::SimpleMath::Vector2		m_pos;
};