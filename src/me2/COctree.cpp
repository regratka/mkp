#include "COctree.h"

/* 10003EF0-10003F60 00070	*/
COctree::COctree(COctree* param_1) {
}

/* 10003F60-10003FD2 00072	*/
COctree* COctree::operator=(COctree* param_1) {
	return 0;
}

/* 10003FE0-10004034 00054	*/
COctree* COctree::scalar_destructor(uchar param_1) {
	return 0;
}

/* 100B6760-100B67B1 00051	*/
COctree::COctree() {
}

/* 100B67C0-100B67C7 00007	*/
COctree::~COctree() {
}

/* 100B67D0-100B6812 00042	*/
void COctree::Create(D3DXVECTOR3* param_1, int param_2) {
}

/* 100B6820-100B685D 0003D	*/
void COctree::Release() {
}

/* 100B6860-100B69B9 00159	*/
void COctree::SetData(D3DXVECTOR3* param_1, int param_2) {
}

/* 100B69C0-100B6FD5 00615	*/
void COctree::CreateNode(D3DXVECTOR3* param_1, int param_2, D3DXVECTOR3 param_3, float param_4) {
}

/* 100B6FE0-100B7151 00171	*/
void COctree::CreateNodeEnd(D3DXVECTOR3* param_1, int param_2, bool* param_3, D3DXVECTOR3 param_4, float param_5, int param_6, COctreeSegment param_7) {
}

/* 100B7160-100B7372 00212	*/
D3DXVECTOR3* COctree::GetNodeCenter(D3DXVECTOR3* param_1, D3DXVECTOR3 param_2, float param_3, COctreeSegment param_4) {
	return 0;
}

/* 100B73A0-100B7410 00070	*/
void COctree::SetNode(D3DXVECTOR3* param_1, int param_2) {
}

/* 100B7410-100B764F 0023F	*/
void COctree::CreateVertexBuffer(IDirect3DDevice8* param_1) {
}

/* 100B7650-100B7823 001D3	*/
void COctree::Render(COctree* param_1) {
}

/* 100B7830-100B7C2A 003FA	*/
void COctree::RenderOctree(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uint param_10, uint param_11) {
}

/* 100B7C30-100B7C51 00021	*/
float COctree::abs_f(float param_1) {
	return 0;
}

/* 100B7C60-100B7C63 00003	*/
void COctree::triangle(uchar param_1, float* param_2, float* param_3, float* param_4, uchar param_5) {
}

/* 100B7C70-100B8168 004F8	*/
void COctree::wire_cube(uchar param_1, float* param_2, float* param_3, uchar param_4) {
}

