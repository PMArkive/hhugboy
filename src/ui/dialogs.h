/*
   hhugboy Game Boy emulator
   copyright 2013 taizou

   Based on GEST
   Copyright (C) 2003-2010 TM

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef DIALOGS_H
#define DIALOGS_H

#define ID_F_DIALOG 701
#define ID_F_SAVE 702
#define ID_F_STATE 703

#define ID_CHT_DIALOG 711
#define ID_CHT_CHEATS 712
#define ID_CHT_ADD    713
#define ID_CHT_ADDBTN 714
#define ID_CHT_RMVBTN 715

#define ID_CTRL_DIALOG 720
#define ID_CTRL_A      721
#define ID_CTRL_B      722
#define ID_CTRL_START  723
#define ID_CTRL_SELECT 724
#define ID_CTRL_AUTO_A 725
#define ID_CTRL_AUTO_B 726
#define ID_CTRL_AUTO_START 727
#define ID_CTRL_AUTO_SELECT 728
#define ID_CTRL_UP     729
#define ID_CTRL_DOWN   730
#define ID_CTRL_LEFT   731
#define ID_CTRL_RIGHT  732
#define ID_CTRL_L      733
#define ID_CTRL_R      734
#define ID_CTRL_SPEEDUP 735

#define ID_SENSOR_LEFT   736
#define ID_SENSOR_RIGHT  737
#define ID_SENSOR_UP     738
#define ID_SENSOR_DOWN   739

#define ID_CTRL_CLEAR  742

#define ID_CTRLMULTI_DIALOG 750

#define ID_SENSOR_DIALOG 745

#define ID_CTRLJOY_DIALOG 790
#define ID_CTRLJOY_A      791
#define ID_CTRLJOY_B      792
#define ID_CTRLJOY_START  793
#define ID_CTRLJOY_SELECT 794
#define ID_CTRLJOY_AUTO_A 795
#define ID_CTRLJOY_AUTO_B 796

#define ID_DEBUG_DIALOG 768
#define ID_DEBUG_LOG 769
#define ID_DEBUG_LOG_CHECKBOX 770

#define WIN32_LEAN_AND_MEAN
#define UNICODE

bool DoFileOpen(HWND hwnd,int gb_number);
BOOL CALLBACK NetplayProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DebugLogProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK FolderProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ChtProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);
VOID CALLBACK TProc(HWND hwnd,UINT uMsg,UINT idEvent,DWORD dwTime);
BOOL CALLBACK CtrlProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam); 
BOOL CALLBACK MultiCtrlProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam); 
BOOL CALLBACK SensorProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam); 
BOOL CALLBACK JoyCtrlProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);
void addDebugLogMessage(const wchar_t* message);

#endif
