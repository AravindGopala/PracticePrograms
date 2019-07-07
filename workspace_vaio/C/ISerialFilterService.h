#pragma once
#define MAX_SIZE 10
#define ADDRESS_TO_READ      0xA010

typedef struct message
{
    char id;
    char data;
}M;

typedef struct filter{
    char maskId;
    char valueId;
    void(*filter)(M*);
}F;

struct SerialFilterService{
    M* m[MAX_SIZE];
    volatile F f1, f2;
    void(*registerMessage)(struct SerialFilterService*,M*);
    void(*update)(struct SerialFilterService*, M*);
    void(*filter)(M*, struct SerialFilterService*);
    void(*deRegister)(M*);
    void(*callback)(char*);
};


