#include "cMagFx.h"

#include "cMagEngineMgr.h"

/* 10077490-100777A7 00317	*/
cMagFx::cMagFx() {
	SetClassName("cMagFx");
	D3DXMatrixIdentity(&temporaryMatrix);
	D3DXMatrixIdentity(&unkn_fec);
	D3DXMatrixIdentity(&unkn_eec);
	D3DXMatrixIdentity(&positionMatrix);
	D3DXMatrixIdentity(&scaleMatrix);
	position = D3DXVECTOR3(0,0,0);
	scale = D3DXVECTOR3(0,0,0);
	unkn_102c = false;
	unkn_1030 = 0.0f;
	unkn_1034 = 0.0f;
	unkn_1038 = FALSE;
	timerInitialized = FALSE;
	usingQPF = FALSE;
	ticksPerSec = 0;
	llStopTime = 0;
	llLastElapsedTime = 0;
	llBaseTime = 0;
	lastElapsedTime = 0;
	baseTime = 0;
	stopTime = 0;
}

/* 100777B0-100777BB 0000B	*/
cMagFx::~cMagFx() {
}

/* 100777C0-10077845 00085	*/
void cMagFx::SetPosition(D3DXVECTOR3 param_1) {
	this->position = param_1;
	D3DXMatrixIdentity(&this->temporaryMatrix);
	D3DXMatrixTranslation(&this->temporaryMatrix, this->position.x, this->position.y, this->position.z);
	this->positionMatrix = this->temporaryMatrix;
}

/* 10077850-100778D5 00085	*/
void cMagFx::SetScale(D3DXVECTOR3 param_1) {
	this->scale = param_1;
	D3DXMatrixIdentity(&this->temporaryMatrix);
	D3DXMatrixTranslation(&this->temporaryMatrix, this->scale.x, this->scale.y, this->scale.z);
	this->scaleMatrix = this->temporaryMatrix;
}

/* 100778E0-1007793B 0005B	*/
void cMagFx::AddTexture(char* param_1) {
	strcpy(this->shockwaveName, param_1);
	RestoreDeviceObjects(param_1, 10.0f, 5.0f, 32, 30.1f, 1.0f);
	this->unkn_102c = true;
}

/* 10077940-10077963 00023	*/
void cMagFx::Restore() {
	RestoreDeviceObjects(shockwaveName, 10.0f, 5.0f, 32, 30.1f, 1.0f);
}

/* 10077970-10077BAC 0023C	*/
void cMagFx::OnRender() {
	if (!this->unkn_102c) {
		return;
	}

	D3DXMATRIX worldMatrix;
	D3DXMatrixIdentity(&worldMatrix);

	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_WORLD, &worldMatrix);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_DESTALPHA);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	Pos() = this->position;
	float appTime = DXUtil_Timer(TIMER_COMMAND::TIMER_GETAPPTIME);
	unkn_1034 = DXUtil_Timer(TIMER_COMMAND::TIMER_GETELAPSEDTIME);
	unkn_1030 = appTime;
	if (unkn_1034 < 0.001f) {
		unkn_1034 = 0.001f;
	}
	ShockwaveUpdate(unkn_1034);
	ShockwaveRender();
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

/* 10077BB0-10077EAD 002FD	*/
float cMagFx::DXUtil_Timer(TIMER_COMMAND param_1) {
    // Initialize the timer
    if (FALSE == timerInitialized) {
        timerInitialized = TRUE;
        LARGE_INTEGER qwTicksPerSec;
        usingQPF = QueryPerformanceFrequency(&qwTicksPerSec);
        if (usingQPF) {
			ticksPerSec = qwTicksPerSec.QuadPart;
		}
    }

    if (usingQPF) {
        double fTime;
        double fElapsedTime;
        LARGE_INTEGER qwTime;
        
        // Get either the current time or the stop time, depending
        // on whether we're stopped and what command was sent
        if(llStopTime != 0 && param_1 != TIMER_START && param_1 != TIMER_GETABSOLUTETIME) {
            qwTime.QuadPart = llStopTime;
		} else {
            QueryPerformanceCounter(&qwTime);
		}

        // Return the elapsed time
        if (param_1 == TIMER_GETELAPSEDTIME)
        {
            fElapsedTime = (double) (qwTime.QuadPart - llLastElapsedTime) / (double) ticksPerSec;
            llLastElapsedTime = qwTime.QuadPart;
            return (FLOAT) fElapsedTime;
        }
    
        // Return the current time
        if (param_1 == TIMER_GETAPPTIME)
        {
            double fAppTime = (double) ( qwTime.QuadPart - llBaseTime ) / (double) ticksPerSec;
            return (FLOAT) fAppTime;
        }
    
        // Reset the timer
        if (param_1 == TIMER_RESET) {
            llBaseTime = qwTime.QuadPart;
            llLastElapsedTime = qwTime.QuadPart;
            return 0.0f;
        }
    
        // Start the timer
        if (param_1 == TIMER_START) {
            llBaseTime += qwTime.QuadPart - llStopTime;
            llStopTime = 0;
            llLastElapsedTime = qwTime.QuadPart;
            return 0.0f;
        }
    
        // Stop the timer
        if (param_1 == TIMER_STOP) {
            llStopTime = qwTime.QuadPart;
            llLastElapsedTime = qwTime.QuadPart;
            return 0.0f;
        }
    
        // Advance the timer by 1/10th second
        if (param_1 == TIMER_ADVANCE) {
            llStopTime += ticksPerSec/10;
            return 0.0f;
        }

        if (param_1 == TIMER_GETABSOLUTETIME)
        {
            fTime = qwTime.QuadPart / (double) ticksPerSec;
            return (FLOAT) fTime;
        }

        return -1.0f; // Invalid command specified
    }
    else
    {
        double fTime;
        double fElapsedTime;
        
        // Get either the current time or the stop time, depending
        // on whether we're stopped and what command was sent
        if (stopTime != 0.0 && param_1 != TIMER_START && param_1 != TIMER_GETABSOLUTETIME)
            fTime = stopTime;
        else
            fTime = timeGetTime() * 0.001;
    
        // Return the elapsed time
        if (param_1 == TIMER_GETELAPSEDTIME) {   
            fElapsedTime = (double) (fTime - lastElapsedTime);
            lastElapsedTime = fTime;
            return (FLOAT) fElapsedTime;
        }
    
        // Return the current time
        if (param_1 == TIMER_GETAPPTIME) {
            return (FLOAT) (fTime - baseTime);
        }
    
        // Reset the timer
        if (param_1 == TIMER_RESET) {
            baseTime         = fTime;
            lastElapsedTime  = fTime;
            return 0.0f;
        }
    
        // Start the timer
        if (param_1 == TIMER_START) {
			baseTime += fTime - stopTime;
            stopTime = 0.0f;
            lastElapsedTime  = fTime;

            return 0.0f;
        }
    
        // Stop the timer
        if (param_1 == TIMER_STOP) {
            stopTime = fTime;
            return 0.0f;
        }
    
        // Advance the timer by 1/10th second
        if (param_1 == TIMER_ADVANCE) {
            stopTime += 0.1f;
            return 0.0f;
        }

        if (param_1 == TIMER_GETABSOLUTETIME){
            return (FLOAT) fTime;
        }

        return -1.0f; // Invalid command specified
    }
}

