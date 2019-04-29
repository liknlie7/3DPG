//
// Game.h
//

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"
#include <SpriteBatch.h>
#include <SpriteFont.h>
#include <SimpleMath.h>
#include <CommonStates.h>
#include "WICTextureLoader.h"
#include "Sprite2D.h"
#include "DebugFont.h"
#include "SimpleMath.h" 
#include "CommonStates.h" 
#include "PrimitiveBatch.h" 
#include "Effects.h" 
#include "VertexTypes.h"


// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game : public DX::IDeviceNotify
{
private:
	Sprite2D sprite2D;
	DebugFont debugFont;
	// �R�����X�e�[�g 
	std::unique_ptr<DirectX::CommonStates> m_state;
	// �v���~�e�B�u�o�b�` 
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionNormal>> m_pPrimitiveBatch;
	// ���C���p�v���~�e�B�u�o�b�`
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_pLinePrimitiveBatch;
	// �x�[�V�b�N�G�t�F�N�g 
	std::unique_ptr<DirectX::BasicEffect> m_pBasicEffect;
	// ���̓��C�A�E�g 
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_pInputLayout;

public:

    Game() noexcept(false);

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // IDeviceNotify
    virtual void OnDeviceLost() override;
    virtual void OnDeviceRestored() override;

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowMoved();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    // Device resources.
    std::unique_ptr<DX::DeviceResources>    m_deviceResources;

    // Rendering loop timer.
    DX::StepTimer                           m_timer;
};