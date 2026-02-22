#ifndef _MAG_GRID
#define _MAG_GRID

#include <globals.h>
#include <d3d8.h>

class MagGrid {
public:
	/* 10001D80 */ long Restore();
	/* 10001D90 */ long Invalidate();
	/* 10001DC0 */ MagGrid(MagGrid* param_1);
	/* 10001E20 */ MagGrid* operator=(MagGrid* param_1);
	/* 10001E70 */ MagGrid* scalar_destructor(uchar param_1);
	/* 1002E5B0 */ MagGrid();
	/* 1002E5F0 */ ~MagGrid();
	/* 1002E630 */ long Create(int param_1, int param_2, float param_3);
	/* 1002E650 */ long InitDeviceObjects(IDirect3DDevice8* param_1);
	/* 1002E670 */ long BuildVertexBuffer();
	/* 1002E9C0 */ long Render();
};

#endif