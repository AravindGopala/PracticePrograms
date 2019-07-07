#include "ISerialFilterService.h"
#include <stdio.h>

static volatile int index=0;
void Update(struct SerialFilterService* S, M* Message)
{
    int i;
    S->filter(Message, S);
}

void Register(struct SerialFilterService* S, M* Message)
{
    S->m[index]=Message;
    index++;
}

void Mailbox(M* Message)
{
    printf("%d", Message->id);
}

void Filter(M* Message, struct SerialFilterService* s)
{
    int found=0;
    char* text="Not Found";
    for(int i=0; i<index; i++)
    {
    s->f1.maskId = 0x0F;
    s->f2.maskId = 0x0F;
    s->f1.valueId =s->m[i]->id;
    if( (s->f1.maskId & s->f1.valueId) == (s->f1.maskId & Message->id))
    {
        found=1;
        text ="Found";
        Mailbox(Message);
        s->callback(text);
    }
    if(index>1)
    {
       i++;
    }
    s->f2.valueId = s->m[i]->id;
    if( (s->f2.maskId & s->f2.valueId) == (s->f2.maskId & Message->id))
    {
        found=1;
        text ="Found";
        Mailbox(Message);
        s->callback(text);
    }
    }
    if(!found)
    {
     s->callback(text);
    }
}

void initialize(struct SerialFilterService* temp, void(*callback)(char *) )
{
    temp->registerMessage=&Register;
    temp->filter=&Filter;
    temp->update=&Update;
    temp->callback=callback;
}


