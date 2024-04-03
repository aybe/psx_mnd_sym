// size: 0x2
struct HL {
    // offset: 0000
    unsigned char LByte;
    // offset: 0001
    unsigned char HByte;
};

// size: 0x2C
struct LoadFiles {
    // offset: 0000
    unsigned char FName[28];
    // offset: 001C
    void **Start;
    // offset: 0020
    void **SEnd;
    // offset: 0024
    unsigned long SLength;
    // offset: 0028
    unsigned short Flags;
    // offset: 002A
    unsigned short Spare;
};

// size: 0x8
struct Sprite {
    // offset: 0000
    unsigned char X;
    // offset: 0001
    unsigned char Y;
    // offset: 0002
    unsigned short Page;
    // offset: 0004
    unsigned char SWidth;
    // offset: 0005
    unsigned char SHeight;
    // offset: 0006
    unsigned short Clut;
};

// size: 0xA
struct Element {
    // offset: 0000
    unsigned short ToSprite;
    // offset: 0002
    short X;
    // offset: 0004
    short Y;
    // offset: 0006
    unsigned short Flags;
    // offset: 0008
    unsigned short Next;
};

// size: 0x8
struct Frame {
    // offset: 0000
    unsigned short FirstElement;
    // offset: 0002
    unsigned char SWidth;
    // offset: 0003
    unsigned char SHeight;
    // offset: 0004
    unsigned char FX;
    // offset: 0005
    unsigned char Flags;
    // offset: 0006
    unsigned short Next;
};

// size: 0x32
struct _0fake {
    // offset: 0000
    unsigned long MyEDI;
    // offset: 0004
    unsigned long MyESI;
    // offset: 0008
    unsigned long MyEBP;
    // offset: 000C
    unsigned long MyReserved;
    // offset: 0010
    unsigned long MyEBX;
    // offset: 0014
    unsigned long MyEDX;
    // offset: 0018
    unsigned long MyECX;
    // offset: 001C
    unsigned long MyEAX;
    // offset: 0020
    unsigned short MyFlags;
    // offset: 0022
    unsigned short MyES;
    // offset: 0024
    unsigned short MyDS;
    // offset: 0026
    unsigned short MyFS;
    // offset: 0028
    unsigned short MyGS;
    // offset: 002A
    unsigned short MyIP;
    // offset: 002C
    unsigned short MyCS;
    // offset: 002E
    unsigned short MySP;
    // offset: 0030
    unsigned short MySS;
};

// size: 0x7
struct SndArray {
    // offset: 0000
    short SndFrame;
    // offset: 0002
    unsigned char SndType;
    // offset: 0003
    unsigned long SndNum;
};

// size: 0xC
struct AllocRem {
    // offset: 0000
    unsigned char *AllocPtr;
    // offset: 0004
    unsigned long AllocSize;
    // offset: 0008
    void *AllocNext;
};

// size: 0x4
struct DosTime {
    // offset: 0000
    unsigned char Hour;
    // offset: 0001
    unsigned char Minute;
    // offset: 0002
    unsigned char Second;
    // offset: 0003
    unsigned char HSecond;
};

// size: 0xE
struct MouseData {
    // offset: 0000
    short MouseX;
    // offset: 0002
    short MouseY;
    // offset: 0004
    short MouseWidth;
    // offset: 0006
    short MouseHeight;
    // offset: 0008
    unsigned char *Buffer;
    // offset: 000C
    short MouseBufferWidth;
};

// size: 0x10
struct MouseBuffer {
    // offset: 0000
    short MouseX;
    // offset: 0002
    short MouseY;
    // offset: 0004
    short MouseWidth;
    // offset: 0006
    short MouseHeight;
    // offset: 0008
    unsigned char *Buffer;
    // offset: 000C
    unsigned long MemOffset;
};

// size: 0x3
struct Colour {
    // offset: 0000
    unsigned char Red;
    // offset: 0001
    unsigned char Green;
    // offset: 0002
    unsigned char Blue;
};

// size: 0xC
struct SpriteData {
    // offset: 0000
    struct Sprite *Sprites;
    // offset: 0004
    struct Sprite *EndSprites;
    // offset: 0008
    unsigned long Data;
};

// size: 0x4
struct _physadr {
    // offset: 0000
    int r[1];
};

// size: 0x30
struct label_t {
    // offset: 0000
    int val[12];
};

// size: 0x8
struct _quad {
    // offset: 0000
    long val[2];
};

// size: 0x1E
struct _1fake {
    // offset: 0000
    short m[3][3];
    // offset: 0012
    long t[3];
};

// size: 0x10
struct _2fake {
    // offset: 0000
    long vx;
    // offset: 0004
    long vy;
    // offset: 0008
    long vz;
    // offset: 000C
    long pad;
};

// size: 0x8
struct _3fake {
    // offset: 0000
    short vx;
    // offset: 0002
    short vy;
    // offset: 0004
    short vz;
    // offset: 0006
    short pad;
};

// size: 0x4
struct _4fake {
    // offset: 0000
    unsigned char r;
    // offset: 0001
    unsigned char g;
    // offset: 0002
    unsigned char b;
    // offset: 0003
    unsigned char cd;
};

// size: 0x4
struct _5fake {
    // offset: 0000
    short vx;
    // offset: 0002
    short vy;
};

// size: 0x2C
struct _6fake {
    // offset: 0000
    struct _3fake v;
    // offset: 0008
    struct _2fake sxyz;
    // offset: 0018
    struct _5fake sxy;
    // offset: 001C
    struct _4fake rgb;
    // offset: 0020
    short txuv;
    // offset: 0022
    short pad;
    // offset: 0024
    long chx;
    // offset: 0028
    long chy;
};

// size: 0x18
struct _7fake {
    // offset: 0000
    struct _3fake v;
    // offset: 0008
    unsigned char uv[2];
    // offset: 000A
    unsigned short pad;
    // offset: 000C
    struct _4fake c;
    // offset: 0010
    struct _5fake sxy;
    // offset: 0014
    unsigned long sz;
};

// size: 0x58
struct _8fake {
    // offset: 0000
    struct _7fake r01;
    // offset: 0018
    struct _7fake r12;
    // offset: 0030
    struct _7fake r20;
    // offset: 0048
    struct _7fake *r0;
    // offset: 004C
    struct _7fake *r1;
    // offset: 0050
    struct _7fake *r2;
    // offset: 0054
    unsigned long *rtn;
};

// size: 0x218
struct _9fake {
    // offset: 0000
    unsigned long ndiv;
    // offset: 0004
    unsigned long pih;
    // offset: 0008
    unsigned long piv;
    // offset: 000C
    unsigned short clut;
    // offset: 000E
    unsigned short tpage;
    // offset: 0010
    struct _4fake rgbc;
    // offset: 0014
    unsigned long *ot;
    // offset: 0018
    struct _7fake r0;
    // offset: 0030
    struct _7fake r1;
    // offset: 0048
    struct _7fake r2;
    // offset: 0060
    struct _8fake cr[5];
};

// size: 0x8C
struct _10fake {
    // offset: 0000
    struct _7fake r01;
    // offset: 0018
    struct _7fake r02;
    // offset: 0030
    struct _7fake r31;
    // offset: 0048
    struct _7fake r32;
    // offset: 0060
    struct _7fake rc;
    // offset: 0078
    struct _7fake *r0;
    // offset: 007C
    struct _7fake *r1;
    // offset: 0080
    struct _7fake *r2;
    // offset: 0084
    struct _7fake *r3;
    // offset: 0088
    unsigned long *rtn;
};

// size: 0x334
struct _11fake {
    // offset: 0000
    unsigned long ndiv;
    // offset: 0004
    unsigned long pih;
    // offset: 0008
    unsigned long piv;
    // offset: 000C
    unsigned short clut;
    // offset: 000E
    unsigned short tpage;
    // offset: 0010
    struct _4fake rgbc;
    // offset: 0014
    unsigned long *ot;
    // offset: 0018
    struct _7fake r0;
    // offset: 0030
    struct _7fake r1;
    // offset: 0048
    struct _7fake r2;
    // offset: 0060
    struct _7fake r3;
    // offset: 0078
    struct _10fake cr[5];
};

// size: 0x10
struct _12fake {
    // offset: 0000
    short xy[3];
    // offset: 0006
    short uv[2];
    // offset: 000A
    short rgb[3];
};

// size: 0x4A
struct _13fake {
    // offset: 0000
    short sxy[4][2];
    // offset: 0010
    short sz[4][2];
    // offset: 0020
    short uv[4][2];
    // offset: 0030
    short rgb[4][3];
    // offset: 0048
    short code;
};

// size: 0x38
struct _14fake {
    // offset: 0000
    short sxy[3][2];
    // offset: 000C
    short sz[3][2];
    // offset: 0018
    short uv[3][2];
    // offset: 0024
    short rgb[3][3];
    // offset: 0036
    short code;
};

// size: 0x8
struct _15fake {
    // offset: 0000
    short x;
    // offset: 0002
    short y;
    // offset: 0004
    short w;
    // offset: 0006
    short h;
};

// size: 0x40
struct _16fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned long code[15];
};

// size: 0x5C
struct _17fake {
    // offset: 0000
    struct _15fake clip;
    // offset: 0008
    short ofs[2];
    // offset: 000C
    struct _15fake tw;
    // offset: 0014
    unsigned short tpage;
    // offset: 0016
    unsigned char dtd;
    // offset: 0017
    unsigned char dfe;
    // offset: 0018
    unsigned char isbg;
    // offset: 0019
    unsigned char r0;
    // offset: 001A
    unsigned char g0;
    // offset: 001B
    unsigned char b0;
    // offset: 001C
    struct _16fake dr_env;
};

// size: 0x14
struct _18fake {
    // offset: 0000
    struct _15fake disp;
    // offset: 0008
    struct _15fake screen;
    // offset: 0010
    unsigned char isinter;
    // offset: 0011
    unsigned char isrgb24;
    // offset: 0012
    unsigned char pad0;
    // offset: 0013
    unsigned char pad1;
};

// size: 0x24
struct _19fake {
    // offset: 0000
    unsigned int addr : 24;
    // offset: 0018
    unsigned int len : 8;
    // offset: 0020
    unsigned char r0;
    // offset: 0021
    unsigned char g0;
    // offset: 0022
    unsigned char b0;
    // offset: 0023
    unsigned char code;
};

// size: 0x4
struct _20fake {
    // offset: 0000
    unsigned char r0;
    // offset: 0001
    unsigned char g0;
    // offset: 0002
    unsigned char b0;
    // offset: 0003
    unsigned char code;
};

// size: 0x14
struct _21fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    short x1;
    // offset: 000E
    short y1;
    // offset: 0010
    short x2;
    // offset: 0012
    short y2;
};

// size: 0x18
struct _22fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    short x1;
    // offset: 000E
    short y1;
    // offset: 0010
    short x2;
    // offset: 0012
    short y2;
    // offset: 0014
    short x3;
    // offset: 0016
    short y3;
};

// size: 0x20
struct _23fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    unsigned char u0;
    // offset: 000D
    unsigned char v0;
    // offset: 000E
    unsigned short clut;
    // offset: 0010
    short x1;
    // offset: 0012
    short y1;
    // offset: 0014
    unsigned char u1;
    // offset: 0015
    unsigned char v1;
    // offset: 0016
    unsigned short tpage;
    // offset: 0018
    short x2;
    // offset: 001A
    short y2;
    // offset: 001C
    unsigned char u2;
    // offset: 001D
    unsigned char v2;
    // offset: 001E
    unsigned short pad1;
};

// size: 0x28
struct _24fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    unsigned char u0;
    // offset: 000D
    unsigned char v0;
    // offset: 000E
    unsigned short clut;
    // offset: 0010
    short x1;
    // offset: 0012
    short y1;
    // offset: 0014
    unsigned char u1;
    // offset: 0015
    unsigned char v1;
    // offset: 0016
    unsigned short tpage;
    // offset: 0018
    short x2;
    // offset: 001A
    short y2;
    // offset: 001C
    unsigned char u2;
    // offset: 001D
    unsigned char v2;
    // offset: 001E
    unsigned short pad1;
    // offset: 0020
    short x3;
    // offset: 0022
    short y3;
    // offset: 0024
    unsigned char u3;
    // offset: 0025
    unsigned char v3;
    // offset: 0026
    unsigned short pad2;
};

// size: 0x1C
struct _25fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    unsigned char r1;
    // offset: 000D
    unsigned char g1;
    // offset: 000E
    unsigned char b1;
    // offset: 000F
    unsigned char pad1;
    // offset: 0010
    short x1;
    // offset: 0012
    short y1;
    // offset: 0014
    unsigned char r2;
    // offset: 0015
    unsigned char g2;
    // offset: 0016
    unsigned char b2;
    // offset: 0017
    unsigned char pad2;
    // offset: 0018
    short x2;
    // offset: 001A
    short y2;
};

// size: 0x24
struct _26fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    unsigned char r1;
    // offset: 000D
    unsigned char g1;
    // offset: 000E
    unsigned char b1;
    // offset: 000F
    unsigned char pad1;
    // offset: 0010
    short x1;
    // offset: 0012
    short y1;
    // offset: 0014
    unsigned char r2;
    // offset: 0015
    unsigned char g2;
    // offset: 0016
    unsigned char b2;
    // offset: 0017
    unsigned char pad2;
    // offset: 0018
    short x2;
    // offset: 001A
    short y2;
    // offset: 001C
    unsigned char r3;
    // offset: 001D
    unsigned char g3;
    // offset: 001E
    unsigned char b3;
    // offset: 001F
    unsigned char pad3;
    // offset: 0020
    short x3;
    // offset: 0022
    short y3;
};

// size: 0x28
struct _27fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    unsigned char u0;
    // offset: 000D
    unsigned char v0;
    // offset: 000E
    unsigned short clut;
    // offset: 0010
    unsigned char r1;
    // offset: 0011
    unsigned char g1;
    // offset: 0012
    unsigned char b1;
    // offset: 0013
    unsigned char p1;
    // offset: 0014
    short x1;
    // offset: 0016
    short y1;
    // offset: 0018
    unsigned char u1;
    // offset: 0019
    unsigned char v1;
    // offset: 001A
    unsigned short tpage;
    // offset: 001C
    unsigned char r2;
    // offset: 001D
    unsigned char g2;
    // offset: 001E
    unsigned char b2;
    // offset: 001F
    unsigned char p2;
    // offset: 0020
    short x2;
    // offset: 0022
    short y2;
    // offset: 0024
    unsigned char u2;
    // offset: 0025
    unsigned char v2;
    // offset: 0026
    unsigned short pad2;
};

// size: 0x34
struct _28fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    unsigned char u0;
    // offset: 000D
    unsigned char v0;
    // offset: 000E
    unsigned short clut;
    // offset: 0010
    unsigned char r1;
    // offset: 0011
    unsigned char g1;
    // offset: 0012
    unsigned char b1;
    // offset: 0013
    unsigned char p1;
    // offset: 0014
    short x1;
    // offset: 0016
    short y1;
    // offset: 0018
    unsigned char u1;
    // offset: 0019
    unsigned char v1;
    // offset: 001A
    unsigned short tpage;
    // offset: 001C
    unsigned char r2;
    // offset: 001D
    unsigned char g2;
    // offset: 001E
    unsigned char b2;
    // offset: 001F
    unsigned char p2;
    // offset: 0020
    short x2;
    // offset: 0022
    short y2;
    // offset: 0024
    unsigned char u2;
    // offset: 0025
    unsigned char v2;
    // offset: 0026
    unsigned short pad2;
    // offset: 0028
    unsigned char r3;
    // offset: 0029
    unsigned char g3;
    // offset: 002A
    unsigned char b3;
    // offset: 002B
    unsigned char p3;
    // offset: 002C
    short x3;
    // offset: 002E
    short y3;
    // offset: 0030
    unsigned char u3;
    // offset: 0031
    unsigned char v3;
    // offset: 0032
    unsigned short pad3;
};

// size: 0x10
struct _29fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    short x1;
    // offset: 000E
    short y1;
};

// size: 0x14
struct _30fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    unsigned char r1;
    // offset: 000D
    unsigned char g1;
    // offset: 000E
    unsigned char b1;
    // offset: 000F
    unsigned char p1;
    // offset: 0010
    short x1;
    // offset: 0012
    short y1;
};

// size: 0x18
struct _31fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    short x1;
    // offset: 000E
    short y1;
    // offset: 0010
    short x2;
    // offset: 0012
    short y2;
    // offset: 0014
    unsigned long pad;
};

// size: 0x20
struct _32fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    unsigned char r1;
    // offset: 000D
    unsigned char g1;
    // offset: 000E
    unsigned char b1;
    // offset: 000F
    unsigned char p1;
    // offset: 0010
    short x1;
    // offset: 0012
    short y1;
    // offset: 0014
    unsigned char r2;
    // offset: 0015
    unsigned char g2;
    // offset: 0016
    unsigned char b2;
    // offset: 0017
    unsigned char p2;
    // offset: 0018
    short x2;
    // offset: 001A
    short y2;
    // offset: 001C
    unsigned long pad;
};

// size: 0x1C
struct _33fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    short x1;
    // offset: 000E
    short y1;
    // offset: 0010
    short x2;
    // offset: 0012
    short y2;
    // offset: 0014
    short x3;
    // offset: 0016
    short y3;
    // offset: 0018
    unsigned long pad;
};

// size: 0x28
struct _34fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    unsigned char r1;
    // offset: 000D
    unsigned char g1;
    // offset: 000E
    unsigned char b1;
    // offset: 000F
    unsigned char p1;
    // offset: 0010
    short x1;
    // offset: 0012
    short y1;
    // offset: 0014
    unsigned char r2;
    // offset: 0015
    unsigned char g2;
    // offset: 0016
    unsigned char b2;
    // offset: 0017
    unsigned char p2;
    // offset: 0018
    short x2;
    // offset: 001A
    short y2;
    // offset: 001C
    unsigned char r3;
    // offset: 001D
    unsigned char g3;
    // offset: 001E
    unsigned char b3;
    // offset: 001F
    unsigned char p3;
    // offset: 0020
    short x3;
    // offset: 0022
    short y3;
    // offset: 0024
    unsigned long pad;
};

// size: 0x10
struct _35fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    unsigned short x0;
    // offset: 000A
    unsigned short y0;
    // offset: 000C
    unsigned short w;
    // offset: 000E
    unsigned short h;
};

// size: 0x14
struct _36fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    unsigned char u0;
    // offset: 000D
    unsigned char v0;
    // offset: 000E
    unsigned short clut;
    // offset: 0010
    short w;
    // offset: 0012
    short h;
};

// size: 0x10
struct _37fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    unsigned char u0;
    // offset: 000D
    unsigned char v0;
    // offset: 000E
    unsigned short clut;
};

// size: 0x10
struct _38fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    unsigned char u0;
    // offset: 000D
    unsigned char v0;
    // offset: 000E
    unsigned short clut;
};

// size: 0x10
struct _39fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
    // offset: 000C
    short w;
    // offset: 000E
    short h;
};

// size: 0xC
struct _40fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
};

// size: 0xC
struct _41fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
};

// size: 0xC
struct _42fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char code;
    // offset: 0008
    short x0;
    // offset: 000A
    short y0;
};

// size: 0xC
struct _43fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned long code[2];
};

// size: 0xC
struct _44fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned long code[2];
};

// size: 0xC
struct _45fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned long code[2];
};

// size: 0xC
struct _46fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned long code[2];
};

// size: 0xC
struct _47fake {
    // offset: 0000
    unsigned long tag;
    // offset: 0004
    unsigned long code[2];
};

// size: 0x78
struct _48fake {
    // offset: 0000
    unsigned long id;
    // offset: 0004
    unsigned char r0;
    // offset: 0005
    unsigned char g0;
    // offset: 0006
    unsigned char b0;
    // offset: 0007
    unsigned char p0;
    // offset: 0008
    unsigned char r1;
    // offset: 0009
    unsigned char g1;
    // offset: 000A
    unsigned char b1;
    // offset: 000B
    unsigned char p1;
    // offset: 000C
    unsigned char r2;
    // offset: 000D
    unsigned char g2;
    // offset: 000E
    unsigned char b2;
    // offset: 000F
    unsigned char p2;
    // offset: 0010
    unsigned char r3;
    // offset: 0011
    unsigned char g3;
    // offset: 0012
    unsigned char b3;
    // offset: 0013
    unsigned char p3;
    // offset: 0014
    unsigned short tpage;
    // offset: 0016
    unsigned short clut;
    // offset: 0018
    unsigned char u0;
    // offset: 0019
    unsigned char v0;
    // offset: 001A
    unsigned char u1;
    // offset: 001B
    unsigned char v1;
    // offset: 001C
    unsigned char u2;
    // offset: 001D
    unsigned char v2;
    // offset: 001E
    unsigned char u3;
    // offset: 001F
    unsigned char v3;
    // offset: 0020
    struct _3fake x0;
    // offset: 0028
    struct _3fake x1;
    // offset: 0030
    struct _3fake x2;
    // offset: 0038
    struct _3fake x3;
    // offset: 0040
    struct _3fake n0;
    // offset: 0048
    struct _3fake n1;
    // offset: 0050
    struct _3fake n2;
    // offset: 0058
    struct _3fake n3;
    // offset: 0060
    struct _3fake *v_ofs;
    // offset: 0064
    struct _3fake *n_ofs;
    // offset: 0068
    unsigned short vert0;
    // offset: 006A
    unsigned short vert1;
    // offset: 006C
    unsigned short vert2;
    // offset: 006E
    unsigned short vert3;
    // offset: 0070
    unsigned short norm0;
    // offset: 0072
    unsigned short norm1;
    // offset: 0074
    unsigned short norm2;
    // offset: 0076
    unsigned short norm3;
};

// size: 0x14
struct _49fake {
    // offset: 0000
    unsigned long mode;
    // offset: 0004
    struct _15fake *crect;
    // offset: 0008
    unsigned long *caddr;
    // offset: 000C
    struct _15fake *prect;
    // offset: 0010
    unsigned long *paddr;
};

// size: 0x26
struct _GsCOORDINATE {
    // offset: 0000
    long rx;
    // offset: 0004
    long ry;
    // offset: 0008
    long rz;
    // offset: 000C
    short sx;
    // offset: 000E
    short sy;
    // offset: 0010
    short sz;
    // offset: 0012
    long tx;
    // offset: 0016
    long ty;
    // offset: 001A
    long tz;
    // offset: 001E
    struct _GsCOORDINATE *super;
    // offset: 0022
    struct _GsCOORDINATE *sub;
};

// size: 0x28
struct _50fake {
    // offset: 0000
    struct _2fake scale;
    // offset: 0010
    struct _3fake rotate;
    // offset: 0018
    struct _2fake trans;
};

// size: 0x50
struct _GsCOORDINATE2 {
    // offset: 0000
    unsigned long flg;
    // offset: 0004
    struct _1fake coord;
    // offset: 0024
    struct _1fake workm;
    // offset: 0044
    struct _50fake *param;
    // offset: 0048
    struct _GsCOORDINATE2 *super;
    // offset: 004C
    struct _GsCOORDINATE2 *sub;
};

// size: 0x22
struct _51fake {
    // offset: 0000
    long rx;
    // offset: 0004
    long ry;
    // offset: 0008
    long rz;
    // offset: 000C
    short sx;
    // offset: 000E
    short sy;
    // offset: 0010
    short sz;
    // offset: 0012
    long tx;
    // offset: 0016
    long ty;
    // offset: 001A
    long tz;
    // offset: 001E
    struct _GsCOORDINATE *super;
};

// size: 0x24
struct _52fake {
    // offset: 0000
    struct _1fake view;
    // offset: 0020
    struct _GsCOORDINATE2 *super;
};

// size: 0x20
struct _53fake {
    // offset: 0000
    long vpx;
    // offset: 0004
    long vpy;
    // offset: 0008
    long vpz;
    // offset: 000C
    long vrx;
    // offset: 0010
    long vry;
    // offset: 0014
    long vrz;
    // offset: 0018
    long rz;
    // offset: 001C
    struct _GsCOORDINATE *super;
};

// size: 0x20
struct _54fake {
    // offset: 0000
    long vpx;
    // offset: 0004
    long vpy;
    // offset: 0008
    long vpz;
    // offset: 000C
    long vrx;
    // offset: 0010
    long vry;
    // offset: 0014
    long vrz;
    // offset: 0018
    long rz;
    // offset: 001C
    struct _GsCOORDINATE2 *super;
};

// size: 0xF
struct _55fake {
    // offset: 0000
    int vx;
    // offset: 0004
    int vy;
    // offset: 0008
    int vz;
    // offset: 000C
    unsigned char r;
    // offset: 000D
    unsigned char g;
    // offset: 000E
    unsigned char b;
};

// size: 0x20
struct _56fake {
    // offset: 0000
    unsigned int p : 24;
    // offset: 0018
    unsigned char num : 8;
};

// size: 0x14
struct _57fake {
    // offset: 0000
    unsigned long length;
    // offset: 0004
    struct _56fake *org;
    // offset: 0008
    unsigned long offset;
    // offset: 000C
    unsigned long point;
    // offset: 0010
    struct _56fake *tag;
};

// size: 0x74
struct _58fake {
    // offset: 0000
    unsigned long attribute;
    // offset: 0004
    struct _1fake lwmatrix;
    // offset: 0024
    struct _1fake lightm;
    // offset: 0044
    struct _GsCOORDINATE coord;
    // offset: 006C
    unsigned long *tmd;
    // offset: 0070
    unsigned long id;
};

// size: 0x10
struct _59fake {
    // offset: 0000
    unsigned long attribute;
    // offset: 0004
    struct _GsCOORDINATE2 *coord2;
    // offset: 0008
    unsigned long *tmd;
    // offset: 000C
    unsigned long id;
};

// size: 0x18
struct _60fake {
    // offset: 0000
    unsigned long attribute;
    // offset: 0004
    struct _GsCOORDINATE2 *coord2;
    // offset: 0008
    unsigned long *pmd;
    // offset: 000C
    unsigned long *base;
    // offset: 0010
    unsigned long *sv;
    // offset: 0014
    unsigned long id;
};

// size: 0x14
struct _61fake {
    // offset: 0000
    unsigned long attribute;
    // offset: 0004
    struct _GsCOORDINATE2 *coord2;
    // offset: 0008
    unsigned long *tmd;
    // offset: 000C
    unsigned long *packet;
    // offset: 0010
    unsigned long id;
};

// size: 0x23
struct _62fake {
    // offset: 0000
    unsigned long attribute;
    // offset: 0004
    short x;
    // offset: 0006
    short y;
    // offset: 0008
    unsigned short w;
    // offset: 000A
    unsigned short h;
    // offset: 000C
    unsigned short tpage;
    // offset: 000E
    unsigned char u;
    // offset: 000F
    unsigned char v;
    // offset: 0010
    short cx;
    // offset: 0012
    short cy;
    // offset: 0014
    unsigned char r;
    // offset: 0015
    unsigned char g;
    // offset: 0016
    unsigned char b;
    // offset: 0017
    short mx;
    // offset: 0019
    short my;
    // offset: 001B
    short scalex;
    // offset: 001D
    short scaley;
    // offset: 001F
    long rotate;
};

// size: 0x48
struct _63fake {
    // offset: 0000
    unsigned long attribute;
    // offset: 0004
    short x;
    // offset: 0006
    short y;
    // offset: 0008
    struct _43fake mode[2];
    // offset: 0020
    struct _36fake packet[2];
};

// size: 0x8
struct _64fake {
    // offset: 0000
    unsigned char u;
    // offset: 0001
    unsigned char v;
    // offset: 0002
    unsigned short cba;
    // offset: 0004
    unsigned short flag;
    // offset: 0006
    unsigned short tpage;
};

// size: 0xE
struct _65fake {
    // offset: 0000
    unsigned char cellw;
    // offset: 0001
    unsigned char cellh;
    // offset: 0002
    unsigned short ncellw;
    // offset: 0004
    unsigned short ncellh;
    // offset: 0006
    struct _64fake *base;
    // offset: 000A
    unsigned short *index;
};

// size: 0x23
struct _66fake {
    // offset: 0000
    unsigned long attribute;
    // offset: 0004
    short x;
    // offset: 0006
    short y;
    // offset: 0008
    short w;
    // offset: 000A
    short h;
    // offset: 000C
    short scrollx;
    // offset: 000E
    short scrolly;
    // offset: 0010
    unsigned char r;
    // offset: 0011
    unsigned char g;
    // offset: 0012
    unsigned char b;
    // offset: 0013
    struct _65fake *map;
    // offset: 0017
    short mx;
    // offset: 0019
    short my;
    // offset: 001B
    short scalex;
    // offset: 001D
    short scaley;
    // offset: 001F
    long rotate;
};

// size: 0xF
struct _67fake {
    // offset: 0000
    unsigned long attribute;
    // offset: 0004
    short x0;
    // offset: 0006
    short y0;
    // offset: 0008
    short x1;
    // offset: 000A
    short y1;
    // offset: 000C
    unsigned char r;
    // offset: 000D
    unsigned char g;
    // offset: 000E
    unsigned char b;
};

// size: 0x12
struct _68fake {
    // offset: 0000
    unsigned long attribute;
    // offset: 0004
    short x0;
    // offset: 0006
    short y0;
    // offset: 0008
    short x1;
    // offset: 000A
    short y1;
    // offset: 000C
    unsigned char r0;
    // offset: 000D
    unsigned char g0;
    // offset: 000E
    unsigned char b0;
    // offset: 000F
    unsigned char r1;
    // offset: 0010
    unsigned char g1;
    // offset: 0011
    unsigned char b1;
};

// size: 0xF
struct _69fake {
    // offset: 0000
    unsigned long attribute;
    // offset: 0004
    short x;
    // offset: 0006
    short y;
    // offset: 0008
    unsigned short w;
    // offset: 000A
    unsigned short h;
    // offset: 000C
    unsigned char r;
    // offset: 000D
    unsigned char g;
    // offset: 000E
    unsigned char b;
};

// size: 0x9
struct _70fake {
    // offset: 0000
    short dqa;
    // offset: 0002
    long dqb;
    // offset: 0006
    unsigned char rfc;
    // offset: 0007
    unsigned char gfc;
    // offset: 0008
    unsigned char bfc;
};

// size: 0x1C
struct _71fake {
    // offset: 0000
    unsigned long pmode;
    // offset: 0004
    short px;
    // offset: 0006
    short py;
    // offset: 0008
    unsigned short pw;
    // offset: 000A
    unsigned short ph;
    // offset: 000C
    unsigned long *pixel;
    // offset: 0010
    short cx;
    // offset: 0012
    short cy;
    // offset: 0014
    unsigned short cw;
    // offset: 0016
    unsigned short ch;
    // offset: 0018
    unsigned long *clut;
};

// size: 0x4
struct _72fake {
    // offset: 0000
    short offx;
    // offset: 0002
    short offy;
};

// size: 0x8
struct _73fake {
    // offset: 0000
    unsigned long farz;
    // offset: 0004
    unsigned long nearz;
};

// size: 0xC
struct _74fake {
    // offset: 0000
    struct _58fake *top;
    // offset: 0004
    int nobj;
    // offset: 0008
    int maxobj;
};

// size: 0xC
struct _75fake {
    // offset: 0000
    struct _59fake *top;
    // offset: 0004
    int nobj;
    // offset: 0008
    int maxobj;
};

// size: 0x14
struct _76fake {
    // offset: 0000
    struct _3fake **diff_sp_vertex;
    // offset: 0004
    unsigned long *diff_off_vertex;
    // offset: 0008
    unsigned long *diff_n_vertex;
    // offset: 000C
    unsigned long *diff_obj_vertex;
    // offset: 0010
    long *mimepr;
};

// size: 0x14
struct _77fake {
    // offset: 0000
    struct _3fake **diff_sp_norm;
    // offset: 0004
    unsigned long *diff_off_norm;
    // offset: 0008
    unsigned long *diff_n_norm;
    // offset: 000C
    unsigned long *diff_obj_norm;
    // offset: 0010
    long *mimepr;
};

// size: 0x4
struct _78fake {
    // offset: 0000
    short left;
    // offset: 0002
    short right;
};

// size: 0x4
struct _79fake {
    // offset: 0000
    unsigned short left;
    // offset: 0002
    unsigned short right;
};

// size: 0x3E
struct _80fake {
    // offset: 0000
    unsigned long voice;
    // offset: 0004
    unsigned long mask;
    // offset: 0008
    struct _78fake volume;
    // offset: 000C
    struct _78fake volmode;
    // offset: 0010
    struct _78fake volumex;
    // offset: 0014
    unsigned short pitch;
    // offset: 0016
    unsigned short note;
    // offset: 0018
    unsigned short sample_note;
    // offset: 001A
    short envx;
    // offset: 001C
    unsigned long addr;
    // offset: 0020
    unsigned long loop_addr;
    // offset: 0024
    long a_mode;
    // offset: 0028
    long s_mode;
    // offset: 002C
    long r_mode;
    // offset: 0030
    unsigned short ar;
    // offset: 0032
    unsigned short dr;
    // offset: 0034
    unsigned short sr;
    // offset: 0036
    unsigned short rr;
    // offset: 0038
    unsigned short sl;
    // offset: 003A
    unsigned short adsr1;
    // offset: 003C
    unsigned short adsr2;
};

// size: 0x14
struct _81fake {
    // offset: 0000
    unsigned long mask;
    // offset: 0004
    long mode;
    // offset: 0008
    struct _78fake depth;
    // offset: 000C
    long delay;
    // offset: 0010
    long feedback;
};

// size: 0x1000
struct _82fake {
    // offset: 0000
    short cd_left[512];
    // offset: 0400
    short cd_right[512];
    // offset: 0800
    short voice1[512];
    // offset: 0C00
    short voice3[512];
};

// size: 0xC
struct _83fake {
    // offset: 0000
    struct _78fake volume;
    // offset: 0004
    long reverb;
    // offset: 0008
    long mix;
};

// size: 0x28
struct _84fake {
    // offset: 0000
    unsigned long mask;
    // offset: 0004
    struct _78fake mvol;
    // offset: 0008
    struct _78fake mvolmode;
    // offset: 000C
    struct _78fake mvolx;
    // offset: 0010
    struct _83fake cd;
    // offset: 001C
    struct _83fake ext;
};

// size: 0x4
struct _85fake {
    // offset: 0000
    unsigned char minute;
    // offset: 0001
    unsigned char second;
    // offset: 0002
    unsigned char sector;
    // offset: 0003
    unsigned char track;
};

// size: 0x4
struct _86fake {
    // offset: 0000
    unsigned char file;
    // offset: 0001
    unsigned char chan;
    // offset: 0002
    unsigned short pad;
};

// size: 0x4
struct _87fake {
    // offset: 0000
    unsigned char val0;
    // offset: 0001
    unsigned char val1;
    // offset: 0002
    unsigned char val2;
    // offset: 0003
    unsigned char val3;
};

// size: 0x18
struct _88fake {
    // offset: 0000
    struct _85fake pos;
    // offset: 0004
    unsigned long size;
    // offset: 0008
    unsigned char name[16];
};

// size: 0x14
struct _89fake {
    // offset: 0000
    unsigned short id;
    // offset: 0002
    unsigned short type;
    // offset: 0004
    unsigned short secCount;
    // offset: 0006
    unsigned short nSectors;
    // offset: 0008
    unsigned long frameCount;
    // offset: 000C
    unsigned long frameSize;
    // offset: 0010
    unsigned short width;
    // offset: 0012
    unsigned short height;
};

// size: 0x14
struct _90fake {
    // offset: 0000
    unsigned short id;
    // offset: 0002
    unsigned short type;
    // offset: 0004
    unsigned short secCount;
    // offset: 0006
    unsigned short nSectors;
    // offset: 0008
    unsigned long frameCount;
    // offset: 000C
    unsigned long frameSize;
    // offset: 0010
    unsigned short width;
    // offset: 0012
    unsigned short height;
};

// size: 0x8
struct ToT {
    // offset: 0000
    unsigned long *head;
    // offset: 0004
    long size;
};

// size: 0x8
struct TCBH {
    // offset: 0000
    struct TCB *entry;
    // offset: 0004
    long flag;
};

// size: 0xC0
struct TCB {
    // offset: 0000
    long status;
    // offset: 0004
    long mode;
    // offset: 0008
    unsigned long reg[40];
    // offset: 00A8
    long system[6];
};

// size: 0x1C
struct EvCB {
    // offset: 0000
    unsigned long desc;
    // offset: 0004
    long status;
    // offset: 0008
    long spec;
    // offset: 000C
    long mode;
    // offset: 0010
    long (*FHandler)();
    // offset: 0014
    long system[2];
};

// size: 0x3C
struct EXEC {
    // offset: 0000
    unsigned long pc0;
    // offset: 0004
    unsigned long gp0;
    // offset: 0008
    unsigned long t_addr;
    // offset: 000C
    unsigned long t_size;
    // offset: 0010
    unsigned long d_addr;
    // offset: 0014
    unsigned long d_size;
    // offset: 0018
    unsigned long b_addr;
    // offset: 001C
    unsigned long b_size;
    // offset: 0020
    unsigned long s_addr;
    // offset: 0024
    unsigned long s_size;
    // offset: 0028
    unsigned long sp;
    // offset: 002C
    unsigned long fp;
    // offset: 0030
    unsigned long gp;
    // offset: 0034
    unsigned long ret;
    // offset: 0038
    unsigned long base;
};

// size: 0x88
struct XF_HDR {
    // offset: 0000
    unsigned char key[8];
    // offset: 0008
    unsigned long text;
    // offset: 000C
    unsigned long data;
    // offset: 0010
    struct EXEC exec;
    // offset: 004C
    unsigned char title[60];
};

// size: 0x28
struct DIRENTRY {
    // offset: 0000
    unsigned char name[20];
    // offset: 0014
    long attr;
    // offset: 0018
    long size;
    // offset: 001C
    struct DIRENTRY *next;
    // offset: 0020
    long head;
    // offset: 0024
    unsigned char system[4];
};

// size: 0x24
struct M33 {
    // offset: 0000
    long R[3][3];
};

// size: 0xC
struct M31 {
    // offset: 0000
    long R[3];
};

// size: 0xE
struct HeapHandle {
    // offset: 0000
    unsigned char *Data;
    // offset: 0004
    unsigned long Size;
    // offset: 0008
    unsigned short Block;
    // offset: 000A
    unsigned short Idx;
    // offset: 000C
    unsigned short ID;
};

// size: 0x1A
struct Heap {
    // offset: 0000
    long Size;
    // offset: 0004
    long Unused;
    // offset: 0008
    struct HeapHandle *Handle;
    // offset: 000C
    struct HeapHandle **Block;
    // offset: 0010
    unsigned char *Data;
    // offset: 0014
    unsigned short BlockCount;
    // offset: 0016
    unsigned short HandleCount;
    // offset: 0018
    unsigned short State;
};

// size: 0x7
struct ScaleSprite {
    // offset: 0000
    unsigned char Flags;
    // offset: 0001
    unsigned char SClass;
    // offset: 0002
    unsigned short Width;
    // offset: 0004
    unsigned short Height;
    // offset: 0006
    unsigned char Data[1];
};

// size: 0x1C
struct AnimPageDynamic {
    // offset: 0000
    unsigned long Active;
    // offset: 0004
    struct ScaleSprite **Data;
    // offset: 0008
    unsigned long CurrentPosition;
    // offset: 000C
    unsigned short PageOffset;
    // offset: 000E
    unsigned short AnimOffset;
    // offset: 0010
    unsigned short NumberOfFrames;
    // offset: 0012
    unsigned short Width;
    // offset: 0014
    unsigned short Height;
    // offset: 0016
    unsigned short CurrentFrame;
    // offset: 0018
    unsigned short Page;
    // offset: 001A
    unsigned short ID;
};

// size: 0x6
struct AnimPageDynamicBank {
    // offset: 0000
    unsigned short Pages;
    // offset: 0002
    struct AnimPageDynamic *Page;
};

// size: 0x2B
struct Joystick {
    // offset: 0000
    long XCount;
    // offset: 0004
    long YCount;
    // offset: 0008
    long XMin;
    // offset: 000C
    long XMax;
    // offset: 0010
    long XCentre;
    // offset: 0014
    long YMin;
    // offset: 0018
    long YMax;
    // offset: 001C
    long YCentre;
    // offset: 0020
    long HatMax;
    // offset: 0024
    unsigned char State;
    // offset: 0025
    unsigned char StickType;
    // offset: 0026
    unsigned char Buttons;
    // offset: 0027
    char X;
    // offset: 0028
    char Y;
    // offset: 0029
    char HatX;
    // offset: 002A
    char HatY;
};

// size: 0x8
struct Proportion {
    // offset: 0000
    long angle;
    // offset: 0004
    long hypotenuse;
};

// size: 0x42
struct NetworkInfo {
    // offset: 0000
    unsigned char Active;
    // offset: 0001
    unsigned char SessionActive;
    // offset: 0002
    short Slot;
    // offset: 0004
    short NumberOfSlots;
    // offset: 0006
    short MaxNumberOfSlots;
    // offset: 0008
    short NumberActive;
    // offset: 000A
    unsigned char *SendBuffer;
    // offset: 000E
    unsigned char *ReceiveBuffer;
    // offset: 0012
    unsigned char *ReceiveBuffers[12];
    // offset: 0016
    unsigned short Abort;
    // offset: 0018
    unsigned short HostSlot;
    // offset: 001A
    struct NCB *MasterNcb;
    // offset: 001E
    struct NCB *UserNcb[12];
    // offset: 0022
    unsigned char Status[12];
    // offset: 002E
    unsigned char Name[20];
};

// size: 0x14
struct Detail {
    // offset: 0000
    long Shading;
    // offset: 0004
    long Sky;
    // offset: 0008
    long SplittingLow;
    // offset: 000C
    long SplittingHigh;
    // offset: 0010
    long SolidPolygons;
};

// size: 0xC
struct XYZ {
    // offset: 0000
    long X;
    // offset: 0004
    long Y;
    // offset: 0008
    long Z;
};

// size: 0xC
struct SetupSprite {
    // offset: 0000
    unsigned long *Start;
    // offset: 0004
    unsigned long *End;
    // offset: 0008
    unsigned long *Data;
};

// size: 0x10
struct PolygonPoint {
    // offset: 0000
    long X;
    // offset: 0004
    long Y;
    // offset: 0008
    long TMapX;
    // offset: 000C
    long TMapY;
};

// size: 0x8
struct Angle {
    // offset: 0000
    short XY;
    // offset: 0002
    short ZY;
    // offset: 0004
    short XZ;
    // offset: 0006
    short Pad;
};

// size: 0x8
struct Coord3D {
    // offset: 0000
    short Xpos;
    // offset: 0002
    short Ypos;
    // offset: 0004
    short Zpos;
    // offset: 0006
    short Pad;
};

// size: 0x4
struct Coord2D {
    // offset: 0000
    short Xpos;
    // offset: 0002
    short Ypos;
};

// size: 0x3C
struct Camera {
    // offset: 0000
    struct Coord3D Position;
    // offset: 0008
    struct Coord3D Destination;
    // offset: 0010
    struct Angle Angle;
    // offset: 0018
    struct Detail Detail;
    // offset: 002C
    long Lens;
    // offset: 0030
    long Distance;
    // offset: 0034
    short Follow;
    // offset: 0036
    short Zoom;
    // offset: 0038
    short Static;
    // offset: 003A
    short Action;
};

// size: 0x8
struct Window {
    // offset: 0000
    struct Coord2D Position;
    // offset: 0004
    struct Coord2D Size;
};

// size: 0xC
struct MapGenerate {
    // offset: 0000
    struct Coord2D Offset;
    // offset: 0004
    long Seed;
    // offset: 0008
    long Raise;
};

// size: 0x8
struct ColideMark {
    // offset: 0000
    short Child;
    // offset: 0002
    short Parent;
    // offset: 0004
    unsigned char Xpos;
    // offset: 0005
    unsigned char Ypos;
    // offset: 0006
    unsigned short Index;
};

// size: 0x4
struct Speed {
    // offset: 0000
    long Actual;
};

// size: 0x8
struct Draw {
    // offset: 0000
    short Number;
    // offset: 0002
    unsigned short PadW;
    // offset: 0004
    unsigned char Mode;
    // offset: 0005
    unsigned char Frame;
    // offset: 0006
    unsigned char NumberOfFrames;
    // offset: 0007
    unsigned char Padb;
};

// size: 0x8
struct Affect {
    // offset: 0000
    unsigned long Status;
    // offset: 0004
    short Number;
    // offset: 0006
    unsigned short Who;
};

// size: 0x14
struct Colide {
    // offset: 0000
    struct Coord3D Size;
    // offset: 0008
    struct Affect Affect;
    // offset: 0010
    unsigned short Group;
    // offset: 0012
    unsigned short Padw;
};

// size: 0xC
struct Movement {
    // offset: 0000
    struct Angle Angle;
    // offset: 0008
    struct Speed Speed;
};

// size: 0x10
struct View {
    // offset: 0000
    struct Coord3D Position;
    // offset: 0008
    struct Angle Angle;
};

// size: 0x8
struct CollidePoint {
    // offset: 0000
    long Flags;
    // offset: 0004
    long Count;
};

// size: 0x20
struct SensorPoint {
    // offset: 0000
    struct Coord3D Position;
    // offset: 0008
    struct CollidePoint Collide;
    // offset: 0010
    long Zpos;
    // offset: 0014
    long ZposFloor;
    // offset: 0018
    long ZposDiff;
    // offset: 001C
    short ZposDisplacement;
    // offset: 001E
    unsigned char Rebound;
    // offset: 001F
    unsigned char ReboundLimit;
};

// size: 0x8
struct VehicleCollideSize {
    // offset: 0000
    short Forward;
    // offset: 0002
    short Rear;
    // offset: 0004
    short Sideways;
    // offset: 0006
    short SensorOffset;
};

// size: 0x10
struct VehicleControlFlags {
    // offset: 0000
    unsigned short Booster : 1;
    // offset: 0001
    unsigned short Brake : 1;
    // offset: 0002
    unsigned short Airbourn : 1;
    // offset: 0003
    unsigned short BarrelRoll : 1;
    // offset: 0004
    unsigned short Autopilot : 1;
    // offset: 0005
    unsigned short AutoRefuel : 1;
    // offset: 0006
    unsigned short AutoRearm : 1;
    // offset: 0007
    unsigned short AutoRepair : 1;
    // offset: 0008
    unsigned short AutoStop : 1;
    // offset: 0009
    unsigned short AutoPilotSet : 1;
    // offset: 000A
    unsigned short AutoDrive : 1;
    // offset: 000B
    unsigned short HealthDeath : 1;
    // offset: 000C
    unsigned short FuelDeath : 1;
    // offset: 000D
    unsigned short Reposition : 1;
    // offset: 000E
    unsigned short pad1 : 1;
    // offset: 000F
    unsigned short pad2 : 1;
};

// size: 0x10
struct VehicleFunctionFlags {
    // offset: 0000
    unsigned short Booster : 1;
    // offset: 0001
    unsigned short Brake : 1;
    // offset: 0002
    unsigned short BarrelRoll : 1;
    // offset: 0003
    unsigned short pad1 : 1;
    // offset: 0004
    unsigned short pad2 : 1;
    // offset: 0005
    unsigned short pad3 : 1;
    // offset: 0006
    unsigned short pad4 : 1;
    // offset: 0007
    unsigned short pad5 : 1;
    // offset: 0008
    unsigned short pad6 : 1;
    // offset: 0009
    unsigned short pad7 : 1;
    // offset: 000A
    unsigned short pad8 : 1;
    // offset: 000B
    unsigned short pad9 : 1;
    // offset: 000C
    unsigned short pad10 : 1;
    // offset: 000D
    unsigned short pad11 : 1;
    // offset: 000E
    unsigned short pad12 : 1;
    // offset: 000F
    unsigned short pad13 : 1;
};

// size: 0x10
struct VehicleFake {
    // offset: 0000
    unsigned short pad1 : 1;
    // offset: 0001
    unsigned short pad2 : 1;
    // offset: 0002
    unsigned short pad3 : 1;
    // offset: 0003
    unsigned short pad4 : 1;
    // offset: 0004
    unsigned short pad5 : 1;
    // offset: 0005
    unsigned short pad6 : 1;
    // offset: 0006
    unsigned short pad7 : 1;
    // offset: 0007
    unsigned short pad8 : 1;
    // offset: 0008
    unsigned short pad9 : 1;
    // offset: 0009
    unsigned short pad10 : 1;
    // offset: 000A
    unsigned short pad11 : 1;
    // offset: 000B
    unsigned short pad12 : 1;
    // offset: 000C
    unsigned short pad13 : 1;
    // offset: 000D
    unsigned short pad14 : 1;
    // offset: 000E
    unsigned short pad15 : 1;
    // offset: 000F
    unsigned short pad16 : 1;
};

// size: 0x90
struct CollideControl {
    // offset: 0000
    struct VehicleCollideSize Size;
    // offset: 0008
    struct SensorPoint FrontLeft;
    // offset: 0028
    struct SensorPoint FrontRight;
    // offset: 0048
    struct SensorPoint RearLeft;
    // offset: 0068
    struct SensorPoint RearRight;
    // offset: 0088
    struct VehicleControlFlags Flag;
    // offset: 008A
    struct VehicleFunctionFlags FunctionFlag;
    // offset: 008C
    unsigned short RideHeight;
    // offset: 008E
    unsigned short BrakePower;
};

// size: 0xC
struct Momentum {
    // offset: 0000
    long DeltaX;
    // offset: 0004
    long DeltaY;
    // offset: 0008
    long AngleXY;
};

// size: 0x8
struct VehicleBooster {
    // offset: 0000
    short InitialThrust;
    // offset: 0002
    short BurnThrust;
    // offset: 0004
    short BurnSetting;
    // offset: 0006
    unsigned char BurnTime;
    // offset: 0007
    unsigned char Burn;
};

// size: 0xC
struct VehicleSpecialMoves {
    // offset: 0000
    struct Angle Angle;
    // offset: 0008
    short Count;
    // offset: 000A
    short PadW;
};

// size: 0x24
struct VehicleAutoTarget {
    // offset: 0000
    unsigned short HitMeTotal[8];
    // offset: 0010
    unsigned char HitMeCount[8];
    // offset: 0018
    unsigned char HitMeTrigger[8];
    // offset: 0020
    unsigned short PrimaryTarget;
    // offset: 0022
    unsigned short ValidTargetCount;
};

// size: 0xC
struct VehicleDamage {
    // offset: 0000
    unsigned short ShimmerCount;
    // offset: 0002
    unsigned short DamageCount;
    // offset: 0004
    unsigned short BulletCount;
    // offset: 0006
    unsigned short MissileCount;
    // offset: 0008
    unsigned short BulletHoles;
    // offset: 000A
    unsigned short Padw;
};

// size: 0x1E
struct VehicleSpins {
    // offset: 0000
    long Count;
    // offset: 0004
    short State;
    // offset: 0006
    short StartAngle;
    // offset: 0008
    short LastAngle;
    // offset: 000A
    short FlagCheck180 : 1;
    // offset: 000B
    short FlagCheck360 : 1;
    // offset: 000C
    short FlagCheck540 : 1;
    // offset: 000D
    short FlagCheck720 : 1;
    // offset: 000E
    short Flag180 : 1;
    // offset: 000F
    short Flag360 : 1;
    // offset: 0010
    short Flag540 : 1;
    // offset: 0011
    short Flag720 : 1;
    // offset: 0012
    short PadBit0 : 1;
    // offset: 0013
    short PadBit1 : 1;
    // offset: 0014
    short PadBit2 : 1;
    // offset: 0015
    short PadBit3 : 1;
    // offset: 0016
    short PadBit4 : 1;
    // offset: 0017
    short PadBit5 : 1;
    // offset: 0018
    short PadBit6 : 1;
    // offset: 0019
    short PadBit7 : 1;
    // offset: 001A
    unsigned char Count180;
    // offset: 001B
    unsigned char Count360;
    // offset: 001C
    unsigned char Count540;
    // offset: 001D
    unsigned char Count720;
};

// size: 0x8
struct VehicleUpgradeBackup {
    // offset: 0000
    unsigned short Weapon[4];
};

// size: 0x1E
struct VehicleSuperCar {
    // offset: 0000
    struct VehicleUpgradeBackup Backup;
    // offset: 0008
    short Level;
    // offset: 000A
    short SuperCar;
    // offset: 000C
    short KillsInFirstPlace;
    // offset: 000E
    short FlagOneLapInTheLead : 1;
    // offset: 000F
    short FlagLapLead : 1;
    // offset: 0010
    short FlagSuperCar : 1;
    // offset: 0011
    short PadBit0 : 1;
    // offset: 0012
    short PadBit1 : 1;
    // offset: 0013
    short PadBit2 : 1;
    // offset: 0014
    short PadBit3 : 1;
    // offset: 0015
    short PadBit4 : 1;
    // offset: 0016
    short PadBit5 : 1;
    // offset: 0017
    short PadBit6 : 1;
    // offset: 0018
    short PadBit7 : 1;
    // offset: 0019
    short PadBit8 : 1;
    // offset: 001A
    short PadBit9 : 1;
    // offset: 001B
    short PadBit10 : 1;
    // offset: 001C
    short PadBit11 : 1;
    // offset: 001D
    short PadBit12 : 1;
};

// size: 0x20
struct VehicleSpecials {
    // offset: 0000
    struct VehicleSpins Spin;
    // offset: 0010
    struct VehicleSuperCar SuperCar;
};

// size: 0xC
struct VehicleMovementStatus {
    // offset: 0000
    struct Coord3D LastPosition;
    // offset: 0008
    short Count;
    // offset: 000A
    short Padw;
};

// size: 0x1C
struct VehicleStats {
    // offset: 0000
    short Behind;
    // offset: 0002
    short Fuel;
    // offset: 0004
    short Weapons;
    // offset: 0006
    short Health;
    // offset: 0008
    short Velocity;
    // offset: 000A
    short DamageCount;
    // offset: 000C
    short Handling;
    // offset: 000E
    short Speed;
    // offset: 0010
    short Armour;
    // offset: 0012
    short Weight;
    // offset: 0014
    short Invincable;
    // offset: 0016
    short Invisible;
    // offset: 0018
    short VehicleHit;
    // offset: 001A
    short Padw;
};

// size: 0x1F0
struct ThingVehicle {
    // offset: 0000
    struct Momentum Momentum;
    // offset: 000C
    struct Movement MovementInput;
    // offset: 0018
    struct Movement Increment;
    // offset: 0024
    struct Movement IncrementAdd;
    // offset: 0030
    struct Movement IncrementSub;
    // offset: 003C
    struct Movement IncrementLimit;
    // offset: 0048
    struct VehicleBooster Booster;
    // offset: 0050
    struct CollideControl FlightModel;
    // offset: 00E0
    struct Coord3D Displacement;
    // offset: 00E8
    struct Coord3D Slope;
    // offset: 00F0
    struct Coord3D Bump;
    // offset: 00F8
    struct Coord3D Bonus;
    // offset: 0100
    struct VehicleSpecialMoves Tumble;
    // offset: 010C
    struct VehicleAutoTarget AutoTarget;
    // offset: 0130
    struct VehicleDamage Damage;
    // offset: 013C
    struct VehicleSpecials Specials;
    // offset: 015C
    struct VehicleMovementStatus MovementStatus;
    // offset: 0168
    struct VehicleFake MoreFlags[2];
    // offset: 016C
    struct View View;
    // offset: 017C
    struct VehicleStats Stats;
    // offset: 0198
    long DistanceToNextCheckPoint;
    // offset: 019C
    long LastLapTicks;
    // offset: 01A0
    long LapTicks;
    // offset: 01A4
    long FastestLapTicks;
    // offset: 01A8
    long TotalRaceTicks;
    // offset: 01AC
    long TotalRaceTicksFinished;
    // offset: 01B0
    long ClosestMissile;
    // offset: 01B4
    short Counter[8];
    // offset: 01C4
    short Weapons[4];
    // offset: 01CC
    short Index;
    // offset: 01CE
    short Friction;
    // offset: 01D0
    short FrictionLimit;
    // offset: 01D2
    short ThrustEffectiveness;
    // offset: 01D4
    short Bounce;
    // offset: 01D6
    short MaximumZpos;
    // offset: 01D8
    short SideslipFriction;
    // offset: 01DA
    short SideslipToThrust;
    // offset: 01DC
    short BumpDamage;
    // offset: 01DE
    short LastWaypoint;
    // offset: 01E0
    short CurrentWaypoint;
    // offset: 01E2
    short CheckPoint;
    // offset: 01E4
    short LapCounter;
    // offset: 01E6
    short RacePosition;
    // offset: 01E8
    short RacePositionHighest;
    // offset: 01EA
    short RaceLaps;
    // offset: 01EC
    short RacePositionFinish;
    // offset: 01EE
    short Padw;
};

// size: 0x8
struct ThingWeapon {
    // offset: 0000
    short Trigger;
    // offset: 0002
    short TriggerTime;
    // offset: 0004
    short TriggerRestrictionCount;
    // offset: 0006
    short Target;
};

// size: 0x4
struct ThingBuilding {
    // offset: 0000
    short MaskNumber;
    // offset: 0002
    short Padw;
};

// size: 0x64
struct Thing {
    // offset: 0000
    struct Coord3D Position;
    // offset: 0008
    struct Draw Draw;
    // offset: 0010
    struct Movement Movement;
    // offset: 001C
    struct Colide Colide;
    // offset: 0030
    struct Coord3D Displacement;
    // offset: 0038
    struct ThingBuilding Building[1];
    // offset: 003C
    struct ThingWeapon Weapon[1];
    // offset: 0044
    unsigned long Status;
    // offset: 0048
    short Target;
    // offset: 004A
    short Index;
    // offset: 004C
    short Child;
    // offset: 004E
    short Parent;
    // offset: 0050
    short Count;
    // offset: 0052
    short Id;
    // offset: 0054
    short Life;
    // offset: 0056
    unsigned short Seed;
    // offset: 0058
    short Owner;
    // offset: 005A
    short VehicleIndex;
    // offset: 005C
    short NextThingInGroup;
    // offset: 005E
    short Upgrade;
    // offset: 0060
    char Member;
    // offset: 0061
    char Action;
    // offset: 0062
    char Group;
    // offset: 0063
    char TimeSlice;
};

// size: 0x8
struct Packet {
    // offset: 0000
    unsigned char CheckSum;
    // offset: 0001
    char Action;
    // offset: 0002
    short Padw;
    // offset: 0004
    union PacketData Data;
};

// size: 0x8
struct PlayerInfo {
    // offset: 0000
    long MissilesLeft;
    // offset: 0004
    unsigned long Score;
};

// size: 0x8
struct Screen {
    // offset: 0000
    struct Coord2D Aspect;
    // offset: 0004
    short Mode;
    // offset: 0006
    short SizeUnit;
};

// size: 0x22F
struct Conditions {
    // offset: 0000
    long BumpAmount;
    // offset: 0004
    long RocketsLaunched;
    // offset: 0008
    long RocketsHit;
    // offset: 000C
    long Bullets;
    // offset: 0010
    long BulletsHit;
    // offset: 0014
    long HitRatio;
    // offset: 0018
    long MiniGunHeatup;
    // offset: 001C
    long Deaths[8];
    // offset: 003C
    long DeathsCount;
    // offset: 0040
    long Kills[8];
    // offset: 0060
    long KillsCount;
    // offset: 0064
    long FlagKill : 1;
    // offset: 0065
    long FlagDeath : 1;
    // offset: 0066
    long FlagNewLap : 1;
    // offset: 0067
    long LapTimes[100];
    // offset: 01F7
    long AverageLapTime;
    // offset: 01FB
    long FastestLapTime;
    // offset: 01FF
    long TotalTime;
    // offset: 0203
    long LapCount;
    // offset: 0207
    long FuelUsed;
    // offset: 020B
    long HealthUsed;
    // offset: 020F
    long WeaponsUsed;
    // offset: 0213
    long RacePosition;
    // offset: 0217
    long RacePositionFinishShowTime;
    // offset: 021B
    long RacePoints;
    // offset: 021F
    long GodFactor;
    // offset: 0223
    char FuelLowCounter;
    // offset: 0224
    char FuelRechargeCounter;
    // offset: 0225
    char FuelFullCounter;
    // offset: 0226
    char WeaponsLowCounter;
    // offset: 0227
    char WeaponsRechargeCounter;
    // offset: 0228
    char WeaponsFullCounter;
    // offset: 0229
    char HealthLowCounter;
    // offset: 022A
    char HealthRechargeCounter;
    // offset: 022B
    char HealthFullCounter;
    // offset: 022C
    char Padb;
    // offset: 022D
    short Padw;
};

// size: 0xC
struct ComputerPlayer {
    // offset: 0000
    short EnemyIndex;
    // offset: 0002
    short Count1;
    // offset: 0004
    short Count2;
    // offset: 0006
    short Count3;
    // offset: 0008
    unsigned char Skill;
    // offset: 0009
    unsigned char Param2;
    // offset: 000A
    unsigned char Param3;
    // offset: 000B
    unsigned char Param4;
};

// size: 0xC
struct BulletHole {
    // offset: 0000
    struct Coord3D Position;
    // offset: 0008
    long Count;
};

// size: 0x10
struct TargetSystem {
    // offset: 0000
    struct Coord3D Position;
    // offset: 0008
    long Count;
    // offset: 000C
    short LastTarget;
    // offset: 000E
    short Padw;
};

// size: 0x300
struct OtherInformation {
    // offset: 0000
    char NameP2[32];
    // offset: 0020
    char NameP3[32];
    // offset: 0040
    char NameP4[32];
    // offset: 0060
    char NameP5[32];
    // offset: 0080
    char NameP6[32];
    // offset: 00A0
    char NameP7[32];
    // offset: 00C0
    char NameP8[32];
    // offset: 00E0
    unsigned char Others[533];
    // offset: 02F5
    unsigned char NumberofLives;
    // offset: 02F6
    unsigned char NumberofTagPlayers;
    // offset: 02F7
    unsigned char TagRaceTime;
    // offset: 02F8
    long ComputerPlayers;
    // offset: 02FC
    long NumberOfLaps;
};

// size: 0x980
struct Control {
    // offset: 0000
    struct Screen Screen;
    // offset: 0008
    struct Coord2D Balance;
    // offset: 000C
    struct PlayerInfo PlayerInfo;
    // offset: 0014
    struct Conditions Conditions;
    // offset: 0244
    struct ComputerPlayer ComputerPlayer[1];
    // offset: 0250
    struct BulletHole BulletHole[16];
    // offset: 0310
    struct TargetSystem TargetSystem;
    // offset: 0320
    struct OtherInformation OtherInformation;
    // offset: 0620
    unsigned char SetPalette[768];
    // offset: 0920
    char Name[32];
    // offset: 0940
    unsigned long Status;
    // offset: 0944
    unsigned long CheckSum;
    // offset: 0948
    unsigned long Seed;
    // offset: 094C
    unsigned long Type;
    // offset: 0950
    unsigned long Origin;
    // offset: 0954
    unsigned long Display;
    // offset: 0958
    unsigned long GameTurn;
    // offset: 095C
    long ControlThing;
    // offset: 0960
    unsigned long Control;
    // offset: 0964
    unsigned long PlayerView;
    // offset: 0968
    long NumberOfPaletteStages;
    // offset: 096C
    long Points;
    // offset: 0970
    long ConnectionTimer;
    // offset: 0974
    short ViewType;
    // offset: 0976
    short ScreenSize;
    // offset: 0978
    short Index;
    // offset: 097A
    char CarColour;
    // offset: 097B
    char CarNumber;
    // offset: 097C
    char SessionNumber;
    // offset: 097D
    char SessionNumberAdded;
    // offset: 097E
    unsigned char PlayerDifficultyLevel;
    // offset: 097F
    unsigned char Padb;
};

// size: 0x18
struct ThingInit {
    // offset: 0000
    char Group;
    // offset: 0001
    char Member;
    // offset: 0002
    short Id;
    // offset: 0004
    short SwitchId;
    // offset: 0006
    unsigned short Parent;
    // offset: 0008
    unsigned short Child;
    // offset: 000A
    unsigned short Status;
    // offset: 000C
    short Connected;
    // offset: 000E
    short Parameter;
    // offset: 0010
    struct Coord2D Position;
    // offset: 0014
    struct Coord2D Size;
};

// size: 0x7DC
struct ThingList {
    // offset: 0000
    short Thing[1000];
    // offset: 07D0
    long Index;
    // offset: 07D4
    unsigned long Sector;
    // offset: 07D8
    unsigned long Group;
};

// size: 0x38
struct Mouse {
    // offset: 0000
    long MLeftButtonCount;
    // offset: 0004
    long MRightButtonCount;
    // offset: 0008
    long LeftButtonCount;
    // offset: 000C
    long RightButtonCount;
    // offset: 0010
    long LeftButton;
    // offset: 0014
    long RightButton;
    // offset: 0018
    long MLeftButton;
    // offset: 001C
    long MRightButton;
    // offset: 0020
    long MMouseX;
    // offset: 0024
    long MMouseY;
    // offset: 0028
    long MouseX;
    // offset: 002C
    long MouseY;
    // offset: 0030
    long MickeyX;
    // offset: 0034
    long MickeyY;
};

// size: 0xC
struct MapElement {
    // offset: 0000
    short Shade;
    // offset: 0002
    short Alt;
    // offset: 0004
    short Block;
    // offset: 0006
    short Child;
    // offset: 0008
    short Vector;
    // offset: 000A
    unsigned char Orientation;
    // offset: 000B
    unsigned char Marker;
};

// size: 0x10
struct Cube {
    // offset: 0000
    unsigned char Blocks[6];
    // offset: 0006
    unsigned char Orientations[6];
    // offset: 000C
    long Used;
};

// size: 0x1C
struct Column {
    // offset: 0000
    short Cubes[8];
    // offset: 0010
    long Used;
    // offset: 0014
    unsigned short SolidMask;
    // offset: 0016
    short BaseBlock;
    // offset: 0018
    unsigned char Orientation;
    // offset: 0019
    unsigned char Padb;
    // offset: 001A
    unsigned char Padbi;
    // offset: 001B
    unsigned char Padbii;
};

// size: 0x6
struct _91fake {
    // offset: 0000
    unsigned short Xpos;
    // offset: 0002
    unsigned short Ypos;
    // offset: 0004
    unsigned short Zpos;
};

// size: 0x6
struct _92fake {
    // offset: 0000
    unsigned short Xpos;
    // offset: 0002
    unsigned short Ypos;
    // offset: 0004
    unsigned short Zpos;
};

// size: 0x10
struct ColVect {
    // offset: 0000
    struct _91fake Pos1;
    // offset: 0006
    struct _92fake Pos2;
    // offset: 000C
    short Angle;
    // offset: 000E
    short PadW;
};

// size: 0x4
struct ColVectList {
    // offset: 0000
    unsigned short Vect;
    // offset: 0002
    unsigned short NextColList;
};

// size: 0x10
struct Waypoint {
    // offset: 0000
    struct Coord3D Position;
    // offset: 0008
    unsigned short PointType;
    // offset: 000A
    unsigned short Peer;
    // offset: 000C
    unsigned short Child;
    // offset: 000E
    unsigned short Padw;
};

// size: 0xABEC
struct Vectors {
    // offset: 0000
    struct ColVect ColVects[250];
    // offset: 0FA0
    struct ColVectList ColVectsList[10000];
    // offset: ABE0
    struct Coord2D TrackCollisionVector;
    // offset: ABE4
    unsigned short NextColVect;
    // offset: ABE6
    unsigned short NextVectsList;
    // offset: ABE8
    short TrackCollisionVectorAngle;
    // offset: ABEA
    short Padw;
};

// size: 0xC84
struct Waypoints {
    // offset: 0000
    struct Waypoint TrackWaypointList[200];
    // offset: 0C80
    unsigned short NextWaypoint;
    // offset: 0C82
    unsigned short Padw;
};

// size: 0x8
struct LevelPicture {
    // offset: 0000
    struct Coord2D Size;
    // offset: 0004
    struct Coord2D Position;
};

// size: 0x14
struct CloneMovements {
    // offset: 0000
    struct Coord3D Position;
    // offset: 0008
    struct Angle Angle;
    // offset: 0010
    short Velocity;
    // offset: 0012
    short Padw;
};

// size: 0x4E34
struct CloneThing {
    // offset: 0000
    struct CloneMovements CloneMovements[1000];
    // offset: 4E20
    long CloneMovementsIndex;
    // offset: 4E24
    long CloneMovementsIndexMaximum;
    // offset: 4E28
    long LapCounter;
    // offset: 4E2C
    long LapTime;
    // offset: 4E30
    short ControlThing;
    // offset: 4E32
    short Padw;
};

// size: 0xD2844
struct Level {
    // offset: 0000
    struct ThingInit ThingInit[4000];
    // offset: 17700
    struct ThingList ThingsFree;
    // offset: 17EDC
    struct Column Columns[1024];
    // offset: 1EEDC
    struct Cube Cubes[1024];
    // offset: 22EDC
    struct Control Control[9];
    // offset: 2845C
    struct Packet Packet[8];
    // offset: 2849C
    struct Thing Thing[1000];
    // offset: 40B3C
    struct ThingVehicle Vehicle[32];
    // offset: 4493C
    struct CloneThing CloneThing[2];
    // offset: 4E5A4
    struct LevelPicture Picture;
    // offset: 4E5AC
    struct Vectors Vectors;
    // offset: 59198
    struct Waypoints Waypoints;
    // offset: 59E1C
    short AffectList[1000];
    // offset: 5A5EC
    long GroupList[14];
    // offset: 5A624
    unsigned short ColideTypes[256];
    // offset: 5A824
    long ColumnIndex;
    // offset: 5A828
    long CubeIndex;
    // offset: 5A82C
    long MapwhoCellsChecked;
    // offset: 5A830
    unsigned long CheckSum;
    // offset: 5A834
    unsigned long TimeInGame;
    // offset: 5A838
    unsigned long Seed;
    // offset: 5A83C
    short AffectListIndex;
    // offset: 5A83E
    short SoundOrigin;
    // offset: 5A840
    short Padw;
    // offset: 5A842
    unsigned char Created;
    // offset: 5A843
    unsigned char Pad;
    // offset: 5A844
    struct MapElement MapElements[40960];
};

// size: 0x18
struct Timer {
    // offset: 0000
    unsigned long Counter;
    // offset: 0004
    unsigned long TCounter;
    // offset: 0008
    unsigned long Process;
    // offset: 000C
    unsigned long Speed;
    // offset: 0010
    unsigned long Factor;
    // offset: 0014
    long Setup;
};

// size: 0x4
struct Player {
    // offset: 0000
    unsigned long Number;
};

// size: 0xC
struct Time {
    // offset: 0000
    unsigned long Years;
    // offset: 0004
    unsigned short Weeks;
    // offset: 0006
    unsigned short Days;
    // offset: 0008
    unsigned char Hours;
    // offset: 0009
    unsigned char Minutes;
    // offset: 000A
    unsigned char Seconds;
    // offset: 000B
    unsigned char Seconds100th;
};

// size: 0x100
struct Strings {
    // offset: 0000
    char String[256];
};

// size: 0x4
struct Config {
    // offset: 0000
    long ActualScreenMode;
};

// size: 0x18
struct GameSound {
    // offset: 0000
    long MusicVolume;
    // offset: 0004
    long SoundVolume;
    // offset: 0008
    long MusicActive;
    // offset: 000C
    long SoundActive;
    // offset: 0010
    long NumberOfChannels;
    // offset: 0014
    long StereoSound;
};

// size: 0x4C
struct TrackInfo {
    // offset: 0000
    char LapName[32];
    // offset: 0020
    char RaceName[32];
    // offset: 0040
    long FastestLap;
    // offset: 0044
    long FastestRace;
    // offset: 0048
    short Padw;
    // offset: 004A
    unsigned char NoLaps;
    // offset: 004B
    unsigned char NoKills;
};

// size: 0x28
struct HiscoreEntry {
    // offset: 0000
    char Name[32];
    // offset: 0020
    long Points;
    // offset: 0024
    char Rating;
    // offset: 0025
    char CarColour;
    // offset: 0026
    char CarNumber;
    // offset: 0027
    char Padb;
};

// size: 0x138
struct TeamHiscoreEntry {
    // offset: 0000
    long Points[8];
    // offset: 0020
    char Name[8][32];
    // offset: 0120
    char CarColour[8];
    // offset: 0128
    char CarNumber[8];
    // offset: 0130
    char Rating[8];
};

// size: 0x110
struct Puzzle {
    // offset: 0000
    long Active;
    // offset: 0004
    long Count;
    // offset: 0008
    long Running;
    // offset: 000C
    long Seed;
    // offset: 0010
    char Grid[16][16];
};

// size: 0x2ECA0
struct GameSave {
    // offset: 0000
    struct Detail Detail;
    // offset: 0014
    struct Control Control;
    // offset: 0994
    struct Config Config;
    // offset: 0998
    struct GameSound Sound;
    // offset: 09B0
    struct HiscoreEntry Hiscore[50];
    // offset: 1180
    struct TeamHiscoreEntry TeamHiscore[20];
    // offset: 29E0
    struct Player Player;
    // offset: 29E4
    struct TrackInfo TrackInfo[9];
    // offset: 2C90
    short TotalPoints[8];
    // offset: 2CA0
    char Comments[32];
    // offset: 2CC0
    short CurrentLevelNumber;
    // offset: 2CC2
    short CurrentMovieNumber;
    // offset: 2CC4
    short Language;
    // offset: 2CC6
    short SaveFile;
    // offset: 2CC8
    unsigned long pad_after_card_load;
    // offset: 2CCC
    struct CloneThing CloneSaves[9];
};

// size: 0x18
struct Restrictions {
    // offset: 0000
    struct Detail Detail;
    // offset: 0014
    long MegaBytes4;
};

// size: 0x18
struct Playback {
    // offset: 0000
    struct Level *Level;
    // offset: 0004
    struct Packet *Packets;
    // offset: 0008
    long Active;
    // offset: 000C
    long Action;
    // offset: 0010
    long Position;
    // offset: 0014
    long MaximumPosition;
};

// size: 0x8C
struct CameraWindow {
    // offset: 0000
    struct Camera Camera;
    // offset: 003C
    struct Camera ChaseCamera;
    // offset: 0078
    struct Coord3D Position;
    // offset: 0080
    struct Coord3D Size;
    // offset: 0088
    long Update;
};

// size: 0x2F660
struct srm_GAME {
    // offset: 0000
    struct Level *Level;
    // offset: 0004
    struct GameSave Save;
    // offset: 2ECA4
    struct Timer Timer;
    // offset: 2ECBC
    struct Restrictions Restrictions;
    // offset: 2ECD4
    struct CameraWindow CameraWindow[16];
    // offset: 2F594
    struct Playback Playback;
    // offset: 2F5AC
    long PacketFileHandle;
    // offset: 2F5B0
    long RaceStartCount;
    // offset: 2F5B4
    unsigned long Status;
    // offset: 2F5B8
    long CdromCheck;
    // offset: 2F5BC
    unsigned int CdromDrive;
    // offset: 2F5C0
    char Comments[5][32];
};

// size: 0x34
struct MemberManage {
    // offset: 0000
    char Name[32];
    // offset: 0020
    long ID;
    // offset: 0024
    long (*Initialise)();
    // offset: 0028
    long (*Process)();
    // offset: 002C
    long (*Remove)();
    // offset: 0030
    unsigned long Active;
};

// size: 0x8
struct GroupManage {
    // offset: 0000
    long ID;
    // offset: 0004
    struct MemberManage *MemberManage;
};

// size: 0xC
struct Credits {
    // offset: 0000
    long Stage;
    // offset: 0004
    long TextType;
    // offset: 0008
    char *Text;
};

// size: 0x4
struct SearchStep {
    // offset: 0000
    char Xpos;
    // offset: 0001
    char Ypos;
    // offset: 0002
    short Level;
};

// size: 0x1090
struct Search {
    // offset: 0000
    short Index;
    // offset: 0002
    short StartIndex;
    // offset: 0004
    short StopIndex;
    // offset: 0006
    short Active;
    // offset: 0008
    long LevelMarkers[32];
    // offset: 0088
    struct Coord3D Position;
    // offset: 0090
    struct SearchStep Steps[1024];
};

// size: 0x8
struct EditorMapCell {
    // offset: 0000
    unsigned char Block;
    // offset: 0001
    unsigned char Column;
    // offset: 0002
    unsigned char Orientation;
    // offset: 0003
    unsigned char Shade;
    // offset: 0004
    unsigned char Altitude;
    // offset: 0005
    unsigned char Flags;
    // offset: 0006
    unsigned short Child;
};

// size: 0x2
struct EditorRoomCell {
    // offset: 0000
    unsigned char Block;
    // offset: 0001
    unsigned char Orientation;
};

// size: 0x18
struct EditorThingInit {
    // offset: 0000
    char Group;
    // offset: 0001
    char Member;
    // offset: 0002
    short Id;
    // offset: 0004
    short SwitchId;
    // offset: 0006
    unsigned short Parent;
    // offset: 0008
    unsigned short Child;
    // offset: 000A
    unsigned short Status;
    // offset: 000C
    short Connected;
    // offset: 000E
    short Parameter;
    // offset: 0010
    struct Coord2D Position;
    // offset: 0014
    struct Coord2D Size;
};

// size: 0x20
struct EditorMenu {
    // offset: 0000
    char *Name;
    // offset: 0004
    long Type;
    // offset: 0008
    struct EditorMenu *Next;
    // offset: 000C
    long (*Function)();
    // offset: 0010
    long Parameter[2];
    // offset: 0018
    long Selected;
    // offset: 001C
    long Counter;
};

// size: 0x7D8
struct EditorMenuBack {
    // offset: 0000
    long Amount;
    // offset: 0004
    unsigned char Selected[2000];
    // offset: 07D4
    long Index;
};

// size: 0x10
struct EditorSlide {
    // offset: 0000
    long Minimum;
    // offset: 0004
    long Maximum;
    // offset: 0008
    long *Variable;
    // offset: 000C
    long Status;
};

// size: 0x4A
struct EditorWindow {
    // offset: 0000
    char Name[32];
    // offset: 0020
    struct Coord3D MapPosition;
    // offset: 0028
    struct Coord3D MapPositionDestination;
    // offset: 0030
    struct Coord2D Position;
    // offset: 0034
    struct Coord2D Size;
    // offset: 0038
    struct Coord2D ZoomSize;
    // offset: 003C
    long Zoom;
    // offset: 0040
    unsigned long Status;
    // offset: 0044
    unsigned char ForeColour;
    // offset: 0045
    unsigned char BackColour;
    // offset: 0046
    long EditModeRestrictions;
};

// size: 0x9984C
struct EditorMap {
    // offset: 0000
    struct Coord3D Size;
    // offset: 0008
    struct EditorMapCell MapCell[256][256];
    // offset: 80008
    struct EditorThingInit ThingInit[4000];
    // offset: 97708
    short RematchThingInit[4000];
    // offset: 99648
    unsigned short Colide[256];
    // offset: 99848
    long SwitchId;
};

// size: 0x809
struct Room {
    // offset: 0000
    struct Coord3D Size;
    // offset: 0008
    unsigned char Orientation;
    // offset: 0009
    struct EditorRoomCell Front[8][16];
    // offset: 0109
    struct EditorRoomCell Back[8][16];
    // offset: 0209
    struct EditorRoomCell Top[16][16];
    // offset: 0409
    struct EditorRoomCell Bottom[16][16];
    // offset: 0609
    struct EditorRoomCell Left[16][8];
    // offset: 0709
    struct EditorRoomCell Right[16][8];
};

// size: 0x80A14
struct EditorRoom {
    // offset: 0000
    long SizeXpos;
    // offset: 0004
    long SizeYpos;
    // offset: 0008
    long SizeZpos;
    // offset: 000C
    long Number;
    // offset: 0010
    long LastNumber;
    // offset: 0014
    struct Room Room[256];
};

// size: 0x1ECA90
struct EditorSave {
    // offset: 0000
    struct EditorMap Map;
    // offset: 9984C
    struct Room Room[256];
    // offset: 11A24C
    struct Level Level;
};

// size: 0xC
struct EditorTool {
    // offset: 0000
    long Selected;
    // offset: 0004
    long OldSelected;
    // offset: 0008
    long SubState;
};

// size: 0xC
struct EditorCamera {
    // offset: 0000
    struct Angle Angle;
    // offset: 0008
    long Status;
};

// size: 0x1B8594
struct Editor {
    // offset: 0000
    unsigned char Setup;
    // offset: 0001
    unsigned char State;
    // offset: 0002
    unsigned char LocalState;
    // offset: 0003
    long EditMode;
    // offset: 0007
    long EditModeDisplay[8];
    // offset: 0027
    long EditModeActive[8];
    // offset: 0047
    long MiscDisplay;
    // offset: 004B
    long GroupDisplay;
    // offset: 004F
    long LevelNumber;
    // offset: 0053
    long AltitudeNumber;
    // offset: 0057
    long ShadeNumber;
    // offset: 005B
    struct EditorWindow Window[8];
    // offset: 02BB
    struct EditorWindow WindowSpare;
    // offset: 0307
    struct Coord3D MCursorPosition;
    // offset: 030F
    struct Coord3D StartMCursorPosition;
    // offset: 0317
    struct Coord3D LastMCursorPosition;
    // offset: 031F
    struct Coord3D RecordPosition[4];
    // offset: 033F
    long WindowNumberOver;
    // offset: 0343
    long WindowNumberSelected;
    // offset: 0347
    char InfoString[256];
    // offset: 0447
    char InfoStringCounter;
    // offset: 0448
    long ThingOver;
    // offset: 044C
    long ThingSelected;
    // offset: 0450
    long ThingAdjust;
    // offset: 0454
    struct EditorMenuBack MenuBack;
    // offset: 0C2C
    struct EditorWindow *WindowInUse;
    // offset: 0C30
    struct EditorMap Map;
    // offset: 9A47C
    struct EditorMap MapSpare;
    // offset: 133CC8
    struct EditorMap *MapRoom;
    // offset: 133CCC
    struct EditorMap *MapUndo;
    // offset: 133CD0
    struct EditorMap *MapTemp;
    // offset: 133CD4
    struct EditorMap *MapBrush;
    // offset: 133CD8
    struct EditorMap *MapInUse;
    // offset: 133CDC
    long RematchThingInit[4000];
    // offset: 137B5C
    long ColideFlags;
    // offset: 137B60
    struct EditorRoom Room;
    // offset: 1B8574
    struct EditorTool Tool;
    // offset: 1B8580
    struct EditorCamera Camera;
    // offset: 1B858C
    unsigned char *Textures;
    // offset: 1B8590
    unsigned char *ColideOverlay[64][64];
};

// size: 0x2
struct posasxy {
    // offset: 0000
    unsigned char X;
    // offset: 0001
    unsigned char Y;
};

// size: 0x14
struct PolyPoint {
    // offset: 0000
    long X;
    // offset: 0004
    long Y;
    // offset: 0008
    long U;
    // offset: 000C
    long V;
    // offset: 0010
    long S;
};

// size: 0x2
struct VMod {
    // offset: 0000
    unsigned char Block;
    // offset: 0001
    unsigned char Orient;
};

// size: 0x4
struct Corners {
    // offset: 0000
    char Cnw;
    // offset: 0001
    char Cne;
    // offset: 0002
    char Cse;
    // offset: 0003
    char Csw;
};

// size: 0x9
struct OriBlock {
    // offset: 0000
    unsigned char Count;
    // offset: 0001
    unsigned char Block[4];
    // offset: 0005
    unsigned char Orient[4];
};

// size: 0x4
struct _93fake {
    // offset: 0000
    short X;
    // offset: 0002
    short Y;
};

// size: 0x6
struct _94fake {
    // offset: 0000
    short X;
    // offset: 0002
    short Y;
    // offset: 0004
    unsigned char U;
    // offset: 0005
    unsigned char V;
};

// size: 0xE
struct DrawActive {
    // offset: 0000
    unsigned short SSpriteIDX;
    // offset: 0002
    unsigned char *Name;
    // offset: 0006
    unsigned short XSize;
    // offset: 0008
    unsigned short YSize;
    // offset: 000A
    unsigned char DrawType;
    // offset: 000B
    unsigned char Priority;
    // offset: 000C
    unsigned char SClass;
    // offset: 000D
    unsigned char BPad;
};

// size: 0x7
struct SmallPolyPoint {
    // offset: 0000
    short X;
    // offset: 0002
    short Y;
    // offset: 0004
    unsigned char U;
    // offset: 0005
    unsigned char V;
    // offset: 0006
    unsigned char S;
};

// size: 0x5
struct BasicQ {
    // offset: 0000
    struct BasicQ *Next;
    // offset: 0004
    unsigned char Code;
};

// size: 0x47
struct PolyQ3 {
    // offset: 0000
    struct BasicQ Packet;
    // offset: 0008
    unsigned char padb;
    // offset: 0009
    unsigned short texture_no;
    // offset: 000B
    struct PolyPoint P0;
    // offset: 001F
    struct PolyPoint P1;
    // offset: 0033
    struct PolyPoint P2;
};

// size: 0x47
struct PolyQ3F {
    // offset: 0000
    struct BasicQ Packet;
    // offset: 0008
    unsigned char Xhade;
    // offset: 0009
    unsigned short texture_no;
    // offset: 000B
    struct PolyPoint P0;
    // offset: 001F
    struct PolyPoint P1;
    // offset: 0033
    struct PolyPoint P2;
};

// size: 0x6B
struct PolyPers3 {
    // offset: 0000
    struct BasicQ Packet;
    // offset: 0008
    unsigned char Split;
    // offset: 0009
    unsigned short texture_no;
    // offset: 000B
    struct PolyPoint P0;
    // offset: 001F
    struct PolyPoint P1;
    // offset: 0033
    struct PolyPoint P2;
    // offset: 0047
    struct XYZ C0;
    // offset: 0053
    struct XYZ C1;
    // offset: 005F
    struct XYZ C2;
};

// size: 0x47
struct PolySolid3 {
    // offset: 0000
    struct BasicQ Packet;
    // offset: 0008
    unsigned char Shade;
    // offset: 0009
    unsigned char Colour;
    // offset: 000A
    unsigned char padb;
    // offset: 000B
    struct PolyPoint P0;
    // offset: 001F
    struct PolyPoint P1;
    // offset: 0033
    struct PolyPoint P2;
};

// size: 0x5B
struct PolyQ4 {
    // offset: 0000
    struct BasicQ Packet;
    // offset: 0008
    unsigned char padb;
    // offset: 0009
    unsigned short texture_no;
    // offset: 000B
    struct PolyPoint P0;
    // offset: 001F
    struct PolyPoint P1;
    // offset: 0033
    struct PolyPoint P2;
    // offset: 0047
    struct PolyPoint P3;
};

// size: 0x15
struct PolyQ3_S {
    // offset: 0000
    struct BasicQ Packet;
    // offset: 0008
    unsigned char Colour;
    // offset: 0009
    short X1;
    // offset: 000B
    short Y1;
    // offset: 000D
    short X2;
    // offset: 000F
    short Y2;
    // offset: 0011
    short X3;
    // offset: 0013
    short Y3;
};

// size: 0x18
struct PolyQ3_G {
    // offset: 0000
    struct BasicQ Packet;
    // offset: 0008
    unsigned char Colour;
    // offset: 0009
    short X1;
    // offset: 000B
    short Y1;
    // offset: 000D
    short X2;
    // offset: 000F
    short Y2;
    // offset: 0011
    short X3;
    // offset: 0013
    short Y3;
    // offset: 0015
    unsigned char S1;
    // offset: 0016
    unsigned char S2;
    // offset: 0017
    unsigned char S3;
};

// size: 0x1D
struct PolyQ3_T {
    // offset: 0000
    struct BasicQ Packet;
    // offset: 0008
    unsigned char padb;
    // offset: 0009
    short X1;
    // offset: 000B
    short Y1;
    // offset: 000D
    short X2;
    // offset: 000F
    short Y2;
    // offset: 0011
    short X3;
    // offset: 0013
    short Y3;
    // offset: 0015
    unsigned short texture_no;
    // offset: 0017
    unsigned char U1;
    // offset: 0018
    unsigned char V1;
    // offset: 0019
    unsigned char U2;
    // offset: 001A
    unsigned char V2;
    // offset: 001B
    unsigned char U3;
    // offset: 001C
    unsigned char V3;
};

// size: 0x20
struct PolyQ3_GT {
    // offset: 0000
    struct BasicQ Packet;
    // offset: 0008
    unsigned char padb;
    // offset: 0009
    short X1;
    // offset: 000B
    short Y1;
    // offset: 000D
    short X2;
    // offset: 000F
    short Y2;
    // offset: 0011
    short X3;
    // offset: 0013
    short Y3;
    // offset: 0015
    unsigned short texture_no;
    // offset: 0017
    unsigned char U1;
    // offset: 0018
    unsigned char V1;
    // offset: 0019
    unsigned char U2;
    // offset: 001A
    unsigned char V2;
    // offset: 001B
    unsigned char U3;
    // offset: 001C
    unsigned char V3;
    // offset: 001D
    unsigned char S1;
    // offset: 001E
    unsigned char S2;
    // offset: 001F
    unsigned char S3;
};

// size: 0x1B
struct RotoSpr {
    // offset: 0000
    struct BasicQ Packet;
    // offset: 0008
    unsigned char padb;
    // offset: 0009
    unsigned short padw;
    // offset: 000B
    struct Thing *Active;
    // offset: 000F
    long X;
    // offset: 0013
    long Y;
    // offset: 0017
    long Distance;
};

// size: 0x17
struct RotoShadow {
    // offset: 0000
    struct BasicQ Packet;
    // offset: 0008
    unsigned char padb;
    // offset: 0009
    unsigned short padw;
    // offset: 000B
    long X;
    // offset: 000F
    long Y;
    // offset: 0013
    long Distance;
};

// size: 0x8
struct ShortXYZ {
    // offset: 0000
    short X;
    // offset: 0002
    short Y;
    // offset: 0004
    short Z;
    // offset: 0006
    unsigned char U;
    // offset: 0007
    unsigned char V;
};

// size: 0x10
struct _95fake {
    // offset: 0000
    short X;
    // offset: 0002
    short Y;
    // offset: 0004
    unsigned short Flags;
    // offset: 0006
    short Shade;
    // offset: 0008
    struct ShortXYZ Coord;
};

// size: 0x8
struct _96fake {
    // offset: 0000
    short X;
    // offset: 0002
    short Y;
    // offset: 0004
    short Z;
    // offset: 0006
    short Wpad;
};

// size: 0xC
struct _98fake {
    // offset: 0000
    unsigned char Mode;
    // offset: 0001
    unsigned char Flags;
    // offset: 0002
    unsigned char Point1;
    // offset: 0003
    unsigned char Point2;
    // offset: 0004
    unsigned char Point3;
    // offset: 0005
    union _97fake srm;
    // offset: 0006
    unsigned char U1;
    // offset: 0007
    unsigned char V1;
    // offset: 0008
    unsigned char U2;
    // offset: 0009
    unsigned char V2;
    // offset: 000A
    unsigned char U3;
    // offset: 000B
    unsigned char V3;
};

// size: 0x8
struct _99fake {
    // offset: 0000
    short WPad;
    // offset: 0002
    unsigned char Mode;
    // offset: 0003
    unsigned char Flags;
    // offset: 0004
    unsigned char Point1;
    // offset: 0005
    unsigned char Point2;
    // offset: 0006
    unsigned char Point3;
    // offset: 0007
    unsigned char Colour;
};

// size: 0xC
struct _100fake {
    // offset: 0000
    unsigned short Sequence;
    // offset: 0002
    unsigned short CurrentMorph;
    // offset: 0004
    unsigned short OutMorph;
    // offset: 0006
    unsigned short Speed;
    // offset: 0008
    unsigned char Flags;
    // offset: 0009
    unsigned char Frame;
    // offset: 000A
    unsigned char Out;
    // offset: 000B
    unsigned char BPad;
};

// size: 0x8
struct _102fake {
    // offset: 0000
    short WPad;
    // offset: 0002
    union _101fake srm;
    // offset: 0004
    unsigned short OFrame;
    // offset: 0006
    unsigned short Matrix;
};

// size: 0x4
struct _103fake {
    // offset: 0000
    unsigned char S;
    // offset: 0001
    unsigned char BPad;
    // offset: 0002
    short WPad;
};

// size: 0x8
struct _105fake {
    // offset: 0000
    struct _96fake *Points;
    // offset: 0004
    union _104fake srm;
};

// size: 0x18
struct _108fake {
    // offset: 0000
    struct _98fake *Faces;
    // offset: 0004
    struct _96fake *Points;
    // offset: 0008
    union _106fake srm1;
    // offset: 000C
    union _107fake srm2;
    // offset: 0010
    unsigned short NoFaces;
    // offset: 0012
    unsigned short NoPoints;
    // offset: 0014
    short WPad;
    // offset: 0016
    unsigned char ID;
    // offset: 0017
    unsigned char NoFrames;
};

// size: 0x80
struct FLCFileHeader {
    // offset: 0000
    unsigned long Size;
    // offset: 0004
    unsigned short Magic;
    // offset: 0006
    unsigned short NumberOfFrames;
    // offset: 0008
    unsigned short Width;
    // offset: 000A
    unsigned short Height;
    // offset: 000C
    unsigned short Depth;
    // offset: 000E
    unsigned short Flags;
    // offset: 0010
    unsigned long Speed;
    // offset: 0014
    unsigned short Reserved_0;
    // offset: 0016
    unsigned long Created;
    // offset: 001A
    unsigned long Creator;
    // offset: 001E
    unsigned long Updated;
    // offset: 0022
    unsigned long Updater;
    // offset: 0026
    unsigned short AspectX;
    // offset: 0028
    unsigned short AspectY;
    // offset: 002A
    unsigned char Reserved_1[38];
    // offset: 0050
    unsigned long OFrame1;
    // offset: 0054
    unsigned long OFrame2;
    // offset: 0058
    unsigned char Reserved_2[40];
};

// size: 0x6
struct FLCPrefixChunk {
    // offset: 0000
    unsigned long Size;
    // offset: 0004
    unsigned short Type;
};

// size: 0x10
struct FLCFrameChunk {
    // offset: 0000
    unsigned long Size;
    // offset: 0004
    unsigned short Type;
    // offset: 0006
    unsigned short Chunks;
    // offset: 0008
    unsigned char Reserved_0[8];
};

// size: 0x6
struct FLCFrameDataChunk {
    // offset: 0000
    unsigned long Size;
    // offset: 0004
    unsigned short Type;
};

// size: 0xC
struct FLCPostageStamp {
    // offset: 0000
    unsigned long Size;
    // offset: 0004
    unsigned short Type;
    // offset: 0006
    unsigned short Height;
    // offset: 0008
    unsigned short Width;
    // offset: 000A
    unsigned short XLate;
};

// size: 0x3D8
struct Animation {
    // offset: 0000
    long PlaybackMode;
    // offset: 0004
    unsigned char *LastFrame;
    // offset: 0008
    unsigned char *NextFrameBuffer;
    // offset: 000C
    union MultiPointer NextFrameBufferPointer;
    // offset: 0010
    long PlayFileHandle;
    // offset: 0014
    long RecordFileHandle;
    // offset: 0018
    short Xpos;
    // offset: 001A
    short Ypos;
    // offset: 001C
    unsigned char Palette[768];
    // offset: 031C
    long FrameNumber;
    // offset: 0320
    long FrameSizeMaximum;
    // offset: 0324
    long Active;
    // offset: 0328
    struct FLCFileHeader FLCFileHeader;
    // offset: 03AC
    struct FLCPrefixChunk FLCPrefixChunk;
    // offset: 03B4
    struct FLCFrameChunk FLCFrameChunk;
    // offset: 03C4
    struct FLCFrameDataChunk FLCFrameDataChunk;
    // offset: 03CC
    struct FLCPostageStamp FLCPostageStamp;
};

// size: 0x1E46C
struct DB {
    // offset: 0000
    struct _17fake draw;
    // offset: 005C
    struct _18fake disp;
    // offset: 0070
    unsigned long ot[1906];
    // offset: 1E38
    unsigned char Prims[116000];
    // offset: 1E358
    struct _17fake top_split_window;
    // offset: 1E3B4
    struct _17fake btm_split_window;
    // offset: 1E410
    struct _17fake panel_split_window;
};

// size: 0x14
struct OptionMenu {
    // offset: 0000
    char *Name;
    // offset: 0004
    unsigned short Flags;
    // offset: 0006
    unsigned short SelectCount;
    // offset: 0008
    struct OptionMenu *NextMenu;
    // offset: 000C
    long TextOffset;
    // offset: 0010
    void (*Function)();
};

// size: 0xE
struct ControlUser {
    // offset: 0000
    unsigned char Key[3];
    // offset: 0003
    char Action;
    // offset: 0004
    long Data1;
    // offset: 0008
    long Data2;
    // offset: 000C
    unsigned short Flags;
};

// size: 0x24
struct tm {
    // offset: 0000
    int tm_sec;
    // offset: 0004
    int tm_min;
    // offset: 0008
    int tm_hour;
    // offset: 000C
    int tm_mday;
    // offset: 0010
    int tm_mon;
    // offset: 0014
    int tm_year;
    // offset: 0018
    int tm_wday;
    // offset: 001C
    int tm_yday;
    // offset: 0020
    int tm_isdst;
};

// size: 0xA
struct SpriteList {
    // offset: 0000
    struct Coord2D Position;
    // offset: 0004
    short SpriteNumber;
    // offset: 0006
    long Unit;
};

// size: 0xC
struct WarningText {
    // offset: 0000
    long TextNumber;
    // offset: 0004
    char Priority;
    // offset: 0005
    char Disturb;
    // offset: 0006
    short Sample;
    // offset: 0008
    char *ConnectingString;
};

// size: 0x14
struct WarningTextDisplay {
    // offset: 0000
    long TextNumber;
    // offset: 0004
    long Priority;
    // offset: 0008
    long Disturb;
    // offset: 000C
    long Count;
    // offset: 0010
    long Action;
};

// size: 0x8
struct StartUp {
    // offset: 0000
    long Action;
    // offset: 0004
    long Count;
};

// size: 0x8
struct _109fake {
    // offset: 0000
    long Min;
    // offset: 0004
    long Max;
};

// size: 0x130
struct _110fake {
    // offset: 0000
    short BBaseAlt;
    // offset: 0002
    short FBaseAlt;
    // offset: 0004
    unsigned short BPointFlags;
    // offset: 0006
    unsigned short FPointFlags;
    // offset: 0008
    unsigned short BackMask;
    // offset: 000A
    unsigned short ThisMask;
    // offset: 000C
    unsigned short FrontMask;
    // offset: 000E
    char BBaseShade;
    // offset: 000F
    char FBaseShade;
    // offset: 0010
    struct _95fake BPoints[9];
    // offset: 00A0
    struct _95fake FPoints[9];
};

// size: 0x28
struct _111fake {
    // offset: 0000
    struct PolyPoint PP;
    // offset: 0014
    struct XYZ Coord;
    // offset: 0020
    long Distance;
    // offset: 0024
    unsigned short Flags;
    // offset: 0026
    unsigned short MapWho;
};

// size: 0x5
struct SideOri {
    // offset: 0000
    unsigned char Back;
    // offset: 0001
    unsigned char Right;
    // offset: 0002
    unsigned char Front;
    // offset: 0003
    unsigned char Left;
    // offset: 0004
    unsigned char FaceOrientation;
};

// size: 0x8
struct Reorient {
    // offset: 0000
    long X;
    // offset: 0004
    long Y;
};

// size: 0x2
struct RTM {
    // offset: 0000
    unsigned char X;
    // offset: 0001
    unsigned char Y;
};

// size: 0xC
struct _112fake {
    // offset: 0000
    struct _3fake v;
    // offset: 0008
    unsigned char shade;
    // offset: 0009
    unsigned char shade2;
    // offset: 000A
    unsigned char shade3;
    // offset: 000B
    unsigned char pad;
};

// size: 0x3
struct _109fake {
    // offset: 0000
    unsigned char Red;
    // offset: 0001
    unsigned char Green;
    // offset: 0002
    unsigned char Blue;
};

// size: 0x2
struct _109fake {
    // offset: 0000
    unsigned char H;
    // offset: 0001
    unsigned char L;
};

// size: 0x1FF
struct _109fake {
    // offset: 0000
    unsigned char Magic[2];
    // offset: 0002
    unsigned char Type;
    // offset: 0003
    unsigned char BlockEntry;
    // offset: 0004
    unsigned char Title[64];
    // offset: 0044
    unsigned char reserve[27];
    // offset: 005F
    unsigned short CLUT[16];
    // offset: 007F
    unsigned char Icon1[128];
    // offset: 00FF
    unsigned char Icon2[128];
    // offset: 017F
    unsigned char Icon3[128];
};

// size: 0x2
struct _109fake {
    // offset: 0000
    unsigned char OFrame;
    // offset: 0001
    unsigned char Time;
};

// size: 0x8
struct _110fake {
    // offset: 0000
    unsigned short Object;
    // offset: 0002
    unsigned short NoFrames;
    // offset: 0004
    struct _109fake *SFrame;
};

// size: 0x8
struct _111fake {
    // offset: 0000
    short dx;
    // offset: 0002
    short dy;
    // offset: 0004
    short dz;
    // offset: 0006
    short ds;
};

// size: 0x24
struct _112fake {
    // offset: 0000
    unsigned char ID[24];
    // offset: 0018
    unsigned long FaceSize;
    // offset: 001C
    unsigned long PointSize;
    // offset: 0020
    unsigned long ShadeSize;
};

// size: 0xF
struct _113fake {
    // offset: 0000
    struct _108fake *Object;
    // offset: 0004
    unsigned short CurrentFrame;
    // offset: 0006
    unsigned short NextFrame;
    // offset: 0008
    unsigned short CurrentMorph;
    // offset: 000A
    struct M33 *Matrix;
    // offset: 000E
    unsigned char Tween : 1;
};

// size: 0x4
struct srm_Tmap_Offsets {
    // offset: 0000
    unsigned char U0;
    // offset: 0001
    unsigned char V0;
    // offset: 0002
    unsigned char U1;
    // offset: 0003
    unsigned char V1;
};

// size: 0x3
struct Cols4 {
    // offset: 0000
    unsigned char Cols[3];
};

// size: 0x8
struct XY {
    // offset: 0000
    long X;
    // offset: 0004
    long Y;
};

// size: 0x12
struct OptionObj {
    // offset: 0000
    unsigned short object_no;
    // offset: 0002
    unsigned short object_handle;
    // offset: 0004
    short tilt;
    // offset: 0006
    short roll;
    // offset: 0008
    short angle;
    // offset: 000A
    short shrink;
    // offset: 000C
    short X;
    // offset: 000E
    short Y;
    // offset: 0010
    short Z;
};

// size: 0x9
struct CarInfo {
    // offset: 0000
    char *Name;
    // offset: 0004
    unsigned char Weight;
    // offset: 0005
    unsigned char Armour;
    // offset: 0006
    unsigned char Speed;
    // offset: 0007
    unsigned char FirePower;
    // offset: 0008
    unsigned char Difficulty;
};

// size: 0x8
struct RandomHoorahs {
    // offset: 0000
    unsigned long Time;
    // offset: 0004
    unsigned long Sample;
};

// size: 0xE
struct _109fake {
    // offset: 0000
    short Id;
    // offset: 0002
    short SampleNo;
    // offset: 0004
    unsigned short left;
    // offset: 0006
    unsigned short right;
    // offset: 0008
    unsigned short pitch;
    // offset: 000A
    unsigned long mask;
};

// size: 0x8
struct _110fake {
    // offset: 0000
    unsigned long s_offset;
    // offset: 0004
    unsigned long s_length;
};

// size: 0x8
struct _111fake {
    // offset: 0000
    unsigned long spu_start;
    // offset: 0004
    unsigned long spu_size;
};

// size: 0xA
struct TmapTab {
    // offset: 0000
    unsigned long Filesize;
    // offset: 0004
    unsigned long Offset;
    // offset: 0008
    unsigned short Group;
};

// size: 0xC
struct Step {
    // offset: 0000
    long RPos;
    // offset: 0004
    long Pos;
    // offset: 0008
    long ACoord;
};

// size: 0xC
struct SkewScan {
    // offset: 0000
    long Skip;
    // offset: 0004
    long ASize;
    // offset: 0008
    long StepIn;
};

// size: 0x8
struct TX {
    // offset: 0000
    long RCoord;
    // offset: 0004
    long Coord;
};

// size: 0x8
struct CCharacter {
    // offset: 0000
    short Nice;
    // offset: 0002
    short Fast;
    // offset: 0004
    short Aggressive;
    // offset: 0006
    short Slow;
};

// size: 0x8
struct _0fake {
    // offset: 0000
    unsigned long lower;
    // offset: 0004
    long upper;
};

// size: 0xC
union MultiPtr {
    // offset: 0000
    unsigned char *AsByte;
    // offset: 0000
    unsigned short *AsWord;
    // offset: 0000
    unsigned long *AsLong;
};

// size: 0x8
union PacketData {
    // offset: 0000
    short Data[2];
    // offset: 0000
    unsigned long Control;
};

// size: 0x4
union MapPosXY {
    // offset: 0000
    unsigned short Pos;
    // offset: 0000
    struct posasxy xy;
};

// size: 0x2
union _97fake {
    // offset: 0000
    unsigned char Block;
    // offset: 0000
    unsigned char Colour;
};

// size: 0x4
union _101fake {
    // offset: 0000
    unsigned short Object;
    // offset: 0000
    unsigned short KFrame;
};

// size: 0x8
union _104fake {
    // offset: 0000
    struct _96fake *Normals;
    // offset: 0000
    struct _103fake *Shades;
};

// size: 0x8
union _106fake {
    // offset: 0000
    void *PadPtr;
    // offset: 0000
    struct _105fake *Frames;
};

// size: 0x8
union _107fake {
    // offset: 0000
    struct _96fake *Normals;
    // offset: 0000
    struct _103fake *Shades;
};

// size: 0x2C
union MultiPointer {
    // offset: 0000
    unsigned char *UByte;
    // offset: 0000
    unsigned short *UWord;
    // offset: 0000
    unsigned long *ULong;
    // offset: 0000
    char *SByte;
    // offset: 0000
    short *SWord;
    // offset: 0000
    long *SLong;
    // offset: 0000
    struct FLCFileHeader *FLCFileHeader;
    // offset: 0000
    struct FLCPrefixChunk *FLCPrefixChunk;
    // offset: 0000
    struct FLCFrameChunk *FLCFrameChunk;
    // offset: 0000
    struct FLCFrameDataChunk *FLCFrameDataChunk;
    // offset: 0000
    struct FLCPostageStamp *FLCPostageStamp;
};

// size: 0x8
union myreg {
    // offset: 0000
    unsigned long Long;
    // offset: 0000
    unsigned short Word;
    // offset: 0000
    struct _109fake WR;
};

// size: 0x10
union double_long {
    // offset: 0000
    double d;
    // offset: 0000
    struct _0fake l;
};

// size: 0x8
union float_long {
    // offset: 0000
    float f;
    // offset: 0000
    long l;
};


