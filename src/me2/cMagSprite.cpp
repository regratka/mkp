#include "cMagSprite.h"
#include "cMagEngineMgr.h"

/* 1000A9B0-1000A9BD 0000D	*/
void cMagSprite::PlayMovie(bool param_1) {
	shouldPlayMovie = param_1;
}

/* 1000FF70-1000FF77 00007	*/
bool cMagSprite::GetStatusRemoveObject() {
	return shouldRemoveObject;
}

/* 1000FF80-1000FF8D 0000D	*/
void cMagSprite::RemoveObject(bool param_1) {
	shouldRemoveObject = param_1;
}

/* 10012910-10012911 00001	*/
void cMagSprite::DeleteAllSprites() {
}

/* 10030740-10030743 00003	*/
void cMagSprite::SetMouseRegion(int param_1, int param_2, int param_3) {
}

/* 1005A5E0-1005A5E3 00003	*/
void cMagSprite::InitDeviceDx(cMagGameObject* param_1) {
}

/* 1005A5F0-1005A5F3 00003	*/
void cMagSprite::SetCursorPosition(int param_1, int param_2) {
}

/* 10062870-10062BD6 00366	*/
cMagSprite::cMagSprite() {
	SetObjectName("No_name");
	SetClassName("cMagSprite");
	unk_d6c = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	unk_d78 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	d3dxSprite = NULL;
	unk_dd0 = 1.0f;
	subSprites = std::vector<SubSpriteData>();
	unk_d4d = false;
	shouldRenderSprites = true;
	testTexture = NULL;
	unk_14c4 = 0x14;
	unk_d59 = false;
	unk_d5a = false;
	vertexBuffer = NULL;
	unk_dd4 = 1.0f;
	srcBlend = 2;
	destBlend = 2;
	D3DXMatrixIdentity(&unk_16a4);
	D3DXMatrixIdentity(&unk_16e4);
	movieScaleX = 1.0f;
	movieScaleY = 1.0f;
	unk_1730 = 1.0f;
	rotationMovie = 0.0f;
	texture = NULL;
	unk_1724 = false;
	shouldPlayMovie = false;
	unk_1738 = false;
}


/* 10062C40-10062D97 00157	*/
cMagSprite::~cMagSprite() {
	directXFont.DestroyFont();

	if (vertexBuffer != NULL) {
		vertexBuffer->Release();
		vertexBuffer = NULL;
	}
}

/* 10062DA0-10062E4F 000AF	*/
void cMagSprite::SetTextColor(int param_1, float param_2, float param_3, float param_4, float param_5) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1 && subSprites[index].unk_17c) {
			subSprites[index].textColor.r = param_2;
			subSprites[index].textColor.g = param_3;
			subSprites[index].textColor.b = param_4;
			subSprites[index].textColor.a = param_5;
			return;
		}
	} 
}

/* 10062DA0-10062E4F 000AF	*/
void cMagSprite::ShowText(int param_1, float param_2, float param_3, float param_4, float param_5) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1 && subSprites[index].unk_17c) {
			subSprites[index].textColor.r = param_2;
			subSprites[index].textColor.g = param_3;
			subSprites[index].textColor.b = param_4;
			subSprites[index].textColor.a = param_5;
			return;
		}
	} 
}

/* 10062E50-10062EC2 00072	*/
void cMagSprite::ShowText(int param_1, bool param_2) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1 && subSprites[index].unk_17c) {
			subSprites[index].shouldShowText = param_2;
			return;
		}
	} 
}

/* 10062ED0-10062F84 000B4	*/
void cMagSprite::SetText(int param_1, char* param_2) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1 && subSprites[index].unk_17c) {
			ZeroMemory(subSprites[index].text, sizeof(subSprites[index].text));
			strcpy(subSprites[index].text, param_2);
			return;
		}
	} 
}

/* 10062F90-1006310A 0017A	*/
void cMagSprite::SetText(int param_1, char* param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8) {
	float posX = GetWindowWidth() * param_3;
	float posY = GetWindowHeight() * param_4;
	
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1 && subSprites[index].unk_17c) {
			ZeroMemory(subSprites[index].text, sizeof(subSprites[index].text));
			strcpy(subSprites[index].text, param_2);
			subSprites[index].unk_14 = D3DXVECTOR2(param_3,param_4);
			subSprites[index].textPosition.x = posX;
			subSprites[index].textPosition.y = posY;
			subSprites[index].textColor.r = param_5;
			subSprites[index].textColor.g = param_6;
			subSprites[index].textColor.b = param_7;
			subSprites[index].textColor.a = param_8;
			return;
		}
	} 
}

/* 10063110-100631FB 000EB	*/
void cMagSprite::SetTextPosition(int param_1, float param_2, float param_3) {
	int windowWidth = GetWindowWidth();
	float posX = windowWidth * param_2;
	int windowHeight = GetWindowHeight();
	float posY = windowHeight * param_3;

	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1 && subSprites[index].unk_17c) {
			subSprites[index].unk_14 = D3DXVECTOR2(param_2,param_3);
			subSprites[index].textPosition.x = posX;
			subSprites[index].textPosition.y = posY;
			return;
		}
	} 
}

/* 10063200-1006327D 0007D	*/
char* cMagSprite::GetText(int param_1) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1 && subSprites[index].unk_17c) {
			return subSprites[index].text;
		}
	} 
	return "Empty";
}

/* 10063280-1006333A 000BA	*/
void cMagSprite::ClearTextBuffer() {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].unk_17c) {
			subSprites.erase(subSprites.begin()+index);
		}
	} 
}

/* 10063340-100636BC 0037C	*/
int cMagSprite::SetText(char* param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7) {
	if (d3dxSprite == NULL) {
		D3DXCreateSprite(cMagEngineMgr::getInstance()->engine, &d3dxSprite);
	}
	float fVar3 =  GetWindowWidth() * param_2;
	float fVar4 =  GetWindowHeight() * param_3;
	int iVar4 = -1;
	if (subSprites.size() > 0) {
		iVar4 = subSprites[subSprites.size()-1].texID;
		if (iVar4 == -1) {
			iVar4 = 0;
		}
	}

	SubSpriteData local_294;
	ZeroMemory(&local_294, sizeof(SubSpriteData));
	strcpy(local_294.text, param_1);
	local_294.unk_17c = true;
	local_294.unk_14.x = param_2;
	local_294.unk_14.y = param_3;
	local_294.textColor.r = param_4;
	local_294.textColor.g = param_5;
	local_294.textColor.b = param_6;
	local_294.textColor.a = param_7;
	local_294.texID = iVar4 + 1;
	subSprites.push_back(local_294);
	return local_294.texID;
}

/* 100636C0-10063713 00053	*/
void cMagSprite::CreateFontA(char* param_1, long param_2) {
	strcpy(typefaceName, param_1); 
	unk_14c4 = param_2;
	directXFont.CreateFontA(cMagEngineMgr::getInstance()->engine, typefaceName, param_2);
}

/* 10063720-100637E0 000C0	*/
void cMagSprite::Restore() {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].unk_17c) {
			SetTextPosition(subSprites[index].texID, 
				subSprites[index].unk_14.x, subSprites[index].unk_14.y);
		}

		if (subSprites[index].unk_34) {
			SetScaleAsWindow(subSprites[index].texID);
		} else {
			SetScale(subSprites[index].texID, 
				subSprites[index].unk_24, subSprites[index].unk_28);
			SetPos(subSprites[index].texID, subSprites[index].unk_1c, subSprites[index].unk_20, 0);	
		}
	} 
}

/* 100637E0-100637FE 0001E	*/
void cMagSprite::SetAlpha1(ulong param_1, ulong param_2) {
	unk_d4d = true;
	srcBlend = param_1;
	destBlend = param_2;
}

/* 10063800-100638A7 000A7	*/
void cMagSprite::LoadSprites(char* param_1) {
	char* dataPath = cMagEngineMgr::getInstance()->gameObject->dataPath;
	char local_12c[300];
	if (dataPath != NULL) {
		sprintf(local_12c, "%s%s", dataPath, param_1);
	} else {
		sprintf(local_12c, "%s", param_1);
	}
	magLog.FileLog("LoadSprites: <%s>", local_12c);
	D3DXCreateTextureFromFileEx(cMagEngineMgr::getInstance()->engine, local_12c, 
		-1, -1, -1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, -1, -1, 
		D3DCOLOR_ARGB(0xff,0,0,0), NULL, NULL, &gameObjectTexture);
}

/* 100638B0-100638D1 00021	*/
void cMagSprite::SetScale(float param_1, float param_2, float param_3) {
	scale.x = param_1;
	scale.y = param_2;
	scale.z = param_3;
}

/* 100638E0-100638ED 0000D	*/
void cMagSprite::EnableSpriteRendering(bool param_1) {
	shouldRenderSprites = param_1;
}

/* 100638F0-10063A91 001A1	*/
void cMagSprite::OnRender() {
	D3DXMATRIX local_40;
	D3DXMATRIX local_80;
	if (shouldPlayMovie && unk_1724) {
		D3DXMatrixOrthoLH(&local_40, 1.0f, 1.0f, 0.0f, 100.0f);
		D3DXMatrixIdentity(&local_80);
		cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_PROJECTION, &local_40);
		cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_VIEW, &local_80);
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_LIGHTING, FALSE);
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_CULLMODE, TRUE);
		cMagEngineMgr::getInstance()->engine->SetTexture(0, teksturyVideo.texture);
		teksturyVideo.SprawdzPetle(this);
		RysujDuszkiEx(0.0f, 0.0f, 0.0f, rotationMovie, movieScaleX, movieScaleY);
		return;
	}

	if (d3dxSprite != NULL && shouldRenderSprites) {
		d3dxSprite->OnLostDevice();
		CheckMouseRegion();
		RenderSprites();
	}
}

/* 10063AA0-10063AAD 0000D	*/
void cMagSprite::SetScale(tagRECT param_1) {
	scale.x = param_1.bottom;
}

/* 10063AB0-10063FB1 00501	*/
int cMagSprite::AddTexture(char* param_1) {
	DataLog("[TEXTURE]:%s", param_1);
	if (d3dxSprite == NULL) {
		D3DXCreateSprite(cMagEngineMgr::getInstance()->engine, &d3dxSprite);
	}
	char* dataPath = cMagEngineMgr::getInstance()->gameObject->dataPath;
	char local_12c[300];
	if (dataPath != NULL) {
		sprintf(local_12c, "%s%s", dataPath, param_1);
	} else {
		sprintf(local_12c, "%s", param_1);
	}
	FileLog("Create sprite: %s", local_12c);
	D3DXIMAGE_INFO local_3dc;
	HRESULT result = D3DXCreateTextureFromFileEx(cMagEngineMgr::getInstance()->engine, local_12c, 
	-1, -1, -1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, -1, -1, 
	D3DCOLOR_ARGB(0xff,0,0,0), &local_3dc, NULL, &gameObjectTexture);
	
	if (result != S_OK) {
		TextureErrorLog("can`t create sprite: %s (error)", param_1);
		D3DXCreateTextureFromFileEx(cMagEngineMgr::getInstance()->engine, "data\\interface\\red.png", 
		-1, -1, -1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, -1, -1, 
		D3DCOLOR_ARGB(0xff,0,0,0), &local_3dc, NULL, &gameObjectTexture);
	}
	DebugLog("SpriteSize w: %d  h: %d", local_3dc.Width, local_3dc.Height);
	SubSpriteData local_3c0;
	local_3c0.unk_38.x = local_3dc.Width;
	local_3c0.unk_38.y = local_3dc.Height;
	int iVar4 = -1;
	if (subSprites.size() > 0) {
		iVar4 = subSprites[subSprites.size()-1].texID;
		if (iVar4 == -1) {
			iVar4 = 0;
		}
	}
	ZeroMemory(&local_3c0, sizeof(SubSpriteData));
	local_3c0.texture = gameObjectTexture;
	local_3c0.unk_40 = D3DXVECTOR2(0.0f, 0.0f);
	local_3c0.unk_48 = D3DXVECTOR2(1.0f, 1.0f);
	local_3c0.unk_64.bottom = local_3dc.Height;
	local_3c0.unk_64.right = local_3dc.Width;
	local_3c0.texID = iVar4+1;
	local_3c0.unk_64.top = 0;
	local_3c0.unk_58 = 0.0f;
	local_3c0.unk_5c = D3DXVECTOR2(0.0f, 0.0f);
	local_3c0.unk_74 = 1.0f;
	local_3c0.shouldCheckMouse = false;
	local_3c0.unk_34 = false;
	local_3c0.shouldHideRender = false;
	local_3c0.shouldShowText = false;
	DebugLog("id: %d", local_3c0.texID);
	strcpy(local_3c0.texturePath, param_1);
	subSprites.push_back(local_3c0);

	return local_3c0.texID;
}

/* 10063FC0-10064237 00277	*/
void cMagSprite::Top(int param_1) {
	if (param_1 < 0) {
		param_1 = 0;
	}
}

/* 10064240-100644C9 00289	*/
void cMagSprite::Bottom(int param_1) {
}

/* 100644D0-1006463F 0016F	*/
void cMagSprite::SetRotate(int param_1, float param_2, D3DXVECTOR2 param_3) {
	float local_4 = param_3.y;
	float local_8 = param_3.x;

}

/* 10064640-1006479E 0015E	*/
void cMagSprite::SetPos(int param_1, float param_2, float param_3, int param_4) {
}

/* 100647A0-10064841 000A1	*/
D3DXVECTOR2 cMagSprite::GetPos(int param_1) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1) {
			return D3DXVECTOR2(subSprites[index].unk_40.x + subSprites[index].unk_48.x * subSprites[index].unk_38.x / 2.0f,
				subSprites[index].unk_40.y + subSprites[index].unk_48.y * subSprites[index].unk_38.y / 2.0f );
		}
	} 
	return D3DXVECTOR2(0.0f, 0.0f);
}

/* 10064850-100648D7 00087	*/
D3DXVECTOR2 cMagSprite::GetSize(int param_1) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1) {
			return subSprites[index].unk_38;
		}
	} 
	return D3DXVECTOR2(-999999.0f, -999999.0f);
}

/* 100648E0-10064A63 00183	*/
void cMagSprite::SetScale(int param_1, float param_2, float param_3) {
}

/* 10064A70-10064AF7 00087	*/
D3DXVECTOR2 cMagSprite::GetScale(int param_1) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1) {
			return subSprites[index].unk_48;
		}
	} 
	return D3DXVECTOR2(0.0f, 0.0f);
}

/* 10064B00-10064B63 00063	*/
void cMagSprite::Show(int param_1) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1) {
			subSprites[index].shouldShowText = true;
			return;
		}
	} 
}

/* 10064B70-10064BD3 00063	*/
void cMagSprite::Hide(int param_1) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1) {
			subSprites[index].shouldShowText = false;
			return;
		}
	} 
}

/* 10064BE0-10064C46 00066	*/
void cMagSprite::HideRender(int param_1, bool param_2) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1) {
			subSprites[index].shouldHideRender = param_2;
			return;
		}
	} 
}

/* 10064C50-10064EB8 00268	*/
void cMagSprite::RenderSprites() {
}

/* 10064EC0-10064F26 00066	*/
void cMagSprite::SetAlpha(int param_1, float param_2) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1) {
			subSprites[index].unk_74 = param_2;
			return;
		}
	} 
}

/* 10064F30-10064F99 00069	*/
void cMagSprite::EnableCheckMouse(int param_1, bool param_2) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1) {
			subSprites[index].shouldCheckMouse = param_2;
			return;
		}
	} 
}

/* 10064FA0-10065127 00187	*/
void cMagSprite::CheckMouseRegion() {
}

/* 10065130-100651E7 000B7	*/
void cMagSprite::SetScaleAsWindow(int param_1) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1) {
			float temp1 = GetWindowWidth() / subSprites[index].unk_38.x;
			float temp2 = GetWindowHeight() / subSprites[index].unk_38.y;
			subSprites[index].unk_48 = D3DXVECTOR2(temp1, temp2);
			return;
		}
	} 
}

/* 100651F0-1006524B 0005B	*/
int cMagSprite::GetMouseActivateSprite() {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].unk_06 == true && subSprites[index].shouldShowText == true) {
			return index;
		}
	} 
	return 0;
}

/* 10065250-100652CF 0007F	*/

void cMagSprite::TexFromDigit(int param_1, int param_2, int param_3, int param_4, Rect& param_5) {
	param_5.unk_04 = (param_1 / param_2) * param_4;
	param_5.unk_00 = param_1 * param_3;
	param_5.unk_08 = (param_1 + 1) * param_3;
	param_5.unk_0c = (param_1 / param_2 + 1) * param_4;
}

/* 100652D0-100653D7 00107	*/
void cMagSprite::CutFrame(int param_1, int param_2, int param_3, int param_4, Rect& param_5) {
}

/* 100653E0-10065481 000A1	*/
void cMagSprite::SetTextureRect(int param_1, Rect param_2) {
	for (int index = 0; index < subSprites.size(); index++) {
		if (subSprites[index].texID == param_1) {
			subSprites[index].unk_64.left = param_2.unk_00;
			subSprites[index].unk_64.top = param_2.unk_04;
			subSprites[index].unk_64.right = param_2.unk_08;
			subSprites[index].unk_64.bottom = param_2.unk_0c;
		}
	} 
}

/* 10065490-10065701 00271	*/
_D3DMATRIX* cMagSprite::BuildMatrix(_D3DMATRIX* param_1, D3DXVECTOR2* param_2, D3DXVECTOR2* param_3, float param_4) {
	return 0;
}

/* 10065710-100657C4 000B4	*/
void cMagSprite::TransformVertices(D3DTLVERTEXS* const param_1, D3DXVECTOR2* param_2, D3DXVECTOR2* param_3, float param_4) {
	D3DXMATRIX local_40;
	BuildMatrix(&local_40, param_2, param_3, param_4);
}

/* 100657D0-10065922 00152	*/
void cMagSprite::Blit(IDirect3DDevice8* param_1, IDirect3DTexture8* param_2, tagPOINT* param_3, D3DXVECTOR2* param_4, D3DXVECTOR2* param_5, float param_6, ulong param_7) {
}

/* 10065930-10065933 00003	*/
void cMagSprite::BlitX(IDirect3DDevice8* param_1, IDirect3DTexture8* param_2, tagPOINT* param_3, ulong param_4, float param_5, float param_6) {
}

/* 10065930-10065933 00003	*/
void cMagSprite::InitSpriteAnim(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
}

/* 10065940-1006594F 0000F	*/
void cMagSprite::CreateSurfaceFromFile(IDirect3DDevice8* param_1, IDirect3DSurface8** param_2, char* const param_3, ulong param_4) {
	GetObjectParam();
}

/* 10065950-1006598C 0003C	*/
void cMagSprite::CreateTextureFromSurface(IDirect3DDevice8* param_1, IDirect3DSurface8* param_2, tagRECT* param_3, IDirect3DTexture8** param_4) {
}

/* 10065990-10065A00 00070	*/
void cMagSprite::LoadSprite(char* param_1) {
	tagRECT local_10;
	local_10.left = 0;
	local_10.top = 0;
	local_10.right = 100;
	local_10.bottom = 100;
	IDirect3DSurface8* surface;
	CreateSurfaceFromFile(cMagEngineMgr::getInstance()->engine, &surface, param_1, D3DCOLOR_ARGB(0xff,0,0,0));
	CreateTextureFromSurface(cMagEngineMgr::getInstance()->engine, surface, &local_10, &testTexture);
	surface->Release();
}

/* 10065A00-10065A37 00037	*/
void cMagSprite::RenderTestSprite() {
	tagPOINT local_8;
	local_8.x = 144;
	local_8.y = 32;
	BlitX(cMagEngineMgr::getInstance()->engine, testTexture, &local_8, -1, 0.0f, 0.0f);
}

/* 10065A40-10065A86 00046	*/
long cMagSprite::LoadMovie(char* param_1) {
	IDirect3DDevice8* engine = cMagEngineMgr::getInstance()->engine;
	if (teksturyVideo.UtworzZPlikuAVI(engine, param_1) < S_OK) {
		return FALSE;
	}

	if (UtworzBuforDuszkow() < S_OK) {
		return FALSE;
	}
	unk_1724 = true;
	return true;
}

/* 10065A90-10065BCC 0013C	*/
long cMagSprite::UtworzBuforDuszkow() {
	return 0;
}

/* 10065BD0-10065D05 00135	*/
long cMagSprite::CreatePlane(char* param_1) {
	return 0;
}

/* 10065D10-1006601C 0030C	*/
void cMagSprite::RenderPlane() {
	if (!unk_1738) {
		return;
	}
	D3DXMATRIX local_80;
	D3DXMatrixOrthoLH(&local_80, 1.0f, 1.0f, 0.0f, 100.0f);
	D3DXMATRIX local_170;
	D3DXMatrixIdentity(&local_170);

	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_PROJECTION, &local_80);
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_VIEW, &local_170);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_LIGHTING, FALSE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_CULLMODE, TRUE);
	D3DXMatrixTranslation(&unk_1664, 0.0f, 0.0f, 0.0f);
	D3DXMatrixRotationZ(&unk_16a4, 0.0f);
	D3DXMatrixScaling(&unk_16e4, 1.0f, 1.0f, 1.0f);
	D3DXMATRIX temp1;
	D3DXMatrixMultiply(&temp1, &unk_16e4, &unk_16a4);
	D3DXMATRIX DStack_130 = temp1;
	D3DXMATRIX DStack_f0;
	D3DXMatrixMultiply(&DStack_f0, &DStack_130, &unk_1664);
	D3DXMATRIX temp2 = DStack_f0;
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_WORLD, &temp2);
	if (srcBlend == 1 || destBlend == 1) {
		MagTextureMgr::getInstance()->BeginAlphaTexture();
	} else {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_SRCBLEND, srcBlend);
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_DESTBLEND, destBlend);
	}
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHAREF, 2);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_LIGHTING, TRUE);
	if (texture != NULL) {
		cMagEngineMgr::getInstance()->engine->SetTexture(0, texture);
	}
	cMagEngineMgr::getInstance()->engine->SetVertexShader(D3DFVF_TEX1 | D3DFVF_DIFFUSE | D3DFVF_XYZ);
	cMagEngineMgr::getInstance()->engine->SetStreamSource(0, vertexBuffer, 0x18);
	cMagEngineMgr::getInstance()->engine->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

/* 10066020-10066137 00117	*/
void cMagSprite::RysujDuszkiEx(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6) {
	D3DXMatrixTranslation(&unk_1664, param_1, param_2, param_3);
	D3DXMatrixRotationZ(&unk_16a4, param_4);
	D3DXMatrixScaling(&unk_16e4, param_5, param_6, 1.0f);
	
	D3DXMATRIX local_80;
	D3DXMatrixMultiply(&local_80, &unk_16e4, &unk_16a4);
	D3DXMATRIX DStack_100 = local_80;
	D3DXMATRIX DStack_c0;
	D3DXMatrixMultiply(&DStack_c0, &DStack_100, &unk_1664);
	D3DXMATRIX DStack_40 = DStack_c0;
	
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_WORLD, &DStack_40);
	cMagEngineMgr::getInstance()->engine->SetVertexShader(D3DFVF_TEX1 | D3DFVF_DIFFUSE | D3DFVF_XYZ);
	cMagEngineMgr::getInstance()->engine->SetStreamSource(0, vertexBuffer, 0x18);
	cMagEngineMgr::getInstance()->engine->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

/* g10066140-10066157 00017	*/
void cMagSprite::SetScaleMovie(float param_1, float param_2) {
	movieScaleX = param_1;
	movieScaleY = param_2;
}

/* 10066160-1006616D 0000D	*/
void cMagSprite::SetRotateMovie(float param_1) {
	rotationMovie = param_1;
}

