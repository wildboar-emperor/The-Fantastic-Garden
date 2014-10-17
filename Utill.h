#pragma once

bool RectToRectCrashCheak(RECT 대상, RECT 범위);

bool RectToRectCrashCheakForBullet(RECT b, RECT e);

bool RectToPointCrashCheak(RECT 대상, RECT 범위);

void println(char *chString, ...);

RECT newRECT(long left, long top, long right, long bottom);