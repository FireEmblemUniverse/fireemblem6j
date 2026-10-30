#include "chapterinfo.h"

#include "hardware.h"
#include "msg.h"
#include "save_xmap.h"
#include "gbasram.h"

struct ChapterInfo const * GetChapterInfo(int chapter)
{
    if (chapter < 0)
        return gExtraMapInfo->chapter_info;

    return ChapterInfoTable + chapter;
}

u8 const * GetChapterMap(int chapter)
{
    if (chapter >= 0)
        return ChapterAssets[GetChapterInfo(chapter)->asset_map];

    ReadSramFast(GetExtraMapMapReadAddr(), gBuf, GetExtraMapMapSize());
    return gBuf;
}

struct MapChangeInfo const * GetChapterMapChanges(int chapter)
{
    if (chapter >= 0)
        return ChapterAssets[GetChapterInfo(chapter)->asset_map_changes];

    return gExtraMapInfo->map_change_info;
}

struct ChapterEventInfo const * GetChapterEventInfo(int chapter)
{
    if (chapter >= 0)
        return ChapterAssets[GetChapterInfo(chapter)->asset_event_info];

    return gExtraMapInfo->event_info;
}

char const * GetChapterTitle(int chapter)
{
    if (chapter >= 0)
        return DecodeMsg(GetChapterInfo(chapter)->msg_chapter_title);

    return gExtraMapInfo->msg_0C;
}
