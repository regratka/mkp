#include "CDirectXFont.h"


#define XStartPos(index) charactersPositionInfo[index*4 + 0]
#define YStartPos(index) charactersPositionInfo[index*4 + 1]
#define XEndPos(index) charactersPositionInfo[index*4 + 2]
#define YEndPos(index) charactersPositionInfo[index*4 + 3]

/* 10066270-10066290 00020	*/
CDirectXFont::CDirectXFont() {
	directDevice = NULL;
	bitmapWidth = NULL;
	directTexture = NULL;
	directVertexBuffer = NULL;
}

/* 10066290-10066297 00007	*/
CDirectXFont::~CDirectXFont() {
}

/* 100662A0-1006668E 003EE	*/
HRESULT CDirectXFont::CreateFontA(IDirect3DDevice8* p_device, char* p_typeFaceName, long param_3) {
	directDevice = p_device;
	HDC deviceContext = CreateCompatibleDC(NULL);
	SetTextColor(deviceContext, RGB(0xff, 0xff, 0xff));
	SetBkColor(deviceContext, 0);
	SetTextAlign(deviceContext, 0);
	SetMapMode(deviceContext, MM_TEXT);
	int characterHeight = MulDiv(param_3, GetDeviceCaps(deviceContext, LOGPIXELSY), 72);

	HFONT fontHandle = ::CreateFont(characterHeight, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, 
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE | VARIABLE_PITCH, p_typeFaceName);
	if (fontHandle == NULL) {
		return E_FAIL;
	}
	HGDIOBJ replacedFont = SelectObject(deviceContext, fontHandle);
	if (param_3 > 0x28) {
		bitmapWidth = 1024;
	} else if (param_3 > 0x14) {
		bitmapWidth = 512;
	} else {
		bitmapWidth = 256;
	}
	
	BITMAPINFO bitmapInfo;
	ZeroMemory(&bitmapInfo.bmiHeader, sizeof(BITMAPINFOHEADER));

	bitmapInfo.bmiHeader.biWidth = bitmapWidth;
	bitmapInfo.bmiHeader.biHeight = -bitmapWidth;
	bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapInfo.bmiHeader.biPlanes = 1;
	bitmapInfo.bmiHeader.biCompression = BI_RGB;
	bitmapInfo.bmiHeader.biBitCount = 0x20;

	void* dibBits;
	HBITMAP bitMap = CreateDIBSection(deviceContext, &bitmapInfo, DIB_RGB_COLORS, &dibBits, NULL, 0);
	HGDIOBJ replacedBitMap = SelectObject(deviceContext, bitMap);

	long characterXPosition = 0;
	int characterYPosition = 0;
	SIZE characterSize;

	for (char characterToCreate = 0x20; characterToCreate < 0x7f; characterToCreate++) {
		GetTextExtentPoint32(deviceContext, &characterToCreate, sizeof(char), &characterSize);

		if ( characterXPosition + characterSize.cx + 1 > bitmapWidth) {
			characterXPosition = 0;
			characterYPosition += characterHeight + 1;
		}

		ExtTextOut(deviceContext, characterXPosition, characterYPosition, ETO_OPAQUE, NULL, &characterToCreate, sizeof(char), NULL);
		int characterIndex = characterToCreate - ' ';
		
		XStartPos(characterIndex) = characterXPosition / (float)bitmapWidth;
		YStartPos(characterIndex) = characterYPosition / (float)bitmapWidth;
		XEndPos(characterIndex)  = (characterXPosition + characterSize.cx) / (float)bitmapWidth;
		YEndPos(characterIndex)  = (characterYPosition  + characterSize.cy) / (float)bitmapWidth;
		characterXPosition += characterSize.cx + 10;
	}
	
	HRESULT result = p_device->CreateTexture(bitmapWidth, bitmapWidth, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, &this->directTexture);
	if (result < 0) {
		return E_FAIL;
	}
	D3DLOCKED_RECT lockedRect;
	directTexture->LockRect(0, &lockedRect, NULL, 0);
	for (int index = 0; index < bitmapWidth * bitmapWidth * 4; index) {

		char val = ((char*)dibBits)[index];
		((char*)lockedRect.pBits)[index] = val;
		((char*)lockedRect.pBits)[index+1] = val;
		((char*)lockedRect.pBits)[index+2] = val;
		((char*)lockedRect.pBits)[index+3] = val;
		index += 4;
	}

	directTexture->UnlockRect(0);
	SelectObject(deviceContext, replacedBitMap);
	DeleteObject(bitMap);
	SelectObject(deviceContext, replacedFont);
	DeleteObject(fontHandle);
	DeleteDC(deviceContext);
	result = p_device->CreateVertexBuffer(16800, 0, D3DFVF_TEX1|D3DFVF_DIFFUSE|D3DFVF_XYZRHW, D3DPOOL_MANAGED, &directVertexBuffer);
	if (result < 0) {
		return E_FAIL;
	}

	int tokenId = 0;
	while (tokenId < 2) {
		directDevice->BeginStateBlock();
		directDevice->SetTexture(0, directTexture);
		directDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, 1);
		directDevice->SetRenderState(D3DRS_SRCBLEND, 5);
		directDevice->SetRenderState(D3DRS_DESTBLEND, 6);
		directDevice->SetRenderState(D3DRS_ALPHATESTENABLE, 1);
		directDevice->SetRenderState(D3DRS_ALPHAREF, 0x10);
		directDevice->SetRenderState(D3DRS_ALPHAFUNC, 7);
		directDevice->SetRenderState(D3DRS_ZENABLE, 0);
		directDevice->SetVertexShader(0x144);
		directDevice->SetStreamSource(0, directVertexBuffer, 0x1c);

		if (tokenId == 0) {
			directDevice->EndStateBlock(&blockToken1);
		} else {
			directDevice->EndStateBlock(&blockToken2);
		}
		tokenId++;
	}
	return 0;
}

/* 10066690-10066832 001A2	*/
void CDirectXFont::DrawDebug(float p_drawXPos, float p_drawYPos) {
	if (directTexture == NULL) {
		return;
	}
	
	directDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	directDevice->SetTexture(0, directTexture);
	directDevice->SetVertexShader(D3DFVF_TEX1 | D3DFVF_DIFFUSE | D3DFVF_XYZRHW);
	directDevice->SetStreamSource(0, directVertexBuffer, sizeof(FONTVERTEX));
	FONTVERTEX* fontVertexes = NULL;
	directVertexBuffer->Lock(0, sizeof(FONTVERTEX)*4, (BYTE**)&fontVertexes, D3DLOCK_DISCARD);
	fontVertexes[0].x = p_drawXPos;
	fontVertexes[0].y = p_drawYPos;
	fontVertexes[0].z = 1.0f;
	fontVertexes[0].u = 0.0f;
	fontVertexes[0].v = 0.0f;

	fontVertexes[1].x = p_drawXPos;
	fontVertexes[1].y = p_drawYPos + 300.0f;
	fontVertexes[1].z = 1.0f;
	fontVertexes[1].u = 0.0f;
	fontVertexes[1].v = 1.0f;

	fontVertexes[2].x = p_drawXPos + 300.0f;
	fontVertexes[2].y = p_drawYPos;
	fontVertexes[2].z = 1.0f;
	fontVertexes[2].u = 1.0f;
	fontVertexes[2].v = 0.0f;

	fontVertexes[3].x = p_drawXPos + 300.0f;
	fontVertexes[3].y = p_drawYPos + 300.0f;
	fontVertexes[3].z = 1.0f;
	fontVertexes[3].u = 1.0f;
	fontVertexes[3].v = 1.0f;


	fontVertexes[3].rhw = 1.0f;
	fontVertexes[2].rhw = 1.0f;
	fontVertexes[1].rhw = 1.0f;
	fontVertexes[0].rhw = 1.0f;
	fontVertexes[3].color = UINT_MAX;
	fontVertexes[2].color = UINT_MAX;
	fontVertexes[1].color = UINT_MAX;
	fontVertexes[0].color = UINT_MAX;

	directVertexBuffer->Unlock();
	directDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

/* 10066840-1006695F 0011F	*/
void CDirectXFont::DrawTextA(float param_1, float param_2, char* p_text, ulong p_color) {
	if (directTexture == NULL) {
		return;
	}
	directDevice->CaptureStateBlock(blockToken2);
	directDevice->ApplyStateBlock(blockToken1);
	float startX = param_1;
	FONTVERTEX* bufferData = NULL;
	directVertexBuffer->Lock(0, 0, (BYTE**)&bufferData, 0);

	uint primitivesToDraw = 0;
	int characterIndex = 0;

	while (p_text[characterIndex] != '\0') {
		FillCharacter(p_text[characterIndex++], &bufferData, startX, &param_1, &param_2, p_color);
		primitivesToDraw += 2;
		if (primitivesToDraw * 3 <= 594) {
			continue;
		}
		directVertexBuffer->Unlock();
		directDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, primitivesToDraw);
		primitivesToDraw = 0;
		bufferData = NULL;
		directVertexBuffer->Lock(0, 0, (BYTE**)&bufferData, 0);
	}
	directVertexBuffer->Unlock();
	directDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, primitivesToDraw);
	directDevice->ApplyStateBlock(blockToken2);
}

/* 10066960-10066A23 000C3	*/
IDirect3DVertexBuffer8* CDirectXFont::CreateStaticText(float param_1, float param_2, char* p_text, ulong p_color) {
	size_t textLen = strlen(p_text);
	IDirect3DVertexBuffer8* vertexBuffer;
	HRESULT result = directDevice->CreateVertexBuffer(textLen * 0xa8, 0x208, 0x144, D3DPOOL_DEFAULT, &vertexBuffer);
	if (result < 0) {
		return NULL;
	}
	
	float c_param_1 = param_1;

	FONTVERTEX* vertexesData = NULL;
	vertexBuffer->Lock(0, 0, (BYTE**) &vertexesData, 0x2000);

	char* character = p_text;
	while (*character != '\0') {
		FillCharacter(*character++, &vertexesData, c_param_1, &param_1, &param_2, p_color);
	}

	vertexBuffer->Unlock();
	return vertexBuffer;
}

/* 10066A30-10066AC3 00093	*/
void CDirectXFont::DrawStaticText(IDirect3DVertexBuffer8* p_vertexBuffer, long p_startVertex, long p_primitiveCount) {
	if (directTexture != NULL || p_vertexBuffer != NULL) {
		directDevice->CaptureStateBlock(blockToken2);
		directDevice->ApplyStateBlock(blockToken1);
		directDevice->SetStreamSource(0, p_vertexBuffer, 0x1c);
		directDevice->DrawPrimitive(D3DPT_TRIANGLELIST, p_startVertex * 6, p_primitiveCount * 2);
		directDevice->ApplyStateBlock(blockToken2);
	}
}

/* 10066AD0-10066AE1 00011	*/
void CDirectXFont::DestroyStaticText(IDirect3DVertexBuffer8* p_vertexBuffer) {
	if (p_vertexBuffer != NULL) {
		p_vertexBuffer->Release();
	}
}

/* 10066AF0-10066B61 00071	*/
void CDirectXFont::DestroyFont() {
	if (directDevice != NULL) {
		if (blockToken1 != 0) {
			directDevice->DeleteStateBlock(blockToken1);
		}
		if (blockToken2 != 0) {
			directDevice->DeleteStateBlock(blockToken2);
		}
	}

	if (directVertexBuffer != NULL) {
		directVertexBuffer->Release();
		directVertexBuffer = NULL;
	}

	if (directTexture != NULL) {
		directTexture->Release();
		directTexture = NULL;
	}
}

/* 10066B70-10066D27 001B7	*/
void CDirectXFont::FillCharacter(char p_char, FONTVERTEX** p_vertexesArrayPointer, float p_globalXStartPos, float* p_charXPos, float* p_charYPos, ulong p_color) {
	if (p_char == '\n') {
		*p_charXPos = p_globalXStartPos;
		int yPosChange = bitmapWidth * (charactersPositionInfo[3] - charactersPositionInfo[1]);
		*p_charYPos += yPosChange;
		return;
	}
	if (p_char >= ' ') {
		int charIndex = p_char- ' ';
		float bitmapCharXStart = XStartPos(charIndex); 
		float bitmapCharYStart = YStartPos(charIndex);
		float bitmapCharXEnd = XEndPos(charIndex);
		float bitmapCharYEnd = YEndPos(charIndex);
		float bitmapCharWidth = (bitmapCharXEnd - bitmapCharXStart) * bitmapWidth;
		float bitmapCharHeight = (bitmapCharYEnd - bitmapCharYStart) * bitmapWidth;

		FillVertex((*p_vertexesArrayPointer)++, *p_charXPos, *p_charYPos + bitmapCharHeight, bitmapCharXStart, bitmapCharYEnd, p_color);
		FillVertex((*p_vertexesArrayPointer)++, *p_charXPos, *p_charYPos, bitmapCharXStart, bitmapCharYStart, p_color);
		FillVertex((*p_vertexesArrayPointer)++, *p_charXPos + bitmapCharWidth, *p_charYPos, bitmapCharXEnd, bitmapCharYStart, p_color);

		FillVertex((*p_vertexesArrayPointer)++, *p_charXPos + bitmapCharWidth, *p_charYPos, bitmapCharXEnd, bitmapCharYStart, p_color);
		FillVertex((*p_vertexesArrayPointer)++, *p_charXPos + bitmapCharWidth, *p_charYPos + bitmapCharHeight, bitmapCharXEnd, bitmapCharYEnd, p_color);
		FillVertex((*p_vertexesArrayPointer)++, *p_charXPos, *p_charYPos + bitmapCharHeight, bitmapCharXStart, bitmapCharYEnd, p_color);

		*p_charXPos += bitmapCharWidth; 
	}
}

/* 10066D30-10066D64 00034	*/
void CDirectXFont::FillVertex(FONTVERTEX* p_vertex, float p_x, float p_y, float p_u, float p_v, ulong p_color) {
	p_vertex->x = p_x;
	p_vertex->y = p_y;
	p_vertex->z = 1.0f;
	p_vertex->rhw = 1.0f;
	p_vertex->color = p_color;
	p_vertex->u = p_u;
	p_vertex->v = p_v;
}

