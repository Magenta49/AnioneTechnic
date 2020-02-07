#include "stdafx.h"
#include "GraphicManager.h"
#include "GameManager.h"
#include "Scene.h"
#include "animation.h"
#include "GameObject.h"

LPDIRECT3DDEVICE9 GraphicManager::device = nullptr;

LPD3DXSPRITE GraphicManager::sprite = nullptr;
std::map<std::string, LPDIRECT3DTEXTURE9> GraphicManager::textureMap = std::map<std::string, LPDIRECT3DTEXTURE9>();

GraphicManager::GraphicManager()
{
}


GraphicManager::~GraphicManager()
{
}

void GraphicManager::Init(LPDIRECT3DDEVICE9 device)
{
	GraphicManager::device = device;

	D3DXCreateSprite(device, &sprite);

	//texttest = CreateTexture(L"TestImage.png");
	AddTexture("TestImage.png", L"TestImage.png");
	AddTexture("TestAnimaion", L"TestAnimaion.png");
}

void GraphicManager::AddTexture(std::string textureName, LPCWCH fileName)
{
	auto pair = textureMap.find(textureName);
	if (pair == textureMap.end())
	{
		auto tex = CreateTexture(fileName);

		textureMap.insert(std::make_pair(textureName, tex));

	}
}

LPDIRECT3DTEXTURE9 GraphicManager::GetTexture(std::string textureName)
{
	auto pair = textureMap.find(textureName);
	if (pair == textureMap.end())
	{
		return nullptr;
	}

	return pair->second;
	return LPDIRECT3DTEXTURE9();
}

LPDIRECT3DTEXTURE9 GraphicManager::CreateTexture(LPCWCH fileName)
{
	LPDIRECT3DTEXTURE9 tex;

	D3DXCreateTextureFromFileEx(device,
		fileName,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		1,
		0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		1,
		1,
		NULL,
		NULL,
		NULL,
		&tex
	);

		return tex;

	return LPDIRECT3DTEXTURE9();
}

void GraphicManager::Render()
{
	auto objList = GameManager::nowScene->GetObjectList();
	for (auto obj : objList)
	{
		//obj->animation->textureName;
		Render(obj);
	}

	
}

void GraphicManager::Render(GameObject * object)
{
	auto tex = GetTexture(object->Animation->textureName);
	
	D3DXMATRIX matrix, positionMatrix;

	D3DXMatrixTranslation(&positionMatrix, 0.0f, 0.0f, 0.0f);

	matrix = positionMatrix;



	RECT rc = object->Animation->GetRect();


	sprite->SetTransform(&matrix);
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->Draw(tex, &rc, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	sprite->End();

}

D3DXVECTOR2 GraphicManager::GetTextureSize(LPDIRECT3DTEXTURE9 texture)
{
	D3DSURFACE_DESC de;

	texture->GetLevelDesc(0, &de);

	return D3DXVECTOR2(de.Width,de.Height);
}

D3DXVECTOR2 GraphicManager::GetTextureSize(std::string textureName)
{
	auto tex = GetTexture(textureName);
	return GetTextureSize(tex);
}

