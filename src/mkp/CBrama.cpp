#include "CBrama.h"

/* 4164E0-4164E3 00003	*/
void CBrama::OnCollisionObject(cMagMeshObject *param_1)
{
}

/* 419BA0-419BA1 00001	*/
void CBrama::OnFrame()
{
}

/* 41A860-41A8A3 00043	*/
CBrama::CBrama()
{
	unk_2748 = 0;
	unk_274c = false;
	unk_274d = false;
	ZeroMemory(&meshData, sizeof(CBramaMeshData));
	unk_2768 = 0;
	unk_276c = false;
}

/* 41A8D0-41A8DB 0000B	*/
CBrama::~CBrama()
{
}

/* 41A8E0-41A93A 0005A	*/
void *CBrama::EXP()
{
	return new CBrama();
}

/* 41A940-41A96D 0002D	*/
void CBrama::OnActivate()
{
	unk_2734 = GetTickCount() * 0.001f;
}

/* 41A970-41AAC7 00157	*/
void CBrama::OnActivateLevel()
{
	unk_2750 = GetPosition();
	unk_275c = GetPosition();
	if (meshData.fWysokosc <= 0.0f)
	{
		meshData.fWysokosc = 350.0f;
	}
	if (meshData.fPredkosc <= 0.0f)
	{
		meshData.fPredkosc = 500.0f;
	}
	EnableFrustumPhysicsPause(false);
	if (meshData.SoundRangesMin == 0)
	{
		meshData.SoundRangesMin = 500;
	}
	if (meshData.SoundRangesMax == 0)
	{
		meshData.SoundRangesMax = 3000;
	}
	if (meshData.SoundName[0] != NULL)
	{
		unk_2768 = LoadSound(meshData.SoundName);
		StopSound(unk_2768);
		SetVolume(unk_2768, 1.0f);
		SetDefaultSoundRanges(unk_2768, meshData.SoundRangesMin, meshData.SoundRangesMax);
		StopSound(unk_2768);
		unk_276c = true;
	}

	if (stateObject->unkn_08 != 1)
	{
		stateObject->unkn_0c = 1;
		stateObject->unkn_10 = true;
	}
}

/* 41AAD0-41AAF1 00021	*/
void CBrama::OnCrash()
{
	if (stateObject->unkn_08 != 1) {
		stateObject->unkn_0c = 1;
		stateObject->unkn_10 = true;
	}
}

/* 41AB00-41AEEF 003EF	*/
bool CBrama::OnProcessStateMachine(StateObject_Str *param_1, int param_2, MsgObject *param_3)
{
	bool res;
	if (param_2 == 0) {
		res = param_3->unkn_00 == 1;
	} else if (param_2 == 1) {
		if (param_3->unkn_00 == 1) {
			SetSpeedValue(100.0f);
			unk_2750 = GetPosition();
			return true;
		}

		if (param_3->unkn_00 == 3) {
			if (meshData.RuchWPoziomie != 0) {
				SetSpeed(GetRight() * meshData.fPredkosc);
			} else {
				SetSpeed(GetUp() * meshData.fPredkosc);
			}
			D3DXVECTOR3 diff = GetPosition() - unk_2750;
			if (meshData.fWysokosc < D3DXVec3Length(&diff)) {
				SetSpeedValue(0.0f);
				if (param_1->unkn_08 != 2)
				{
					param_1->unkn_0c = 2;
					param_1->unkn_10 = true;
				}
			}
			return true;
		}
		res = param_3->unkn_00 == 2;
	} else if (param_2 == 2) {
		if (param_3->unkn_00 == 1)
		{
			SetSpeedValue(100.0f);
			unk_2750 = GetPosition();
			if (unk_276c)
			{
				PlaySoundA(unk_2768, false);
			}
			return true;
		}
		if (param_3->unkn_00 == 3)
		{
			if (meshData.RuchWPoziomie != 0)
			{
				SetSpeed(-GetRight() * meshData.fPredkosc);
			}
			else
			{
				SetSpeed(-GetUp() * meshData.fPredkosc);
			}
			D3DXVECTOR3 diff = GetPosition() - unk_2750;
			if (meshData.fWysokosc < D3DXVec3Length(&diff))
			{
				SetPosition(unk_275c);
				SetSpeedValue(0.0f);
				SetPosition(unk_275c);
				if (param_1->unkn_08 != 1)
				{
					param_1->unkn_0c = 1;
					param_1->unkn_10 = true;
				}
			}
			return true;
		}
		res = param_3->unkn_00 == 2;
	} else if (param_2 == 4) {
		res = param_3->unkn_00 == 1;
	} else {
		return false;
	}

	return res;
}

/* 41AEF0-41AF1A 0002A	*/
void CBrama::OnLoadChunk(_ED_CHUNK param_1, std::ifstream &param_2)
{
	if (param_1.chunkType == 15 && param_1.chunkDataSize == sizeof(CBramaMeshData))
	{
		param_2.read((char *)&meshData, sizeof(CBramaMeshData));
	}
}
