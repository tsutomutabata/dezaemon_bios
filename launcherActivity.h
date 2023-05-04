#ifndef _LAUNCHER_ACTIVITY_H
#define _LAUNCHER_ACTIVITY_H


typedef struct {
	void *InitAddr;
	void *UpdateAddr;
} Launcher;

typedef struct {
	short		Select;	
	Launcher	Menu[8];
} LauncherActivityWork;


short LauncherInit(LauncherActivityWork *aw);
short LauncherUpdate(LauncherActivityWork *aw);

#endif