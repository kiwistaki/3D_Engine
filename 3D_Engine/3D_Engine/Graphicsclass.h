#pragma once
////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_

//////////////
// INCLUDES //
//////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "textclass.h"
#include "modelclass.h"
#include "modellistclass.h"
#include "frustumclass.h"
#include "Lightclass.h"
#include "Bumpmapshaderclass.h"

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame(int, int, float, float);
	bool Render();

private:
	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	TextClass* m_Text;
	ModelClass* m_Model;
	ModelListClass* m_ModelList;
	FrustumClass* m_Frustum;
	LightClass* m_Light;
	BumpMapShaderClass* m_BumpMapShader;
};

#endif