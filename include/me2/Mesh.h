#ifndef _MESH
#define _MESH

#include <globals.h>

#include <vector>
#include <d3dx8.h>

struct DLLEXPORT Mesh {
public:

private:
	/* 0x000 */ D3DXVECTOR3 unk_00;
	/* 0x00c */ char unk_0c[255];
	/* 0x10c */ int unk_10c;
	/* 0x110 */ std::vector<D3DXVECTOR3> unk_110;
	/* 0x120 */ int unk_120;
	/* 0x124 */ std::vector<D3DXVECTOR3> unk_124;
	/* 0x134 */ std::vector<int> unk_134;
	/* 0x144 */ std::vector<D3DXVECTOR3> unk_144;
	/* 0x154 */ std::vector<D3DXVECTOR3> unk_154;
	/* 0x164 */ int unk_164;
	/* 0x168 */ std::vector<D3DXVECTOR3> unk_168;
	/* 0x178 */ int unk_178;
	/* 0x17c */ std::vector<D3DXVECTOR2> unk_17c;
	/* 0x18c */ std::vector<D3DXVECTOR2> unk_18c;
	/* 0x19c */ std::vector<D3DXVECTOR3> unk_19c;
	/* 0x1ac */ std::vector<D3DXVECTOR3> unk_1ac;
	/* 0x1bc */ int unk_1bc;
	/* 0x1c0 */ std::vector<void*> unk_1c0;
	/* 0x1d0 */ std::vector<D3DXVECTOR3> unk_1d0;
	/* 0x1e0 */ std::vector<D3DXVECTOR3> unk_1e0;
	/* 0x1f0 */ int unk_1f0;

	friend class MagnumMesh;
};

STATIC_ASSERT(sizeof(Mesh) == 0x1f4);

#endif