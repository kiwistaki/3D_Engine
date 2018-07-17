////////////////////////////////////////////////////////////////////////////////
// Filename: texturearrayclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "texturearrayclass.h"

TextureArrayClass::TextureArrayClass()
{
	for (int i = 0; i < NUM_OF_TEXT; i++)
	{
		m_textures[i] = 0;
	}
}

TextureArrayClass::TextureArrayClass(const TextureArrayClass& other)
{
}

TextureArrayClass::~TextureArrayClass()
{
}

bool TextureArrayClass::Initialize(ID3D11Device* device, WCHAR* filename1, WCHAR* filename2, WCHAR* filename3)
{
	HRESULT result;

	// Load the first texture in.
	result = D3DX11CreateShaderResourceViewFromFile(device, filename1, NULL, NULL, &m_textures[0], NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Load the second texture in.
	result = D3DX11CreateShaderResourceViewFromFile(device, filename2, NULL, NULL, &m_textures[1], NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Load the third texture in.
	result = D3DX11CreateShaderResourceViewFromFile(device, filename3, NULL, NULL, &m_textures[2], NULL);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

void TextureArrayClass::Shutdown()
{
	// Release the texture resources.
	for (int i = 0; i < NUM_OF_TEXT; i++)
	{
		if (m_textures[i])
		{
			m_textures[i]->Release();
			m_textures[i] = 0;
		}
	}

	return;
}

ID3D11ShaderResourceView** TextureArrayClass::GetTextureArray()
{
	return m_textures;
}