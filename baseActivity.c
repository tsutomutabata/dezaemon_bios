#include "dezaemonSymbol.h"
#include "ioMapping.h"
#include "bios.h"
#include "baseActivity.h"
#include "launcherActivity.h"

short Init(BaseActivityWork *aw){
	return false;
}

short Update(BaseActivityWork *aw){
	NextActivity(LauncherInit,LauncherUpdate);
	return true;
}
